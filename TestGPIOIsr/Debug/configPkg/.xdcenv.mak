#
_XDCBUILDCOUNT = 
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = /home/dmitrii/ti/bios_6_76_02_02/packages;/home/dmitrii/ti/pdk_am57xx_1_0_16/packages;/home/dmitrii/ti/edma3_lld_2_12_05_30E/packages;/home/dmitrii/ti/ipc_3_50_04_07/packages
override XDCROOT = /home/dmitrii/ti/ccs910/xdctools_3_55_02_22_core
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = /home/dmitrii/ti/bios_6_76_02_02/packages;/home/dmitrii/ti/pdk_am57xx_1_0_16/packages;/home/dmitrii/ti/edma3_lld_2_12_05_30E/packages;/home/dmitrii/ti/ipc_3_50_04_07/packages;/home/dmitrii/ti/ccs910/xdctools_3_55_02_22_core/packages;..
HOSTOS = Linux
endif
