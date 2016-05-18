################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../source/ClientImpl.cpp \
../source/SupplierImpl.cpp \
../source/main.cpp 

OBJS += \
./source/ClientImpl.o \
./source/SupplierImpl.o \
./source/main.o 

CPP_DEPS += \
./source/ClientImpl.d \
./source/SupplierImpl.d \
./source/main.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++11 -D__cplusplus=201103L -I"/home/parallels/workspace/DependencyInjection/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


