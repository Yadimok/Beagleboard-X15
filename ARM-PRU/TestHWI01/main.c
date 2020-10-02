
#include <xdc/std.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/System.h>
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#include <xdc/std.h>
#include <xdc/cfg/global.h>
#include <xdc/runtime/System.h>
#include <ti/drv/pruss/pruicss.h>
#include <ti/drv/pruss/test/src/test_pruss_intc_mapping.h>
#include <ti/drv/pruss/test/src/pru_firmware/pruss_test_pru0_bin.h>

#include <ti/board/board.h>
#include <ti/csl/csl_clec.h>
#include <ti/csl/csl_gpio.h>
#include <ti/csl/example/utils/uart_console/inc/uartConfig.h>
#include <ti/csl/soc.h>
#include <ti/csl/hw_types.h>

/* BIOS Header files */
#include <ti/sysbios/BIOS.h>

uint32_t gpio_base_address3 = CSL_MPU_GPIO3_REGS;
uint32_t gpio_pin3[] = {7, 8, 9};


extern unsigned int TestLEDGPIO3_7_image_0[54];

unsigned int *memValue;


/*
 *  ======== taskFxn ========
 */
Void taskFxn(UArg a0, UArg a1);

/*
 *  ======== main ========
 */
Int main()
{
    Board_initCfg boardCfg;

    boardCfg = BOARD_INIT_PINMUX_CONFIG | BOARD_INIT_DDR |
            BOARD_INIT_MODULE_CLOCK | BOARD_INIT_ICSS_PINMUX |
            BOARD_INIT_UART_STDIO;

    Board_init(boardCfg);

    /*Enable GPIO3 clock*/
    HW_WR_REG32(CSL_MPU_L4PER_CM_CORE_REGS+CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO3_CLKCTRL_REG,0x102);
    while ((HW_RD_REG32(CSL_MPU_L4PER_CM_CORE_REGS+CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO3_CLKCTRL_REG) & (0x00030000U)) != 0x0)
    {
        ;
    }

    GPIOModuleReset(gpio_base_address3);
    GPIOModuleEnable(gpio_base_address3);

    GPIOIntTypeSet(gpio_base_address3, gpio_pin3[0], GPIO_INT_TYPE_RISE_EDGE);

    /*Set pin direction*/
    GPIODirModeSet(gpio_base_address3, gpio_pin3[0], GPIO_DIR_INPUT);
    GPIODirModeSet(gpio_base_address3, gpio_pin3[1], GPIO_DIR_INPUT);
    GPIODirModeSet(gpio_base_address3, gpio_pin3[2], GPIO_DIR_OUTPUT);

    GPIOPinWrite(gpio_base_address3, gpio_pin3[0], 0);
    GPIOPinWrite(gpio_base_address3, gpio_pin3[1], 0);
    GPIOPinWrite(gpio_base_address3, gpio_pin3[0], 0);


    Task_Handle task;
    Error_Block eb;

    Error_init(&eb);
    task = Task_create(taskFxn, NULL, &eb);
    if (task == NULL) {
        System_printf("Task_create failed\n");
        BIOS_exit(0);
    }

    BIOS_start();    /* does not return */
    return(0);
}

Void taskFxn(UArg a0, UArg a1)
{
    PRUICSS_Config  *pruss_config = NULL;
    PRUICSS_Handle handle;

    int32_t ret  = PRUICSS_socGetInitCfg(&pruss_config);
    if (ret  != PRUICSS_RETURN_SUCCESS)
    {
        System_abort("main: PRUICSS_socGetInitCfg returned error \n");
    }

    handle = PRUICSS_create(pruss_config, PRUICCSS_INSTANCE_ONE);
    if (handle == NULL)
    {
        System_abort("main: PRUICSS_create returned error \n");
    }

    if (PRUICSS_pruDisable(handle,0) != 0)
    {
        System_abort("main: PRUICSS_pruDisable returned error \n");
    }

    if (PRUICSS_setPRUBuffer(handle,0, (void*)TestLEDGPIO3_7_image_0, sizeof(TestLEDGPIO3_7_image_0)) != 0)
    {
        System_abort("main: PRUICSS_setPRUBuffer returned error \n");
    }

    PRUICSS_enableOCPMasterAccess(handle);


    if (PRUICSS_pruExecProgram(handle,0) != 0)
    {
        System_abort("main: PRUICSS_pruExecProgram returned error \n");
    }

    if (PRUICSS_pruEnable(handle,0) != 0)
    {
        System_abort("main: PRUICSS_pruEnable returned error \n");
    }

    memValue = (unsigned int *)0x80006000;
}
