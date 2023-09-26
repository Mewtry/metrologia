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
#define BLYNK_PRINT Serial

/* Pinos sensor */
#define DT  25
#define SCK 26

HX711 sensor; // Instância biblioteca sensor

#line 22 "C:\\Users\\theo-\\Área de Trabalho\\Arquivos Theo\\Metrologia\\metrologia\\balance\\balance.ino"
void setup();
#line 28 "C:\\Users\\theo-\\Área de Trabalho\\Arquivos Theo\\Metrologia\\metrologia\\balance\\balance.ino"
void loop();
#line 48 "C:\\Users\\theo-\\Área de Trabalho\\Arquivos Theo\\Metrologia\\metrologia\\balance\\balance.ino"
void loading(int timePerLoop, uint8_t loops);
#line 22 "C:\\Users\\theo-\\Área de Trabalho\\Arquivos Theo\\Metrologia\\metrologia\\balance\\balance.ino"
void setup(){
    Serial.begin(115200);
    Serial.println("Inicializando Comunicação");
    sensor.begin(DT, SCK);
}

void loop(){
    if(sensor.is_ready()){
        sensor.set_scale();
        Serial.print("Tarando... remova qualquer peso da balanca");
        loading(500, 5);
        sensor.tare();
        Serial.println("Tara feita.");
        Serial.print("Coloque um peso conhecido sobre a balança");
        loading(500, 5);
        long leituraTaraMedia20 = sensor.get_units(20);
        long leituraMedia20 = sensor.read_average(20);
        Serial.print("Leitura com tara: "); Serial.println(leituraTaraMedia20);
        Serial.print("Leitura sem tara: "); Serial.println(leituraMedia20);
    }else{
        Serial.print("HX711 not found. Reiniciando");
        loading(500, 5);
        esp_restart();
    }
}

void loading(int timePerLoop, uint8_t loops){
    for(byte i=0; i<loops; i++){
        delay(timePerLoop);
        Serial.print(".");
    }
    Serial.println("");
}
