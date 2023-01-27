# sixpair

This file is from project http://www.pabr.org/sixlinux/sixlinux.en.html

## Prerequisite

You must have a sane installation of `libusb`
## Build

```bash
make
```

## Usage

### 1 - You must first plug the ps3 controller via USB

### 2 - Read the paired device

```bash
./sixpair
```

### 3 - Pair the ESP32

Get the address of the ESP32 by pluggin it to the usb, and openning the serial console.

Then type:

```bash
./sixpair xx:xx:xx:xx:xx:xx
```
