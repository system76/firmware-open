echo "# Models" > README.md
for readme in ./*/README.md
do
    line="$(head -n 1 "$readme" | cut -d ' ' -f2-)"
    echo "- [$line]($readme)" >> README.md
done
