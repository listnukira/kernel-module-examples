PWD:=$(shell pwd)
KERNELVERSION:=$(shell uname -r)
KERNELDIR:=/lib/modules/$(KERNELVERSION)/build

MODULE_NAME=demo_module
obj-m:=$(MODULE_NAME).o

all:
	make -C $(KERNELDIR) M=$(PWD) modules
clean:
	make -C $(KERNELDIR) M=$(PWD) clean
