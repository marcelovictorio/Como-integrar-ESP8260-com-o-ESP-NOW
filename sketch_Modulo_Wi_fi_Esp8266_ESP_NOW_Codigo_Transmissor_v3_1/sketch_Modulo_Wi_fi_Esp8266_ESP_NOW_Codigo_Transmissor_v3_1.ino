/*
👉 Código gerado pelo Chat GPT e refinado conforme as necessidades do projeto em 29/01/2026 
https://github.com/marcelovictorio @MarceloVictorio YouTube

Para obter o endereço MAC do seu ESP8266 receptor, você deve carregar um pequeno código (sketch) 
nele e abrir o Monitor Serial da Arduino IDE. Cada placa possui um endereço físico único e permanente.

 Envia um comando via ESP-NOW sempre que o botão for pressionado

┌──────────────────┐    ESP-NOW   ┌────────────────────┐
│  ESP8266 EMISSOR │ ───────────▶│  ESP8266 RECEPTOR  │
│  (Controle)      │              │  (Atuador / Relé)  │
└──────────────────┘              └────────────────────┘

*/

#include <ESP8266WiFi.h>
#include <espnow.h>

// SUBSTITUA PELOS ENDEREÇOS MAC REAIS QUE VOCÊ OBTEVE
uint8_t macReceptor1[] = {0xBC, 0xDD, 0xC2, 0x26, 0x18, 0x8A};
uint8_t macReceptor2[] = {0x5C, 0xCF, 0x7F, 0xD4, 0xAB, 0x3D};

const int pinoBotao1 = 0; 
const int pinoBotao2 = 2;

struct struct_message {
    bool estado;
};

struct_message msg1; // Dados para o receptor 1
struct_message msg2; // Dados para o receptor 2

void setup() {
  Serial.begin(115200);
  pinMode(pinoBotao1, INPUT_PULLUP);
  pinMode(pinoBotao2, INPUT_PULLUP);

  WiFi.mode(WIFI_STA);

  if (esp_now_init() != 0) {
    Serial.println("Erro ao iniciar ESP-NOW");
    return;
  }

  esp_now_set_self_role(ESP_NOW_ROLE_CONTROLLER);

  // Registra os dois receptores como "Peers"
  esp_now_add_peer(macReceptor1, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);
  esp_now_add_peer(macReceptor2, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);
}

void loop() {
  // Lógica para o Receptor 1
  if (digitalRead(pinoBotao1) == LOW) {
    msg1.estado = !msg1.estado;
    esp_now_send(macReceptor1, (uint8_t *) &msg1, sizeof(msg1));
    Serial.println("Comando enviado para Receptor 1");
    delay(300); // Debounce
  }

  // Lógica para o Receptor 2
  if (digitalRead(pinoBotao2) == LOW) {
    msg2.estado = !msg2.estado;
    esp_now_send(macReceptor2, (uint8_t *) &msg2, sizeof(msg2));
    Serial.println("Comando enviado para Receptor 2");
    delay(300); // Debounce
  }
}