🚀 Acione qualquer coisa à distância com ESP8266 e ESP-NOW! (Sem precisar de Wi-Fi)
Você sabia que pode controlar um relé a mais de 150 metros de distância sem usar nenhum roteador? Hoje vamos resumir como dominar o protocolo ESP-NOW com o ESP8266! 📡🔌

📡 O que é o ESP-NOW?
É um protocolo de comunicação direta entre placas ESP. É como um "walkie-talkie" para eletrônica:
Super Rápido: Latência quase zero.
Longo Alcance: Chega a 200m em campo aberto.
Independente: Não precisa de internet nem de roteador Wi-Fi.

🛠️ O que você vai precisar?
2x ESP8266 (NodeMCU ou Wemos D1 Mini).
1x Módulo Relé (Para o receptor).
1x Botão (Para o transmissor).

📝 O Passo a Passo Didático:
1. O "RG" da Placa (MAC Address) 🆔 Cada ESP tem um endereço único. Antes de tudo, você precisa rodar um código simples para descobrir o MAC do seu Receptor. Sem esse número,
   o Transmissor não sabe para onde enviar o sinal!

2. Preparando a IDE 💻 No Arduino IDE, você não instala a biblioteca ESP8266WiFi separadamente. Ela vem junto com o pacote de placas ESP8266 no "Gerenciador de Placas".
   Instalou a placa, a biblioteca aparece!

3. O Transmissor (O Controle) 🎮 Ele fica "vigiando" o botão. Quando você clica, ele empacota a ordem (ex: estado = true) e envia direto para o MAC do receptor.

4. O Receptor (O Executor) ⚡ Ele fica no modo "escuta". Assim que recebe o pacote, ele lê o comando e aciona o relé.
   
   
