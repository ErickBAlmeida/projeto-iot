#include <WiFi.h>
#include <HTTPClient.h>
#include <DHT.h>

#define DHTPIN 15
#define DHTTYPE DHT22
#define url  "http://webhook.site/df4f28dd-7b09-43ef-bf8f-68f9e849d9ec"

DHT dht(DHTPIN, DHTTYPE);

String rede = "Wokwi-GUEST";
String senha = "";



void wifiSetup() {
  WiFi.begin(rede.c_str(), senha.c_str());

  Serial.print("Conectando à Internet...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" Conectado!");
}

void setup() {
  Serial.begin(115200);
  delay(2000);

  dht.begin();
  wifiSetup();
}

void postAPI(float temperatura, float umidade){
  HTTPClient http;

  Serial.println("Enviando dados:");
  Serial.println(url);

  http.begin(url);
  http.addHeader("Content-Type", "application/json");

  String payload = "{\"temperatura\" : " + String(temperatura) + ", \"umidade\" : " + String(umidade) + "}";
  int httpResponseCode = http.POST(payload);
  
  if (httpResponseCode > 0) {
    Serial.print("Código HTTP: ");
    Serial.println(httpResponseCode);
  } else {
    Serial.print("Erro na requisição: ");
    Serial.println(httpResponseCode);
  }

  http.end();
}

void loop() {
  if (WiFi.status() != WL_CONNECTED) {
    wifiSetup();
    return;
  }

  float temperatura = dht.readTemperature();
  float umidade = dht.readHumidity();

  Serial.print("temperatura = ");
  Serial.println(temperatura);

  Serial.print("umidade = ");
  Serial.println(umidade);

  if (isnan(temperatura) || isnan(umidade)) {
    Serial.println("Erro ao ler o DHT!");
    delay(2000);
    return;
  } else {
    postAPI(temperatura, umidade);
  }

  delay(20000);
}