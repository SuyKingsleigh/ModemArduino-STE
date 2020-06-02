#if !defined(LOGIN)
#define LOGIN

<<<<<<< HEAD
#include "menu.h"
#include "Arduino.h"

static String D_LOGIN = "admin";
static String D_PASSWORD = "admin";


class Login{
    private:
        String user; 

        // senha que pode ser alterada, padrão é ter 5 dígitos
        String password;

    public:
        Login(String &user = D_LOGIN, String &password = D_PASSWORD);   

        String get_username();

        // Alterar a senha de acesso ao modem
        bool set_newPassword(String &newPwd);

        // Volta a senha para o padrão de fábrica        
        void resetPassword();

        // validar credencias do usuario
        bool log_in(String &user,String &pwd);

        // retorna caso o usuario esteja autenticado
        bool is_authenticated(); 
=======
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

>>>>>>> 54c82d91e56ed8d820d11b6fd832a9fe4cb7166b
};


class LoginInterface : public IMenu {
    private:
        Login login; 

<<<<<<< HEAD
        // indica se o usuario está autenticado 
        bool status; 

=======
>>>>>>> 54c82d91e56ed8d820d11b6fd832a9fe4cb7166b
    public:
        LoginInterface();

        ~LoginInterface() = default;
<<<<<<< HEAD

        // Mostra o usuário para logar no modem
        void print_Login(); 

        // Altera a senha do modem
        void update_Password();

        // Volta a senha para o padrão
        void reset_Password();

=======
        // Mostra o usuário para logar no modem
        void print_Login(); 
        // Altera a senha do modem
        void update_Password();
        // Volta a senha para o padrão
        void reset_Password();
>>>>>>> 54c82d91e56ed8d820d11b6fd832a9fe4cb7166b
        // validar credencias do usario
        void log_in_interface();
        
        // Metodos da classe pai         
<<<<<<< HEAD
        
        const char * get_info();

        void show_menu();
        
        bool is_authenticated();
};


#endif // LOGIN
=======
        const char * get_info();

        void show_menu();

};







#endif // LOGIN
>>>>>>> 54c82d91e56ed8d820d11b6fd832a9fe4cb7166b
