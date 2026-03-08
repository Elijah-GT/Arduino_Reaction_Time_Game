/*Two player reaction time game using an Arduino Uno
  Components: Two white LEDS, one red LED, one yellow LED, one green LED
              Five 220Ohm resistors
              One Active buzzer
              Two buttons
*/

int whiteLED1 = 12;
int greenLED = 11;
int yellowLED = 10;
int redLED = 9;
int whiteLED2 = 8;

int buzzer = 7;

int button1 = 13;
int button2 = 6;

bool buttonPressed = false;

void setup() {
  pinMode(whiteLED1, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(whiteLED2, OUTPUT);

  pinMode(buzzer, OUTPUT);

  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
}

void loop() {
  //Initial traffic light LED sequence
  digitalWrite(greenLED, HIGH);
  delay(1000);
  digitalWrite(greenLED, LOW);

  digitalWrite(yellowLED, HIGH);
  delay(1000);
  digitalWrite(yellowLED, LOW);

  digitalWrite(redLED, HIGH);
  delay(1000);
  digitalWrite(redLED, LOW);

  //While neither button has been pressed white LEDs stay on.
  while(!buttonPressed)
  {
    digitalWrite(whiteLED1, HIGH);
    digitalWrite(whiteLED2, HIGH);
    if(digitalRead(button1) == 0); 
  }

  /*
  digitalWrite(buzzer, HIGH);
  delay(500);
  digitalWrtie(buzzer, LOw);
  */

  if(button1)

}
