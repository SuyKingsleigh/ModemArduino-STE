#include "login.h"


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
        return false;
    }
}


bool Login::log_in(string user, string pwd){
    if(user == this->LOGINDEFAULT && pwd == this->password){
        // Aqui precisa ir para o menu do Modem
        cout << "Logou\n";
        return true;
    }else{
        cout << "Usuario ou senha invalido\n";
        return false;
    }
}


// Volta a senha para o padrão de fábrica
bool Login::resetPassword(){
    this->password = PASSWORDDEFAULT;
    cout << "Senha voltou padra o padrão admin\n";
    return true;
}



// ******************************************** LOGIN INTERFACE ******************************************** //


LoginInterface::LoginInterface(){
    this->login = Login();
}


 void LoginInterface::show_menu(){ 
    cout << ("[1] para logar no modem\n[2] para alterar a senha\n[3] para resetar a senha\n[4] para mostrar o usuario\n");
    int c =0;
    cin >> c;
    // int c = -1; 
    // while (c < 1) 
    //     c = Serial.parseInt();
    
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



const char * LoginInterface::get_info(){
    return "Interface LOGIN";
}