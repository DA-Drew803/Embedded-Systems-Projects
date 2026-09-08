# Lab 06 - Keypad PWM Brightness Controller

Keys 0-9 select the on-board LED duty cycle in 10% increments. Timer0 schedules
matrix-keypad scans, while Timer2 generates software PWM.
The foreground loop remains idle; all periodic work is interrupt-driven.

## Wiring

- Keypad rows: PD4-PD7
- Keypad columns: PB0-PB3
- LED: PB5

The source is the original coursework implementation.
