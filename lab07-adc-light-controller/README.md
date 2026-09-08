# Lab 07 - ADC LED Brightness Controller

Samples a potentiometer on ADC3 every 10 ms and maps the 10-bit result to LED
brightness. Timer0 schedules conversions, the ADC completion interrupt updates
the duty cycle, and Timer2 generates 500 Hz software PWM.

## Wiring

| Potentiometer terminal | Connection |
| --- | --- |
| One outer terminal | VCC |
| Wiper | PC3 / ADC3 |
| Other outer terminal | GND |

The LED is on PB5. The source is the original coursework implementation.
