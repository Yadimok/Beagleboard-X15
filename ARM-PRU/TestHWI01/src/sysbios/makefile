#  This is a generated file.
#
#  Do not edit this file. Any modifications to this file
#  will be overwritten whenever makefiles are re-generated.
#
#  template: ti.sysbios/makefile_gccArmLto.xdt
#  target: gnu.targets.arm.A15F

vpath % /home/dmitrii/ti/bios_6_76_03_01/packages/ti/sysbios/
vpath %.c /home/dmitrii/ti/ccs1000/xdctools_3_61_00_16_core/packages/

XOPTS = -I"/home/dmitrii/ti/ccs1000/xdctools_3_61_00_16_core/packages/" -Dxdc_target_types__=/home/dmitrii/ti/bios_6_76_03_01/packages/gnu/targets/arm/std.h -Dxdc_target_name__=A15F

BIOS_DEFS =  -Dti_sysbios_BIOS_swiEnabled__D=TRUE -Dti_sysbios_BIOS_taskEnabled__D=TRUE -Dti_sysbios_BIOS_clockEnabled__D=TRUE -Dti_sysbios_BIOS_runtimeCreatesEnabled__D=TRUE -Dti_sysbios_knl_Task_moduleStateCheckFlag__D=FALSE -Dti_sysbios_knl_Task_objectCheckFlag__D=FALSE -Dti_sysbios_hal_Hwi_DISABLE_ALL_HOOKS -Dti_sysbios_knl_Swi_DISABLE_ALL_HOOKS -Dti_sysbios_BIOS_smpEnabled__D=FALSE -Dti_sysbios_BIOS_mpeEnabled__D=FALSE -Dti_sysbios_Build_useHwiMacros -Dti_sysbios_knl_Swi_numPriorities__D=16 -Dti_sysbios_knl_Task_deleteTerminatedTasks__D=FALSE -Dti_sysbios_knl_Task_numPriorities__D=16 -Dti_sysbios_knl_Task_checkStackFlag__D=TRUE -Dti_sysbios_knl_Task_initStackFlag__D=TRUE -Dti_sysbios_knl_Clock_TICK_SOURCE=ti_sysbios_knl_Clock_TickSource_TIMER -Dti_sysbios_knl_Clock_TICK_MODE=ti_sysbios_knl_Clock_TickMode_PERIODIC -Dti_sysbios_hal_Core_delegate_getId=ti_sysbios_family_arm_a15_Core_getId__E -Dti_sysbios_hal_Core_delegate_interruptCore=ti_sysbios_family_arm_a15_Core_interruptCore__E -Dti_sysbios_hal_Core_delegate_lock=ti_sysbios_family_arm_a15_Core_lock__E -Dti_sysbios_hal_Core_delegate_unlock=ti_sysbios_family_arm_a15_Core_unlock__E -Dti_sysbios_hal_Core_numCores__D=1 -Dti_sysbios_family_arm_a15_Core_numCores__D=1 -Dti_sysbios_utils_Load_taskEnabled__D=TRUE -Dti_sysbios_utils_Load_swiEnabled__D=FALSE -Dti_sysbios_utils_Load_hwiEnabled__D=FALSE -Dti_sysbios_family_arm_gic_Hwi_dispatcherSwiSupport__D=TRUE -Dti_sysbios_family_arm_gic_Hwi_dispatcherTaskSupport__D=TRUE -Dti_sysbios_family_arm_gic_Hwi_dispatcherAutoNestingSupport__D=TRUE -Dti_sysbios_family_arm_gic_Hwi_dispatcherIrpTrackingSupport__D=TRUE -Dti_sysbios_knl_Semaphore_supportsEvents__D=FALSE -Dti_sysbios_knl_Semaphore_supportsPriority__D=TRUE 

CCOPTS = -Wunused -Wunknown-pragmas -ffunction-sections -fdata-sections  -mcpu=cortex-a15 -mfpu=neon -mfloat-abi=hard -mabi=aapcs -g  -O3 -Dfar= -D__DYNAMIC_REENT__   -Dti_sysbios_rts_gnu_ReentSupport_enableReentSupport__D=TRUE -Dti_sysbios_family_arm_exc_Exception_enableDecode__D=TRUE -Dti_sysbios_family_arm_gic_Hwi_enableSecureMode__D=FALSE -Dti_sysbios_family_arm_gic_Hwi_enableAsidTagging__D=FALSE -Dti_sysbios_knl_Clock_stopCheckNext__D=FALSE -Dti_sysbios_hal_Core_numCores__D=1 -Dti_sysbios_family_arm_gic_Hwi_initGicd__D=TRUE -Dti_sysbios_family_arm_a15_Cache_errata798870__D=TRUE -Dti_sysbios_knl_Task_minimizeLatency__D=FALSE

BIOS_INC = -I"/home/dmitrii/ti/bios_6_76_03_01/packages/"
ANNEX_INCS = 
INCS = $(BIOS_INC) $(ANNEX_INCS) -I"/home/dmitrii/ti/bios_6_76_03_01/packages/" -I"/home/dmitrii/ti/pdk_am57xx_1_0_17/packages/" -I"/home/dmitrii/ti/edma3_lld_2_12_05_30E/packages/" -I"/home/dmitrii/ti/ipc_3_50_04_08/packages/" -I"/home/dmitrii/ti/uia_2_30_01_02/packages/" -I"/home/dmitrii/ti/ndk_3_61_01_01/packages/" -I"/home/dmitrii/ti/ccs1000/xdctools_3_61_00_16_core/packages/" -I"../" -I"/packages//"  -I/home/dmitrii/ti/bios_6_76_03_01/packages/gnu/targets/arm//libs/install-native/arm-none-eabi/include/newlib-nano -I/home/dmitrii/ti/bios_6_76_03_01/packages/gnu/targets/arm//libs/install-native/arm-none-eabi/include

CC = /home/dmitrii/ti/ccs910/ccs/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major/bin/arm-none-eabi-gcc -c -MD -MF $@.dep $(CCOPTS)
ASM = /home/dmitrii/ti/ccs910/ccs/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major/bin/arm-none-eabi-gcc -c -x assembler-with-cpp $(CCOPTS)
AR = /home/dmitrii/ti/ccs910/ccs/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major/bin/arm-none-eabi-ar cr

DEL = rm -f
CP = cp -f

define RM
	$(if $(wildcard $1),$(DEL) $1,:)
endef

define ASSEMBLE
	@echo asma15fg $< ...
	@$(ASM) $(BIOS_DEFS) $(XOPTS) $(INCS) $<
endef

define COMPILE
	@echo cla15fg $< ...
	@$(CC) $(BIOS_DEFS) $(XOPTS) $(INCS) $<
endef


all: sysbios.aa15fg

arm_IntrinsicsSupport_asm_gnu.o: family/arm/IntrinsicsSupport_asm_gnu.asm makefile
	@-$(call RM, $@)
	$(ASSEMBLE) -o arm_IntrinsicsSupport_asm_gnu.o

arm_TaskSupport_asm_gnu.o: family/arm/TaskSupport_asm_gnu.asm makefile
	@-$(call RM, $@)
	$(ASSEMBLE) -o arm_TaskSupport_asm_gnu.o

gic_Hwi_asm_gnu.o: family/arm/gic/Hwi_asm_gnu.asm makefile
	@-$(call RM, $@)
	$(ASSEMBLE) -o gic_Hwi_asm_gnu.o

exc_Exception_asm_gnu.o: family/arm/exc/Exception_asm_gnu.asm makefile
	@-$(call RM, $@)
	$(ASSEMBLE) -o exc_Exception_asm_gnu.o

a15_Cache_asm_gnu.o: family/arm/a15/Cache_asm_gnu.asm makefile
	@-$(call RM, $@)
	$(ASSEMBLE) -o a15_Cache_asm_gnu.o

a15_Mmu_asm_gnu.o: family/arm/a15/Mmu_asm_gnu.asm makefile
	@-$(call RM, $@)
	$(ASSEMBLE) -o a15_Mmu_asm_gnu.o

a15_TimestampProvider_asm_gnu.o: family/arm/a15/TimestampProvider_asm_gnu.asm makefile
	@-$(call RM, $@)
	$(ASSEMBLE) -o a15_TimestampProvider_asm_gnu.o

systimer_Timer_asm_gnu.o: family/arm/systimer/Timer_asm_gnu.asm makefile
	@-$(call RM, $@)
	$(ASSEMBLE) -o systimer_Timer_asm_gnu.o


_BIOS.o: BIOS.c makefile
	@-$(call RM, _BIOS.o)
	$(COMPILE) -o _BIOS.o
arm_IntrinsicsSupport.o: family/arm/IntrinsicsSupport.c makefile
	@-$(call RM, arm_IntrinsicsSupport.o)
	$(COMPILE) -o arm_IntrinsicsSupport.o
arm_TaskSupport.o: family/arm/TaskSupport.c makefile
	@-$(call RM, arm_TaskSupport.o)
	$(COMPILE) -o arm_TaskSupport.o
knl_Clock.o: knl/Clock.c makefile
	@-$(call RM, knl_Clock.o)
	$(COMPILE) -o knl_Clock.o
knl_Idle.o: knl/Idle.c makefile
	@-$(call RM, knl_Idle.o)
	$(COMPILE) -o knl_Idle.o
knl_Intrinsics.o: knl/Intrinsics.c makefile
	@-$(call RM, knl_Intrinsics.o)
	$(COMPILE) -o knl_Intrinsics.o
knl_Queue.o: knl/Queue.c makefile
	@-$(call RM, knl_Queue.o)
	$(COMPILE) -o knl_Queue.o
knl_Semaphore.o: knl/Semaphore.c makefile
	@-$(call RM, knl_Semaphore.o)
	$(COMPILE) -o knl_Semaphore.o
knl_Swi.o: knl/Swi.c makefile
	@-$(call RM, knl_Swi.o)
	$(COMPILE) -o knl_Swi.o
knl_Task.o: knl/Task.c makefile
	@-$(call RM, knl_Task.o)
	$(COMPILE) -o knl_Task.o
hal_Cache.o: hal/Cache.c makefile
	@-$(call RM, hal_Cache.o)
	$(COMPILE) -o hal_Cache.o
hal_Core.o: hal/Core.c makefile
	@-$(call RM, hal_Core.o)
	$(COMPILE) -o hal_Core.o
hal_Hwi.o: hal/Hwi.c makefile
	@-$(call RM, hal_Hwi.o)
	$(COMPILE) -o hal_Hwi.o
hal_Hwi_stack.o: hal/Hwi_stack.c makefile
	@-$(call RM, hal_Hwi_stack.o)
	$(COMPILE) -o hal_Hwi_stack.o
hal_Hwi_startup.o: hal/Hwi_startup.c makefile
	@-$(call RM, hal_Hwi_startup.o)
	$(COMPILE) -o hal_Hwi_startup.o
gic_Hwi.o: family/arm/gic/Hwi.c makefile
	@-$(call RM, gic_Hwi.o)
	$(COMPILE) -o gic_Hwi.o
exc_Exception.o: family/arm/exc/Exception.c makefile
	@-$(call RM, exc_Exception.o)
	$(COMPILE) -o exc_Exception.o
vayu_IntXbar.o: family/shared/vayu/IntXbar.c makefile
	@-$(call RM, vayu_IntXbar.o)
	$(COMPILE) -o vayu_IntXbar.o
gnu_ReentSupport.o: rts/gnu/ReentSupport.c makefile
	@-$(call RM, gnu_ReentSupport.o)
	$(COMPILE) -o gnu_ReentSupport.o
gnu_SemiHostSupport.o: rts/gnu/SemiHostSupport.c makefile
	@-$(call RM, gnu_SemiHostSupport.o)
	$(COMPILE) -o gnu_SemiHostSupport.o
a15_Core.o: family/arm/a15/Core.c makefile
	@-$(call RM, a15_Core.o)
	$(COMPILE) -o a15_Core.o
a15_Cache.o: family/arm/a15/Cache.c makefile
	@-$(call RM, a15_Cache.o)
	$(COMPILE) -o a15_Cache.o
a15_Mmu.o: family/arm/a15/Mmu.c makefile
	@-$(call RM, a15_Mmu.o)
	$(COMPILE) -o a15_Mmu.o
a15_TimestampProvider.o: family/arm/a15/TimestampProvider.c makefile
	@-$(call RM, a15_TimestampProvider.o)
	$(COMPILE) -o a15_TimestampProvider.o
gates_GateHwi.o: gates/GateHwi.c makefile
	@-$(call RM, gates_GateHwi.o)
	$(COMPILE) -o gates_GateHwi.o
gates_GateMutex.o: gates/GateMutex.c makefile
	@-$(call RM, gates_GateMutex.o)
	$(COMPILE) -o gates_GateMutex.o
heaps_HeapMem.o: heaps/HeapMem.c makefile
	@-$(call RM, heaps_HeapMem.o)
	$(COMPILE) -o heaps_HeapMem.o
systimer_Timer.o: family/arm/systimer/Timer.c makefile
	@-$(call RM, systimer_Timer.o)
	$(COMPILE) -o systimer_Timer.o

sysbios.aa15fg: arm_IntrinsicsSupport_asm_gnu.o arm_TaskSupport_asm_gnu.o gic_Hwi_asm_gnu.o exc_Exception_asm_gnu.o a15_Cache_asm_gnu.o a15_Mmu_asm_gnu.o a15_TimestampProvider_asm_gnu.o systimer_Timer_asm_gnu.o _BIOS.o arm_IntrinsicsSupport.o arm_TaskSupport.o knl_Clock.o knl_Idle.o knl_Intrinsics.o knl_Queue.o knl_Semaphore.o knl_Swi.o knl_Task.o hal_Cache.o hal_Core.o hal_Hwi.o hal_Hwi_stack.o hal_Hwi_startup.o gic_Hwi.o exc_Exception.o vayu_IntXbar.o gnu_ReentSupport.o gnu_SemiHostSupport.o a15_Core.o a15_Cache.o a15_Mmu.o a15_TimestampProvider.o gates_GateHwi.o gates_GateMutex.o heaps_HeapMem.o systimer_Timer.o
	@-$(call RM, $@)
	@echo ara15fg $^ ...
	@$(AR) $@ $^


clean:
	@$(DEL) ../makefile.libs
	@-$(call RM, *)
