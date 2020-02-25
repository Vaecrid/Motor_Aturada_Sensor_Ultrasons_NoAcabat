//Sensor
const int EchoPin = 3;
const int TriggerPin = 2;

//Motor
const int pinENA = 6;
const int pinIN1 = 7;
const int pinIN2 = 8;
const int speed = 200;

//If
const int analogPin = A0;    // pin that the sensor is attached to
const int motorpin = 13;       // pin that the LED is attached to
const int threshold = 25;   // an arbitrary threshold level that's in the range of the analog input


void setup() {

  //Sensor
   Serial.begin(9600);
   pinMode(TriggerPin, OUTPUT);
   pinMode(EchoPin, INPUT);
   pinMode(motorpin, OUTPUT);

   //Motor
 pinMode(pinIN1, OUTPUT);
   pinMode(pinIN2, OUTPUT);
   pinMode(pinENA, OUTPUT);

   //If
    // initialize the LED pin as an output:
  pinMode(motorpin, OUTPUT);
  // initialize serial communications:
  Serial.begin(9600);
}
 
void loop() {

  //Sensor
   int cm = ping(TriggerPin, EchoPin);
   Serial.print("Distancia: ");
   Serial.println(cm);
   delay(1000);
}
 
int ping(int TriggerPin, int EchoPin) {
   long duration, distanceCm;
   
   digitalWrite(TriggerPin, LOW);  //para generar un pulso limpio ponemos a LOW 4us
   delayMicroseconds(4);
   digitalWrite(TriggerPin, HIGH);  //generamos Trigger (disparo) de 10us
   delayMicroseconds(10);
   digitalWrite(TriggerPin, LOW);
   
   duration = pulseIn(EchoPin, HIGH);  //medimos el tiempo entre pulsos, en microsegundos
   
   distanceCm = duration * 10 / 292/ 2;   //convertimos a distancia, en cm
   return distanceCm;

   //Motor
   digitalWrite(pinIN1, HIGH);
   digitalWrite(pinIN2, LOW);
   analogWrite(pinENA, speed);
   delay(1000);

   //If
   int analogValue = analogRead(analogPin);

  // if the analog value is high enough, turn on the LED:
  if (analogValue > 25) {
    digitalWrite(motorpin, HIGH);
  } else {
    digitalWrite(motorpin, LOW);
  }

  // print the analog value:
  Serial.println(motorpin);
  delay(1);        // delay in between reads for stability
}
