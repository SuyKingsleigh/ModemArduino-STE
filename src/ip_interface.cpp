#include "ip_interface.h"

// ***************************** IP **********************************************//


Ip::Ip(){
    this->ip_addr = IPDEFAULT;
    this->mask_addr = MASKDEFAULT;
    this->gw_addr = GWDEFAULT;
}

Ip::Ip(string ip_addr){
    this->ip_addr = ip_addr;
    this->mask_addr = MASKDEFAULT;
    this->gw_addr = GWDEFAULT;
}
Ip::Ip(string ip_addr, string mask_addr){
    this->ip_addr = ip_addr;
    this->mask_addr = mask_addr;
    this->gw_addr = GWDEFAULT;
}

Ip::Ip(string ip_addr, string mask_addr, string gw_addr){
    this->ip_addr = ip_addr;
    this->mask_addr = mask_addr;
    this->gw_addr = gw_addr;
}

// método para auxiliar a validar o IP
bool Ip::isNumber(const string& str)
{
    return !str.empty() &&
        (str.find_first_not_of("[0123456789]") == std::string::npos);
}

// método para separar a string recebida para conseguir validar(fazer o check)
vector<string> Ip::split(const string& str, char delim)
{
	auto i = 0;
	vector<string> list;

	auto pos = str.find(delim);

	while (pos != string::npos)
	{
		list.push_back(str.substr(i, pos - i));
		i = ++pos;
		pos = str.find(delim, pos);
	}

	list.push_back(str.substr(i, str.length()));

	return list;
}


// Verifica se o endereço IP digita é válido
bool Ip::check(string addr){

	vector<string> list = split(addr, '.');

	// if token size is not equal to four
	if (list.size() != 4)
		return false;

	// validate each token
	for (string str : list)
	{
		// verify that string is number or not and the numbers
		// are in the valid range
		if (!isNumber(str) || stoi(str) > 255 || stoi(str) < 0)
			return false;
	}
	return true;
}    

// seta um IP estático no modem
bool Ip::set_ip_addr_static(string addr){

    if(this->check(addr)==true){
        this->ip_addr = addr;
        return true;
    }else{
        return false;
    }

}

// seta uma máscara estática no modem
bool Ip::set_mask_addr_static(string addr){

    if(this->check(addr)==true){
        this->mask_addr = addr;
        return true;
    }else{
        return false;
    }

}

// seta um gateway estático no modem
bool Ip::set_gw_addr_static(string addr){

    if(this->check(addr)==true){
        this->gw_addr = addr;
        return true;
    }else{
        return false;
    }
}

// Define um endereço com todas as informações para o Modem
bool Ip::set_ip_full_static(string ip_addr, string mask_addr, string gw_addr){

    if(this->check(ip_addr)==true && this->check(mask_addr)==true && this->check(gw_addr)==true){
        this->ip_addr = ip_addr;
        this->mask_addr = mask_addr;
        this->gw_addr = gw_addr;
        return true;
    }else{
        return false;
    }
}

string Ip::get_ip_addr(){
    return this->ip_addr;
}

string Ip::get_mask_addr(){
    return this->mask_addr;
}

string Ip::get_gw_addr(){
    return this->gw_addr;
}



// **************** IP INTERFACE ********************************************* //


IpInterface::IpInterface(){
    this->ip = Ip();
}


void IpInterface::show_menu(){ 
    print("\n[1] para mostrar o endereço IP \n[2] para alterar o IP\n[3] para alterar a Máscara\n[4] para alterar o Gateway\n[5] para alterar tudo \n");

    switch (read()) {
        case 1:
            this->print_ip();
            break;
        case 2:
            this->update_ip();
            break; 
         case 3:
            this->update_mask();
            break; 
        case 4:
            this->update_gw();
            break; 
        case 5:
            this->update_all_fields();                

        default:
            break;
    }
}

void IpInterface::print_ip(){ 
    print("seu endereço IP é: \n");
    print("IP: " +this->ip.get_ip_addr()+"\n"+"Máscara: "+this->ip.get_mask_addr()+"\n"+"Gateway: "+this->ip.get_gw_addr()+"\n");
}

void IpInterface::update_ip(){ 

    print("Digite o novo endereço IP, deve ter o seguinte formato: 10.10.10.10\n"); 
    string user_input; 
    cin >> user_input; 

    if(this->ip.set_ip_addr_static(user_input)){
        print("Endereço IP trocado com sucesso, novo endereço é: \n");
        print(this->ip.get_ip_addr());
    }
}

void IpInterface::update_mask(){ 

    print("Digite a nova máscara de rede, deve ter o seguinte formato: 255.0.0.0\n"); 
    string user_input; 
    cin >> user_input; 

    if(this->ip.set_mask_addr_static(user_input)){
        print("Máscara de rede trocada com sucesso, nova máscara é: \n");
        print(this->ip.get_mask_addr());
    }
}

void IpInterface::update_gw(){

    print("Digite o novo Gateway, deve ter o seguinte formato: 10.10.10.1\n"); 
    string user_input; 
    cin >> user_input; 

    if(this->ip.set_gw_addr_static(user_input)){
        print("Gateway trocado com sucesso, novo Gateway é: \n");
        print(this->ip.get_gw_addr());
    }      
}

void IpInterface::update_all_fields(){ 
    print("Digite o novo endereço, deve ter o seguinte formato: 10.10.10.10 255.255.255.0 10.10.10.1\n"); 
    string user_input1, user_input2, user_input3; 
    cin >> user_input1 >> user_input2 >> user_input3; 

    if(this->ip.set_ip_addr_static(user_input1)&&this->ip.set_ip_addr_static(user_input2)&&this->ip.set_ip_addr_static(user_input3)){
        this->ip.set_ip_addr_static(user_input1);
        this->ip.set_mask_addr_static(user_input2);
        this->ip.set_gw_addr_static(user_input3);   
        print("Endereço alterado, novo endereço é:  \n");
        print("IP: " +this->ip.get_ip_addr()+"\n"+"Máscara: "+this->ip.get_mask_addr()+"\n"+"Gateway: "+this->ip.get_gw_addr());
    }      
}
