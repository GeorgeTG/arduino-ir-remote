
#include <Arduino.h>
#include <IRremote.h>
#include <Timer.h>
#include "main.hpp"

#define IR_PERIOD 150

const int ir_pin = 6;
const int led_pin = 2;

int ir_event;
unsigned long last_code;

Timer t;

IRrecv irrecv(ir_pin, led_pin);
decode_results results; //Keep decoded IR data

void setup() {
  Serial.begin(9600);

  irrecv.enableIRIn(); //Enable IR receiver
  ir_event = t.every(IR_PERIOD, ir_read);
  pinMode(led_pin, OUTPUT);
  blink(2);
}

void loop() {
  t.update();
}

void handle_key_press() {
  switch(last_code) {
    case KEY_RIGHT:{
      Serial.println("KEY_RIGHT");
      break;
    }
    case KEY_LEFT:{
      Serial.println("KEY_LEFT");
      break;
    }
    case KEY_UP:{
      Serial.println("KEY_UP");
      break;
    }
    case KEY_DOWN:{
      Serial.println("KEY_DOWN");
      break;
    }
    case KEY_OK:{
      Serial.println("KEY_OK");
      break;
    }
  }
}

void ir_read() {
  if ( irrecv.decode(&results) ) {
    // We got some IR data
    if ( results.value != IR_REPEAT ) {
      last_code = results.value;
    }
    irrecv.resume(); // receive the next value
    blink(2);
    handle_key_press();
  }
}

void blink(int times) {
  t.oscillate(led_pin, 150, LOW, times);
}
