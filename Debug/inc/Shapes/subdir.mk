################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../inc/Shapes/Tetromino.cpp \
../inc/Shapes/TetrominoGenerator.cpp 

OBJS += \
./inc/Shapes/Tetromino.o \
./inc/Shapes/TetrominoGenerator.o 

CPP_DEPS += \
./inc/Shapes/Tetromino.d \
./inc/Shapes/TetrominoGenerator.d 


# Each subdirectory must supply rules for building sources it contributes
inc/Shapes/%.o: ../inc/Shapes/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/rami/eclipse-jdt-workspace/Graphics Tetris Game/Debug/GL" -I"/home/rami/eclipse-jdt-workspace/Graphics Tetris Game/Debug/GLU" -I"/home/rami/eclipse-jdt-workspace/Graphics Tetris Game/Debug/glut" -O3 -g3 -Wall -c -fmessage-length=0 -std=c++11 -pthread -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


