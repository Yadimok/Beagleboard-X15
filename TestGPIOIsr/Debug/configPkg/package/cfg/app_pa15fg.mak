#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#
#  target compatibility key = gnu.targets.arm.A15F{1,0,7.2,1
#
ifeq (,$(MK_NOGENDEPS))
-include package/cfg/app_pa15fg.oa15fg.dep
package/cfg/app_pa15fg.oa15fg.dep: ;
endif

package/cfg/app_pa15fg.oa15fg: | .interfaces
package/cfg/app_pa15fg.oa15fg: package/cfg/app_pa15fg.c package/cfg/app_pa15fg.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cla15fg $< ...
	$(gnu.targets.arm.A15F.rootDir)/bin/arm-none-eabi-gcc -c -MD -MF $@.dep -x c  -Wunused -Wunknown-pragmas -ffunction-sections -fdata-sections  -mcpu=cortex-a15 -mfpu=neon -mfloat-abi=hard -mabi=aapcs -g -Dfar= -D__DYNAMIC_REENT__   -Dxdc_cfg__xheader__='"configPkg/package/cfg/app_pa15fg.h"'  -Dxdc_target_name__=A15F -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_2_1  -O2   $(XDCINCS) -I/home/dmitrii/ti/bios_6_76_02_02/packages/gnu/targets/arm//libs/install-native/arm-none-eabi/include/newlib-nano -I/home/dmitrii/ti/bios_6_76_02_02/packages/gnu/targets/arm//libs/install-native/arm-none-eabi/include -o $@ $<
	-@$(FIXDEP) $@.dep $@.dep
	
package/cfg/app_pa15fg.oa15fg: export LD_LIBRARY_PATH=

package/cfg/app_pa15fg.sa15fg: | .interfaces
package/cfg/app_pa15fg.sa15fg: package/cfg/app_pa15fg.c package/cfg/app_pa15fg.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cla15fg -S $< ...
	$(gnu.targets.arm.A15F.rootDir)/bin/arm-none-eabi-gcc -c -MD -MF $@.dep -x c -S -Wunused -Wunknown-pragmas -ffunction-sections -fdata-sections  -mcpu=cortex-a15 -mfpu=neon -mfloat-abi=hard -mabi=aapcs -g -Dfar= -D__DYNAMIC_REENT__   -Dxdc_cfg__xheader__='"configPkg/package/cfg/app_pa15fg.h"'  -Dxdc_target_name__=A15F -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_2_1  -O2   $(XDCINCS) -I/home/dmitrii/ti/bios_6_76_02_02/packages/gnu/targets/arm//libs/install-native/arm-none-eabi/include/newlib-nano -I/home/dmitrii/ti/bios_6_76_02_02/packages/gnu/targets/arm//libs/install-native/arm-none-eabi/include -o $@ $<
	-@$(FIXDEP) $@.dep $@.dep
	
package/cfg/app_pa15fg.sa15fg: export LD_LIBRARY_PATH=

clean,a15fg ::
	-$(RM) package/cfg/app_pa15fg.oa15fg
	-$(RM) package/cfg/app_pa15fg.sa15fg

app.pa15fg: package/cfg/app_pa15fg.oa15fg package/cfg/app_pa15fg.mak

clean::
	-$(RM) package/cfg/app_pa15fg.mak
