#!/bin/bash
set -e

pkill -f "qemu-system-aarch64.*-s" 2>/dev/null || true
sleep 0.5

qemu-system-aarch64 -machine virt -cpu cortex-a57 -m 1G \
    -bios bin/uboot-tftp.bin \
    -netdev user,id=net0,tftp=build \
    -device virtio-net-device,netdev=net0 \
    -nographic -s -S &
PID=$!
until nc -z localhost 1234 2>/dev/null; do sleep 0.1; done
echo 'QEMU ready (GDB on :1234)'
wait $PID
