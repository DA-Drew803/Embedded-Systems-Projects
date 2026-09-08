# ATmega328P Bare-Metal Embedded Projects

Eight register-level C projects developed on the AVR Xplained Mini 328P. The
collection progresses from GPIO timing and serial communication to matrix
keypads, timer interrupts, ADC sampling, PWM, and EEPROM persistence.

## Projects

| Project | Demonstrates | Hardware |
| --- | --- | --- |
| [01 - Morse LED Encoder](lab01-morse-led/) | GPIO, timed character encoding | On-board LED |
| [02 - UART Transmitter](lab02-uart-transmitter/) | USART configuration, polling | USB-to-serial adapter |
| [03 - Keypad UART Interface](lab03-keypad-uart/) | Matrix scanning, USART | 4x4 keypad |
| [04 - Button LED Fader](lab04-button-led-fader/) | Timer polling, software PWM | Push button, LED |
| [05 - Keypad Synthesizer](lab05-keypad-synth/) | Timer-based tone generation | 4x4 keypad, audio output |
| [06 - Keypad PWM Controller](lab06-keypad-pwm/) | Multiple timers, interrupts, software PWM | 4x4 keypad, LED |
| [07 - ADC Light Controller](lab07-adc-light-controller/) | ADC, periodic sampling, interrupts, PWM | Potentiometer, LED |
| [08 - Persistent LED State](lab08-eeprom-persistent-led/) | EEPROM, power-cycle persistence, PWM | LED |

## Target

- Microcontroller: ATmega328P
- Development board: AVR Xplained Mini 328P
- Clock: 16 MHz
- IDE used for the coursework: Atmel Studio
- Language/toolchain: AVR GCC C through Atmel Studio
- Programming style: direct peripheral-register access

## Building with Atmel Studio

1. Open Atmel Studio and select **File > New > Project**.
2. Create a **GCC C Executable Project**.
3. Select the **ATmega328P** target device.
4. Replace the generated `main.c` with the file from one lab folder.
5. Select **Build > Build Solution**.
6. Connect the AVR Xplained Mini 328P and program it with the board's
   integrated debugger/programmer.

Each lab should be a separate Atmel Studio project because every folder has its
own `main()` function. All projects assume a 16 MHz clock. The included
Makefile is an optional command-line alternative.

## Design notes

The `main.c` files preserve the original coursework implementations. Only
PDF formatting was normalized and personal identifiers were replaced with
neutral placeholders. Known issues in the original source remain unchanged.

All identifiers and sample messages in this public version are non-personal.
Pin mappings are documented inside each project directory. Verify voltage
levels and disconnect conflicting peripherals before wiring external hardware.
