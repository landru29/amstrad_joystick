# Amstrad Joystick

Use a PS3 controller as joystick on an AMSTRAD CPC.

![Amstrad](https://github.com/landru29/amstrad_joystick/blob/master/Amstrad_CPC464.jpg)

## What's needed

* PS3 controller
* ESP32
* 74LS38
* Resostor 1K


![Open-collector Nand Gate](https://github.com/landru29/amstrad_joystick/blob/master/esp32.jpg)

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

In the [tool](https://github.com/landru29/amstrad_joystick/tree/master/tool) folder, compile `sixpair.c` and use it as describes in the `tool/README.md`.

### hardware

#### Scanning the Keyboard and Joysticks

The keyboard and joysticks are scanned using the AY-3-8912 PSG and the 8255 PPI.

It is necessary that you understand how to use these before you continue to read this document.

The keys on the keyboard, and the joystick directions and buttons, are arranged in an 10 by 8 matrix. Each element of the matrix is a switch and represents the state of a key or a joystick button.

The matrix is read a column at a time, each column is read as a byte, and this holds the state of 8 switches.

When the matrix is read, a switch will be "0" or "1".

If the switch is "0" then the key/joystick button corresponding to that bit is pressed,
If the switch is "1" then the key/joystick button is not pressed,
Joystick 0 occupies it's own space in the matrix and is accessed at line 9. Joystick 1 shares line 6 with the keyboard. As a result, it is possible to simulate the state of joystick 1 by pressing the appropiate keys on the keyboard.

#### The matrix

The position of each key/joystick button in the matrix is shown in the table below.

bit | 0            | 1            | 2       | 3     | 4    | 5      | 6                 | 7   | 8          | 9            |
----|--------------|--------------|---------|-------|------|--------|-------------------|-----|------------|--------------|
  7 | f.           | f0           | Ctrl    | > ,   | < .  | Space  | V                 | X   | Z          | Del          |
  6 | Enter        | f2           | ` \     | ? /   | M    | N      | B                 | C   | Caps Lock  | Unused       |
  5 | f3           | f1           | Shift   | * :   | K    | J      | F / Joy 1 Fire 1  | D   | A          | Joy 0 Fire 1 |
  4 | f6           | f5           | f4      | + ;   | L    | H      | G / Joy 1 Fire 2  | S   | Tab        | Joy 0 Fire 2 |
  3 | f9           | f8           | } ]     | P     | I    | Y      | T / Joy 1 Right   | W   | Q          | Joy 0 Right  |
  2 | Cursor Down  | f7           | Return  | @     | O    | U      | R / Joy 1 Left    | E   | Esc        | Joy 0 Left   |
  1 | Cursor Right | Copy         | { [     | = -   | ) 9  | ' 7    | % 5 / Joy 1 Down  | # 3 | " 2        | Joy 0 Down   |
  0 | Cursor Up    | Cursor Left  | Clr     | Â£ ^  | _ 0  | ( 8    | & 6 / Joy 1 Up    | $ 4 | ! 1        | Joy 0 Up     |

Note:

* Bit 6 on lines 9 and 6, may be used to report a third fire button on a joystick. This bit is also used as the middle button on an AMX compatible mouse.
* For CPC464 and CPC664 users: Those keys prefixed with an "f" are located on the numeric keypad.
* "f." is the "." key on the numeric keypad.
* For CPC464 and CPC664 users:
  * ENTER is the small ENTER key,
  * RETURN is the large ENTER key
* If matrix line 11-14 are selected, the byte is always &ff. After testing on a real CPC, it is found that these never change, they always return &FF.
* Watch out for KEYBOARD CLASH!

#### Amstrad D-Sub pinout

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

#### Build the Hardware

Refer to the folder [hardware](https://github.com/landru29/amstrad_joystick/tree/master/hardware) to read information to build the hardware.

## Reference

- https://github.com/jvpernis/esp32-ps3
- https://cpctech.cpc-live.com/docs/keyboard.html