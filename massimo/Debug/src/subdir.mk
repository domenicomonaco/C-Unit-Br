################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/massimo.c \
../src/matematica_function.c \
../src/matematica_proc_point.c \
../src/test_matematica_function.c \
../src/test_matematica_proc_point.c 

OBJS += \
./src/massimo.o \
./src/matematica_function.o \
./src/matematica_proc_point.o \
./src/test_matematica_function.o \
./src/test_matematica_proc_point.o 

C_DEPS += \
./src/massimo.d \
./src/matematica_function.d \
./src/matematica_proc_point.d \
./src/test_matematica_function.d \
./src/test_matematica_proc_point.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I/opt/local/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


