#!/usr/bin/env bash

if [ "${EUID}" != "0" ]
then
	exec sudo "$0" "$@"
fi

set -e

for codec in /dev/snd/hw*
do
	codec_id="$(basename "${codec}")"
	codec_sys="/sys/class/sound/${codec_id}"
	vendor="$(cat "${codec_sys}/vendor_name")"
	chip="$(cat "${codec_sys}/chip_name")"
	if [ "${vendor}" == "Realtek" ]
	then
		echo "# ${codec_id}: ${vendor} ${chip}"

		# Realtek vendor node
		nid=0x20

		# Get processing capabilities
		proc_cap="$(hda-verb "${codec}" "${nid}" PARAMETERS PROC_CAP 2>/dev/null | cut -d " " -f 3)"

		seq "$(("${proc_cap}" >> 8))" | while read index
		do
			# Set coefficient index
			index_hex="$(printf "0x%02x\n" "${index}")"
			hda-verb "${codec}" "${nid}" SET_COEF_INDEX "${index_hex}" &>/dev/null

			# Get processing coefficient
			value="$(hda-verb "${codec}" "${nid}" GET_PROC_COEF 0 2>/dev/null | cut -d " " -f 3)"
			echo "${index_hex}: ${value}"
		done
	fi
done
