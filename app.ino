#include "src/menu.h"
#include "src/login.h"
#include "src/channel.h"
#include "src/ip_interface.h"
#include "src/mac_interface.h"


IpInterface ip = IpInterface();
MacInterface mac = MacInterface();
LoginInterface login = LoginInterface();
ChannelInterface chan = ChannelInterface(11, 22, 2412); 


void setup(){
    Serial.begin(9600);
    delay(500);
}


void loop(){
    // fica bloqueado até o usuário logar 
    delay(50);
    while(!login.is_authenticated())  
        login.log_in_interface();
    

    Serial.println("[1] Para interface MAC\n[2] Para interface IP\n[3] Para interface dos canais");

    int select = -1;
    while (select < 1) 
        select = Serial.parseInt();
    
    
    switch (select) {
        case 1: // interface mac 
            mac.show_menu();
            delay(125);
            break; 
        
        case 2: // interface IP
            ip.show_menu();
            delay(125);
            break; 
        
        case 3: // interface Canais 
            chan.show_menu();
            delay(125);
            break;

        case 4: // interface do usuario
            login.show_menu();
            delay(125);
            break;
    }
}