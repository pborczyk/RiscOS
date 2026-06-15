#!/bin/bash
qemu-system-aarch64 -machine virt -cpu cortex-a57 -kernel build/Kernel.elf -nographic -s -S &
PID=$!
until nc -z localhost 1234 2>/dev/null; do sleep 0.1; done
echo 'QEMU ready (GDB on :1234)'
wait $PID
