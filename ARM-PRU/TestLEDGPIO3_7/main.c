#include <string.h>
#include <stdint.h>
#include "pru_cfg.h"

volatile register uint32_t __R30; //gpo
volatile register uint32_t __R31; //gpi


int main(void)
{
    CT_CFG.GPCFG0 = 0;
    CT_CFG.SYSCFG_bit.STANDBY_INIT = 0;

    int idx;
    unsigned int *addr = (unsigned int *)0x80006000;

    volatile uint32_t readen = 0;
    volatile uint32_t value = 0;

    while(1)
    {
        readen = (*(volatile uint32_t *)0x48057138);// DATAIN
        __delay_cycles(1);
        if ((readen & 0x80) == 0x80)
        {
            *(volatile uint32_t *)0x48057194 = 0x200; //SET
            value = (*(volatile uint32_t *)0x48057138) & 0x100;
            __delay_cycles(1);
            *addr = value;
            addr++;
            *(volatile uint32_t *)0x48057190 = 0x200; //CLEAR
        }
    }
    __halt();
}
