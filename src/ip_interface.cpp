#include <iostream>
#include "ip_interface.h"

// ***************************** IP **********************************************//


Ip::Ip(){
    this->ip_addr = this->get_ip_addr();
}


string Ip::_generate_random_ip(){
    return nullptr;
}


bool Ip::check(const char * addr){
    return false;
}    


bool Ip::set_ip_addr(const char * addr){
    return false;
}


string Ip::get_ip_addr(){
    return this->ip_addr;
}


// **************** IP INTERFACE ********************************************* //


IpInterface::IpInterface(){
    this->ip = Ip();
}


void IpInterface::show_menu(){ }


void IpInterface::print_ip(){ }


void IpInterface::update_ip(const char * addr){ }