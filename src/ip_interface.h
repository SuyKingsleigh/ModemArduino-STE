#if !defined(IP_INTERFACE)
#define IP_INTERFACE
using namespace std;

#include <iostream>
#include <string>
#include "menu.h"


class Ip{
    private:
        // endereÃ§o IP
        string ip_addr;

        // gera um endereÃ§o aleatÃ³rio        
        string _generate_random_ip(); // para usar como DHCP

        // verificar se Ã© IPV4 ou IPV6 vÃ¡lido
        bool check(const char * addr); 

    public:
        /** 
         * Cria um endereÃ§o aleatÃ³rio 
        */
        Ip();

        /** 
         * Tenta setar um endereÃ§o IP. 
         * Caso falhe, mantÃ©m o endereÃ§o que tem.
        */
        bool set_ip_addr(const char * addr); // para ip estÃ¡tico


        string get_ip_addr();

        ~Ip();
    
};

class IpInterface {
    private:
        Ip ip; 

    public:
        IpInterface();
        
        // mostra as opcoes referentes ao endereco mac 
        void show_menu();

        void print_ip(); 

        void update_ip(const char * addr);
        
        ~IpInterface();

};


#endif // IP_INTERFACE
