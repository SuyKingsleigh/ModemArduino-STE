#include "mac_interface.h"


// ******************************************** MAC ******************************************** //


Mac::Mac(){
    this->mac_addr_str.reserve(MAC_ADDR_STR_LEN); // alloca um buffer na memoria  

    for(uint8_t i = 0, n = 0; i < 12; i++, ++n) { 
        char hex = "0123456789ABCDEF"[random() % 16];
        if(n == 2){ 
            this->mac_addr_str += ":";
            n = 0;
        }
        this->mac_addr_str += String(hex);
    }
}


void Mac::set_mac_addr(String &addr){
    this->mac_addr_str = addr;
}


String Mac::get_mac_addr_str(){
    return this->mac_addr_str;
}


// ******************************************** MAC INTERFACE ******************************************** //


MacInterface::MacInterface(){
    this->mac = new Mac();
}


void MacInterface::print_mac(){
    Serial.print(F("\nEndereço MAC: ")); 
    Serial.println(this->mac->get_mac_addr_str());
}


void MacInterface::update_mac(){
    Serial.println(F("Digite o novo endereço MAC, deve ter o seguinte formato: 01:23:45:67:89:aB:")); 
    Serial.println(F("Digite [q] para voltar"));

    uint8_t user_input, n = 0; 
    String new_mac;
    new_mac.reserve(MAC_ADDR_STR_LEN);
    
    // espera o usuario digitar o endereço MAC (ou desistir)
    while(new_mac.length() < MAC_ADDR_STR_LEN){
        user_input = Serial.read();

        if(user_input == 113 or user_input == 81) 
            return;

        if((user_input >= 48 and user_input <= 57) or 
           (user_input >= 65 and user_input <= 70) or 
           (user_input >= 97 and user_input <= 102)
        ) {
            
            char c = user_input; 
            c = toupper(c);
            Serial.print(c);
            new_mac += String(c);
            
            // so acontece depois que o usuario digita algo valido
            ++n;
            if(n == 2) {
                new_mac += ":"; 
                Serial.print(":");  
                n = 0; 
            }  
        }
    }
    Serial.print("\n");
    
    this->mac->set_mac_addr(new_mac);
    this->print_mac();
}

// *** Métodos da classe Parente *** 


 void MacInterface::show_menu(){ 
    Serial.println(F("[1] para mostrar o MAC\n[2] para alterar o MAC"));

    int c = -1; 
    while (c < 1) 
        c = Serial.parseInt();
    
    switch (c) {
        case 1:
            this->print_mac();
            delay(125);
            return; 

        case 2:
            this->update_mac();
            delay(125);
            return; 

        default:
            this->get_info();
            delay(125);
            return;
    }
}


const char * MacInterface::get_info(){
    return "Interface MAC";
}