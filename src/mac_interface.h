#if !defined(MAC_INTERFACE)
#define MAC_INTERFACE

// #include<stdint.h> // precisa pra rodar no windows o uint8_t
#include "Arduino.h"
#include "WString.h"
// #include <iostream>
// #include <cstdlib>
// #include <cstdio>
// #include <string>
#include "menu.h"


class Mac{
    private:
        // endereço MAC, ponteiro para um array com 6 bytes
        uint8_t * mac_addr;
        // verifica se o endereco mac passado pelo usuario eh valido
        bool check(const char * addr);    

    public:
        /** 
         * Cria com um endereço aleatório 
        */
        Mac();

        /** 
         * Tenta setar um endereço MAC. 
         * Caso falhe, mantém o endereço que tem.
        */
        bool set_mac_addr(const char * addr);

        uint8_t * get_mac_addr();

        void get_mac_addr_str(); 
        
};

class MacInterface : public IMenu {
    private:
        Mac mac; 

    public:
        MacInterface();

        ~MacInterface() = default;

        void print_mac(); 

        void update_mac();

        // Metodos da classe pai 
        
        const char * get_info();
        
        void show_menu();

};

#endif // MAC_INTERFACE