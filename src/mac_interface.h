#if !defined(MAC_INTERFACE)
#define MAC_INTERFACE
#define MAC_ADDR_STR_LEN 17 


#include "Arduino.h"
#include "menu.h"



class Mac{
    private:
        String mac_addr_str; 
        
    public:
        /** 
         * Cria com um endereço aleatório 
        */
        Mac();

        /** 
         * Tenta setar um endereço MAC. 
         * Caso falhe, mantém o endereço que tem.
        */
        void set_mac_addr(String &addr);

        String get_mac_addr_str(); 
        
};


class MacInterface : public IMenu {
    private:
        Mac *mac; 

    public:
        MacInterface();

        void print_mac(); 

        void update_mac();

        // Metodos da classe pai 
        
        const char * get_info();
        
        void show_menu();
};

#endif // MAC_INTERFACE