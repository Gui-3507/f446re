ARMGCC := arm-none-eabi-gcc 
ARMOBJ := arm-none-eabi-objcopy
PARAMS 	:= -mcpu=cortex-m4 -mthumb -nostdlib 
LINKER	:= -T $(wildcard core/*.ld)
FILES 	:= -Icore app/main.c $(wildcard core/clock/*.c) $(wildcard core/startupcode.c) 
TARGET 	:= -o main.elf 
MAIN 	:= main.c
PROGRAM	:= -O binary main.elf main.bin

compile:
	$(ARMGCC) $(PARAMS) $(LINKER) $(FILES) $(TARGET)
	$(ARMOBJ) $(PROGRAM)

clean:
	rm -f main.*