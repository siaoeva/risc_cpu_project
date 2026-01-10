#!/bin/bash
riscv64-unknown-elf-as -march=rv32i "$1" -o programs/tmp.o
riscv64-unknown-elf-objcopy -O ihex programs/tmp.o programs/program.hex
