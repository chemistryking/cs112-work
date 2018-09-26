################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ArrayQueueTester.cpp \
../LinkedQueue.cpp \
../LinkedQueueTester.cpp \
../PalDetector.cpp \
../PalDetectorTester.cpp \
../tester.cpp 

OBJS += \
./ArrayQueueTester.o \
./LinkedQueue.o \
./LinkedQueueTester.o \
./PalDetector.o \
./PalDetectorTester.o \
./tester.o 

CPP_DEPS += \
./ArrayQueueTester.d \
./LinkedQueue.d \
./LinkedQueueTester.d \
./PalDetector.d \
./PalDetectorTester.d \
./tester.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


