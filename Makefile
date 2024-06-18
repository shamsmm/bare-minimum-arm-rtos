TOOLCHAIN=arm-none-eabi
CC=$(TOOLCHAIN)-gcc
OBJCOPY=$(TOOLCHAIN)-objcopy


OBJS = crt0_stm32f103.o syscalls.o stm32f103_it.o system_stm32f1xx.o
OBJS += stm32f1xx_hal.o stm32f1xx_hal_cortex.o stm32f1xx_hal_rcc.o stm32f1xx_hal_gpio.o stm32f1xx_hal_dma.o stm32f1xx_hal_uart.o stm32f1xx_hal_spi.o
OBJS += port.o tasks.o queue.o list.o heap_1.o
OBJS += fonts.o GFX_FUNCTIONS.o ST7735.o
OBJS += main.o

BUILD=build
SRC=src

STM32CubeF1=/home/shams/W/Embedded/ARM/Libraries/STM32CubeF1
STM32F1XX_HAL_DRIVER=$(STM32CubeF1)/Drivers/STM32F1xx_HAL_Driver
CMSIS=$(STM32CubeF1)/Drivers/CMSIS

FreeRTOS=/home/shams/W/Embedded/FreeRTOS/FreeRTOS/Source

# Paths to libraries .c source files
vpath %.c $(STM32F1XX_HAL_DRIVER)/Src

# Paths to RTOS source libraries
vpath %.c $(FreeRTOS)/portable/GCC/ARM_CM3
vpath %.c $(FreeRTOS)/portable/MemMang
vpath %.c $(FreeRTOS)

# Paths to project .c source files
vpath %.c $(SRC)

vpath %.c lib/st7735

CFLAGS=-ggdb -mthumb -mcpu=cortex-m3 -O2 -DSTM32F103xB -DUSE_FULL_ASSERT -DINCLUDE_xTaskGetCurrentTaskHandle

# Paths to libraries .h header files
CFLAGS+= -I$(STM32F1XX_HAL_DRIVER)/Inc/ -I$(CMSIS)/Device/ST/STM32F1xx/Include/ -I$(CMSIS)/Include

CFLAGS+= -I$(FreeRTOS)/include -I$(FreeRTOS)/portable/GCC/ARM_CM3

CFLAGS+= -Ilib/st7735

CFLAGS+= -Iinc/

# Auto create build directory
_ := $(shell mkdir -p $(BUILD))


flash: main.elf
	openocd -f stlink.cfg -c "program main.elf verify reset exit"

main.elf: clean $(OBJS)
	$(CC) $(CFLAGS) -TSTM32F103.ld -o main.elf $(BUILD)/*

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $(BUILD)/$@

%.o: %.s
	$(CC) -c $(CFLAGS) $< -o $(BUILD)/$@

clean:
	rm -f build/*