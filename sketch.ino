#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

const int pinLDR = 18;      // Verifique se é um pino ADC válido
const int pinBotao = 19;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_BT");

  pinMode(pinBotao, INPUT_PULLUP);
  Serial.println("Bluetooth INICIADO");
}

void loop() {
  // Botão pressionado (INPUT_PULLUP => LOW)
  if (digitalRead(pinBotao) == LOW) {

    int leitura = analogRead(pinLDR);

    int luminosidade = map(leitura, 0, 4095, 0, 100);
    luminosidade = constrain(luminosidade, 0, 100);

    Serial.print("Luminosidade: ");
    Serial.print(luminosidade);
    Serial.println("%");

    SerialBT.print("Luminosidade: ");
    SerialBT.print(luminosidade);
    SerialBT.println("%");

    // Aguarda soltar o botão
    while (digitalRead(pinBotao) == LOW) {
      delay(10);
    }

    // Debounce
    delay(50);
  }
}
