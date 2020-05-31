#if !defined(CHANNEL)
#define CHANNEL
#define BANDWIDTH 22 // largura de banda padrao 


#include "Arduino.h"


class Channel { 
    private:
        int min_freq; 
        int max_freq; 
        int central_frequency; 
        bool allocated; 
    
    public:
        Channel(int c_freq);
        
        /** 
         * Aloca um canal 
         * Caso já esteja alocado retorna false 
        */
        bool allocate();


        /** 
         * Desaloca um canal
         * Caso não esteja alocado retorna false 
        */
        bool deallocate();

        // fmin, fmax, fcentral e status 
        const char * to_string(); 

};


struct ChannelTable {
    int id; 
    Channel chan; 
};


class ChannelInterface : public IMenu { 
    private: 
        struct ChannelTable table; 

        Channel get_channel(int id);
        
        bool allocate_chan(int id);

        bool deallocate_chan(int id);

        bool get_chan_info(int id);
   
    public:
        ChannelInterface();

        // Metodos da classe parente 
        
        const char * get_info(); 

        void show_menu();

};

#endif // CHANNEL