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
fw_9-1.0.lss \

FLASH_IMAGE += \
fw_9-1.0.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: fw_9-1.0.elf secondary-outputs

# Tool invocations
fw_9-1.0.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,fw_9-1.0.map -L./../../../../avrlib/ -mmcu=atmega16 -o "fw_9-1.0.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

fw_9-1.0.lss: fw_9-1.0.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S fw_9-1.0.elf  >"fw_9-1.0.lss"
	@echo 'Finished building: $@'
	@echo ' '

fw_9-1.0.hex: fw_9-1.0.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -O ihex fw_9-1.0.elf  "fw_9-1.0.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: fw_9-1.0.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=berkeley -t fw_9-1.0.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(FLASH_IMAGE)$(ELFS)$(LSS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) fw_9-1.0.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
