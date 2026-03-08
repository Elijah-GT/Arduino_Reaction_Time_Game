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

unsigned long startTime = 0;
unsigned long reactionTime = 0;

void setup() {
  Serial.begin(9600);

  pinMode(whiteLED1, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(whiteLED2, OUTPUT);

  pinMode(buzzer, OUTPUT);

  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);

  //Creating random number using noise from floating analog pin
  //A0 is unconnected so its just picking up random electrical noise
  randomSeed(analogRead(A0));
}

void loop() {
  //Initial traffic light LED sequence. Buzzer sounds when each light turns on.
  digitalWrite(greenLED, HIGH);
  digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(buzzer, LOW);
  delay(900);
  digitalWrite(greenLED, LOW);

  digitalWrite(yellowLED, HIGH);
  digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(buzzer, LOW);
  delay(900);
  digitalWrite(yellowLED, LOW);

  digitalWrite(redLED, HIGH);
  digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(buzzer, LOW);
  delay(random(900, 4901));
  digitalWrite(redLED, LOW);


  digitalWrite(whiteLED1, HIGH);
  digitalWrite(whiteLED2, HIGH);
  startTime = millis();

  //While neither button has been pressed white LEDs stay on.
  while (!buttonPressed) {

    //The buttons use pull-up logic so their defualt state is HIGH (1).
    //When pressed their state will become LOW (0).
    if (digitalRead(button1) == LOW) {
      buttonPressed = true;
      reactionTime = millis() - startTime;

      digitalWrite(whiteLED2, LOW);  //Player 2's light turns of
    } 
    else if (digitalRead(button2) == LOW) {
      buttonPressed = true;
      reactionTime = millis() - startTime;

      digitalWrite(whiteLED1, LOW);  //Player 1's light turns off
    }
  }

  //Display Reaction Time
  Serial.print("Reaction time: ");
  Serial.print(reactionTime);
  Serial.println(" ms");
  //Sound buzzer after one of the players wins
  digitalWrite(buzzer, HIGH);
  delay(500);
  digitalWrite(buzzer, LOW);

  delay(1500);  //Long delay to rub in the loss
  digitalWrite(whiteLED1, LOW);
  digitalWrite(whiteLED2, LOW);
  buttonPressed = 0;
}
