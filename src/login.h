#if !defined(LOGIN)
#define LOGIN

// #include "Arduino.h"
#include <string>
#include "menu.h"
#include <iostream>

using namespace std;

class Login{
    private:
    // senha que pode ser alterada, padrão é ter 5 dígitos
    string password;
    // login padrão e único
    string LOGINDEFAULT ="admin";
    // senha para primeiro acesso ao modem
    string PASSWORDDEFAULT = "admin";

    public:
  

        Login();   
        // retornar o usário padrão
        string get_username();
        // Alterar a senha de acesso ao modem
        bool set_newPassword(string newPwd);
        // Volta a senha para o padrão de fábrica        
        bool resetPassword();
        // validar credencias do usuario
        bool log_in(string user,string pwd);

};


class LoginInterface : public IMenu {
    private:
        Login login; 

    public:
        LoginInterface();

        ~LoginInterface() = default;
        // Mostra o usuário para logar no modem
        void print_Login(); 
        // Altera a senha do modem
        void update_Password();
        // Volta a senha para o padrão
        void reset_Password();
        // validar credencias do usario
        void log_in_interface();
        
        // Metodos da classe pai         
        const char * get_info();

        void show_menu();

};







#endif // LOGIN
