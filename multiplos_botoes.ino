// Pino ligado ao push-button
int buttonPin = A0;

// Variáveis de estado dos botões
bool botao1State = false, botao2State = false, botao3State = false, botao4State = false;
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50; // 50 ms de debounce

void setup() {
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int reading = analogRead(buttonPin);
  unsigned long currentTime = millis();

  // Aplica debounce: verifica se o tempo decorrido é maior que o debounceDelay
  if (currentTime - lastDebounceTime > debounceDelay) {
    // Verifica se apenas um botão está na faixa correta por vez
    if (reading > 690 && reading <= 735) {  // Botão 1
      if (!botao1State) {
        Serial.println("O botao 1 foi apertado!");
        botao1State = true;
        botao2State = botao3State = botao4State = false; // Reseta os outros estados
      }
    }
    else if (reading >= 736 && reading <= 790) {  // Botão 2
      if (!botao2State) {
        Serial.println("O botao 2 foi apertado!");
        botao2State = true;
        botao1State = botao3State = botao4State = false; // Reseta os outros estados
      }
    }
    else if (reading > 800 && reading < 855) {  // Botão 3
      if (!botao3State) {
        Serial.println("O botao 3 foi apertado!");
        botao3State = true;
        botao1State = botao2State = botao4State = false; // Reseta os outros estados
      }
    }
    else if (reading > 900 && reading < 935) {  // Botão 4
      if (!botao4State) {
        Serial.println("O botao 4 foi apertado!");
        botao4State = true;
        botao1State = botao2State = botao3State = false; // Reseta os outros estados
      }
    } else {
      // Se nenhuma faixa é detectada, reseta os estados
      botao1State = botao2State = botao3State = botao4State = false;
    }

    lastDebounceTime = currentTime; // Atualiza o tempo do debounce
  }
}
