#!/usr/bin/env groovy

// Required plugins:
// - Jenkins Core
// - AnsiColor (https://plugins.jenkins.io/ansicolor/)
// - Git (https://plugins.jenkins.io/git/)
// - Pipeline (https://plugins.jenkins.io/workflow-aggregator/)
// - Slack Notification (https://plugins.jenkins.io/slack/)

def all_models = 'addw2 addw3 bonw14 bonw15 darp5 darp6 darp7 darp8 darp9 galp3-c galp4 galp5 galp6 galp7 gaze15 gaze16-3050 gaze16-3060 gaze16-3060-b gaze16-3050 gaze16-3060-b gaze17-3050 gaze17-3060-b gaze18 lemp9 lemp10 lemp11 lemp12 oryp5 oryp6 oryp7 oryp8 oryp9 oryp10 oryp11 serw13'

void setBuildStatus(String state, String message) {
    // FIXME: https://www.jenkins.io/doc/book/pipeline/jenkinsfile/#string-interpolation
    sh """
    curl \
      -X POST \
      -H \'Accept: application/vnd.github+json\' \
      -H \'Authorization: Bearer ${GITHUB_TOKEN}\' \
      -H \'X-GitHub-Api-Version: 2022-11-28\' \
      https://api.github.com/repos/system76/firmware-open/statuses/${GIT_COMMIT} \
      -d \'{\"state\": \"${state}\", \"target_url\": \"${BUILD_URL}\", \"description\": \"${message}\"}\'
    """
}

pipeline {
    agent {
        label 'warp.pop-os.org'
    }

    environment {
        GITHUB_TOKEN = credentials('github-commit-status')
    }

    options {
        buildDiscarder(logRotator(numToKeepStr: '16', artifactNumToKeepStr: '1'))
        disableConcurrentBuilds()
        timeout(time: 1, unit: 'HOURS')
        timestamps()
        ansiColor('xterm')
    }

    parameters {
        string(name: 'MODELS', defaultValue: "$all_models", description: 'Space separated list of models to build', trim: true)
        string(name: 'SOURCE_BRANCH', defaultValue: 'master', description: 'Git branch or revision to build', trim: true)
    }

    triggers {
        pollSCM('')
    }

    stages {
        stage('Prepare') {
            steps {
                setBuildStatus("pending", "Pending")
                slackSend(color: "good", message: "${env.JOB_NAME} - #${env.BUILD_ID} started (<${env.BUILD_URL}|Open>)")

                // https://www.jenkins.io/doc/pipeline/steps/params/scmgit/
                checkout scmGit(
                    branches: [[name: '${SOURCE_BRANCH}']],
                    extensions: [
                        lfs(),
                        pruneStaleBranch(),
                        pruneTags(true),
                        submodule(
                            parentCredentials: true,
                            recursiveSubmodules: true,
                            reference: ''
                        ),
                    ],
                    userRemoteConfigs: [[url: 'https://github.com/system76/firmware-open.git']]
                )

                sh """#!/bin/bash
                    # Install dependencies
                    #./scripts/install-deps.sh
                    . "${HOME}/.cargo/env"

                    # Reset
                    git submodule update --init --recursive --checkout
                    git reset --hard
                    git submodule foreach --recursive git reset --hard

                    # Clean
                    git clean -dffx
                    git submodule foreach --recursive git clean -dff

                    # EDK2 builds fail if file paths in INFs change from what's in the build cache
                    pushd edk2; git clean -dffx; popd
                """
            }
        }
        stage('Build') {
            steps {
                // The workspace is reused, so must build models sequentially.
                script {
                    def list = params.MODELS.tokenize()
                    list.each { model ->
                        stage(model) {
                            sh """#!/bin/bash
                                . "${HOME}/.cargo/env"
                                # WORSKSPACE is set by Jenkins, but EDK2 uses it
                                env --unset=WORKSPACE \
                                ./scripts/build.sh "${model}"
                            """
                        }
                    }
                }
            }
        }
    }

    post {
        always {
            archiveArtifacts artifacts: 'build/*/*', allowEmptyArchive: true
        }
        success {
            setBuildStatus("success", "Successful")
            slackSend(color: "good", message: "${env.JOB_NAME} - #${env.BUILD_ID} successful after ${currentBuild.durationString} (<${env.BUILD_URL}|Open>)")
        }
        failure {
            setBuildStatus("failure", "Failed")
            slackSend(color: "danger", message: "${env.JOB_NAME} - #${env.BUILD_ID} failed after ${currentBuild.durationString} (<${env.BUILD_URL}|Open>)")
        }
        aborted {
            setBuildStatus("failure", "Failed")
            slackSend(color: "warning", message: "${env.JOB_NAME} - #${env.BUILD_ID} aborted after ${currentBuild.durationString} (<${env.BUILD_URL}|Open>)")
        }
    }
}
