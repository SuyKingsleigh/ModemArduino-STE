#if !defined(LOGIN)
#define LOGIN

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
};


class LoginInterface : public IMenu {
    private:
        Login login; 

        // indica se o usuario está autenticado 
        bool status; 

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
        
        bool is_authenticated();
};


#endif // LOGIN