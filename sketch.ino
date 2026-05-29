// Defines pins
const int pinLDR = 12; 
const int pinButton = 25;
int OldValue = LOW;

void setup() {
  // Inicializes communication with terminal
  Serial.begin(115200);
  pinMode(pinButton, INPUT);
}

void loop() {
  // Analog Reading
  int valorLuminosidade = analogRead(pinLDR);
  int NewValue = digitalRead(pinButton);

if(NewValue == HIGH){
  // Shows values on monitor
  Serial.print("Luminosidade: ");
  Serial.println(valorLuminosidade);
}
  delay(2000);
}
