# Hardware

Install Fritzing (on Ubuntu: `apt install fritzing`) to read the file `joystick.fzz`.

## Description

The hardware is based on the ESP32 which have a blutooth module. The microcotroller controls open-collector gates. Such gates have 2 states: 0V or High impedance.

The `common` pin on the Amstrad D-Sub connector is used to select the joystick for reading its state. When the line is 0V, the joystick is selected (otherwise it is high impedance).

## Open-collector gate

![Open-collector Nand Gate](https://github.com/landru29/amstrad_joystick/blob/master/hardware/open-collector-nand-gate.png)

## Principle

On each command passed from the PS3 controller, the ESP32 will activate an IO pin to 5V. this pin is connected to a Nand open-collector gate. the other input of the gate is the chip-select.

The chip-select of each Nand gate is the `common` line  (inverted).

![Scheme](https://github.com/landru29/amstrad_joystick/blob/master/hardware/scheme.png)

## Components

* 1 x ESP32
* 2 x 74LS38
* 1 x Resostor 1K
