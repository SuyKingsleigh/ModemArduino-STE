// #if !defined(IP_INTERFACE)
// #define IP_INTERFACE
// using namespace std;

// #include "Arduino.h"
// #include <iostream>
// #include <string>
// #include "menu.h"
// #include <vector>
// #include <stdlib.h>




// class Ip{
//     private:
//         // endereço IP, máscara de gateway
//         string ip_addr; 
//         string mask_addr;
//         string gw_addr; 
//         // Valores que vão ser usadoss caso seja instanciado sem argumentos
//         string IPDEFAULT = "192.168.1.50";
//         string MASKDEFAULT = "255.0.0.1";
//         string GWDEFAULT = "192.168.1.1";

//         // verificar se o endereço informado é válido
//         bool check(string addr); 
//         //Para verificar se o IP digitado é somente número
//         bool isNumber(const string& str);
//         //Separa o endereço IP em tokens para validar
//         vector<string> split(const string& str, char delim);

//     public:

//         // Constutores
//         Ip();
//         Ip(string ip_addr);
//         Ip(string ip_addr, string mask_addr);
//         Ip(string ip_addr, string mask_addr, string gw_addr);
 
//         bool set_ip_addr_static(string addr); // para ip estático
//         bool set_mask_addr_static(string mask_addr); // para máscara estática
//         bool set_gw_addr_static(string gw_addr); // para gateway estático
//         bool set_ip_full_static(string ip_addr, string mask_addr, string gw_addr);
   
    
//         string get_ip_addr();
//         string get_mask_addr();
//         string get_gw_addr();

    
// };

// class IpInterface {
//     private:
//         Ip ip; 

//     public:
//         IpInterface();
        
//         // mostra as opcoes referentes ao endereco mac 
//         void show_menu();

//         void print_ip(); 

//         void update_ip();
//         void update_mask();
//         void update_gw();
//         void update_all_fields();
//         const char * get_info();    

// };

// #endif // IP_INTERFACE
