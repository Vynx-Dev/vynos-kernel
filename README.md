# VynOS
Under Development!
# Compiling
`docker build buildenv -t vynos-buildenv`
### Entering compilation enviorment
`docker run --rm -it -v C:\insertpathtoclonedrepohere:/root/env vynos-buildenv`
### Making files
`make build-x86_64`
### Emulating
`qemu-system-x86-64 -cdrom dist/x86_64/kernel.iso`
Or just flash the ISO to a CD-ROM or DVD, then boot the OS from the CD-ROM/DVD
You can easily download the ISO from releases
