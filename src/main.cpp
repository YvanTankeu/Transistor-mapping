/*
  Titre      : Transistor
  Auteur     : Yvan Tankeu
  Date       : 28/02/2022
  Description: Actionner un moteur en utilisant le transistor
  vers, ion    : 0.0.1
*/

#include <Arduino.h>

#define pinPotentio A1
#define pinMoteur 2

const float PIN_BASE_VOLTAGE = 3.3 ;   // Tension de base maximale pour la broche PWM du uC utilisé
const int PIN_ANALOG_MAX_VALUE = 1023; // Valeur maximale de la lecture de la broche analogue
float PinVoltage = 0;       

int valeurPotentio = 0;
int vitesseMoteur  = 0;

void setup() {

  Serial.begin(9600);

  pinMode(pinPotentio, INPUT);
  pinMode(pinMoteur, OUTPUT);
}

void loop() {
  
  valeurPotentio = analogRead(pinPotentio);

  PinVoltage = (valeurPotentio * PIN_BASE_VOLTAGE) / PIN_ANALOG_MAX_VALUE;

  vitesseMoteur = map(valeurPotentio, 0,PIN_ANALOG_MAX_VALUE,50,255);

  analogWrite(pinMoteur, vitesseMoteur);

  delay(2000);
}