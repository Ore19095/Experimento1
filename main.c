
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/systick.h"

void delay();
void semaforo();


/**
 * main.c
 */
    int main(void){
    // PARTE 2: CONFIGURACION DEL RELOJ
    // configuración del reloj, uso de pll, con divisor de 5, la frecuencia es de 40 MHz
    SysCtlClockSet(SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_SYSDIV_5 | SYSCTL_OSC_MAIN);
    // PARTE 3: configurar los pines como salida
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF); // puerto F
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1| GPIO_PIN_2| GPIO_PIN_3 );
    //PARTE 4:  CONFIGURAR LOS BOTONES SW0 de la tiva


    GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_4);
    GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_4,  GPIO_STRENGTH_8MA, GPIO_PIN_TYPE_STD_WPU);
    int32_t botonActual = 16;
    int32_t botonAnterior = 16;
    while(1){
        // encender y hacer combinacion de cololes
        // color blanco
        //GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2|GPIO_PIN_3  , 255);
        botonAnterior = botonActual;
        botonActual = GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_4);

        if(botonAnterior == 0 && botonActual==16) semaforo();
    }


    return 0;
}

void semaforo(){

    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, 8 ); //SE ENCIENDE EL LED VERDE
    SysCtlDelay(40000000/3);  // delay de 2000000*3/40M
    int i;
    for (i = 0; i<9; i++){
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, 0 ); //SE ENCIENDE APAGA
        SysCtlDelay(10000000/3);
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, 8 ); //SE ENCIENDE EL LED VERDE
        SysCtlDelay(10000000/3);
    }

    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, 10 ); //SE ENCIENDE EL LED ROJO y VERDE PARA HACER AMARILLO
    SysCtlDelay(40000000/3);
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, 2 ); //SE ENCIENDE EL LED ROJO
    SysCtlDelay(40000000/3);


}

// delay
void delay(){
    volatile uint32_t i;
    for(i = 0 ; i<1000000; i++){}
}
