#include "channel.h"


Channel::Channel(int c_freq, int id, int bandwidth) {
    this->min_freq = c_freq - (bandwidth/2);
    this->central_frequency = c_freq; 
    this->max_freq = c_freq + (bandwidth/2);
    this->allocated = false; 
    this->id = id;
}


bool Channel::is_allocated(){ 
    return this->allocated;
}


bool Channel::allocate() {
    if (!this->allocated) {
        this->allocated = true; 
        return true;
    }
    return false; 
}


bool Channel::deallocate() { 
    if(this->allocated) { 
        this->allocated = false; 
        return true; 
    }
    return false; 
}


String Channel::to_string() {
    String r = F("ID: "); 
    r += String(this->id, DEC);

    r += F(" Frequencia Minima: ");
    r += String(this->min_freq, DEC);

    r += F(" Frequencia Central: ");
    r += String(this->central_frequency, DEC);

    r += F(" Frequencia Maxima: ");
    r += String(this->max_freq, DEC);
    
    r +=  F(" Status: ");
    r += (this->allocated) ? F("alocado") : F("desalocado");

    return r;
}


// ****************************************** Channel Interface ****************************************** //


ChannelInterface::ChannelInterface(int num_channel, int c_freq_distance, int ifreq) { 
    this->table = malloc(num_channel * sizeof(Channel));
    this->num_channel = num_channel; 

    for (int i = 0; i < num_channel; i++, ifreq += c_freq_distance) 
        this->table[i] = Channel(ifreq, i+1, c_freq_distance);
        
}


bool ChannelInterface::allocate_chan(int id) {
    return this->table[id].allocate();
}


bool ChannelInterface::deallocate_chan(int id) {
    return this->table[id].deallocate();
}


String ChannelInterface::get_chan_info(int id) { 
    return this->table[id].to_string();
}
   

int ChannelInterface::selectChannel(){ 
    Serial.println(F("Escolha um canal "));
    Serial.print(F("Valor deve ser entre 1 e ")); 
    Serial.println(this->num_channel); 

    int uin = -1; 

    //0 eh a entrada padrao, entao os canais comecam em 1 
    // mas eh apenas para visibilidade do usuario 
    while (uin < 1 or uin > this->num_channel) 
        uin = Serial.parseInt();

    return --uin;
}


// *** Metodos da classe parente *** 


const char * ChannelInterface::get_info() { 
    return "fazer";
}


void ChannelInterface::show_menu() { 
    Serial.println(F("[1]Informação de todos os canais \
    \n[2]Informação de Um canal especifico \
    \n[3]Aloca um canal  \
    \n[4]Desaloca um canal"));

    int select = -1;

    while (select < 1) 
        select = Serial.parseInt();
    
    switch (select) {
        case 1: // mostra todos canais 
            for(int i = 0; i < this->num_channel; i++) 
                Serial.println(this->table[i].to_string());
            return; 
        
        case 2: // mostra canal especifico 
            Serial.println(this->table[this->selectChannel()].to_string());
            return; 

        case 3: // aloca um canal 
            Serial.println(F("alocar um canal: ")); 
            Serial.println (
                (this->table[this->selectChannel()].allocate()) ? F("Sucesso") : F("Canal já alocado")
            );
            return;

        case 4: // desaloca um canal 
            Serial.println(F("alocar um canal: ")); 
            Serial.println (
                (this->table[this->selectChannel()].deallocate()) ? F("Sucesso") : F("Falhou")
            );
            return;

        default: // ajuda 
            this->get_info();
            delay(125);
            return;

    }

}