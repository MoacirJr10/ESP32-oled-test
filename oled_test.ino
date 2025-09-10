#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// ====== OLED CONFIG ======
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// ====== VARIÁVEIS ======
int testPattern = 0;
unsigned long lastChange = 0;
const unsigned long PATTERN_DURATION = 3000; // 3 segundos por padrão

// ====== FUNÇÕES DE TESTE ======

// Teste 1: Pixels aleatórios
void testRandomPixels() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("Teste: Pixels");
  
  for (int i = 0; i < 200; i++) {
    int x = random(0, SCREEN_WIDTH);
    int y = random(10, SCREEN_HEIGHT);
    display.drawPixel(x, y, SSD1306_WHITE);
  }
  display.display();
}

// Teste 2: Linhas horizontais e verticais
void testLines() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("Teste: Linhas");
  
  // Linhas horizontais
  for (int y = 15; y < SCREEN_HEIGHT; y += 5) {
    display.drawLine(0, y, SCREEN_WIDTH, y, SSD1306_WHITE);
  }
  
  // Linhas verticais
  for (int x = 0; x < SCREEN_WIDTH; x += 10) {
    display.drawLine(x, 15, x, SCREEN_HEIGHT, SSD1306_WHITE);
  }
  display.display();
}

// Teste 3: Círculos concêntricos
void testCircles() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("Teste: Circulos");
  
  int centerX = SCREEN_WIDTH / 2;
  int centerY = (SCREEN_HEIGHT + 10) / 2;
  
  for (int radius = 5; radius < 30; radius += 5) {
    display.drawCircle(centerX, centerY, radius, SSD1306_WHITE);
  }
  display.display();
}

// Teste 4: Retângulos
void testRectangles() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("Teste: Retangulos");
  
  for (int i = 0; i < 5; i++) {
    int x = 10 + (i * 5);
    int y = 15 + (i * 5);
    int w = SCREEN_WIDTH - (2 * x);
    int h = SCREEN_HEIGHT - (2 * y);
    
    if (i % 2 == 0) {
      display.drawRect(x, y, w, h, SSD1306_WHITE);
    } else {
      display.fillRect(x, y, w, h, SSD1306_WHITE);
    }
  }
  display.display();
}

// Teste 5: Texto em diferentes tamanhos
void testText() {
  display.clearDisplay();
  
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("Texto tamanho 1");
  
  display.setTextSize(2);
  display.setCursor(0, 15);
  display.print("Tam 2");
  
  display.setTextSize(1);
  display.setCursor(0, 35);
  display.print("123456789012345678");
  
  display.setCursor(0, 45);
  display.print("ABCDEFGHIJKLMNOPQR");
  
  display.setCursor(0, 55);
  display.print("!@#$%^&*()_+-=[]{}");
  
  display.display();
}

// Teste 6: Animação de barra de progresso
void testProgressBar() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("Teste: Progresso");
  
  static int progress = 0;
  progress = (progress + 2) % 100;
  
  // Barra externa
  display.drawRect(10, 25, 108, 10, SSD1306_WHITE);
  
  // Barra interna (progresso)
  int fillWidth = (progress * 106) / 100;
  display.fillRect(11, 26, fillWidth, 8, SSD1306_WHITE);
  
  // Texto do progresso
  display.setCursor(45, 45);
  display.print(progress);
  display.print("%");
  
  display.display();
}

// Teste 7: Gráfico de barras animado
void testBarChart() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("Teste: Graficos");
  
  static unsigned long barTime = 0;
  if (millis() - barTime > 200) {
    barTime = millis();
  }
  
  int bars[] = {
    10 + (millis() / 100) % 30,
    15 + (millis() / 150) % 25,
    20 + (millis() / 120) % 35,
    8 + (millis() / 180) % 28,
    12 + (millis() / 90) % 32
  };
  
  int barWidth = 20;
  int spacing = 4;
  
  for (int i = 0; i < 5; i++) {
    int x = 5 + (i * (barWidth + spacing));
    int barHeight = bars[i];
    int y = SCREEN_HEIGHT - barHeight;
    
    display.fillRect(x, y, barWidth, barHeight, SSD1306_WHITE);
    
    // Valor da barra
    display.setTextSize(1);
    display.setCursor(x + 6, y - 8);
    display.print(bars[i]);
  }
  
  display.display();
}

// Teste 8: Animação de ondas
void testWaveAnimation() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("Teste: Ondas");
  
  static float waveOffset = 0;
  waveOffset += 0.2;
  
  for (int x = 0; x < SCREEN_WIDTH; x++) {
    float wave1 = sin((x * 0.1) + waveOffset) * 10;
    float wave2 = cos((x * 0.08) + waveOffset) * 8;
    
    int y1 = 30 + wave1;
    int y2 = 45 + wave2;
    
    display.drawPixel(x, y1, SSD1306_WHITE);
    display.drawPixel(x, y2, SSD1306_WHITE);
  }
  
  display.display();
}

// Teste 9: Teste de bordas e cantos
void testBorders() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("Teste: Bordas");
  
  // Borda externa
  display.drawRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, SSD1306_WHITE);
  
  // Cantos
  display.fillRect(0, 0, 10, 10, SSD1306_WHITE);
  display.fillRect(SCREEN_WIDTH-10, 0, 10, 10, SSD1306_WHITE);
  display.fillRect(0, SCREEN_HEIGHT-10, 10, 10, SSD1306_WHITE);
  display.fillRect(SCREEN_WIDTH-10, SCREEN_HEIGHT-10, 10, 10, SSD1306_WHITE);
  
  // Cruz central
  display.drawLine(SCREEN_WIDTH/2, 0, SCREEN_WIDTH/2, SCREEN_HEIGHT, SSD1306_WHITE);
  display.drawLine(0, SCREEN_HEIGHT/2, SCREEN_WIDTH, SCREEN_HEIGHT/2, SSD1306_WHITE);
  
  display.display();
}

// Teste 10: Tela cheia branca/preta alternada
void testFullScreen() {
  static bool whiteScreen = false;
  whiteScreen = !whiteScreen;
  
  display.clearDisplay();
  
  if (whiteScreen) {
    display.fillRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, SSD1306_WHITE);
    // Texto em "negativo"
    display.setTextSize(2);
    display.setTextColor(SSD1306_BLACK);
    display.setCursor(20, 20);
    display.print("TELA");
    display.setCursor(15, 40);
    display.print("CHEIA");
  } else {
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(25, 20);
    display.print("TELA");
    display.setCursor(20, 40);
    display.print("PRETA");
  }
  
  display.display();
}

// ====== SETUP ======
void setup() {
  Serial.begin(115200);
  
  // Inicializa OLED
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("Erro ao iniciar OLED SSD1306!");
    for(;;);
  }
  
  // Tela inicial
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(5, 10);
  display.println("TESTE");
  display.setCursor(15, 35);
  display.println("OLED");
  display.display();
  
  delay(2000);
  
  Serial.println("Iniciando testes do OLED...");
  Serial.println("10 padrões diferentes a cada 3 segundos");
}

// ====== LOOP ======
void loop() {
  unsigned long currentTime = millis();
  
  // Muda padrão a cada intervalo
  if (currentTime - lastChange >= PATTERN_DURATION) {
    lastChange = currentTime;
    testPattern = (testPattern + 1) % 10;
    
    Serial.print("Executando teste ");
    Serial.print(testPattern + 1);
    Serial.println("/10");
  }
  
  // Executa o teste atual
  switch (testPattern) {
    case 0: testRandomPixels(); break;
    case 1: testLines(); break;
    case 2: testCircles(); break;
    case 3: testRectangles(); break;
    case 4: testText(); break;
    case 5: testProgressBar(); break;
    case 6: testBarChart(); break;
    case 7: testWaveAnimation(); break;
    case 8: testBorders(); break;
    case 9: testFullScreen(); break;
  }
  
  delay(50); // Pequeno delay para animações suaves
}
