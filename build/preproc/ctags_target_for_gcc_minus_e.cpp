# 1 "C:\\Users\\theo-\\Área de Trabalho\\Arquivos Theo\\Metrologia\\metrologia\\balance\\balance.ino"
/**************************************************************************/
/**

 * @file    balance.ino

 * @authors  Theo Pires, Yasmin 

 * @date    26/09/2023

*/
# 7 "C:\\Users\\theo-\\Área de Trabalho\\Arquivos Theo\\Metrologia\\metrologia\\balance\\balance.ino"
/**************************************************************************/
# 9 "C:\\Users\\theo-\\Área de Trabalho\\Arquivos Theo\\Metrologia\\metrologia\\balance\\balance.ino" 2

/* Dados integração BLINK */





/* Pinos sensor */



HX711 sensor; // Instância biblioteca sensor

void setup(){
    Serial.begin(115200);
    Serial.println("Inicializando Comunicação");
    sensor.begin(25, 26);
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
