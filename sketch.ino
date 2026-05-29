// Defines pins
const int pinLDR = 12; 
const int pinButton = 25;
const int pinBuzzer = 33;
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
  if(valorLuminosidade < 2000){ // Higher LUX
    tone(pinBuzzer, 250, 300); //plays buzzer 25Hz for 0.300 miliseconds
  }
  else{ // Lower LUX
    tone(pinBuzzer, 400, 500);
  }
}
  delay(2000);
}
