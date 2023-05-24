const int numFinsDeCurso = 4; // Número total de fins de curso
const int pinoChaves[numFinsDeCurso] = {7, 8, 9, 10}; // PINOS DIGITAIS UTILIZADOS PELOS FINS DE CURSO
const int pinoLed = 12; // PINO DIGITAL UTILIZADO PELO LED

bool finsDeCursoAtivados[numFinsDeCurso] = {false}; // Estado dos fins de curso
unsigned long tempoInicial = 0;
bool primeiroFimDeCursoAtivado = false;
bool sinalEnviado = false; // Flag indicando se o sinal '1' já foi enviado

void setup() {
  for (int i = 0; i < numFinsDeCurso; i++) {
    pinMode(pinoChaves[i], INPUT_PULLUP); // Configura os pinos dos fins de curso como entrada com resistor pull-up
  }
  
  pinMode(pinoLed, OUTPUT); // Configura o pino do LED como saída
  digitalWrite(pinoLed, LOW); // Inicialmente, o LED está desligado
  
  Serial.begin(9600); // Inicializa a comunicação serial
}

void loop() {
  // Verificar o estado dos fins de curso
  bool algumFimDeCursoAtivado = false;

  for (int i = 0; i < numFinsDeCurso; i++) {
    if (digitalRead(pinoChaves[i]) == LOW) { // Verifica se o fim de curso está ativado
      finsDeCursoAtivados[i] = true; // Marca o fim de curso como ativado
      algumFimDeCursoAtivado = true; // Define a flag para indicar que pelo menos um fim de curso foi ativado
    }
  }

  // Aguardar 5 segundos após o acionamento do primeiro fim de curso ativado
  if (!primeiroFimDeCursoAtivado && algumFimDeCursoAtivado) {
    tempoInicial = millis(); // Armazena o tempo inicial
    primeiroFimDeCursoAtivado = true; // Define a flag para indicar que o primeiro fim de curso foi ativado
  }

  // Verificar se todos os fins de curso foram ativados dentro do período de 5 segundos
  if (primeiroFimDeCursoAtivado && (millis() - tempoInicial) >= 5000) {
    bool todosAtivados = true;

    for (int i = 0; i < numFinsDeCurso; i++) {
      if (!finsDeCursoAtivados[i]) { // Verifica se algum fim de curso não foi ativado
        todosAtivados = false; // Define a flag para indicar que nem todos os fins de curso foram ativados
        break;
      }
    }

    if (todosAtivados) {
      digitalWrite(pinoLed, HIGH); // Liga o LED se todos os fins de curso foram ativados
      sinalEnviado = false; // Reseta a flag do sinal enviado
    } else if (!sinalEnviado) {
      Serial.write('1'); // Enviar o sinal para o computador indicando que os fins de curso não foram ativados dentro do tempo limite
      sinalEnviado = true; // Marca o sinal como enviado
    }
  } else {
    digitalWrite(pinoLed, LOW); // Desliga o LED

    // Verificar se todos os fins de curso estão desativados
    bool todosDesativados = true;

    for (int i = 0; i < numFinsDeCurso; i++) {
      if (finsDeCursoAtivados[i]) { // Verifica se algum fim de curso está ativado
        todosDesativados = false; // Define a flag para indicar que pelo menos um fim de curso está ativado
        break;
      }
    }

    if (todosDesativados) {
      sinalEnviado = false; // Reseta a flag do sinal enviado
    }
  }
}
