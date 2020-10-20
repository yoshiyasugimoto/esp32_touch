//#include <CapacitiveSensor.h>
//
//#define LED_BUILTIN 
//
//CapacitiveSensor touchPad = CapacitiveSensor(4, 2);
//
//void setup() {
//  pinMode(LED_BUILTIN, OUTPUT);
//  touchPad.set_CS_AutocaL_Millis(0xFFFFFFFF);
//  Serial.begin(115200);
//}
//
//void loop() {
//  long val = touchPad.capacitiveSensor(30);
//  Serial.println(val);
//
//  delay(10);
//}
//

// set pin numbers
const int touchPin = 4; 
const int ledPin = 16;

// change with your threshold value
const int threshold = 20;
// variable for storing the touch pin value 
int touchValue;

void setup(){
  Serial.begin(115200);
  delay(1000); // give me time to bring up serial monitor
  // initialize the LED pin as an output:
  pinMode (ledPin, OUTPUT);
}

void loop(){
  // read the state of the pushbutton value:
  touchValue = touchRead(touchPin);
  Serial.print(touchValue);
  // check if the touchValue is below the threshold
  // if it is, set ledPin to HIGH
  if(touchValue < threshold){
    // turn LED on
    digitalWrite(ledPin, HIGH);
    Serial.println(" - LED on");
  }
  else{
    // turn LED off
    digitalWrite(ledPin, LOW);
    Serial.println(" - LED off");
  }
  delay(500);
}


//void setup() {
//  Serial.begin(115200);
//  delay(1000); // give me time to bring up serial monitor
//  Serial.println("ESP32 Touch Test");
//}
//
//void loop() {
//  Serial.println(touchRead(4));  // get value of Touch 0 pin = GPIO 4
//  delay(1000);
//}
