/*
 ESP8266 ESP-01S
 Receptor ESP-NOW com Relé FAIL-SAFE
 Relé só permanece ligado enquanto houver sinal
*/
#include <ESP8266WiFi.h>
#include <espnow.h>

const int pinoRele = 0; 

struct struct_message {
    bool estado;
};

struct_message incomingData;

// Função disparada quando qualquer dado chega
void OnDataRecv(uint8_t * mac, uint8_t *incomingByte, uint8_t len) {
  memcpy(&incomingData, incomingByte, sizeof(incomingData));
  
  // Se estado for true, liga relé (LOW em módulos comuns), se false desliga (HIGH)
  if (incomingData.estado) {
    digitalWrite(pinoRele, LOW);  
  } else {
    digitalWrite(pinoRele, HIGH); 
  }
  
  Serial.print("Estado do Relé alterado para: ");
  Serial.println(incomingData.estado ? "LIGADO" : "DESLIGADO");
}

void setup() {
  Serial.begin(115200);
  pinMode(pinoRele, OUTPUT);
  digitalWrite(pinoRele, HIGH); // Começa desligado

  WiFi.mode(WIFI_STA);

  if (esp_now_init() != 0) {
    Serial.println("Erro ao iniciar ESP-NOW");
    return;
  }

  esp_now_set_self_role(ESP_NOW_ROLE_SLAVE);
  esp_now_register_recv_cb(OnDataRecv);
}

void loop() {
  // O receptor fica em modo passivo aguardando o sinal
}
