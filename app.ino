#include "src/menu.h"
#include "src/ip_interface.h"
#include "src/mac_interface.h"

MacInterface mac; 

void setup(){
    Serial.begin(9600);
    delay(500);

    mac = MacInterface();
}

void loop(){
    mac.show_menu();
}