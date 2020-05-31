#if !defined(CHANNEL)
#define CHANNEL


#include "Arduino.h"
#include "menu.h"


class Channel { 
    private:
        int id; 
        int min_freq; 
        int max_freq; 
        bool allocated; 
        int central_frequency; 
    
    public:
        Channel(int c_freq, int id, int bandwidth);

        bool is_allocated();

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
        String to_string(); 

};

class ChannelInterface : public IMenu { 
    private:
        int num_channel; 

        Channel * table; 
        
        bool allocate_chan(int id);

        bool deallocate_chan(int id);

        String get_chan_info(int id);

        int selectChannel(); 
   
    public:
        /**
         * num_channel = numero de canais 
         * c_freq_distance = distancia da freq central de um canal para outro 
         * ifreq = frequencia central do primeiro canal 
        */
        ChannelInterface(int num_channel, int c_freq_distance, int ifreq);

        // Metodos da classe parente 
        
        const char * get_info(); 

        void show_menu();

};

#endif // CHANNEL