
#include <avr/io.h>
#include "AVR_Ports.h"
#include "AVR_GPIO_Declarations.h"
#include "AVR_UART_Declarations.h"
#define F_CPU 4000000ul

int main(void)
{
	Pin_Direction(B, 0, input);
	UART_INT();

    while (1) 
    {
		if(Pin_Read(B, 0) == 0)
		{
			UART_Transmit('1');
			while((Pin_Read(B, 0)) == 0) ; //don't toggle while the press in still on (only one toggle per press)
		}
    }
}
