#include "mac_interface.h"


// ******************************************** MAC ******************************************** //


Mac::Mac(){
    uint8_t mac[6];
    for(int i = 0; i < 6; i++) mac[i] = rand()%256; 
    this->mac_addr = mac;
}


bool Mac::set_mac_addr(const char * addr){
    static uint8_t new_mac[6]; // so funciona quando essa variavel eh estatica
    char aux[2];

    for(int i = 2, j = 0; i < 18; i += 3, j++){
        aux[0] = addr[i-2];
        aux[1] = addr[i-1]; 
        aux[2] = '\0'; // sem isso da erro

        new_mac[j] = (uint8_t)strtol(aux, NULL, 16); 
    }
    
    this->mac_addr = new_mac;
    return true; 
}


uint8_t * Mac::get_mac_addr(){
    return this->mac_addr;
}


void Mac::get_mac_addr_str(){
    String s; 
    char hex[2];
    for(int i = 0; i < 6; i++){
        sprintf(hex, "%X", this->mac_addr[i]);
        String str_aux(hex);
        s += str_aux; 
        s += ":";
    }

    Serial.print("Endereço MAC"); 
    Serial.println(s);

    // return s; 
}


// ******************************************** MAC INTERFACE ******************************************** //


MacInterface::MacInterface(){
    this->mac = Mac();
}


void MacInterface::print_mac(){
    // Serial.print("seu endereço MAC é: ");
    // Serial.println(this->mac.get_mac_addr_str());
    this->mac.get_mac_addr_str();
}


void MacInterface::update_mac(){
    Serial.println("Digite o novo endereço MAC, deve ter o seguinte formato: 01:23:45:67:89:aB:"); 
    Serial.println("Digite [q] para voltar");

    int user_input; 
    String new_mac; 
    
    // espera o usuario digitar o endereço MAC (ou desistir)
    while(new_mac.length() < 17){
        user_input = Serial.read();

        if(user_input == 113 or user_input == 81) 
            return;

        // 58 inclui o : 
        if((user_input >= 48 and user_input <= 58) or 
           (user_input >= 65 and user_input <= 70) or 
           (user_input >= 97 and user_input <= 102)
        ) {
            char c = user_input; 
            Serial.print(c);
            new_mac += String(c);
        }
        delay(50);
    }

    this->mac.set_mac_addr(new_mac.c_str());

    Serial.println(" ");
    Serial.print("Novo endereço MAC: "); 
    Serial.println(new_mac);    
}
  

// IMenu

 void MacInterface::show_menu(){ 
    Serial.println("[1] para mostrar o MAC\n[2] para alterar o MAC");

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
            return;
    }
}


const char * MacInterface::get_info(){
    return "Interface MAC";
}