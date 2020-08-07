# Beam Shutter

Set of shutters for controlling beams in optical systems. Designed for fluorescence microscopy to prevent photobleaching.

## Getting Started

When you have servos with any light blocking material attached to them simply connect them to any Arduino board, attach some switches, upload code to Arduino (change ports in code according to your setup) and enjoy.

## Theory of operation

Servos use a PWM signal for steering, the angle at wich the servo settles is directly proportional to the signal's duty cycle (or, at least in some range!). Servos need power (two connections) and steering (the third connection), power is delivered directly, but the signal comes from an Arduino board. The maximal number of usable servos is lemited by the number of PWM outputs on the Arduino used. In the case of Arduino Micro it's 7. The current project uses only 4 servos but nearly all other outputs are used for remote control and state display. More servos are only possible while sarificing local control for only the serial port control.

Based on the expected state, the Arduino changes the output state in order to change the servo state and the display state. The remote has two buttons (one for opening the respective shutter and one for closing) and two LEDs (green and red, respectively). They are diven by a pair of chained transistors, so only one signal is needed to control their state.

## Built With

* [Arduino](https://www.arduino.cc/) - Arduino web site
* [Thingiverse - shutters](https://www.thingiverse.com/thing:1767151) - 3D models of shutters and holders for servos
