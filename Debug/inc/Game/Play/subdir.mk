################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../inc/Game/Play/PlayActions.cpp \
../inc/Game/Play/PlayAnimator.cpp \
../inc/Game/Play/PlayDisplay.cpp \
../inc/Game/Play/PlayKeyboard.cpp 

OBJS += \
./inc/Game/Play/PlayActions.o \
./inc/Game/Play/PlayAnimator.o \
./inc/Game/Play/PlayDisplay.o \
./inc/Game/Play/PlayKeyboard.o 

CPP_DEPS += \
./inc/Game/Play/PlayActions.d \
./inc/Game/Play/PlayAnimator.d \
./inc/Game/Play/PlayDisplay.d \
./inc/Game/Play/PlayKeyboard.d 


# Each subdirectory must supply rules for building sources it contributes
inc/Game/Play/%.o: ../inc/Game/Play/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/rami/eclipse-jdt-workspace/Graphics Tetris Game/Debug/GL" -I"/home/rami/eclipse-jdt-workspace/Graphics Tetris Game/Debug/GLU" -I"/home/rami/eclipse-jdt-workspace/Graphics Tetris Game/Debug/glut" -O3 -g3 -Wall -c -fmessage-length=0 -std=c++11 -pthread -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


