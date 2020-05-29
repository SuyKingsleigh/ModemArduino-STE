#include "mac_interface.h"

// ******************************************** MAC ******************************************** //


Mac::Mac(){
    uint8_t mac[6];
    for(int i = 0; i < 6; i++) mac[i] = rand()%256; 
    this->mac_addr = mac;
}


bool Mac::set_mac_addr(const char * addr){
    try{
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
    catch(...){
        return false; 
    }
}


uint8_t * Mac::get_mac_addr(){
    return this->mac_addr;
}


std::string Mac::get_mac_addr_str(){
    std::string s; 
    char hex[2];
    for(int i = 0; i < 6; i++){
        sprintf(hex, "%X", this->mac_addr[i]);
        std::string str_aux(hex);
        s += str_aux; 
        s += ":";
    }
    return s; 
}


// ******************************************** MAC INTERFACE ******************************************** //


MacInterface::MacInterface(){
    this->mac = Mac();
}


void MacInterface::print_mac(){
    print("seu endereço MAC é: ");
    print(this->mac.get_mac_addr_str().c_str());
 }


void MacInterface::update_mac(){
    try{
        print("Digite o novo endereço MAC, deve ter o seguinte formato: 01:23:45:67:89:AB:"); 
        std::string user_input; 
        std::cin >> user_input; 

        if(this->mac.set_mac_addr(user_input.c_str())) {
            print("Endereço MAC trocado com sucesso, novo endereço é: ");
            print(this->mac.get_mac_addr_str().c_str());
        }else 
            print("Falhou ao trocar o endereço MAC");
        
    }catch(...){
        print("Algum erro aconteceu");
    }
 } 
  
// IMenu

 void MacInterface::show_menu(){ 
    print("[1] para mostrar o MAC\n[2] para alterar o MAC");

    switch (read()) {
        case 1:
            this->print_mac();
            break;

        case 2:
            this->update_mac();
            break; 

        default:
            break;
    }
}


const char * MacInterface::get_info(){
    return "Interface MAC";
}