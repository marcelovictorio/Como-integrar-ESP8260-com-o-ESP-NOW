/*
👉 Código gerado pelo Chat GPT e refinado conforme as necessidades do projeto em 26/01/2026 
https://github.com/marcelovictorio @MarceloVictorio YouTube

Para obter o endereço MAC Address do seu ESP8266 receptor, você deve carregar um pequeno código (sketch) 
nele e abrir o Monitor Serial da Arduino IDE. Cada placa possui um endereço físico único e permanente.
*/

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <espnow.h>

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("--- Iniciando Leitura de MAC ---");
  Serial.println();
  delay(1000);
  
  // PASSO 1: Colocar em modo Station e ler o MAC
  WiFi.mode(WIFI_STA);
  Serial.print("MAC em modo Station (STA): ");
  Serial.println(WiFi.macAddress());

  // PASSO 2: Colocar em modo Access Point e ler o MAC
  WiFi.mode(WIFI_AP);
  Serial.print("MAC em modo Access Point (AP): ");
  Serial.println(WiFi.softAPmacAddress());
}

void loop() {
  // Não precisa de nada aqui
}