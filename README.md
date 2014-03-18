Midi-theremin
=============
A Midi Theremin

MIDI THEREMIN
Moritz Simon Geist
www.sonicrobots.com
v.1.0 14 March 2014
////////////////////////////////
This arduino sketch uses an HC-SR04 Ultrasonic Sensor and produces a MIDI out signal, according to the measured distance from an object. Be sure to include the latest MIDI Library (here 4.0)
http://playground.arduino.cc/Main/MIDILibrary#.UyNutYUn2Hs

Wiring
=============
Ping pin from the HC-SR04 Ultrasonic Sensor --> arduino Pin 13
Echo pin from HC-SR04 Ultrasonic Sensor --> Arduino PIN 12
MIDI-Out --> TX according to this sketch http://arduino.cc/en/uploads/Tutorial/MIDI_schem.png

The Notes which are played can be edited in the sketch
