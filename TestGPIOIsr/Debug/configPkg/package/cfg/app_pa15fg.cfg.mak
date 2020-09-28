# invoke SourceDir generated makefile for app.pa15fg
app.pa15fg: .libraries,app.pa15fg
.libraries,app.pa15fg: package/cfg/app_pa15fg.xdl
	$(MAKE) -f /home/dmitrii/ti/ccs910/workspace_v9/TestGPIOIsr/src/makefile.libs

clean::
	$(MAKE) -f /home/dmitrii/ti/ccs910/workspace_v9/TestGPIOIsr/src/makefile.libs clean

