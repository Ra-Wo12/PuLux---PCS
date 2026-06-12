#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

const int pinoLDR = 34;
const int pinoBotao = 4;
const int pinoLed = 18;
const int pinoMotor = 23;

const float VCC = 3.3;
const float R_FIXO = 10000.0;

bool ultimoEstadoBotao = HIGH;

void setup() {
  Serial.begin(115200);

  SerialBT.begin("ESP32_Luminosidade");

  pinMode(pinoBotao, INPUT_PULLUP);
  pinMode(pinoLed, OUTPUT);
  pinMode(pinoMotor, OUTPUT);

  digitalWrite(pinoLed, HIGH);
  digitalWrite(pinoMotor, LOW);

  Serial.println("Sistema iniciado.");
}

void vibrar(int vezes) {

  Serial.print("Vibrando ");
  Serial.print(vezes);
  Serial.println(" vez(es)");

  for (int i = 0; i < vezes; i++) {

    digitalWrite(pinoMotor, HIGH);
    delay(300);

    digitalWrite(pinoMotor, LOW);
    delay(300);
  }
}

void loop() {

  bool estadoBotao = digitalRead(pinoBotao);

  // Detecta apenas a transição HIGH -> LOW
  if (ultimoEstadoBotao == HIGH && estadoBotao == LOW) {

    delay(50); // debounce

    if (digitalRead(pinoBotao) == LOW) {

      Serial.println("\n=== BOTAO PRESSIONADO ===");

      // Pisca LED para indicar o evento
      digitalWrite(pinoLed, LOW);
      delay(100);
      digitalWrite(pinoLed, HIGH);

      int adc = analogRead(pinoLDR);

      if (adc < 1) adc = 1;
      if (adc > 4094) adc = 4094;

      float tensao = adc * (VCC / 4095.0);

      float rLDR = R_FIXO * ((VCC / tensao) - 1.0);

      float lux = 500.0 / pow((rLDR / 1000.0), 1.4);

      Serial.print("ADC: ");
      Serial.println(adc);

      Serial.print("Tensao: ");
      Serial.print(tensao);
      Serial.println(" V");

      Serial.print("Lux: ");
      Serial.println(lux);

      String msg =
        "ADC=" + String(adc) +
        " | V=" + String(tensao, 2) +
        "V | Lux=" + String(lux, 1);

      SerialBT.println(msg);

      if (lux > 50.0) {
        Serial.println("Luminosidade acima de 50 lux");
        vibrar(2);
      }
      else {
        Serial.println("Luminosidade abaixo de 50 lux");
        vibrar(1);
      }
    }
  }

  ultimoEstadoBotao = estadoBotao;
}
