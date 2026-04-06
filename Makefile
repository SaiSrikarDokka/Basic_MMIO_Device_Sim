CC = gcc

TARGET = sim
SRCS = sim.c cpu.c memory.c event_scheduler.c device.c mmu.c ISR.c dma.c

all:
	$(CC) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET)