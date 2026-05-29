void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
}

void loop() {
  // These constants should match the photoresistor's "gamma" and "rl10" attributes
const float GAMMA = 0.7;
const float RL10 = 50;

// Convert the analog value into lux value:
int digitalValue = digitalRead(12);
Serial.print("LDR Value: ");
Serial.println(digitalValue);
delay(500); 
}
