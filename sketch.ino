#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

const int pinoLDR = 34;
const int pinoBotao = 4;
const int pinoLed = 18;

const float VCC = 3.3;
const float R_FIXO = 10000.0; // resistor de 10kΩ

void setup() {
  Serial.begin(115200);

  SerialBT.begin("ESP32_Luminosidade");

  pinMode(pinoBotao, INPUT_PULLUP);
  pinMode(pinoLed, OUTPUT);

  digitalWrite(pinoLed, HIGH);

  Serial.println("Bluetooth iniciado.");
}

void loop() {

  if (digitalRead(pinoBotao) == LOW) {

    int adc = analogRead(pinoLDR);

    // Evita divisão por zero
    if (adc < 1) adc = 1;

    float tensao = adc * (VCC / 4095.0);

    // Resistência do LDR
    float rLDR = R_FIXO * ((VCC / tensao) - 1.0);

    // Aproximação para LDR tipo GL5528
    float lux = 500.0 / pow((rLDR / 1000.0), 1.4);

    String msg =
      "ADC: " + String(adc) +
      " | Tensao: " + String(tensao, 2) + " V" +
      " | Lux: " + String(lux, 1);

    Serial.println(msg);
    SerialBT.println(msg);

    delay(300);
  }
}
