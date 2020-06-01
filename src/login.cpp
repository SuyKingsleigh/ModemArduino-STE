#include "login.h"


// ******************************************** LOGIN ******************************************** //


Login::Login(){
    this->password = PASSWORDDEFAULT;    
}

String Login::get_username(){
    return this->LOGINDEFAULT;
}


String StringSerial(){
  String conteudo = "";

  // Enquanto receber algo pela serial
  while(conteudo.length()<5) {
    // Lê byte da serial
    int caractere = Serial.read();
    // Ignora caractere de quebra de linha
    char c = caractere;
    if((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') ){
      conteudo += c;
    }
    // Aguarda buffer serial ler próximo caractere
    delay(50);
  } 
  return conteudo;
}

LoginInterface::LoginInterface(){
    this->login = Login();
}

// Alterar a senha de acesso ao modem
bool Login::set_newPassword(String newPwd){
    Serial.println("Digite a senha antiga\n");
    String oldpwd = StringSerial();


    if(oldpwd == this->password){
        this->password = newPwd;
        Serial.println("Senha alterada \n");
        return true;
    }else{
        Serial.println("Senha antiga invalida\n");
        return false;
    }
}


bool Login::log_in(String user, String pwd){
    if(user == this->LOGINDEFAULT && pwd == this->password){
        Serial.println("Logando no modem\n");
        // Aqui precisa ir para o menu do Modem

        return true;
    }else{
        Serial.println("Usuario ou senha invalido\n");
        return false;
    }
}


// Volta a senha para o padrão de fábrica
bool Login::resetPassword(){
    this->password = PASSWORDDEFAULT;
    Serial.println("Senha voltou padra o padrão admin\n");
    return true;
}



// ******************************************** LOGIN INTERFACE ******************************************** //


 void LoginInterface::show_menu(){ 
    Serial.println("[1] para logar no modem\n[2] para alterar a senha\n[3] para resetar a senha\n[4] para mostrar o usuario\n");

    int c = -1; 
    while (c < 1) 
        c = Serial.parseInt();
    
    switch (c) {
        case 1:
            this->log_in_interface();
            break; 
        case 2:
            this->update_Password();
            break; 
        case 3:
            this->reset_Password();
            break; 
        case 4:
            this->print_Login();
            break;
        default:
            this->get_info();
            break;
    }
}

    void LoginInterface::print_Login(){
        Serial.println(this->login.get_username()+"\n");
    } 

    void LoginInterface::update_Password(){
        Serial.println("Digite a nova senha\n");
        String newpwd = StringSerial();
        this->login.set_newPassword(newpwd);
    }

    void LoginInterface::reset_Password(){
        this->login.resetPassword();
    }

    void LoginInterface::log_in_interface(){
        String user; String pwd;
        Serial.println("Digite o usuario\n");
        user = StringSerial();
        Serial.println("Digite a senha\n");
        pwd = StringSerial(); 
        this->login.log_in(user,pwd);
    }



const char * LoginInterface::get_info(){
    return "Interface LOGIN";
}