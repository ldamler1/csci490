################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/MainProcess.cpp \
../src/SeqProcess.cpp \
../src/StandardDeviation.cpp \
../src/assign3.cpp 

OBJS += \
./src/MainProcess.o \
./src/SeqProcess.o \
./src/StandardDeviation.o \
./src/assign3.o 

CPP_DEPS += \
./src/MainProcess.d \
./src/SeqProcess.d \
./src/StandardDeviation.d \
./src/assign3.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


