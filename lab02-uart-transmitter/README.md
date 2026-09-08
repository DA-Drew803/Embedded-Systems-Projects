# Lab 02 - UART Transmitter

Configures the hardware USART for 9600 baud, 8 data bits, no parity, and one
stop bit. The transmitter polls the data-register-empty flag before sending
each byte.

## Wiring

| ATmega328P | USB-to-serial adapter |
| --- | --- |
| PD1 / TXD | RX |
| GND | GND |

Open a serial terminal at 9600 8-N-1. Do not connect two actively driven TX
outputs together.

