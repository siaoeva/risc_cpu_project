#!/bin/bash
set -e

SRC=$1
TMP_OBJ="programs/tmp.o"
TMP_BIN="programs/tmp.bin"
HEX_OUT="programs/program.hex"

# Assemble RV32I code
riscv64-unknown-elf-as -march=rv32i "$SRC" -o "$TMP_OBJ"

# Convert .text section to raw binary
riscv64-unknown-elf-objcopy -O binary -j .text "$TMP_OBJ" "$TMP_BIN"

# Convert binary to $readmemh-compatible 32-bit words with correct little-endian text
# This Perl one-liner reverses bytes per 4-byte word
perl -ne 'for($i=0;$i<length($_);$i+=4){print unpack("H8", reverse substr($_,$i,4))."\n"}' "$TMP_BIN" > "$HEX_OUT"

