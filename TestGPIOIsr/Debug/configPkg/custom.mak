## THIS IS A GENERATED FILE -- DO NOT EDIT
.configuro: .libraries,a15fg linker.cmd package/cfg/app_pa15fg.oa15fg

# To simplify configuro usage in makefiles:
#     o create a generic linker command file name 
#     o set modification times of compiler.opt* files to be greater than
#       or equal to the generated config header
#
linker.cmd: package/cfg/app_pa15fg.xdl
	$(SED) 's"^\"\(package/cfg/app_pa15fgcfg.cmd\)\"$""\"/home/dmitrii/ti/ccs910/workspace_v9/TestGPIOIsr/Debug/configPkg/\1\""' package/cfg/app_pa15fg.xdl > $@
	-$(SETDATE) -r:max package/cfg/app_pa15fg.h compiler.opt compiler.opt.defs
