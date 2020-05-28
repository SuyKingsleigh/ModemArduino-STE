#if !defined(MAC_INTERFACE)
#define MAC_INTERFACE

#include<stdint.h> // precisa pra rodar no windows o uint8_t
#include "menu.h"


class Mac{
    private:
        // endereço MAC, ponteiro para um array com 6 bytes
        uint8_t * mac_addr;

        // gera um endereço aleatório        
        uint8_t * _generate_random_mac();

        // verifica se o endereco mac passado pelo usuario eh valido
        bool check(const char * addr);    

    public:
        /** 
         * Cria um endereço aleatório 
        */
        Mac();

        /** 
         * Tenta setar um endereço MAC. 
         * Caso falhe, mantém o endereço que tem.
        */
        bool set_mac_addr(const char * addr);

        uint8_t * get_mac_addr();

        virtual ~Mac();
    
};

class MacInterface {
    private:
        Mac mac; 

    public:
        MacInterface();
        
        // mostra as opcoes referentes ao endereco mac 
        void show_menu();

        void print_mac(); 

        void update_mac(const char * addr);
        
        virtual ~MacInterface();

};


#endif // MAC_INTERFACE