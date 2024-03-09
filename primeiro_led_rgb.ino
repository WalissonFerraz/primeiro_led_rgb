#define btn 13
#define ledR 4
#define ledG 3
#define ledB 2
#define maximo 4

int clicado;
int liberado;
int ciclo;

void desliga() {
  digitalWrite(ledR, 0);
  digitalWrite(ledG, 0);
  digitalWrite(ledB, 0);
}
void vermelho() {
  digitalWrite(ledR, 0);
  digitalWrite(ledG, 254);
  digitalWrite(ledB, 100);
}
void amarelo() {
  digitalWrite(ledR, 0);
  digitalWrite(ledG, 1);
  digitalWrite(ledB, 0);
}
void azul() {
  digitalWrite(ledR, 0);
  digitalWrite(ledG, 0);
  digitalWrite(ledB, 1);
}

void trocaLed() {
  if (ciclo == 0) {
    vermelho();
  } else if (ciclo == 1) {
    amarelo();
  } else if (ciclo == 2) {
    azul();
  } else if (ciclo == 3) {
    desliga();
  }
  ciclo++;

  if (ciclo > 3) {
    ciclo = 0;
  }
}

void verificaBtn() {
  if (digitalRead(btn) == 1) {
    clicado = 1;
    liberado = 0;
  } else {
    liberado = 1;
  }

  if (clicado == 1 and liberado == 1) {
    clicado = 0;
    liberado = 0;
    trocaLed();
  }
}

void setup() {
  pinMode(btn, INPUT);
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
}

void loop() {
  verificaBtn();
}
