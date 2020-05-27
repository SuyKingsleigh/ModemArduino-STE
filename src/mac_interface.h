#if !defined(MAC_INTERFACE)
#define MAC_INTERFACE


class MacInterface{

    private:
        // endereço MAC, ponteiro para um array com 6 bytes
        uint8_t * mac_addr;

        // gera um endereço aleatório        
        uint8_t * _generate_random_mac();

        // verifica se o endereco mac passado pelo usuario eh valido
        bool check(const char * addr);    

    public:
        /** 
         * Cria com um endereço aleatório 
        */
        MacInterface();

        /** 
         * Tenta setar um endereço MAC. 
         * Caso falhe, mantém o endereço que tem.
        */
        bool set_mac_addr(const char * addr);

        uint8_t * get_mac_addr();

        ~MacInterface();
    
};


#endif // MAC_INTERFACE