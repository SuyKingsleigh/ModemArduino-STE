#include "mac_interface.h"
#include <cstdlib>

// ***************************** MAC **********************************************//


Mac::Mac(){
    this->mac_addr = this->_generate_random_mac();
}


uint8_t * Mac::_generate_random_mac(){
    static uint8_t mac[6];
    for(int i = 0; i < 6; i++) mac[i] = rand()%256; 
    return mac;
}   


bool Mac::check(const char * addr){
    return false;
}    


bool Mac::set_mac_addr(const char * addr){
        try{
        static uint8_t new_mac[6];
        char aux[2];

        for(int i = 2, j = 0; i < 18; i += 3, j++){
            aux[0] = addr[i-2];
            aux[1] = addr[i-1]; 
            aux[2] = '\0';

            new_mac[j] = (uint8_t)strtol(aux, NULL, 16); 
            // cout << hex << unsigned(inteiro[j]) << endl;
 
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

Mac::~Mac(){

}


// **************** MAC INTERFACE ********************************************* //


MacInterface::MacInterface(){
    this->mac = Mac();
}


void MacInterface::show_menu(){ }


void MacInterface::print_mac(){ }


void MacInterface::update_mac(const char * addr){ } 


MacInterface::~MacInterface(){ }