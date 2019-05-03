.PHONY: flash_stlink flash_openocd

HEXFILE=./$(PRJNAME)/BUILD/NUCLEO_L432KC/GCC_ARM/$(PRJNAME).hex
ELFFILE=./$(PRJNAME)/BUILD/NUCLEO_L432KC/GCC_ARM/$(PRJNAME).elf

flash_stlink:
	arm-none-eabi-objcopy.exe -O ihex $(ELFFILE) $(HEXFILE)
	ST-LINK_CLI.exe -c swd -p $(HEXFILE) -v -rst

flash_openocd:
	arm-none-eabi-objcopy.exe -O ihex $(ELFFILE) $(HEXFILE)
	openocd -f stlink_v2.cfg -c "program $(HEXFILE) verify reset exit"

