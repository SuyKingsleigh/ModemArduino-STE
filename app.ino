#include "src/menu.h"
#include "src/channel.h"
#include "src/ip_interface.h"
#include "src/mac_interface.h"


MacInterface mac; 

void setup(){
    Serial.begin(9600);
    delay(500);

    mac = MacInterface();

}

void loop(){
    Serial.println("[1] Para interface MAC\n[2] Para interface IP\n");

    int select = -1;

    while (select < 1) 
        select = Serial.parseInt();
    
    switch (select) {
        case 1:
            mac.show_menu();
            delay(125);
            return; 

        default:
            return;
    }
}