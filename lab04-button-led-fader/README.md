# Lab 04 - Button-Controlled LED Fader

Implements software PWM by polling Timer0 compare flags. Holding the button
ramps the LED toward full brightness; releasing it ramps toward off.

## Wiring

- LED: PB5 (on-board LED)
- Active-low push button: PB7 to ground, with internal pull-up enabled

PB7 availability depends on the board clock configuration. If PB7 is used by
an external crystal, move the button to an available GPIO and update the pin
definitions.

