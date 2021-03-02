# Beagleboard-X15 projects

`IDE - Code Composer Studio 9.1/9.3. Processor - Sitara AM572X.`

1. TestGPIOIsr - Registers a `GPIO` interrupt on a specific pin.
2. TestWriteSD - Writing large data to `mSD` card's.
3. ARM-PRU - Writing any values to a specific memory address from the `PRU` core.

	3.1 TestHW01 - Firmware for `ARM` core

	3.2 TestLEDGPIO3_7 - Firmware for `PRU` core
	
	
	<b>Generator PRU:</b>

	`XXX@XXX:~/ti/ti-cgt-pru_2.3.2/bin$ ./hexpru -h --array`
	
	  `--array                 Array output format`
	  
	  `--array:name_prefix=string` 
	  
                          Prefix for array names in array output format. Arrays
                           will be named PREFIX_0, PREFIX_1, etc..
	  
	  `--array:page0_type_size=8,32` 
	  
                          Select the type for the array containing code
                           sections.


	1)
	`./hexpru --array:page0_type_size=8 TestLEDGPIO3_7.out --array`
	
	`Translating to Array format...`
	
		"TestLEDGPIO3_7.out" .text:_c_int00* ==> .text:_c_int00*
		
	`warning: Data is being written to auto-generated file TestLEDGPIO3_7.c`
	
	`warning: Data is being written to auto-generated file TestLEDGPIO3_7.h`
	
		"TestLEDGPIO3_7.out" .text ==> .text

	2)
	`XXX@XXX:~/ti/ti-cgt-pru_2.3.2/bin$ ./hexpru bin.cmd TestLEDGPIO3_7.out`
	
	`Translating to Binary format...`
	
		"TestLEDGPIO3_7.out" .text:_c_int00* ==> .text:_c_int00*
		"TestLEDGPIO3_7.out" .text ==> .text

	
4. docs:
	1. AM572x_Datasheet.pdf
	2. AM572x_TRM.pdf
	
