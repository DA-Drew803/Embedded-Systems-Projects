# Lab 03 - Keypad UART Interface

Scans a 4x4 matrix keypad and transmits each newly pressed key through the
hardware UART. The original implementation uses a 500 ms delay after detecting
a key press to limit repeated characters.

## Wiring

- Keypad rows: PD4-PD7
- Keypad columns: PB0-PB3 (internal pull-ups enabled)
- UART TX: PD1
- Common ground between the board and serial adapter
