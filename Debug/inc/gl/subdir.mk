################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../inc/gl/GL.cpp \
../inc/gl/GLUT.cpp 

OBJS += \
./inc/gl/GL.o \
./inc/gl/GLUT.o 

CPP_DEPS += \
./inc/gl/GL.d \
./inc/gl/GLUT.d 


# Each subdirectory must supply rules for building sources it contributes
inc/gl/%.o: ../inc/gl/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/rami/eclipse-jdt-workspace/Graphics Tetris Game/Debug/GL" -I"/home/rami/eclipse-jdt-workspace/Graphics Tetris Game/Debug/GLU" -I"/home/rami/eclipse-jdt-workspace/Graphics Tetris Game/Debug/glut" -O3 -g3 -Wall -c -fmessage-length=0 -std=c++11 -pthread -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


