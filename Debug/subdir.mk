################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Client.cpp \
../testClient.cpp 

OBJS += \
./Client.o \
./testClient.o 

CPP_DEPS += \
./Client.d \
./testClient.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: NVCC Compiler'
	/usr/local/cuda-6.0/bin/nvcc -G -g -O0 -ccbin arm-linux-gnueabihf-g++-4.6  --target-cpu-architecture ARM -m32 -odir "" -M -o "$(@:%.o=%.d)" "$<"
	/usr/local/cuda-6.0/bin/nvcc -G -g -O0 --compile --target-cpu-architecture ARM -m32 -ccbin arm-linux-gnueabihf-g++-4.6  -x c++ -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


