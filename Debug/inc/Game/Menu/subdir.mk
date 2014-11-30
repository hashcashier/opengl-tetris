################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../inc/Game/Menu/MenuDisplay.cpp \
../inc/Game/Menu/MenuKeyboard.cpp 

OBJS += \
./inc/Game/Menu/MenuDisplay.o \
./inc/Game/Menu/MenuKeyboard.o 

CPP_DEPS += \
./inc/Game/Menu/MenuDisplay.d \
./inc/Game/Menu/MenuKeyboard.d 


# Each subdirectory must supply rules for building sources it contributes
inc/Game/Menu/%.o: ../inc/Game/Menu/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/rami/eclipse-jdt-workspace/Graphics Tetris Game/Debug/GL" -I"/home/rami/eclipse-jdt-workspace/Graphics Tetris Game/Debug/GLU" -I"/home/rami/eclipse-jdt-workspace/Graphics Tetris Game/Debug/glut" -O3 -g3 -Wall -c -fmessage-length=0 -std=c++11 -pthread -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


