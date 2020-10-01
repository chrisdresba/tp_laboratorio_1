################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ArrayEmployees.c \
../src/Trabajo\ Practico\ 2.c \
../src/utn.c 

OBJS += \
./src/ArrayEmployees.o \
./src/Trabajo\ Practico\ 2.o \
./src/utn.o 

C_DEPS += \
./src/ArrayEmployees.d \
./src/Trabajo\ Practico\ 2.d \
./src/utn.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/Trabajo\ Practico\ 2.o: ../src/Trabajo\ Practico\ 2.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Trabajo Practico 2.d" -MT"src/Trabajo\ Practico\ 2.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


