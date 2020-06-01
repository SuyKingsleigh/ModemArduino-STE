#if !defined(LOGIN)
#define LOGIN

#include "Arduino.h"
#include <WString>
#include "menu.h"


using namespace std;

class Login{
    private:
    // senha que pode ser alterada, padrão é ter 5 dígitos
    String password;
    // login padrão e único
    String LOGINDEFAULT ="admin";
    // senha para primeiro acesso ao modem
    String PASSWORDDEFAULT = "admin";

    public:
  

        Login();   
        // retornar o usário padrão
        String get_username();
        // Alterar a senha de acesso ao modem
        bool set_newPassword(String newPwd);
        // Volta a senha para o padrão de fábrica        
        bool resetPassword();
        // validar credencias do usuario
        bool log_in(String user,String pwd);

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
