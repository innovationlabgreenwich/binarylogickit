//defining some pins and their corresponding connections
//this allows us to reference the pin name in the code instead of the number
//if you change a connection, simply change the corresponding number in the define statement
#define BUTTON_A_PIN 2
#define BUTTON_B_PIN 3
#define GATE_LED_PIN 5
#define LED_A_PIN 6
#define LED_B_PIN 9


//variables used to track whether the buttons are pressed
int buttonA = 0;
int buttonB = 0;

void setup() {
  //setup() runs only once, the first time the code is loaded
  
  //pinMode tells the Arduino whether to take in or send out a signal to that pin
  pinMode(BUTTON_A_PIN, INPUT);
  pinMode(BUTTON_B_PIN, INPUT);
  
  pinMode(GATE_LED_PIN, OUTPUT);
  pinMode(LED_A_PIN, OUTPUT);
  pinMode(LED_B_PIN, OUTPUT);
}

void loop() {
  //loop() runs continuously over and over while the Arduino is powered

  //digitalRead detects whether the buttons are pressed or not
  buttonA = digitalRead(BUTTON_A_PIN);
  buttonB = digitalRead(BUTTON_B_PIN);

  //if the button is pressed, turn on its LED
  if(buttonA){
    digitalWrite(LED_A_PIN, HIGH);
  }
  else{
    digitalWrite(LED_A_PIN, LOW);
  }

  if(buttonB){
    digitalWrite(LED_B_PIN, HIGH);
  }
  else{
    digitalWrite(LED_B_PIN, LOW);
  }

  //this is the actual 'gate' 
  //the '||' is the function that checks that EITHER input is 1
  //turns OFF the gate LED if yes, turns on if not
  if(buttonA || buttonB){
    digitalWrite(GATE_LED_PIN, LOW);
  }
  else{
    digitalWrite(GATE_LED_PIN, HIGH);
  }

  //reset the button values just to be safe
  buttonA = 0;
  buttonB = 0;

}
