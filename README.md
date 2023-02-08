# ecgc-boot

This project is part of the [ecgc](https://efacdev.nl/pages/project/?name=ecgc)
project.

This repository contains the boot code stored on the cartridge's boot ROM.
The boot code is the first piece of code ran to initialise the cartridge.
It also has the necessary symbols for the Gameboy to successfully boot
(cartridge header at the right place).

# Building

The boot code is developed using the [RGBDS](https://rgbds.gbdev.io/) toolchain.
It is a collection of tools for compiling and linking Gameboy assembly.

To build the code, just run the `Makefile` as such in a bash terminal:

```bash
make mem
```

This will create the Gameboy executable as `build/boot.gb`.
The added `mem` target will additionally build `build/boot.mem`,
which is needed to include the boot executable in the firmware image.

# Uploading

## Flash alongside firmware image

This method of uploading will include the boot image in the firmware image.
If this newly created firmware image is uploaded to its flash memory,
the boot code will be uploaded to flash memory as well.
Then the boot code will be loaded into the boot RAM at startup.

Firstly, the `boot_ram.vhd` file needs to be re-generated.
Using [Lattice Diamond](https://www.latticesemi.com/latticediamond)
and in the [ecgc-firmware](https://github.com/elialm/ecgc-firmware) repository,
open `/src/ips/boot_ram/boot_ram.ipx`.
This will show a dialog box like the one below,
where one must update the path to point to the new `.mem` file.

**TODO: insert image**

After the ip code is generated,
the firmware can be built and uploaded to the FPGA.

## Flash to volatile boot RAM

With this manner of uploading the boot code,
the boot image is written directly into the boot RAM.
This is volatile (meaning, the uploaded image will be gone with a powercycle),
but this is a much faster way of uploading.
It is only really intended for development purposes.

Uploading can be done using the `ecgc-upload` tool I made in the
[ecgc-util](https://github.com/elialm/ecgc-util) repository.
The command below can then be ran to upload to the boot RAM:

```bash
ecgc-upload /dev/tty-port-used path/to/boot.gb --target boot
```

Where the 1st argument is the serial port used
and the 2nd arguments is the path to the `boot.gb` file.