#include <Arduino.h>
#line 1 "C:\\Users\\theo-\\Área de Trabalho\\Arquivos Theo\\Metrologia\\metrologia\\balance\\balance.ino"
/**************************************************************************/
/**
 * @file    balance.ino
 * @authors  Theo Pires, Yasmin 
 * @date    26/09/2023
*/
/**************************************************************************/
#include "HX711.h"

/* Dados integração BLINK */
#define BLYNK_TEMPLATE_ID   "TMPL2d51ih57v"
#define BLYNK_TEMPLATE_NAME "Balança1"
#define BLYNK_AUTH_TOKEN    "Ln17IZgla8YnJqnETl4fCSCXmE8HzoIG"

/* Pinos sensor */
#define DT  25
#define SCK 26

HX771 sensor; // Instância biblioteca sensor

#line 21 "C:\\Users\\theo-\\Área de Trabalho\\Arquivos Theo\\Metrologia\\metrologia\\balance\\balance.ino"
void setup();
#line 27 "C:\\Users\\theo-\\Área de Trabalho\\Arquivos Theo\\Metrologia\\metrologia\\balance\\balance.ino"
void loop();
#line 21 "C:\\Users\\theo-\\Área de Trabalho\\Arquivos Theo\\Metrologia\\metrologia\\balance\\balance.ino"
void setup(){
    Serial.begin(115200);
    Serial.println("Inicializando Comunicação");
    sensor.begin(DT, SCK);
}

void loop(){
    if(sensor.is_ready()){

    }
}
