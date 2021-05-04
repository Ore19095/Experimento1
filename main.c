#include <stdint.h>
#include <stdbool.h>
#include "driverlib/sysctl.h"


/**
 * main.c
 */
int main(void){
    // PARTE 2: CONFIGURACION DEL RELOJ
    // configuración del reloj, uso de pll, con divisor de 5, la frecuencia es de 40 MHz
    SysCtlClockSet(SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_SYSDIV_4 | SYSCTL_OSC_MAIN);
    // PARTE 3: configurar los pines como salida




	return 0;
}
