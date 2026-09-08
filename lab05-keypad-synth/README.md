# Lab 05 - Keypad Synthesizer

Turns a 4x4 matrix keypad into a small monophonic synthesizer. Each key selects
a different note, and Timer0 produces a square wave while the key is held.

## Wiring

- Keypad rows: PD4-PD7
- Keypad columns: PB0-PB3
- Audio square-wave output: PD1
- Common ground

Use an appropriate current-limiting/interface circuit for the selected audio
device. A microcontroller GPIO pin should not directly drive low-impedance
headphones or a speaker.

