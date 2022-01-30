# Amstrad Joystick

Use a PS3 controller as joystick on an AMSTRAD CPC.

## What's needed

* PS3 controller
* ESP32

## Installation

### Installing the ESP32 board ###

In case you haven't yet, you can add the ESP32 boards to your Arduino IDE by adding them to the Boards Manager: Open `File -> Preferences`, and paste the following URL in the `Additional Boards Manager URLs` field:

- `https://dl.espressif.com/dl/package_esp32_index.json`

Open the Boards Manager with `Tools -> Board: "xxx" -> Boards Manager`, look for `esp32` (probably the last one in the list), and click `Install`.

Finally, select the ESP32 board you have with `Tools -> Board: "xxx"` under the section `ESP32 Arduino` (I always have `ESP32 Dev Module` selected).


### Installing the library ###

You can install the Arduino library from within the Arduino IDE. Open the Library Manager with `Sketch -> Include Library -> Manage Libraries...`.

Search for `PS3 Controller Host`, and click `Install`.

### Upload code

Compile and download the code on the `ESP32 Dev Module`.

On the serial console, the ESP32 Address is displayed. This address must be paired on the PS3 controller.

### Pair the device

In the `tool` folder, compile `sixpair.c` and use it as describes in the `tool/README.md`.

### hardware

| Amstrad pin | Description |
| ----------- | ----------- |
| 01          | Up          |
| 02          | Down        |
| 03          | Left        |
| 04          | Right       |
| 05          | Spare       |
| 06          | Button2     |
| 07          | Button1     |
| 08          | Common      |

TODO: How to control the CPC joystick port.
TODO: Where to find 5V.

## Reference

https://github.com/jvpernis/esp32-ps3