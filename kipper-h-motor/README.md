# Stage controller for a dump track + asphalt roller animation
This firmware plays ~30 seconds long automated control sequence

## Components

- Digispark ATTiny85
- H-bridge DRV8833
- prototype PCB

## Controlled objects

- Viessmann Dump truck (3V DC motor)
- Magnetically driven asphalt roller (3V 14rpm gear motor)

## Power supply

The setup is powered from the 16V DC stage grid. 
Digispark onboard linear converter is sufficient to provide ~80mA operating current for motors.