// made by SnootyPascal

// Define each staircase light
const int LED_pin_1  =  13;
const int LED_pin_2  =  2;
const int LED_pin_3  =  3;
const int LED_pin_4  =  4;
const int LED_pin_5  =  5;
const int LED_pin_6  =  6;
const int LED_pin_7  =  7;
const int LED_pin_8  =  8;
const int LED_pin_9  =  9;
const int LED_pin_10 = 10;
const int LED_pin_11 = 11;
const int LED_pin_12 = 12;




//Define LDR
const int LDR_pin = A0;
// Define the LDR values 
int LDR_Night = 200;      // Adjust these values based on your specific LDR readings
int LDR_evening = 500;
int ldrValue = 0;
int mode = 1;

// Define pir PIN
const int PIR_down_stair = 3;
const int PIR_up_stair  = 4;

// Define time all stairs will be illuminated after the on animation.

//Define  light times
#define Start_up_time 5
#define Cool_down_time 5
#define Time_between_stairs_on 60
#define Time_between_stairs_off 1
#define Time_between_on_off 60


void setup() {
Serial.begin(115200);

// put your setup code here, to run once:
pinMode(LED_pin_1, OUTPUT);
pinMode(LED_pin_2, OUTPUT);
pinMode(LED_pin_3, OUTPUT);
pinMode(LED_pin_4, OUTPUT);
pinMode(LED_pin_5, OUTPUT);
pinMode(LED_pin_6, OUTPUT);
pinMode(LED_pin_7, OUTPUT);
pinMode(LED_pin_8, OUTPUT);
pinMode(LED_pin_9, OUTPUT);
pinMode(LED_pin_10, OUTPUT);
pinMode(LED_pin_11, OUTPUT);
pinMode(LED_pin_12, OUTPUT);

// setup LDR Pin
pinMode(LDR_pin, INPUT);

// setup PIR
pinMode(PIR_down_stair, INPUT);
pinMode(PIR_up_stair, INPUT);
}


void loop() {
 int ldrValue = analogRead(LDR_pin);
 Serial.println(ldrValue); // this prints the value of the LDR

  if (ldrValue < LDR_Night) {
    mode = 1; //Night mode 
  }
  else if (ldrValue >= LDR_Night && ldrValue < LDR_evening) {
    mode = 2; //Evening mode
  }
  else {
    mode = 3; //Day mode
  }

  switch (mode) {
    case 1:  //=========================================================================================================================================================== Night mode 
              if (digitalRead(PIR_down_stair) == LOW) {
    int ledPins[] = {LED_pin_1, LED_pin_2, LED_pin_3, LED_pin_4, LED_pin_5, LED_pin_6, LED_pin_7, LED_pin_8, LED_pin_9, LED_pin_10, LED_pin_11, LED_pin_12};
  for (int i = 0; i < 12; i++) {
    for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
      analogWrite(ledPins[i], dutyCycle);
      delay(Start_up_time);
  }
  delay(Time_between_stairs_on); 
}

  delay(Time_between_on_off);

  for (int i = 0; i < 12; i++) {
    for (int dutyCycle = 255; dutyCycle >= 0; dutyCycle--) {
        analogWrite(ledPins[i], dutyCycle);
       delay(Cool_down_time);
  }
  delay(Time_between_stairs_off);
}


  }
   else if (digitalRead(PIR_up_stair) == LOW) {

     int ledPins[] = {LED_pin_12, LED_pin_11, LED_pin_10, LED_pin_9, LED_pin_8, LED_pin_7, LED_pin_6, LED_pin_5, LED_pin_4, LED_pin_3, LED_pin_2, LED_pin_1};
  for (int i = 0; i < 12; i++) {
    for (int dutyCycle = 0; dutyCycle <= 10; dutyCycle++) {
    analogWrite(ledPins[i], dutyCycle);
    delay(Start_up_time);
  }
  delay(Time_between_stairs_on);
}

  delay(Time_between_on_off);

  for (int i = 0; i < 12; i++) {
    for (int dutyCycle = 10; dutyCycle >= 0; dutyCycle--) {
      analogWrite(ledPins[i], dutyCycle);
      delay(Cool_down_time);
  }
  delay(Time_between_stairs_off);
}

  } 
      break;
    case 2: //=========================================================================================================================================================== Evening mode
        if (digitalRead(PIR_down_stair) == LOW) {
    int ledPins[] = {LED_pin_1, LED_pin_2, LED_pin_3, LED_pin_4, LED_pin_5, LED_pin_6, LED_pin_7, LED_pin_8, LED_pin_9, LED_pin_10, LED_pin_11, LED_pin_12};
  for (int i = 0; i < 12; i++) {
    for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
      analogWrite(ledPins[i], dutyCycle);
      delay(Start_up_time);
  }
  delay(Time_between_stairs_on);
}

  delay(Time_between_on_off);

  for (int i = 0; i < 12; i++) {
    for (int dutyCycle = 255; dutyCycle >= 0; dutyCycle--) {
        analogWrite(ledPins[i], dutyCycle);
       delay(Cool_down_time);
  }
  delay(Time_between_stairs_off);
}


  }
   else if (digitalRead(PIR_up_stair) == LOW) {

     int ledPins[] = {LED_pin_12, LED_pin_11, LED_pin_10, LED_pin_9, LED_pin_8, LED_pin_7, LED_pin_6, LED_pin_5, LED_pin_4, LED_pin_3, LED_pin_2, LED_pin_1};
  for (int i = 0; i < 12; i++) {
    for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
    analogWrite(ledPins[i], dutyCycle);
    delay(Start_up_time);
  }
  delay(Time_between_stairs_on);
}

  delay(Time_between_on_off);

  for (int i = 0; i < 12; i++) {
    for (int dutyCycle = 255; dutyCycle >= 0; dutyCycle--) {
      analogWrite(ledPins[i], dutyCycle);
      delay(Cool_down_time);
  }
  delay(Time_between_stairs_off);
}

  } 
    break;
    case 3: //=========================================================================================================================================================== day mode

  if (digitalRead(PIR_down_stair) == LOW) {
    int ledPins[] = {LED_pin_1, LED_pin_2, LED_pin_3, LED_pin_4, LED_pin_5, LED_pin_6, LED_pin_7, LED_pin_8, LED_pin_9, LED_pin_10, LED_pin_11, LED_pin_12};
  for (int i = 0; i < 12; i++) {
    for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
      analogWrite(ledPins[i], dutyCycle);
      delay(Start_up_time);
  }
  delay(Time_between_stairs_on);
}

  delay(Time_between_on_off);

  for (int i = 0; i < 12; i++) {
    for (int dutyCycle = 255; dutyCycle >= 0; dutyCycle--) {
        analogWrite(ledPins[i], dutyCycle);
       delay(Cool_down_time);
  }
  delay(Time_between_stairs_off);
}


  }
   else if (digitalRead(PIR_up_stair) == LOW) {

     int ledPins[] = {LED_pin_12, LED_pin_11, LED_pin_10, LED_pin_9, LED_pin_8, LED_pin_7, LED_pin_6, LED_pin_5, LED_pin_4, LED_pin_3, LED_pin_2, LED_pin_1};
  for (int i = 0; i < 12; i++) {
    for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
    analogWrite(ledPins[i], dutyCycle);
    delay(Start_up_time);
  }
  delay(Time_between_stairs_on);
}

  delay(Time_between_on_off);

  for (int i = 0; i < 12; i++) {
    for (int dutyCycle = 255; dutyCycle >= 0; dutyCycle--) {
      analogWrite(ledPins[i], dutyCycle);
      delay(Cool_down_time);
  }
  delay(Time_between_stairs_off);
}

  } 
  }
}
