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



HX771 sensor; // Instância biblioteca sensor

void setup(){
    Serial.begin(115200);
    Serial.println("Inicializando Comunicação");
    sensor.begin(25, 26);
}

void loop(){
    if(sensor.is_ready()){

    }
}
