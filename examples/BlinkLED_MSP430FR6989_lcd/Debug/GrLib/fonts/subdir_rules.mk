################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
GrLib/fonts/fontfixed6x8.obj: ../GrLib/fonts/fontfixed6x8.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-msp430_16.9.3.LTS/bin/cl430" -vmspx --data_model=restricted -Ooff --use_hw_mpy=F5 --include_path="C:/ti/ccsv7/ccs_base/msp430/include" --include_path="E:/Data/TU-Sofia/Teaching/09 - Praktikum_MSHT/MSHT_PRAKT/examples/BlinkLED_MSP430FR6989_lcd/GrLib/grlib" --include_path="E:/Data/TU-Sofia/Teaching/09 - Praktikum_MSHT/MSHT_PRAKT/examples/BlinkLED_MSP430FR6989_lcd/LcdDriver" --include_path="E:/Data/TU-Sofia/Teaching/09 - Praktikum_MSHT/MSHT_PRAKT/examples/BlinkLED_MSP430FR6989_lcd/driverlib/MSP430FR5xx_6xx" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-msp430_16.9.3.LTS/include" --advice:power="all" --advice:hw_config="all" -g --define=__MSP430FR6989__ --define=ccs --define=_MPU_ENABLE --diag_warning=225 --display_error_number --diag_wrap=off --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU40 --printf_support=full --preproc_with_compile --preproc_dependency="GrLib/fonts/fontfixed6x8.d" --obj_directory="GrLib/fonts" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


