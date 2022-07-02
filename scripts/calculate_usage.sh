#!/bin/sh

error() {
    echo "$1"
    echo "$usage_str"
    exit 1
}

usage_str="calculate_usage.sh MAP_FILE

Calculates usage of ROM0 in percentage with 100% being 4kB"

map_file="$1"

[ ! -f "$map_file" ] && error "Missing MAP_FILE"

# Size of output ROM
mem_size=4096

bytes_used_hex=$( grep --color=never -e 'ROM0: ' "$map_file" | sed -E 's/\s*ROM0: \$([0-9A-Fa-f]{4}) bytes in 1 bank/\1/' )
bytes_used_dec=$(( 0x$bytes_used_hex ))
percentage_used=$( echo "scale=4;$bytes_used_dec/$mem_size*100" | bc | sed -E 's/([0-9]{1,3}.[0-9]{2})00/\1/' )

echo "Using $bytes_used_dec of $mem_size bytes ($percentage_used%)"