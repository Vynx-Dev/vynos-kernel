# VynOS

Under Development!

# Compiling and Running

## Prerequisites

Docker, QEMU (you just need the qemu-system-x86_64 binary), WSL (if you're on windows)

### Entering compilation environment

MAKE SURE DOCKER IS RUNNING FIRST

`sudo docker build buildenv -t vynos-buildenv`

`sudo docker run --rm -it -v /insertpathtoclonedrepohere:/root/env vynos-buildenv`
### Making files

`make build-x86_64`

### Emulating

`qemu-system-x86-64 -cdrom dist/x86_64/kernel.iso`

Or just flash the ISO to a CD-ROM or DVD, then boot the OS from the CD-ROM/DVD,

you can also download the ISO from the releases page

# Docs

Please check out the docs in docs/

These docs contain important info about error codes and OS contributing
