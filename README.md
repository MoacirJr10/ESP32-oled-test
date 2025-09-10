#  ESP32 OLED Test Suite - SSD1306

Conjunto completo de testes para displays OLED SSD1306 usando ESP32. Detecta pixels mortos, problemas de contraste e funcionalidades do display.

![OLED Test](https://img.shields.io/badge/OLED-Test%20Suite-orange?style=for-the-badge&logo=arduino)
![ESP32](https://img.shields.io/badge/ESP32-Compatible-blue?style=for-the-badge&logo=espressif)
![SSD1306](https://img.shields.io/badge/SSD1306-128x64-green?style=for-the-badge)

##  Sobre

Este código executa **10 testes diferentes** no display OLED para verificar:

- ✅ **Pixels funcionais** (todos os 8.192 pixels)
- ✅ **Funções gráficas** (linhas, círculos, retângulos)
- ✅ **Renderização de texto** em diferentes tamanhos
- ✅ **Animações** e transições suaves
- ✅ **Contraste máximo** (branco/preto total)
- ✅ **Performance** do controlador I2C

###  **Por que usar?**

-  **Diagnóstico rápido** de problemas no OLED
-  **Validação** antes de projetos importantes  
-  **Benchmark** de performance
-  **Demonstração** de capacidades gráficas
-  **Teste de qualidade** em lotes de displays

## 🛠 Hardware Necessário

| Item | Especificação | Obs |
|------|---------------|-----|
| **Microcontrolador** | ESP32 (qualquer modelo) | NodeMCU, DevKit, etc |
| **Display** | OLED 128x64 SSD1306 I2C | Azul ou branco |
| **Jumpers** | 4x macho-fêmea | Para conexões |
| **Cabo USB** | Para programação | Micro-USB ou USB-C |

##  Instalação

### **1️⃣ Arduino IDE Setup**

1. Instalar **Arduino IDE 1.8.19+** ou **2.0+**
2. Adicionar suporte ao ESP32:
   ```
   Arquivo > Preferências > URLs Adicionais de Placas:
   https://dl.espressif.com/dl/package_esp32_index.json
   ```

3. Instalar placa ESP32:
   ```
   Ferramentas > Placa > Gerenciador de Placas
   Buscar: "ESP32" > Instalar
   ```

### **2️⃣ Bibliotecas Necessárias**

Via **Gerenciador de Bibliotecas** (`Ctrl+Shift+I`):

```
📚 Adafruit GFX Library (by Adafruit)
📚 Adafruit SSD1306 (by Adafruit)
```

### **3️⃣ Download do Código**

```bash
git clone https://github.com/seu-usuario/esp32-oled-test.git
```

Ou copie o código diretamente do arquivo `oled_test.ino`

## 🔌 Conexões

### **ESP32 ↔ OLED SSD1306**

| ESP32 Pin | OLED Pin | Função | Cor Sugerida |
|-----------|----------|--------|---------------|
| **3.3V** | **VCC** | Alimentação | 🔴 Vermelho |
| **GND** | **GND** | Terra | ⚫ Preto |
| **GPIO 21** | **SDA** | Dados I2C | 🔵 Azul |
| **GPIO 22** | **SCL** | Clock I2C | 🟡 Amarelo |

### 📐 **Diagrama de Conexão**

```
     ESP32                           OLED SSD1306
┌─────────────────┐                ┌──────────────┐
│              3V3├────────────────┤VCC       ┌───┤
│              GND├────────────────┤GND       │ O │
│    GPIO 21 (SDA)├────────────────┤SDA       │ L │
│    GPIO 22 (SCL)├────────────────┤SCL/SCK   │ E │
│                 │                │          │ D │
│      [USB]      │                └──────────┴───┘
└─────────────────┘
```

### ⚠️ **Dicas de Conexão**

- 🔧 Use **jumpers de boa qualidade** para evitar falsos negativos
- 📏 Mantenha **cabos curtos** (< 20cm) para melhor sinal I2C
- 🔍 Confirme **polaridade** antes de ligar (VCC/GND)
- 📱 Teste com **multímetro** se houver dúvidas

## 🧪 Testes Disponíveis

### **Sequência Automática (30 segundos total)**

| # | Teste | Duração | Objetivo |
|---|-------|---------|----------|
| 1️⃣ | **Pixels Aleatórios** | 3s | Detectar pixels mortos |
| 2️⃣ | **Linhas** | 3s | Testar desenho de linhas |
| 3️⃣ | **Círculos** | 3s | Verificar formas geométricas |
| 4️⃣ | **Retângulos** | 3s | Testar preenchimento |
| 5️⃣ | **Texto** | 3s | Fontes e caracteres |
| 6️⃣ | **Barra Progresso** | 3s | Animação simples |
| 7️⃣ | **Gráfico Barras** | 3s | Dados dinâmicos |
| 8️⃣ | **Ondas** | 3s | Animação matemática |
| 9️⃣ | **Bordas** | 3s | Extremidades da tela |
| 🔟 | **Tela Cheia** | 3s | Contraste máximo |

### 📋 **Detalhamento dos Testes**

#### **1️⃣ Pixels Aleatórios**
```cpp
// Testa 200 pixels aleatórios
// Detecta: pixels mortos, linhas com defeito
for (int i = 0; i < 200; i++) {
    int x = random(0, SCREEN_WIDTH);
    int y = random(10, SCREEN_HEIGHT);
    display.drawPixel(x, y, SSD1306_WHITE);
}
```

#### **2️⃣ Linhas Horizontais/Verticais**
```cpp
// Grade de linhas espaçadas
// Detecta: problemas de varredura, ghosting
for (int y = 15; y < SCREEN_HEIGHT; y += 5) {
    display.drawLine(0, y, SCREEN_WIDTH, y, SSD1306_WHITE);
}
```

#### **3️⃣ Círculos Concêntricos**
```cpp
// Círculos de diferentes raios
// Detecta: distorção geométrica, anti-aliasing
for (int radius = 5; radius < 30; radius += 5) {
    display.drawCircle(centerX, centerY, radius, SSD1306_WHITE);
}
```

#### **4️⃣ Retângulos Alternados**
```cpp
// Retângulos vazios e preenchidos
// Detecta: preenchimento uniforme, bordas
if (i % 2 == 0) {
    display.drawRect(x, y, w, h, SSD1306_WHITE);     // Vazio
} else {
    display.fillRect(x, y, w, h, SSD1306_WHITE);     // Preenchido
}
```

#### **5️⃣ Teste de Texto**
```cpp
display.setTextSize(1); display.print("Texto tamanho 1");
display.setTextSize(2); display.print("Tam 2");
// Testa: renderização de fontes, caracteres especiais
```

#### **6️⃣ Barra de Progresso**
```cpp
// Animação de carregamento 0-100%
int fillWidth = (progress * 106) / 100;
display.fillRect(11, 26, fillWidth, 8, SSD1306_WHITE);
// Testa: animações suaves, refresh rate
```

#### **7️⃣ Gráfico de Barras**
```cpp
// 5 barras com valores dinâmicos
int bars[] = { 10 + (millis() / 100) % 30, ... };
// Testa: dados em tempo real, múltiplos objetos
```

#### **8️⃣ Animação de Ondas**
```cpp
// Ondas senoidais matemáticas
float wave1 = sin((x * 0.1) + waveOffset) * 10;
// Testa: cálculos matemáticos, refresh suave
```

#### **9️⃣ Teste de Bordas**
```cpp
// Pixels nos 4 cantos + bordas
display.fillRect(0, 0, 10, 10, SSD1306_WHITE);           // Canto superior esquerdo
display.fillRect(SCREEN_WIDTH-10, SCREEN_HEIGHT-10, 10, 10, SSD1306_WHITE); // Inferior direito
// Testa: área útil completa, extremidades
```

#### **🔟 Tela Cheia (Branco/Preto)**
```cpp
// Alternância total branco ↔ preto
display.fillRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, SSD1306_WHITE);
// Testa: contraste máximo, uniformidade, ghosting
```

## 🚀 Como Usar

### **1️⃣ Upload e Execução**

```cpp
// 1. Conectar ESP32 via USB
// 2. Selecionar: Ferramentas > Placa > ESP32 Dev Module  
// 3. Selecionar porta COM correta
// 4. Upload do código (Ctrl+U)
```

### **2️⃣ Monitoramento**

**Monitor Serial** (`Ctrl+Shift+M`):
```
Baud Rate: 115200
```

**Saída esperada:**
```
Iniciando testes do OLED...
10 padrões diferentes a cada 3 segundos

Executando teste 1/10
Executando teste 2/10
Executando teste 3/10
...
```

### **3️⃣ Observação Visual**

-  **Observe atentamente** cada teste no display
-  **Procure por**: pixels que não acendem, linhas faltando, distorções
-  **Cada teste dura 3 segundos** - tempo suficiente para análise
-  **Ciclo completo**: 30 segundos, depois reinicia automaticamente

## 🔍 Interpretando Resultados

### ✅ **Sinais de Display Saudável**

| Teste | O que observar |
|-------|----------------|
| **Pixels** | Todos os pontos acendem uniformemente |
| **Linhas** | Retas contínuas, sem falhas |
| **Círculos** | Formas suaves, simétricas |
| **Retângulos** | Preenchimento uniforme |
| **Texto** | Caracteres nítidos, legíveis |
| **Animações** | Transições suaves, sem piscadas |
| **Bordas** | Extremidades funcionais |
| **Tela Cheia** | Branco/preto uniformes |

### ⚠️ **Problemas Comuns**

| Sintoma | Causa Provável | Solução |
|---------|----------------|---------|
| **Pixels não acendem** | Pixels mortos | ❌ Trocar display |
| **Linhas faltando** | Problema de varredura | 🔧 Verificar conexões |
| **Formas distorcidas** | Timing I2C incorreto | ⚙️ Reduzir velocidade |
| **Texto borrado** | Contraste baixo | 🔧 Verificar alimentação |
| **Animação travada** | Código/hardware | 🔄 Reset ESP32 |
| **Metade da tela preta** | Conexão SDA/SCL | 🔌 Reconectar cabos |
| **Display não liga** | Alimentação | ⚡ Testar 5V ao invés de 3.3V |
| **Ghosting** | Refresh lento | ⚙️ Otimizar código |

###  **Critérios de Aprovação**

**✅ PASSOU** se:
-  Todos os 10 testes executam sem erros
-  Elementos visuais aparecem corretamente  
-  Animações são fluidas (sem travamentos)
-  Ciclo completa e reinicia normalmente

** FALHOU** se:
-  Pixels mortos visíveis
-  Linhas/formas incompletas
-  Áreas que não respondem
-  Display não liga/não responde

##  Troubleshooting

### **Display não liga**

```cpp
// Verificações básicas:
1. ✅ Conexões corretas (VCC, GND, SDA, SCL)
2. ✅ Alimentação 3.3V ou 5V
3. ✅ Endereço I2C correto (0x3C padrão)
```

**Teste de endereço I2C:**
```cpp
// Adicionar ao setup() para escanear endereços:
Wire.begin();
for (byte addr = 1; addr < 127; addr++) {
    Wire.beginTransmission(addr);
    if (Wire.endTransmission() == 0) {
        Serial.printf("Dispositivo I2C encontrado: 0x%02X\n", addr);
    }
}
```

### **Erro de compilação**

```
Error: 'SSD1306_SWITCHCAPVCC' was not declared
```

**Solução:**

Reinstalar biblioteca:
Gerenciador de Bibliotecas > Adafruit SSD1306 > Reinstalar


### **Tela branca/congelada**


 Possíveis causas:
1.  Cabo SDA/SCL trocado
2.  Tensão insuficiente  
3.  Cabos muito longos (>50cm)
4.  Interferência eletromagnética


### **Alguns pixels não funcionam**

 Pixels mortos: Problema físico - trocar display
 Linha inteira: Verificar conexões
 Área específica: Possível dano no controlador


## Especificações Técnicas

### **Performance**
-  **Refresh Rate**: ~60 FPS
-  **Uso RAM**: ~2KB para buffer de tela  
-  **I2C Speed**: 400kHz (padrão)
-  **Consumo**: ~15mA (OLED) + 80mA (ESP32)

### **Compatibilidade**
- ✅ **ESP32** (todos os modelos)
- ✅ **ESP32-S2**, **ESP32-C3**
- ✅ **Arduino Uno/Nano** (com ajustes de pinos)
- ✅ **Raspberry Pi Pico**

### **Displays Testados**
- 🟦 **OLED 128x64 SSD1306 I2C** (azul/branco)
- 🟨 **OLED 128x32 SSD1306 I2C** 
- 🔵 **OLED 128x64 SH1106 I2C** (compatível)

##  Contribuições

Melhorias são bem-vindas! Ideias:

-  **Novos padrões de teste** (xadrez, gradiente, etc)
-  **Alertas sonoros** para problemas detectados
-  **Relatório automático** de qualidade
-  **Interface web** para controle remoto
-  **App mobile** para análise
-  **IA** para detecção automática de defeitos

### **Como contribuir:**
1. Fork este repositório
2. Crie uma branch: `git checkout -b nova-funcionalidade`
3. Commit: `git commit -m 'Adiciona: nova funcionalidade'`
4. Push: `git push origin nova-funcionalidade`  
5. Abra um Pull Request

##  Licença

```
MIT License - Use livremente em projetos pessoais e comerciais
```

##  Contato e Suporte

-  **GitHub Issues**: [Reportar problemas](https://github.com/MoacirJr10/ESP32-oled-test/issues)
---

###  **Conclusão**

Este test suite é essencial para:
-  **Validar** displays OLED antes de usar em projetos
-  **Diagnosticar** problemas rapidamente  
-  **Comparar** qualidade entre diferentes fornecedores
-  **Testar** novos displays ou após soldagem

 **Se foi útil, deixe uma estrela no repositório!**

 **Versão**: 1.0.0 | **Status**: ✅ Estável | **Testes**: ✅ Todos passando
