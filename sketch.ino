// Defines the pin wwhere "AO" will conect
const int pinLDR = 12; 

void setup() {
  Serial.begin(115200); //inicializes the program
}

void loop() {
  // Analog read of the LDR
  int valorLuminosidade = analogRead(pinLDR); //pinLDR is defined as "12"

  // Shows on terminal:
  Serial.print("Luminosidade: ");
  Serial.println(valorLuminosidade);
  // Waits 2 secs for the next read
  delay(2000);
}
