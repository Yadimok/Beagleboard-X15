################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
build-405984305:
	@$(MAKE) --no-print-directory -Onone -f subdir_rules.mk build-405984305-inproc

build-405984305-inproc: ../app.cfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: XDCtools'
	"/home/dmitrii/ti/ccs910/xdctools_3_55_02_22_core/xs" --xdcpath="/home/dmitrii/ti/bios_6_76_02_02/packages;/home/dmitrii/ti/pdk_am57xx_1_0_16/packages;/home/dmitrii/ti/edma3_lld_2_12_05_30E/packages;/home/dmitrii/ti/ipc_3_50_04_07/packages;" xdc.tools.configuro -o configPkg -t gnu.targets.arm.A15F -p ti.platforms.evmAM572X -r release -c "/home/dmitrii/ti/ccs910/ccs/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major" -DBOARD=evmAM572x "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

configPkg/linker.cmd: build-405984305 ../app.cfg
configPkg/compiler.opt: build-405984305
configPkg/: build-405984305

%.o: ../%.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: GNU Compiler'
	"/home/dmitrii/ti/ccs910/ccs/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major/bin/arm-none-eabi-gcc" -c -mcpu=cortex-a15 -mtune=cortex-a15 -marm -mfloat-abi=hard -Dam5728 -Dcore0 -DSOC_AM572x -DevmAM572x -DUSE_BIOS -I"/home/dmitrii/ti/ccs910/workspace_v9/TestGPIOIsr" -I"/home/dmitrii/ti/bios_6_76_02_02/packages/gnu/targets/arm/libs/install-native/arm-none-eabi/include/newlib-nano" -I"/home/dmitrii/ti/bios_6_76_02_02/packages/ti/posix/gcc" -I"/home/dmitrii/ti/ccs910/ccs/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major/arm-none-eabi/include" -I"/home/dmitrii/ti/pdk_am57xx_1_0_16/packages/ti/board" -I"/home/dmitrii/ti/pdk_am57xx_1_0_16/packages/ti/csl" -I"/home/dmitrii/ti/pdk_am57xx_1_0_16/packages/ti/drv/gpio" -I"/home/dmitrii/ti/pdk_am57xx_1_0_16/packages/ti/drv/uart" -I"/home/dmitrii/ti/pdk_am57xx_1_0_16/packages/ti/drv/i2c" -Og -g -gdwarf-3 -gstrict-dwarf -Wall -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -std=c99 $(GEN_OPTS__FLAG) -o"$@" "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '


