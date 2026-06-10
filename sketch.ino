#include <Arduino.h>

const int pinLDR = 12; 
const int pinButton = 25;
const int pinBuzzer = 33;

void setup() {
  Serial.begin(115200);
  pinMode(pinButton, INPUT);
  pinMode(pinBuzzer, OUTPUT);
}

void loop() {
  int valorLuminosidade = analogRead(pinLDR);
  int NewValue = digitalRead(pinButton);

  // Proteção contra leitura zero (evita travar o cálculo)
  if (valorLuminosidade == 0) valorLuminosidade = 1; 

  // --- CÁLCULO DO LUX ---
  float voltagem = valorLuminosidade * (3.3 / 4095.0);
  float resistenciaLDR = (10000.0 * (3.3 - voltagem)) / voltagem;
  
  // Garante que a resistência não zere se a voltagem atingir o pico
  if (resistenciaLDR <= 0) resistenciaLDR = 1; 
  
  // Cálculo final em Lux
  float lux = pow(500000.0 / resistenciaLDR, 1.4);
  // ----------------------

  if(NewValue == HIGH){
    Serial.print("Leitura ADC: ");
    Serial.print(valorLuminosidade);
    Serial.print(" | Voltagem: ");
    Serial.print(voltagem);
    Serial.print("V | Lux Calculado: ");
    Serial.println(lux);

    // Condicional baseada no Lux real estimado
    if(lux > 250.0){ // Ambiente bem iluminado
      tone(pinBuzzer, 250, 250); 
      delay(1000);
      tone(pinBuzzer, 250, 250);
      delay(1000);
      tone(pinBuzzer, 250, 250);
    }
    else if(lux > 150.0 && lux <= 250.0){ 
      tone(pinBuzzer, 250, 250);
      delay(1000);
      tone(pinBuzzer, 250, 250);
    }
    else if(lux > 50.0 && lux <= 150.0){
      tone(pinBuzzer, 250, 250); 
    }
    else{
      tone(pinBuzzer, 500, 500);
    }
  }
  delay(2000);
}
