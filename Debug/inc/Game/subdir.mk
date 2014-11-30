################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../inc/Game/DisplayManager.cpp \
../inc/Game/GameManager.cpp \
../inc/Game/KeyboardManager.cpp \
../inc/Game/MouseManager.cpp 

OBJS += \
./inc/Game/DisplayManager.o \
./inc/Game/GameManager.o \
./inc/Game/KeyboardManager.o \
./inc/Game/MouseManager.o 

CPP_DEPS += \
./inc/Game/DisplayManager.d \
./inc/Game/GameManager.d \
./inc/Game/KeyboardManager.d \
./inc/Game/MouseManager.d 


# Each subdirectory must supply rules for building sources it contributes
inc/Game/%.o: ../inc/Game/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/rami/eclipse-jdt-workspace/Graphics Tetris Game/Debug/GL" -I"/home/rami/eclipse-jdt-workspace/Graphics Tetris Game/Debug/GLU" -I"/home/rami/eclipse-jdt-workspace/Graphics Tetris Game/Debug/glut" -O3 -g3 -Wall -c -fmessage-length=0 -std=c++11 -pthread -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


