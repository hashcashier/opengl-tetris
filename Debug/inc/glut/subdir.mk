################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../inc/glut/GLUTManager.cpp 

OBJS += \
./inc/glut/GLUTManager.o 

CPP_DEPS += \
./inc/glut/GLUTManager.d 


# Each subdirectory must supply rules for building sources it contributes
inc/glut/%.o: ../inc/glut/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -IGL -IGLU -Iglut -O3 -g3 -Wall -c -fmessage-length=0 -std=c++11 -pthread -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


