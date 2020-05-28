#include "mac_interface.h"


// ***************************** MAC **********************************************//


Mac::Mac(){
    this->mac_addr = this->get_mac_addr();
}


uint8_t * Mac::_generate_random_mac(){
    return nullptr;
}


bool Mac::check(const char * addr){
    return false;
}    


bool Mac::set_mac_addr(const char * addr){
    return false;
}


uint8_t * Mac::get_mac_addr(){
    return this->mac_addr;
}


// **************** MAC INTERFACE ********************************************* //


MacInterface::MacInterface(){
    this->mac = Mac();
}


void MacInterface::show_menu(){ }


void MacInterface::print_mac(){ }


void MacInterface::update_mac(const char * addr){ }