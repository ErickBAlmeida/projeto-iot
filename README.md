# Projeto IoT - Monitoramento de Temperatura e Umidade

Um projeto de Internet das Coisas (IoT) que utiliza um **ESP32** para monitorar temperatura e umidade através de um sensor **DHT22**, enviando os dados em tempo real para um servidor via HTTP.

## 🎯 Objetivo

Coletar dados de temperatura e umidade do ambiente e transmiti-los para uma API externa, permitindo monitoramento remoto e armazenamento de dados ambientais.

## 🛠️ Componentes Utilizados

- **Microcontrolador**: ESP32 (ESP32-DEV)
- **Sensor**: DHT22 (Sensor de Temperatura e Umidade)
- **Conectividade**: WiFi integrado do ESP32
- **Linguagem**: C++ com Arduino Framework

## 📦 Dependências

As seguintes bibliotecas são necessárias:

- **WiFi.h** - Conectividade WiFi (incluída no ESP32)
- **HTTPClient.h** - Requisições HTTP (incluída no ESP32)
- **DHT** - Biblioteca Adafruit para sensor DHT (`adafruit/DHT sensor library@^1.4.4`)
- **ArduinoJson** - Manipulação de JSON (`bblanchon/ArduinoJson@^6.21.3`)

## 🔧 Configuração

### 1. Hardware

- Conecte o sensor DHT22 ao pino **GPIO 15** do ESP32
- Alimentação: 3.3V ou 5V (conforme especificação do DHT22)
- GND: Conecte ao GND do ESP32

### 2. Software

#### Configurar Credenciais WiFi

Edite o arquivo `src/main.cpp` e atualize as credenciais:

```cpp
String rede = "Wokwi-GUEST";    // Nome da rede WiFi
String senha = "";               // Senha da rede WiFi
```

#### Configurar Endpoint da API

Atualize a URL do webhook:

```cpp
#define url "http://webhook.site/seu-uuid-aqui"
```

### 3. Instalação

1. Certifique-se de ter o PlatformIO instalado
2. Clone o repositório
3. Configure as credenciais conforme descrito acima
4. Faça upload do código:

```bash
platformio run -t upload -e esp32dev
```

## 📊 Funcionamento

O projeto executa o seguinte fluxo:

1. **Inicialização**: Conecta o ESP32 ao WiFi
2. **Leitura**: A cada 20 segundos, lê os dados do sensor DHT22
3. **Processamento**: Extrai temperatura (°C) e umidade (%)
4. **Transmissão**: Envia os dados em formato JSON para a API via POST
5. **Validação**: Verifica a resposta HTTP e exibe o código de resposta

## 📡 Formato de Dados

Os dados são enviados em formato JSON:

```json
{
  "temperatura": 25.5,
  "umidade": 60.2
}
```

## 🔍 Monitoramento Serial

Use o Monitor Serial para acompanhar o funcionamento:

```bash
platformio device monitor -e esp32dev -b 115200
```

Exemplo de saída esperada:
```
Conectando à Internet....... Conectado!
temperatura = 25.50
umidade = 60.20
Enviando dados:
http://webhook.site/seu-uuid-aqui
Código HTTP: 200
```

## ⚠️ Troubleshooting

| Problema | Solução |
|----------|---------|
| WiFi não conecta | Verifique SSID e senha da rede |
| Erro ao ler DHT | Verifique conexões do sensor no GPIO 15 |
| Requisição HTTP falha | Verifique URL da webhook e conexão com internet |
| Leituras NaN | Reinicie o ESP32 ou aguarde estabilização do sensor |

## 📝 Estrutura do Projeto

```
projeto-iot/
├── platformio.ini      # Configuração do projeto
├── src/
│   └── main.cpp        # Código principal
└── README.md           # Este arquivo
```

## 📸 Imagens

### Código e montagem do projeto
<img width="1600" height="758" alt="image" src="https://github.com/user-attachments/assets/9946edb0-fc9b-4657-a8e0-6bdf94d33805" />

### Reposta http no webhook
<img width="1915" height="548" alt="image" src="https://github.com/user-attachments/assets/f77555d9-f851-4dc6-9822-0cdb656d6d65" />


Para dúvidas ou sugestões, entre em contato com o desenvolvedor do projeto.

---

**Última atualização**: Abril de 2026
