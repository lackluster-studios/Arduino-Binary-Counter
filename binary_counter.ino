
//code for part 4 of my arduino tutorial: https://lacklusterstudios.blogspot.com/2020/07/arduino-binary-counter.html
//Binary Counter. button presses are counted and displayed as binary on 4 LED.
//licensed under GPL 3.0
//Author: chris nichols (github/rteturn5)


#define LED_1 7        //LED corresponding to digit 2^0
#define LED_2 6       //LED corresponding to digit 2^1
#define LED_4 5      //LED corresponding to digit 2^2
#define LED_8 4     //LED coresponding to digit 2^3
#define BTN_PIN 2 //pin connected to push button

int counter = 0;  //counter to hold how many times button has been pressed

void setup() {
  pinMode(LED_1,OUTPUT);
  pinMode(LED_2,OUTPUT);
  pinMode(LED_4,OUTPUT);
  pinMode(LED_8,OUTPUT);
  pinMode(BTN_PIN,INPUT);
}

void loop() {
  if(digitalRead(BTN_PIN) == HIGH) {   //when buton is pressed, set all LED to off.
    digitalWrite(LED_1,LOW);
    digitalWrite(LED_2,LOW);
    digitalWrite(LED_4,LOW);
    digitalWrite(LED_8,LOW);
    counter++;                     //increase counter by 1.
  }
  if(counter & 0b01) {          //if counter has a 1 in 2^0 place
    digitalWrite(LED_1,HIGH);
  }
  if(counter & 0b10) {         //if counter has a 1 in 2^1 place
    digitalWrite(LED_2,HIGH);
  }
  if(counter & 0b100) {        //if counter has a 1 in 2^2 place
    digitalWrite(LED_4,HIGH);
  }
  if(counter & 0b1000) {       //if counter has a 1 in 2^3 place
    digitalWrite(LED_8,HIGH);
  } 
  delay(150);                 //delay acts as software debouncing. 
}
