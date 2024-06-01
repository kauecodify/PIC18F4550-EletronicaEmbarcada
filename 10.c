#include <xc.h> // inclui a biblioteca para o microcontrolador PIC
#include <stdint.h> // inclui a biblioteca para tipos de dados inteiros

#define _XTAL_FREQ 4000000 // frequência do oscilador (4MHz)

// definições dos pinos e botões
#define S1 PORTBbits.RB0
#define S2 PORTBbits.RB1
#define LED1 PORTCbits.RC0
#define LED2 PORTCbits.RC1

// função de inicialização
void init() {
    TRISB = 0b00000011; // configura RB0 e RB1 como entradas (botões)
    TRISC = 0b00000000; // configura RC0 e RC1 como saídas (LEDs)
}

// função para aguardar um determinado número de milissegundos
void delay_ms(uint16_t milliseconds) {
    for (uint16_t i = 0; i < milliseconds; i++) {
        __delay_ms(1); // espera 1 milissegundo
    }
}

// função principal
void main() {
    init(); // inicializa o sistema
    
    while (1) {
        // quando acionado o botão S1
        if (S1) {
            // liga o LED1, espera 2 segundos e desliga
            LED1 = 1;
            delay_ms(2000);
            LED1 = 0;

            // liga o LED2, espera 3 segundos e desliga
            LED2 = 1;
            delay_ms(3000);
            LED2 = 0;
        }
        
        // enquanto pressionado o botão S2
        while (S2) {
            // faz o LED1 piscar (1 segundo ligado e 1 segundo desligado)
            LED1 = !LED1;
            delay_ms(1000);
        }
        
        // quando acionado os botões S1 e S2
        if (S1 && S2) {
            // desliga ambos os LEDs
            LED1 = 0;
            LED2 = 0;
        }
    }
}
