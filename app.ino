#include "src/menu.h"
#include "src/channel.h"
#include "src/ip_interface.h"
#include "src/mac_interface.h"

IpInterface ip = IpInterface();
MacInterface mac = MacInterface();
ChannelInterface chan = ChannelInterface(11, 22, 2412); 


void setup(){
    Serial.begin(9600);
    delay(500);
}


void loop(){
    Serial.println("[1] Para interface MAC\n[2] Para interface IP\n[3] Para interface dos canais");

    int select = -1;

    while (select < 1) 
        select = Serial.parseInt();
    
    switch (select) {
        case 1:
            mac.show_menu();
            delay(125);
            return; 
        
        case 2:
            ip.show_menu();
            delay(125);
            return; 
        
        case 3: 
            chan.show_menu();
            delay(125);
            return;

        default:
            return;
    }
}