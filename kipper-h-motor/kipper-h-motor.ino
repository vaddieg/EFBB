// DRV8833 
// IN1 connected to Digispark P0
// IN2 connected to Digispark P1

#define PWM_UP 52
// Slightly more down to avoid start point drift upwards
#define PWM_DOWN 53
#define KICK_TIME 7
#define ROTOR_TIME 560

#define ROLLER_PWM_SLOW 128
#define ROLLER_PWM_FAST 255

// for Digi
#define OUT1 0
#define OUT2 1
// for Uno
//#define OUT1 5
//#define OUT2 6


void setup() {
  pinMode(OUT1, OUTPUT);
  pinMode(OUT2, OUTPUT);
  pinMode(4, OUTPUT);
}

void dumpUp2s() {
  analogWrite(OUT1, 255);
  analogWrite(OUT2, 0);
  delay(KICK_TIME);
  analogWrite(OUT1, PWM_UP); 
  delay(ROTOR_TIME);
  analogWrite(OUT2, 0);
  analogWrite(OUT1, 0);
  delay(max(0, 2000-ROTOR_TIME-KICK_TIME));
}

void dumpDown2s() {
  analogWrite(OUT2, 255);
  analogWrite(OUT1, 0);
  delay(KICK_TIME);
  analogWrite(OUT2, PWM_DOWN);
  delay(ROTOR_TIME);
  analogWrite(OUT2, 0);
  analogWrite(OUT1, 0);
  delay(max(0, 2000-ROTOR_TIME-KICK_TIME));
}

void rollerFast() {
  analogWrite(4, ROLLER_PWM_FAST);
}

void rollerSlow() {
  analogWrite(4, ROLLER_PWM_SLOW);
}

void rollerStop() {
  analogWrite(4, 0);
}

// PLAN
//
// -0---2-----4-------8---10------14---16--18---21--23---------30-> Time, sec
//  |   |     |       |    |       |   |   |    |   |           |
// PWR  |  ROL_SLOW   |  ROL_FST ROL_0 | ROL_FST| ROL_SLOW    PWR OFF expected
//   DUMP_UP       DUMP_DOWN        DUMP_UP  DUMP_DOWN


void loop() {
  delay(2000);
  dumpUp2s();
  rollerSlow();
  delay(4000);
  dumpDown2s();
  rollerFast();
  delay(4000);
  rollerStop();
  dumpUp2s();
  rollerFast();
  delay(3000);
  dumpDown2s();
  rollerSlow();
  //wait until powered off 
  delay(15000);
  rollerStop();
  exit(0);
}
