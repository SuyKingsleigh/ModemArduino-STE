#if !defined(MACRO)
#define MACRO


class IMenu {
    public: 
        /**
         * Nome do menu e mensagem a ser exibida 
         * exemplo "Interface MAC"
        */
        virtual const char * get_info() = 0; 

        /**
         *  Exibe um menu com todas as opções da interface 
        */
        virtual void show_menu() = 0;

        virtual ~IMenu() = default; 
};


#endif // MACRO