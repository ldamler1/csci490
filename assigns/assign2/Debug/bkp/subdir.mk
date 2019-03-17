################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../bkp/MainProcess.cpp \
../bkp/SeqProcess.cpp \
../bkp/StandardDeviation.cpp \
../bkp/assign2.cpp 

OBJS += \
./bkp/MainProcess.o \
./bkp/SeqProcess.o \
./bkp/StandardDeviation.o \
./bkp/assign2.o 

CPP_DEPS += \
./bkp/MainProcess.d \
./bkp/SeqProcess.d \
./bkp/StandardDeviation.d \
./bkp/assign2.d 


# Each subdirectory must supply rules for building sources it contributes
bkp/%.o: ../bkp/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -D__GXX_EXPERIMENTAL_CXX0X__ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


