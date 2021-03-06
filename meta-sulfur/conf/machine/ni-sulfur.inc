require conf/machine/ni-zynq.inc

MACHINEOVERRIDES = "ni-sulfur:${MACHINE}"

MACHINE_FEATURES = "vfat ethernet usbhost ext2 rtc"

SERIAL_CONSOLE = "115200 ttyPS0"

UBOOT_SUFFIX ?= "img"
UBOOT_ENTRYPOINT = "0000000"
UBOOT_LOADADDRESS = "0000000"
UBOOT_BINARY_ni-sulfur = "u-boot.${UBOOT_SUFFIX}"

IMAGE_BOOT_FILES ?= "boot.bin ${UBOOT_BINARY}"

KERNEL_CLASSES += "kernel-fitimage"
KERNEL_IMAGETYPE = "fitImage"
KERNEL_DEFCONFIG ?= "ni_sulfur_defconfig"

PREFERRED_VERSION_linux-yocto = "4.15.%"

MACHINE_EXTRA_RRECOMMENDS = " \
                             kernel-modules \
                             gpsd \
                             gpsd-gpsctl \
                             gpsd-machine-conf \
                             kernel-image \
                             linux-firmware-ni-sulfur \
                             linux-firmware-ni-magnesium \
                             linux-firmware-adi-mykonos \
                            "

IMAGE_INSTALL_append_ni-sulfur = " kernel-image"

PREFERRED_VERSION_u-boot = "2018.01"
