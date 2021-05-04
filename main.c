#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/debug.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"

/**
 * main.c
 */
int main(void){
    // PARTE 2: CONFIGURACION DEL RELOJ
    // configuración del reloj, uso de pll, con divisor de 5, la frecuencia es de 40 MHz
    SysCtlClockSet(SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_SYSDIV_5 | SYSCTL_OSC_MAIN);
    // PARTE 3: configurar los pines como salida
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF); // puerto F
    GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_1| GPIO_PIN_2| GPIO_PIN_3 );





	return 0;
}
