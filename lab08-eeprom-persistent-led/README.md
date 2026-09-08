# Lab 08 - EEPROM-Persistent LED Brightness

Stores an LED brightness setting in EEPROM so it survives loss of power. Each
reset advances the brightness by 10%; after 100%, it wraps back to off. Timer0
generates approximately 200 Hz software PWM.

## Hardware

- LED: PB5 (on-board LED)
- Board powered through its normal regulated supply

This demonstrates power-cycle persistence; the firmware does not electrically
detect a charger or power connector. `eeprom_update_byte` avoids writing when
the stored value is already unchanged.

