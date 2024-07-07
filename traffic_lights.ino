#include <Arduino.h>

#define GREEN 14
#define YELLOW 27
#define RED 12

#define STOP_DELAY 3000
#define WAIT_DELAY 3000
#define GO_DELAY 1500
#define GO_WAIT_BLINKS 5

#define IDEL_BLINK_DELAY 300

enum stateMachine_t : int {
  WAIT = 1,
  STOP = 2,
  GO = 3,
  IDEL = 4

};

stateMachine_t currant_state;
int blink_counter = 0;

long globleStartTime = millis();

void changeStatus(stateMachine_t state);
void doStop();
void doWait();
void changeLED(int value);
void doIdel(int blink_count, stateMachine_t next);
void doGo();
void doTrafficLights();
void testLights();

void changeStatus(stateMachine_t state) {
  globleStartTime = millis();
  currant_state = state;
}

void changeLED(int value) {
  digitalWrite(YELLOW, value);
  digitalWrite(RED, value);
  digitalWrite(GREEN, value);
}
void testLights() {

  changeLED(LOW);
  delay(500);
  changeLED(HIGH);
  delay(50);
  changeLED(LOW);
}

void doStop() {

  digitalWrite(RED, HIGH);
  if ((globleStartTime + STOP_DELAY) < millis() &&
      currant_state == stateMachine_t::STOP) {
    digitalWrite(RED, LOW);
    changeStatus(stateMachine_t::WAIT);
  }
}

void doWait() {
  digitalWrite(YELLOW, HIGH);
  if (globleStartTime + WAIT_DELAY < millis() &&
      currant_state == stateMachine_t::WAIT) {
    changeStatus(stateMachine_t::GO);
    changeLED(LOW);
  }
}

void doIdel(int blink_count, stateMachine_t next) {
  static long startTime = millis();
  if (startTime + IDEL_BLINK_DELAY < millis() &&
      currant_state == stateMachine_t::IDEL) {
    digitalWrite(YELLOW, !digitalRead(YELLOW));
    blink_counter++;
    startTime = millis();
  }
  if (blink_counter > blink_count) {
    changeStatus(next);
    blink_counter = 0;
    changeLED(LOW);
  }
}

void doGo() {
  digitalWrite(GREEN, HIGH);
  if (globleStartTime + 1500 < millis() &&
      currant_state == stateMachine_t::GO) {
    changeStatus(stateMachine_t::IDEL);
    doIdel(GO_WAIT_BLINKS, stateMachine_t::STOP);
  }
}

void doTrafficLights() {
  switch (currant_state) {
  case stateMachine_t::WAIT: {

    doWait();
    break;
  }
  case stateMachine_t::GO: {
    doGo();
    break;
  }
  case stateMachine_t::STOP: {
    doStop();
    break;
  }
  case stateMachine_t::IDEL: {
    doIdel(20, stateMachine_t::STOP);
    break;
  }
  }
}

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  testLights();
  changeStatus(stateMachine_t::IDEL);
}
void loop() {
  doTrafficLights();
  // d
}
