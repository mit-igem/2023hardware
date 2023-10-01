// remember to add the ezButton library before starting
#include <ezButton.h>

#define enA 5
#define in1 8
#define in2 9
ezButton toggleSwitch(12);

int motorSpeedA = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  toggleSwitch.setDebounceTime(50);
  pinMode(enA, OUTPUT);
  pinMode(in1,  OUTPUT);
  pinMode(in2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //analogWrite(enA, 100)
  toggleSwitch.loop();

  if (toggleSwitch.isPressed())
    Serial.println("The switch: OFF -> ON");

  if (toggleSwitch.isReleased())
    Serial.println("The switch: ON -> OFF");

  int state = toggleSwitch.getState();
  if (state == HIGH)
    Serial.println("The switch: OFF");
  else
    Serial.println("The switch: ON");

  if (state == LOW){
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(enA, 92);
  }else{
    digitalWrite(in1, HIGH);
    digitalWrite(in2, HIGH);
  }

}
/*
references:
 - https://howtomechatronics.com/tutorials/arduino/arduino-dc-motor-control-tutorial-l298n-pwm-h-bridge/
  - code and circuitry for motor and H-bridge
 - https://arduinogetstarted.com/tutorials/arduino-switch
  - code and cicuitry for switch
*/

