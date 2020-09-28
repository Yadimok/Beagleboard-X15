/* XDCtools Header files */
#include <xdc/std.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/Error.h>

/* BIOS Header files */
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/hal/Hwi.h>

#include <stdio.h>
#include <string.h>

/* TI-RTOS Header files */
#include <ti/drv/gpio/GPIO.h>
#include <ti/drv/gpio/soc/GPIO_soc.h>

#include <ti/board/board.h>
#include <ti/csl/csl_clec.h>
#include <ti/csl/csl_gpio.h>
#include <ti/csl/example/utils/uart_console/inc/uartConfig.h>
#include <ti/csl/soc.h>
#include <ti/csl/hw_types.h>

/* Callback function */
void AppGpioCallbackFxn();

uint32_t gpio_base_address=CSL_MPU_GPIO2_REGS;
uint32_t gpio_pin[2] = {25, 28};

/*
 *  ======== main ========
 */
int main(void)
{
    Board_initCfg boardCfg;

    boardCfg = BOARD_INIT_PINMUX_CONFIG |
            BOARD_INIT_MODULE_CLOCK |
            BOARD_INIT_UART_STDIO;

    Board_init(boardCfg);

    /*Enable GPIO clock*/
    HW_WR_REG32(CSL_MPU_L4PER_CM_CORE_REGS+CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO2_CLKCTRL_REG,0x102);
    while ((HW_RD_REG32(CSL_MPU_L4PER_CM_CORE_REGS+CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO2_CLKCTRL_REG) & (0x00030000U)) != 0x0)
    {
        ;
    }

    /*Reset GPIO*/
    GPIOModuleReset(gpio_base_address);

    /*Enable GPIO*/
    GPIOModuleEnable(gpio_base_address);

    GPIOIntTypeSet(gpio_base_address, gpio_pin[0], GPIO_INT_TYPE_RISE_EDGE);

    /*Set pin direction*/
    GPIODirModeSet(gpio_base_address, gpio_pin[0], GPIO_DIR_INPUT); //25 - input
    GPIODirModeSet(gpio_base_address, gpio_pin[1], GPIO_DIR_OUTPUT); //28 - output

    /*Clear interrupt*/
    GPIOPinIntDisable(gpio_base_address, GPIO_INT_LINE_1, gpio_pin[0]);

    GPIOPinIntClear(gpio_base_address, GPIO_INT_LINE_1, gpio_pin[0]);

    /*Enable interrupt*/
    GPIOPinIntEnable(gpio_base_address, GPIO_INT_LINE_1, gpio_pin[0]);

    GPIOPinWrite(gpio_base_address, gpio_pin[0], GPIO_PIN_LOW);
    GPIOPinWrite(gpio_base_address, gpio_pin[1], GPIO_PIN_LOW);


    Hwi_Params hwiParams;
    Hwi_Handle hwiHandle;
    Error_Block eb;

    Hwi_Params_init(&hwiParams);
    Error_init(&eb);

    hwiParams.eventId = 62; //MPU_IRQ_30(ID62)25
    hwiParams.arg = 0;
    hwiParams.maskSetting = Hwi_MaskingOption_SELF;
    hwiParams.enableInt = FALSE;
    hwiHandle = Hwi_create(62, AppGpioCallbackFxn, &hwiParams, &eb);
    if (hwiHandle == NULL) {
        System_abort("Hwi create failed\n");
    }
    Hwi_enable();
    Hwi_enableInterrupt(62);


    /* Start BIOS */
    BIOS_start();
    return (0);
}

void AppGpioCallbackFxn()
{
    GPIOPinWrite(gpio_base_address, gpio_pin[1], GPIO_PIN_HIGH);

    /*Disable interrupt*/
    GPIOPinIntDisable(gpio_base_address, GPIO_INT_LINE_1, gpio_pin[0]);

    GPIOPinIntClear(gpio_base_address, GPIO_INT_LINE_1, gpio_pin[0]);

    /*Enable interrupt interrupt*/
    GPIOPinIntEnable(gpio_base_address, GPIO_INT_LINE_1, gpio_pin[0]);

    GPIOPinWrite(gpio_base_address, gpio_pin[1], GPIO_PIN_LOW);
}
