/* XDCtools Header files */
#include <xdc/std.h>
#include <xdc/runtime/System.h>
#include <stdio.h>
#include <stdbool.h>
#include <ti/sysbios/knl/Task.h>

/* BIOS Header files */
#include <ti/sysbios/BIOS.h>
#include <xdc/runtime/Error.h>

/* TI-RTOS Header files */
#include <ti/csl/cslr_device.h>
#include <ti/fs/fatfs/example/console/src/FATFS_log.h>
#include <ti/fs/fatfs/example/console/src/fs_shell_app_utils.h>

#include <ti/fs/fatfs/diskio.h>
#include <ti/fs/fatfs/FATFS.h>
#include <ti/drv/mmcsd/MMCSD.h>

#include <ti/board/board.h>
#include <ti/drv/gpio/GPIO.h>
#include <ti/drv/gpio/soc/GPIO_soc.h>
#include <ti/sdo/edma3/drv/edma3_drv.h>

#include <ti/drv/vps/include/osal/bsp_osal.h>

#define MMCSD_INSTANCE_MMCSD            (0U)
#define MMCSD_INSTANCE_EMMC             (1U)

#define GPIO_PIN_VAL_LOW                (0U)
#define GPIO_PIN_VAL_HIGH               (1U)



/* ON Board LED pins which are connected to GPIO pins. */
typedef enum GPIO_PIN {
    GPIO_PIN_MMC_SDCD      = 0U,
    GPIO_PIN_COUNT
}GPIO_PIN;

/* GPIO Driver board specific pin configuration structure */
GPIO_PinConfig gpioPinConfigs[] = {
                                   /* Output pin : AM335X_ICE V2_LD_PIN */
                                   GPIO_DEVICE_CONFIG(GPIO_MMC_SDCD_PORT_NUM, GPIO_MMC_SDCD_PIN_NUM) |
                                   GPIO_CFG_IN_INT_BOTH_EDGES | GPIO_CFG_INPUT,
};

/* GPIO Driver call back functions */
GPIO_CallbackFxn gpioCallbackFunctions[] = {
                                            NULL,
};

/* GPIO Driver configuration structure */
GPIO_v1_Config GPIO_v1_config = {
                                 gpioPinConfigs,
                                 gpioCallbackFunctions,
                                 sizeof(gpioPinConfigs) / sizeof(GPIO_PinConfig),
                                 sizeof(gpioCallbackFunctions) / sizeof(GPIO_CallbackFxn),
                                 0,
};



/* MMCSD function table for MMCSD implementation */
FATFS_DrvFxnTable FATFS_drvFxnTable = {
                                       MMCSD_close,
                                       MMCSD_control,
                                       MMCSD_init,
                                       MMCSD_open,
                                       MMCSD_write,
                                       MMCSD_read
};

/* FATFS configuration structure */
FATFS_HwAttrs FATFS_initCfg[_VOLUMES] =
{
 {
  0U
 },
 {
  1U
 },
 {
  2U
 },
 {
  3U
 }
};

/* FATFS objects */
FATFS_Object FATFS_objects[_VOLUMES];

/* FATFS configuration structure */
const FATFSConfigList FATFS_config = {
                                      {
                                       &FATFS_drvFxnTable,
                                       &FATFS_objects[0],
                                       &FATFS_initCfg[0]
                                      },

                                      {
                                       &FATFS_drvFxnTable,
                                       &FATFS_objects[1],
                                       &FATFS_initCfg[1]
                                      },

                                      {
                                       &FATFS_drvFxnTable,
                                       &FATFS_objects[2],
                                       &FATFS_initCfg[2]
                                      },

                                      {NULL, NULL, NULL},

                                      {NULL, NULL, NULL}
};

FATFS_Handle fatfsHandle = NULL;


Uint32 fatfsShellProcessFlag = 0;
Uint32 fs_media_needs_initialization=0;
Uint32 fs_media_needs_close=0;

static char fileName[] = "test.dat";
UInt32 bytesWritten;
int idx = 0, retVal = 0;

#define SIZE_ARRAY_64KB     (64 * 1024)
#define SIZE_ARRAY_512KB    (512 * 1024)
#define SIZE_ARRAY_1MB      (1024 * 1024)
#define SIZE_ARRAY_4MB      (4 * 1024 * 1024)
#define SIZE_ARRAY_8MB      (8 * 1024 * 1024)
#define SIZE_ARRAY_16MB     (16 * 1024 * 1024)
#define SIZE_ARRAY_24MB     (24 * 1024 * 1024)
#define SIZE_ARRAY_32MB     (32 * 1024 * 1024)
#define SIZE_ARRAY_40MB     (40 * 1024 * 1024)
#define SIZE_ARRAY_48MB     (48 * 1024 * 1024)

char data[SIZE_ARRAY_1MB];

/* Callback function */
void AppGpioCallbackFxn(void);

void fatfs_console()
{
    FIL     fp;
    FRESULT fresult = FR_OK;

    const int chunk = 512;
    int remainder = 0;
    int total_bytes = 0;
    int N = SIZE_ARRAY_1MB;
    int counter_written = 0;


    /* GPIO initialization */
    GPIO_init();

    /* Set the callback function */
    GPIO_setCallback(GPIO_PIN_MMC_SDCD, AppGpioCallbackFxn);

    /* Enable GPIO interrupt on the specific gpio pin */
    GPIO_enableInt(GPIO_PIN_MMC_SDCD);

    /* MMCSD FATFS initialization */
    FATFS_init();
    if (GPIO_PIN_MMC_SDCD_ACTIVE_STATE == GPIO_read(GPIO_PIN_MMC_SDCD))
    {
        FATFS_open(MMCSD_INSTANCE_MMCSD, NULL, &fatfsHandle);
        fatfsShellProcessFlag = 1;
        fs_is_media_inserted = 1;

    }
    else
    {
        FATFS_log ("\nPlease insert card.\r\n");
        fs_is_media_inserted = 0;
    }

    while(1)
    {
        if(fs_media_needs_initialization) {

            FATFS_log("\nMedia Inserted..Initializing..\n");
            FATFS_open(MMCSD_INSTANCE_MMCSD, NULL, &fatfsHandle);
            fatfsShellProcessFlag = 1;
            fs_media_needs_initialization=0;
        }

        if(fs_media_needs_close) {
            FATFS_close(fatfsHandle);
            fatfsShellProcessFlag = 0;
            fs_media_needs_close=0;
            FATFS_log("\nMedia Removed..Please insert media..\n");
        }

        if (0 != fatfsShellProcessFlag)
        {
            fresult = f_open(&fp, fileName, (BYTE) FA_CREATE_NEW);
            if (fresult != FR_OK)
            {
                FATFS_log("\r\n File create failed. File exists\r\n");
                fresult = f_unlink(fileName);
                if (fresult != FR_OK)
                {
                    FATFS_log("\r\n File create failed\r\n");
                }
                else
                {
                    fresult = f_open(&fp, fileName, (BYTE) FA_CREATE_NEW);
                    if (fresult != FR_OK)
                    {
                        FATFS_log("\r\n File create failed\r\n");
                    }
                    else
                    {
                        f_close(&fp);
                        fresult = f_open(&fp, fileName, FA_OPEN_ALWAYS | FA_WRITE);
                        FATFS_log("\r\n File created\r\n");
                    }
                }
            }
            else
            {
                f_close(&fp);
                fresult = f_open(&fp, fileName, FA_OPEN_ALWAYS | FA_WRITE);
                FATFS_log("\r\n File created\r\n");
            }
            FATFS_log("Saving buffer to file %s in Sd Card \r\n", fileName);
            while (N > 0)
            {
                if (N < chunk) {
                    total_bytes += N;
                    remainder = N;
                    N -= N;
                } else {
                    total_bytes += chunk;
                    N -= chunk;
                    remainder = chunk;
                }

                fresult   = f_write(&fp, &data[total_bytes], remainder, &bytesWritten);
                counter_written++;
                if (fresult != FR_OK)
                {
                    FATFS_log("\r\n Chunk write failed \r\n");
                }
                else
                {
                    FATFS_log("Size chunk %d written, counter_written %d\r\n", remainder, counter_written);
                };

                fresult = f_sync(&fp);
                if (fresult)
                    break;
            }

            if (fresult != FR_OK)
            {
                FATFS_log("\r\n File write failed \r\n");
            }
            else
            {
                FATFS_log("File written \r\n");
            }

            f_close(&fp);

            fatfsShellProcessFlag = 0;

        }
    }
}


int main(void)
{
    /* Call board init functions */
    Board_initCfg boardCfg;
    boardCfg = BOARD_INIT_PINMUX_CONFIG | BOARD_INIT_UART_STDIO | BOARD_INIT_MODULE_CLOCK;

    Board_init(boardCfg);


    for (idx=0; idx<SIZE_ARRAY_1MB; idx++) {
        data[idx] = '2';
    }

    fatfs_console();

    /* Start BIOS */
    BIOS_start();

    return (0);
}

/*
 *  ======== Callback function ========
 */
void AppGpioCallbackFxn(void)
{
    if (GPIO_PIN_MMC_SDCD_ACTIVE_STATE == GPIO_read(GPIO_PIN_MMC_SDCD))
    {
        fs_is_media_inserted=1; /* The media has been inserted now */
        fs_media_needs_initialization=1; /* Need to initialize FATFS with the media */
    }
    else
    {
        fs_is_media_inserted=0;/*  The media has been ejected now */
        fs_media_needs_close=1; /* Need to close FATFS with the media */
    }
}
