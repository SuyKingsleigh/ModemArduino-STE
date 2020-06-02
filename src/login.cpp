#include "login.h"


<<<<<<< HEAD
// Funcao para leitura serial 
// caso esteja lendo a senha, mostra apenas asteriscos 
String StringSerial(bool password = false){
  String conteudo = "";

  while(conteudo.length()<5) {
    int caractere = Serial.read();
    char c = caractere;

    if((c >= '0' && c <= '9') || 
       (c >= 'a' && c <= 'z') || 
       (c >= 'A' && c <= 'Z')) {
        conteudo += c;
        Serial.print(
            (password) ? '*' : c 
        );
    }
    delay(50);
  } 
  Serial.println("");
  return conteudo;
}


// ******************************************** LOGIN ******************************************** //


Login::Login(String &user = D_LOGIN, String &password = D_PASSWORD){
    this->user = user; 
    this->password = password;    
}


String Login::get_username(){
    return this->user;
}


// Alterar a senha de acesso ao modem
bool Login::set_newPassword(String &newPwd){
    Serial.println("Digite a senha antiga\n");
    String oldpwd = StringSerial(true);

    if(oldpwd == this->password){
        this->password = newPwd;
        return true;
    }else{
=======
// ******************************************** LOGIN ******************************************** //


Login::Login(){
    this->password = PASSWORDDEFAULT;    
}

string Login::get_username(){
    return this->LOGINDEFAULT;
}



// Alterar a senha de acesso ao modem
bool Login::set_newPassword(string newPwd){
    cout << "Digite a senha antiga\n";
    string oldpwd;
    cin >> oldpwd;
    if(oldpwd == this->password){
        this->password = newPwd;
        cout << "Senha alterada \n";
        return true;
    }else{
        cout << "Senha antiga invalida\n";
>>>>>>> 54c82d91e56ed8d820d11b6fd832a9fe4cb7166b
        return false;
    }
}


<<<<<<< HEAD
bool Login::log_in(String &user, String &pwd){
    return user == this->user && pwd == this->password; 
=======
bool Login::log_in(string user, string pwd){
    if(user == this->LOGINDEFAULT && pwd == this->password){
        // Aqui precisa ir para o menu do Modem
        cout << "Logou\n";
        return true;
    }else{
        cout << "Usuario ou senha invalido\n";
        return false;
    }
>>>>>>> 54c82d91e56ed8d820d11b6fd832a9fe4cb7166b
}


// Volta a senha para o padrão de fábrica
<<<<<<< HEAD
void Login::resetPassword(){
    this->password = D_PASSWORD;
}


=======
bool Login::resetPassword(){
    this->password = PASSWORDDEFAULT;
    cout << "Senha voltou padra o padrão admin\n";
    return true;
}



>>>>>>> 54c82d91e56ed8d820d11b6fd832a9fe4cb7166b
// ******************************************** LOGIN INTERFACE ******************************************** //


LoginInterface::LoginInterface(){
    this->login = Login();
<<<<<<< HEAD
    this->status = false;
=======
>>>>>>> 54c82d91e56ed8d820d11b6fd832a9fe4cb7166b
}


 void LoginInterface::show_menu(){ 
<<<<<<< HEAD
    Serial.println("\n[1] para logar no modem \
                    \n[2] para alterar a senha \
                    \n[3] para resetar a senha  \
                    \n[4] para mostrar o usuario \n");

    int c = -1; 
    while (c < 1) 
        c = Serial.parseInt();
=======
    cout << ("[1] para logar no modem\n[2] para alterar a senha\n[3] para resetar a senha\n[4] para mostrar o usuario\n");
    int c =0;
    cin >> c;
    // int c = -1; 
    // while (c < 1) 
    //     c = Serial.parseInt();
>>>>>>> 54c82d91e56ed8d820d11b6fd832a9fe4cb7166b
    
    switch (c) {
        case 1:
            this->log_in_interface();
<<<<<<< HEAD
            delay(125);
            return; 

        case 2:
            this->update_Password();
            delay(125);
            return;  

        case 3:
            this->reset_Password();
            delay(125);
            return;   
        
        case 4:
            this->print_Login();
            delay(125);
            return;  

        default:
            this->get_info();
            delay(125);
            return;  
    }
}


void LoginInterface::print_Login(){
    Serial.println(this->login.get_username()+"\n");
} 


void LoginInterface::update_Password(){
    Serial.println("Digite a nova senha\n");
    String newpwd = StringSerial(true);
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
    pwd = StringSerial(true); 

    this->status = this->login.log_in(user,pwd); 
    Serial.println(
        (this->status) ? "Logou com sucesso" : "Senha ou usuario errado"
    );
}
=======
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
        cout << this->login.get_username()+"\n";
    } 

    void LoginInterface::update_Password(){
        cout << "Digite a nova senha\n";
        string newpwd;
        cin >> newpwd;
        this->login.set_newPassword(newpwd);
    }

    void LoginInterface::reset_Password(){
        this->login.resetPassword();
    }

    void LoginInterface::log_in_interface(){
        string user; string pwd;
        cout << "Digite o usuario\n";
        cin >> user;
        cout << "Digite a senha\n";
        cin >> pwd;
        this->login.log_in(user,pwd);
    }

>>>>>>> 54c82d91e56ed8d820d11b6fd832a9fe4cb7166b


const char * LoginInterface::get_info(){
    return "Interface LOGIN";
<<<<<<< HEAD
}

bool LoginInterface::is_authenticated() {
    return this->status;
=======
>>>>>>> 54c82d91e56ed8d820d11b6fd832a9fe4cb7166b
}