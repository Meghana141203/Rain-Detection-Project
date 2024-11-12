const int sensorPin = 2;   // Raindrop sensor module
const int ledPin = 3;      // LED
const int buzzerPin = 4;   // Buzzer
 
void setup() 
{
  pinMode(sensorPin, INPUT);   // Set sensorPin as input
  pinMode(ledPin, OUTPUT);     // Set ledPin as output
  pinMode(buzzerPin, OUTPUT);  // Set buzzerPin as output
  Serial.begin(9600);          // Start serial communication at 9600 baud rate
}
 
void loop() 
{
  int sensorState = digitalRead(sensorPin);  // Read the digital value from the sensor
 
  if(sensorState == HIGH)  // No rain detected
  {
    digitalWrite(ledPin, LOW);    // Turn LED OFF
    noTone(buzzerPin);            // Stop playing any tone on the buzzer
    Serial.println("No rain detected");  // Output message to serial monitor
  }
  else  // Rain detected
  {
    digitalWrite(ledPin, HIGH);   // Turn LED ON
    tone(buzzerPin, 1000);        // Play a tone at 1000 Hz on the buzzer
    Serial.println("Rain detected");  // Output message to serial monitor
  }
 
  delay(1000);
}