# Modem com Arduino UNO 

### Esse projeto simula a interface de um modem, a qual o usuário interage com. 

Para usar qualquer uma das interfaces implementadas o usuário deve estar conectado. 

por padrão, o login e senha são "admin" 

## Interface IP: 

Permite que usuário veja e modifique seu ip, gateway e mascára da rede. 

Os valores padrões são: 
        IP: 192.168.1.50
        Mascara: 255.0.0.1
        Gateway: 192.168.1.1


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

## Interface do usuário. 

Login e senha padrão: "admin" 

Permite que o usuário altere sua senha e volte-a para o padrão de fábrica (admin)
