# Modem com Arduino UNO 

Esse projeto tem a intenção de simular uma interface de um modem,  a qual o usuário pode interage com o Arduino.   Antes de conseguir fazer qualquer alteração no Modem,  o usuário é obrigado a se logar nele.   Assim que conseguir logar,  ele poderá fazer alterações na InterfaceMAC, Interface IP, Interface Channels e na Interface de usuário, como é mostrado abaixo.

![Inicial](Relatorio/inicial.png)

## Interface do usuário. 

Essa interface gerencia o acesso do usuário ao Modem. No primeiro acesso o usuário deve acessar usando usuário:"admin" e senha: "admin. Após o primeiro acesso ele tem as seguintes opções para serem alteradas: 

![Usuario](Relatorio/usuario.png)

Os metódos implementados para essas opções, são os abaixo.
```C
String get_username();
// Alterar a senha de acesso ao modem
bool set_newPassword(String &newPwd);
// Volta a senha para o padrão de fábrica        
void resetPassword();
// validar credencias do usuario
bool log_in(String &user,String &pwd);
// retorna caso o usuario esteja autenticado
bool is_authenticated(); 
```


## Interface IP: 

A função dessa interface é possibilitar ao usuário configurar um endereço IPV4 no Modem.
Assim que o usuário estiver logado no Modem, e optar por alterar as configurações da Interface IP, ele terá as seguintes opções:

![IP](Relatorio/OP_IP.png)
Para isso, o programa faz uso dos seguintes métodos: 

```C
// para ip estático
bool set_ip_addr_static(String addr); 
// para máscara estática
bool set_mask_addr_static(String mask_addr); 
// para gateway estático
bool set_gw_addr_static(String gw_addr); 
//Alterar todos os campos
bool set_ip_full_static(String ip_addr, String mask_addr, String gw_addr);
// retorna endereço IP
String get_ip_addr(); 
// retorna a máscara
String get_mask_addr(); 
// retorna o gateway
String get_gw_addr(); 
```




## Interface MAC: 

Permite que o usuário veja e modifique seu endereço MAC. 
O valor padrão é gerado aleatóriamente. 

## Interface dos Canais: 

Cria 11 canais, permitindo que o usuário aloque-os e os desaloque. 

Os valores padrões são: 
        Numero de canais: 11
        Largura de banda 22MHz 
        Frequência central inicial: 2412MHz

Para cada canal a frequência central aumenta em 5MHz.

## Conclusões

Na implementação encontramos um problema relacionado ao consumo de memória RAM, por ser um programa puramente textual, usamos muito a classe String, que acabou aumentando muito o processamento, chegando a 2300 bytes, impossibilitando de rodar no Arduino Uno. Com isso, encontramos uma função chamada F() que remove a String da RAM e joga para memória flash, fazendo assim, com que se tenha uma grande melhorá no desempenho. Com uso dessa função, juntamente com o uso de ponteiros para alguns objetos, o consumo da RAM caiu para 370 bytes.


## Demonstração do aplicativo em execução

Video

