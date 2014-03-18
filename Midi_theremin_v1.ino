// MIDI THEREMIN
// Moritz Simon Geist
// www.sonicrobots.com
// v.1.0 14 March 2014
////////////////////////////////
// This sketch uses an HC-SR04 Ultrasonic Sensor and produces an MIDI out signal, according to the measured distance form a object
// Be sure to include the latest MIDI Library  (here 4.0)
// http://playground.arduino.cc/Main/MIDILibrary#.UyNutYUn2Hs
//
// Wiring: Ping pin from the HC-SR04 Ultrasonic Sensor --> arduino Pin 13, 
// Echo pin from HC-SR04 Ultrasonic Sensor --> Arduino PIN 12
// MIDI-Out --> TX according to this sketch http://arduino.cc/en/uploads/Tutorial/MIDI_schem.png

#include <MIDI.h>
int pingPin = 13;
int inPin = 12;
long duration;
int cm_new = 20;
int cm_old = 20;
int sens = 5; // sensivity range when to launch a new  note

void setup() {

  Serial.begin(31250); // MIDI Begin
  pinMode(pingPin, OUTPUT); // setup the Pins
  pinMode(inPin, INPUT); // setup the Pins

}
 
void loop()
{


// The PING is triggered by a HIGH pulse of 2 or more microseconds.
// Give a short LOW pulse beforehand to ensure a clean HIGH pulse:

digitalWrite(pingPin, LOW);
delayMicroseconds(2);
digitalWrite(pingPin, HIGH);
delayMicroseconds(10);
digitalWrite(pingPin, LOW);
duration = pulseIn(inPin, HIGH); // the singal from the Sensor is measured. The length of the pulse describes the distance form an object to the sensor.
 
cm_new = map(constrain(duration, 20, 3000), 50, 2000, 96, 48); // contrain --> set a threshold to cut values of the sensor that are to far away of to short (20 .. 3000) MAP --> Map the sensor range to a note values vom 96 (A high C) to 48 (a low C)

if (cm_new != cm_old) // only if a new sensor value is detected, a new nite will be send. IF the object stays stable infront of the sensor, no note will be send.
{
 MIDI.sendNoteOff(cm_old,0,1);   // Stop the old note
 MIDI.sendNoteOn(cm_new,127,1);  // Send a new Note (pitch , velocity 127, on channel 1)
cm_old = cm_new;
}
delay(30); // for staiblity
}
 

