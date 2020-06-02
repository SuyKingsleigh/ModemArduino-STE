#include "ip_interface.h"

// ***************************** IP **********************************************//


Ip::Ip(){
    this->ip_addr = IPDEFAULT;
    this->mask_addr = MASKDEFAULT;
    this->gw_addr = GWDEFAULT;
}

Ip::Ip(String ip_addr){
    this->ip_addr = ip_addr;
    this->mask_addr = MASKDEFAULT;
    this->gw_addr = GWDEFAULT;
}
Ip::Ip(String ip_addr, String mask_addr){
    this->ip_addr = ip_addr;
    this->mask_addr = mask_addr;
    this->gw_addr = GWDEFAULT;
}

Ip::Ip(String ip_addr, String mask_addr, String gw_addr){
    this->ip_addr = ip_addr;
    this->mask_addr = mask_addr;
    this->gw_addr = gw_addr;
}

// método para auxiliar a validar o IP


// método para separar a String recebida para conseguir validar(fazer o check)



// Verifica se o endereço IP digitado é válido
bool Ip::check(String addr){

    int cont_delim = 0;
    for(int i =0;i<addr.length();i++){
        if(addr[i]=='.'){
            cont_delim++;
        }else{
            if(addr[i]<'0' || addr[i]>'9'){
                return false;
            }          
        }        
    }
    if(cont_delim==3 && addr[3]=='.' &&  addr[7]=='.' &&  addr[11]=='.'){
        return true;
    }else{
        return false;
    }

}    

// seta um IP estático no modem
bool Ip::set_ip_addr_static(String addr){

    if(this->check(addr)==true){
        this->ip_addr = addr;
        return true;
    }else{
        return false;
    }

}

// seta uma máscara estática no modem
bool Ip::set_mask_addr_static(String addr){

    if(this->check(addr)==true){
        this->mask_addr = addr;
        return true;
    }else{
        return false;
    }

}

// seta um gateway estático no modem
bool Ip::set_gw_addr_static(String addr){

    if(this->check(addr)==true){
        this->gw_addr = addr;
        return true;
    }else{
        return false;
    }
}

// Define um endereço com todas as informações para o Modem
bool Ip::set_ip_full_static(String ip_addr, String mask_addr, String gw_addr){

    if(this->check(ip_addr)==true && this->check(mask_addr)==true && this->check(gw_addr)==true){
        this->ip_addr = ip_addr;
        this->mask_addr = mask_addr;
        this->gw_addr = gw_addr;
        return true;
    }else{
        return false;
    }
}

String Ip::get_ip_addr(){
    return this->ip_addr;
}

String Ip::get_mask_addr(){
    return this->mask_addr;
}

String Ip::get_gw_addr(){
    return this->gw_addr;
}



// **************** IP INTERFACE ********************************************* //


String leStringSerial(){
  String conteudo = "";

  // Enquanto receber algo pela serial
  while(conteudo.length()<15) {
    // Lê byte da serial
    int caractere = Serial.read();
    // Ignora caractere de quebra de linha
    char c = caractere;
    if((c >= '0' && c <= '9') || c=='.' ){
      conteudo += c;
      Serial.print(c); // assim aparece o que ta sendo digitado
    }
    // Aguarda buffer serial ler próximo caractere
    delay(50);
  } 
  return conteudo;
}


IpInterface::IpInterface(){
    this->ip = Ip();
}


void IpInterface::show_menu(){ 
    Serial.println("\n[1] para mostrar o endereço IP \
    \n[2] para alterar o IP \
    \n[3] para alterar a Máscara \
    \n[4] para alterar o Gateway \
    \n[5] para alterar tudo \n");
    
    int c = -1; 
    while (c < 1) 
        c = Serial.parseInt();

    switch (c) {
        case 1:
            this->print_ip();
            delay(125);
            return; 
        
        case 2:
            this->update_ip();
            delay(125);
            return; 
        
         case 3:
            this->update_mask();
            delay(125);
            return; 
        
        case 4:
            this->update_gw();
            delay(125);
            return; 
        
        case 5:
            this->update_all_fields();                
            delay(125);
            return;         

        default:
            this->get_info();
            delay(125);
            return;
    }
}

void IpInterface::print_ip(){ 
    Serial.println("IP: " +this->ip.get_ip_addr()); 
    Serial.println("Mascara: "+this->ip.get_mask_addr()); 
    Serial.println("Gateway: "+this->ip.get_gw_addr()+"\n"); 
    // delay(100);
}

void IpInterface::update_ip(){ 

    Serial.println("Digite o novo endereco IP, deve ter o seguinte formato: xxx.xxx.xxx.xxx \n"); 
    String user_input = leStringSerial(); 


    if(this->ip.set_ip_addr_static(user_input)){
        Serial.println("Endereço IP trocado com sucesso, novo endereco e: \n");
        Serial.println(this->ip.get_ip_addr());
        delay(50);
    }else{
        Serial.println("Endereço IP nao foi alterado, nao esta no padrao xxx.xxx.xxx.xxx  \n");
        delay(50);    
    }

}

void IpInterface::update_mask(){ 

    Serial.println("Digite a nova mascara de rede, deve ter o seguinte formato: xxx.xxx.xxx.xxx \n"); 
    String user_input = leStringSerial(); 
    
    if(this->ip.set_mask_addr_static(user_input)){
        Serial.println("Mascara de rede trocada com sucesso, nova máscara e: \n");
        Serial.println(this->ip.get_mask_addr());
        delay(50);
    }else{
        Serial.println("Mascada nao foi alterada, nao esta no padrao xxx.xxx.xxx.xxx \n");
        delay(50);
    }
}

void IpInterface::update_gw(){

    Serial.println("Digite o novo Gateway, deve ter o seguinte formato: xxx.xxx.xxx.xxx \n"); 
    String user_input = leStringSerial(); 

    if(this->ip.set_gw_addr_static(user_input)){
        Serial.println("Gateway trocado com sucesso, novo Gateway e: \n");
        Serial.println(this->ip.get_gw_addr());
        delay(50);
    }else{
        Serial.println("Gateway nao foi alterado, nao esta no padrao xxx.xxx.xxx.xxx \n");
        delay(50);       
    }      
}

void IpInterface::update_all_fields(){ 
    String user_input1, user_input2, user_input3; 

    Serial.println("Digite o novo endereco IP, deve ter o seguinte formato: xxx.xxx.xxx.xxx \n");  
    user_input1 = leStringSerial();
    delay(200);

    Serial.println("Digite a nova mascara de rede, deve ter o seguinte formato: xxx.xxx.xxx.xxx \n"); 
    user_input2 = leStringSerial();
    delay(200);

    Serial.println("Digite o novo Gateway, deve ter o seguinte formato: xxx.xxx.xxx.xxx \n"); 
    user_input3 = leStringSerial();
    delay(200);

    if(this->ip.set_ip_addr_static(user_input1)&&this->ip.set_ip_addr_static(user_input2)&&this->ip.set_ip_addr_static(user_input3)){
        this->ip.set_ip_addr_static(user_input1);
        this->ip.set_mask_addr_static(user_input2);
        this->ip.set_gw_addr_static(user_input3);   
        Serial.println("Endereco alterado, novo endereco e:  \n");
        Serial.println ("IP: " +this->ip.get_ip_addr()+"\n"+"Mascara: "+this->ip.get_mask_addr()+"\n"+"Gateway: "+this->ip.get_gw_addr());
    }      
}

const char * IpInterface::get_info(){
    return "Interface IP";
}