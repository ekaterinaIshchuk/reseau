#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

#include "serial.h"
#include "ethernet.h"
#include "w5100.h"
#include "socket.h"

#define MAC_SIZE	6
#define IPV4_SIZE	4

int main(void)
{
    init_printf();
    // Your code here !!

    // init constants
    // socket =>[ (in while) recieveFrom => sentTo ]

    // => init (input(pin), output (leds), spiO_init + ethernet)

    // define socket variables
    SOCKET s;
    uint8 protocol;
    uint16 port;
    unit8 flag;

    //define ethernet

    uint8_t mac;
    uint8_t ip;
    uint8_t gateway;
    uint8_t mask;

    //define recvfrom
    uint8* buf;
    uint16 len;
    uint8* addr;
    uint16* port;

    // buf = tableau 5 octet
    // 2 octets = valeurs de capteurs
    // 2 octets = mot magique
    // 1 octet = numero capter = groupe 
    uint16_t pollution;
    uint8 table[5];
    // socket d'écoute
    // socket de dialogues = nombre des clients

    uint8 definedSocket = socket(s, protocol, port, flag);
    table[2] = 0x78; // nmot magique "X"
    table[3] = 0x07; // mot magique "7"
    table[4] = 0x06; // numero groupe "6"

    while (1) {
        if (recvfrom(definedSocket, buf, 1, addr, port)) { // PC qui est client
            pollution = (uint16_t)ad_sample();
            table[0] = pollution & 0xff;
            table[1] = (pollution >> 8);
            // unit8 mot magiqr => X7
            sendto(definedSocket, table, 5, addr, port);
        }

    }


    return 0;
}

void configuration() {
    ad_init(0x06);
    output_init();
    SPI0_Init();
    ethernet_init(mac, ip, gateway, mask);   
}
