################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
avrlib-if_usart.lss \

FLASH_IMAGE += \
avrlib-if_usart.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: avrlib-if_usart.elf secondary-outputs

# Tool invocations
avrlib-if_usart.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,avrlib-if_usart.map -L./../../../../avrlib/ -mmcu=atmega16 -o "avrlib-if_usart.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

avrlib-if_usart.lss: avrlib-if_usart.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S avrlib-if_usart.elf  >"avrlib-if_usart.lss"
	@echo 'Finished building: $@'
	@echo ' '

avrlib-if_usart.hex: avrlib-if_usart.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -O ihex avrlib-if_usart.elf  "avrlib-if_usart.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: avrlib-if_usart.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=berkeley -t avrlib-if_usart.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(FLASH_IMAGE)$(ELFS)$(LSS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) avrlib-if_usart.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
