/**************************************************************************/
/**
 * @file    balance.ino
 * @author  Theo Pires
 * @date    26/09/2023
*/
/**************************************************************************/
#include <HX711.h>
#include <WiFi.h>
#include <WiFiClient.h>

/* Dados integração BLINK */
#define BLYNK_TEMPLATE_ID   "TMPL2d51ih57v"
#define BLYNK_TEMPLATE_NAME "Balança1"
#define BLYNK_AUTH_TOKEN    "Ln17IZgla8YnJqnETl4fCSCXmE8HzoIG"
#define BLYNK_PRINT Serial

#include <BlynkSimpleEsp32.h>

/* Pinos sensor */
#define DT  25
#define SCK 26

HX711 sensor; // Instância biblioteca sensor

BlynkTimer timer;

bool debug = false;

char ssid[] = "Yas";
char pass[] = "senha123";

// This function is called every time the Virtual Pin 0 state changes
BLYNK_WRITE(V0)
{
  int pinValue = param.asInt();
  if(pinValue == 1){
    Serial.println("Tarando via Blink...");
    sensor.tare(50);// Fixa o peso como tara
  }  
}

BLYNK_WRITE(V2)
{
    int pinValue = param.asInt();
    if(pinValue == 1){
        Serial.println("Alterando modo debug/leitura");
        debug = true;
    }else if(pinValue == 0){
        debug = false;
    }
}

void setup(){
    Serial.begin(115200);
    Serial.println("Inicializando Comunicacao");
    Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
    sensor.begin(DT, SCK);
    delay(500);
    sensor.set_scale(437); // 436.4
    if(!sensor.is_ready()){
        Serial.print("HX711 not found. Reiniciando");
        loading(500, 5);
        esp_restart();
    }
    sensor.tare(50);
}

void loop(){
    if(debug){
        sensor.set_scale();
        Serial.print("Tarando... remova qualquer peso da balanca");
        loading(500, 5);
        sensor.tare(50);
        Serial.println("Tara feita.");
        Serial.print("Coloque um peso conhecido sobre a balanca");
        loading(500, 5);
        long leituraTaraMedia20 = sensor.get_units(20);
        long leituraMedia20 = sensor.read_average(20);
        Serial.print("Leitura com tara: "); Serial.println(leituraTaraMedia20);
        Serial.print("Leitura sem tara: "); Serial.println(leituraMedia20);
        delay(1000);
    }else{
        //double raw = sensor.read_average(20);
        double leitura = sensor.get_units(20)*0.99992;
        //Serial.print("Raw: "); Serial.print(raw, 0);
        Serial.print("Convertido: "); Serial.print(leitura, 2); Serial.println("g");
        Blynk.virtualWrite(V1, leitura);
        //delay(200);
    }
}

void loading(int timePerLoop, uint8_t loops){
    for(byte i=0; i<loops; i++){
        delay(timePerLoop);
        Serial.print(".");
    }
    Serial.println("");
}