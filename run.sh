#!/usr/bin/env bash
qemu-system-riscv64 -M virt \
-display none -serial stdio \
-bios bin/u-boot-spl.bin \
-device loader,file=bin/u-boot.itb,addr=0x80200000 \
-netdev user,id=n0,tftp=./${BUILD_DIR},bootfile=build/Kernel.bin -device virtio-net-device,netdev=n0