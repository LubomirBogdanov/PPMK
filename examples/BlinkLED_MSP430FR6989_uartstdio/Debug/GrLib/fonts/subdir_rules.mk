################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
GrLib/fonts/fontfixed6x8.obj: ../GrLib/fonts/fontfixed6x8.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-msp430_15.12.1.LTS/bin/cl430" -vmspx --data_model=restricted -Ooff --use_hw_mpy=F5 --include_path="C:/ti/ccsv6/ccs_base/msp430/include" --include_path="C:/Users/lbogdanov/workspace_6_1_3/BlinkLED_MSP430FR6989_uartstdio/GrLib/grlib" --include_path="C:/Users/lbogdanov/workspace_6_1_3/BlinkLED_MSP430FR6989_uartstdio/LcdDriver" --include_path="C:/Users/lbogdanov/workspace_6_1_3/BlinkLED_MSP430FR6989_uartstdio/driverlib/MSP430FR5xx_6xx" --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-msp430_15.12.1.LTS/include" --advice:power="all" --advice:hw_config="all" -g --define=__MSP430FR6989__ --define=ccs --define=_MPU_ENABLE --diag_warning=225 --display_error_number --diag_wrap=off --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU40 --printf_support=full --preproc_with_compile --preproc_dependency="GrLib/fonts/fontfixed6x8.d" --obj_directory="GrLib/fonts" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


