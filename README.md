# PINAUK
PINAUK Is Not an Another Unix Kernel

Yeah, it uses UEFI-SIMPLE.

Its license is in the LICENSE file.


## What is PINAUK?
PINAUK means "**P**INAUK **I**s **N**ot an **A**nother **U**nix **K**ernel".

This is a kernel written in C for UEFI.

You can also contribute to this project as written in the CONTRIBUTING file.

## How to build and run?
Follow those instructions to ensure the kernel builds correctly:
### Prerequisites
- [Microsoft Visual Studio 2022](https://visualstudio.microsoft.com/)
- A Git client such as [GitHub Desktop](https://desktop.github.com/download/)
- [QEMU](http://www.qemu.org) __v2.7 or later__ (NB: You can find QEMU Windows binaries [here](https://qemu.weilnetz.de/w64/))
### Compilation and testing
If you are using Visual Studio, press ```F5``` to build and run the kernel in QEMU.
If you need to test it on real hardware:
#### Testing on real hardware
1. Get a USB stick
2. Format is as FAT32
3. Copy the built binaries folder onto it (the entire image folder's contents (subfolders), not just the binaries)
4. Boot from the drive
### Note about ARM/ARM64 support
Edit your current VS installation in VS Installer -> Add individual components "MSVC v142 - VS 2019 C++ ARM build tools (v14.22)" for ARM and "MSVC v142 - VS 2019 C++ ARM64 build tools (v14.22)" for ARM64.
