#if !defined(IP_INTERFACE)
#define IP_INTERFACE


#include "Arduino.h"
// #include "WString.h"
#include "menu.h"
// #include <stdlib.h>

class Ip{
    private:
        // endereço IP
        String ip_addr; 
        String mask_addr;
        String gw_addr; 
        // Ip que vai assumir caso não seja instanciado sem nada
        String IPDEFAULT = "192.168.1.50";
        String MASKDEFAULT = "255.0.0.1";
        String GWDEFAULT = "192.168.1.1";

        // verificar se o endereço informado é válido
        bool check(String addr); 
        //Para verificar se o IP digitado é somente número
        bool isNumber(const String& str);
        //Separa o endereço IP em tokens para validar


    public:

        Ip();
        Ip(String ip_addr);
        Ip(String ip_addr, String mask_addr);
        Ip(String ip_addr, String mask_addr, String gw_addr);
 
        bool set_ip_addr_static(String addr); // para ip estático
        bool set_mask_addr_static(String mask_addr); // para máscara estática
        bool set_gw_addr_static(String gw_addr); // para gateway estático
        bool set_ip_full_static(String ip_addr, String mask_addr, String gw_addr);
   

        String get_ip_addr();
        String get_mask_addr();
        String get_gw_addr();

};


class IpInterface {
    private:
        Ip ip; 

    public:
        IpInterface();
        
        // mostra as opcoes referentes ao endereco mac 
        void show_menu();

        void print_ip(); 

        void update_ip();
        void update_mask();
        void update_gw();
        void update_all_fields();
        const char * get_info();
        

};


#endif // IP_INTERFACE