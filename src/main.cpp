#include <Arduino.h>

const int ledP = 13;
const int pot = A5;
int valor_pot;
int valor_pot_convertido;

const int ledL = 12;
const int ldr = A4;
int valor_ldr;

const int rele = 11;

const int btn_on_off = 9;
const int ledE = 10;

bool condicao_umidade = false;
bool condicao_horario = false;
bool estado_sistema = false;

void setup() {
  pinMode(ledP, OUTPUT);
  pinMode(ledL, OUTPUT);
  pinMode(ledE, OUTPUT);
  pinMode(pot, INPUT);
  pinMode(ldr, INPUT);
  pinMode(btn_on_off, INPUT_PULLUP);
  pinMode(rele, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // O potenciometro vai simular a umidade do ambiente. Seu valor varia de 0 a 5, sendo que quando ele é menor que 2, seu led irá acender indicando que está na situação adequada
  valor_pot = analogRead(pot);
  valor_pot_convertido = map(valor_pot,0,1025,0,5);
  Serial.println(valor_pot_convertido);
  delay(1000);

  if (valor_pot_convertido < 2){
    digitalWrite(ledP, HIGH);
    condicao_umidade = true;
  }
  else {
    digitalWrite(ledP, LOW);
    condicao_umidade = false;
  }

  // ----------------------------------------------------------------------------------------------------

  // O ldr vai funcionar como um relógio, sendo que determinada quantidade de luz vai representar um horário do dia. Seu valor varia de 0 a 1023, sendo que quando ele é menor ou igual a 200, seu led irá acender indicando que está na situação adequada
  valor_ldr = analogRead(ldr);

  Serial.println(valor_ldr);
  delay(1000);

  if (valor_ldr <= 200){
    digitalWrite(ledL, HIGH);
    condicao_horario = true;
  }
  else {
    digitalWrite(ledL, LOW);
    condicao_horario = false;
  }

  // --------------------------------------------------------------------------------------

  // Se o botão for pressionado, ele vai destravar o sistema (obs: antes dele ser pressionado, até é possível estar nas condições ideais de umidade e horário, mas o relé não vai ligar)
  if (!digitalRead(btn_on_off)){
    estado_sistema = !estado_sistema;
    delay(200);
  }

  if (estado_sistema == true)
    digitalWrite(ledE, HIGH);
  else
    digitalWrite(ledE, LOW);

  // --------------------------------------------------------------------------------------

  if (condicao_umidade == true && condicao_horario == true && estado_sistema == true)
    digitalWrite(rele, LOW);
  else
    digitalWrite(rele, HIGH);

}

