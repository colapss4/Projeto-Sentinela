const int pinoChave = 7; // PINO DIGITAL UTILIZADO PELA CHAVE FIM DE CURSO
const int pinoLed = 12; // PINO DIGITAL UTILIZADO PELO LED
bool fimDeCursoAtivado = false; // Variável para controlar o estado do fim de curso

void setup() {
  pinMode(pinoChave, INPUT_PULLUP); // DEFINE O PINO COMO ENTRADA / "_PULLUP" É PARA ATIVAR O RESISTOR INTERNO
  pinMode(pinoLed, OUTPUT); // DEFINE O PINO COMO SAÍDA
  digitalWrite(pinoLed, LOW); // LED INICIA DESLIGADO

  Serial.begin(9600); // Inicializa a comunicação serial
}

void loop() {
  if (digitalRead(pinoChave) == LOW && !fimDeCursoAtivado) { // SE A LEITURA DO PINO FOR IGUAL A LOW E fimDeCursoAtivado for false, FAZ
    fimDeCursoAtivado = true; // Define fimDeCursoAtivado como true
    digitalWrite(pinoLed, HIGH); // ACENDE O LED
    
  } else if (digitalRead(pinoChave) == HIGH && fimDeCursoAtivado) { // SENÃO SE A LEITURA DO PINO FOR IGUAL A HIGH E fimDeCursoAtivado for true, FAZ
    fimDeCursoAtivado = false; // Define fimDeCursoAtivado como false
    digitalWrite(pinoLed, LOW); // APAGA O LED
    
    // Envia um caractere '1' pela comunicação serial para o PC indicando que o fim de curso foi desativado
    Serial.write('1');
  }
}