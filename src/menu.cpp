#include<iostream>

#include <iostream>

using namespace std;

int main()
{
    int choice;
    bool Option = true;
    while (Option != false){
        cout << "*******************************\n";
        cout << " 1 - Logar no modem.\n";
        cout << " 2 - Definir endereço IP.\n";
        cout << " 3 - Definir endereço MAC.\n";
        cout << " 4 - Escolher um canal.\n";
        cout << " Escolha a opção: ";

        cin >> choice;

        switch (choice)
        {
            case 1:
            break;
            case 2:
            break;
            case 3:
            break;
            case 4:
            break;
            default:
            cout << "Escolha errada. \n";
            cin >> choice;
            break;
        }

    }
    return 0;
    }