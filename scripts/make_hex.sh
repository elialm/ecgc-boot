#!/bin/sh

error() {
    echo "$1"
    echo "$usage_str"
    exit 1
}

usage_str="make_hex.sh IN_FILE OUT_FILE

Outputs IN_FILE bin data as hex numbers to OUT_FILE"

gb_file="$1"
out_file="$2"


[ ! -f "$gb_file" ] && error "Missing IN_FILE"
[ -z "$out_file" ] && error "Missing OUT_FILE"

# Size of output ROM
mem_size=4096

hexdump -n $mem_size -v -e '1/1 "%02x" "\n"' $gb_file > $out_file
echo "Outputted \"$1\" to \"$2\""
