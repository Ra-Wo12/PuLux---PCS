# PuLux---PCS
Repositório projeto semestral de PCS - PuLux - Grupo 12

 Componentes necessários para a instalação do projeto:
  - ESP32 ;
  - LDR;
  - Micro Push Button;
  - Motor vibratório (Vibracall);
  - Bateria LiPo 300 mA;
  Para as conexões e segurança:
     - resistores 10 éres;
     - MOSFET;
     - Diodo Flyback.
 
 Instalação - Conexões:
  A bateria LiPo é conectada ao ESP32 para alimentação. Recomendavél utilizar de um circuito de proteção;
  O ESP32 possui o pino 3.3V conectado ao botão, LDR e Vibracall;
  O LDR possui, no outro pino, um resistor para dividir a tensão entre ground e um dos pinos ADIO do ESP32;
  O botão conecta-se à um resistor, no outro pino, para dividir tensão, conectando no ground e em um pino do ESP32;
  O MOSFET, protegido pelo Diodo Flyback para evitar picos na tensão, alimento o Vibracall, que por sua vez é conectado ao ground.

 Observações:
  Na falta de uma bateria LiPo, ou de um sistema de proteção para ela, o projeto deve, por motivos de segurança, estar conectado a um dispositivo porte 
  Notebook para a alimentação do projeto.
  Os resistores, MOSFET e Diodo flyback são precisos para a regulagem da tensão do sistema e, assim, a evitar que ocorra curto e qualquer componente.
  
