#include "mmu.h"

byte mmu_addr;
int mmu_data_in;
int mmu_data_out;

void mmu_read() {
    if(mmu_addr < 10) {
        printf("MMU read Memory: Address %d \n", mmu_addr);
        mem_addr = mmu_addr; // Set MMU address
        mem_read();
        mmu_data_out = mem_data_out; // Get data from memory
        
    } else {
        printf("MMU read Device: Address %d, Data %d\n", mmu_addr, mmu_data_out);
        dev_addr = mmu_addr-10; // Set device address
        dev_read();
        mmu_data_out = dev_out; // Get data from device
        
    }
}

void mmu_write() {
    if(mmu_addr < 10) {
        printf("MMU write Memory: Address %d, Data %d\n", mmu_addr, mmu_data_in);
        mem_addr = mmu_addr; // Set MMU address
        mem_data = mmu_data_in; // Set data to write
        mem_write();
        
    } else {
        printf("MMU write Device: Address %d, Data %d\n", mmu_addr, mmu_data_in);
        dev_addr = mmu_addr-10; // Set device address
        dev_data_in = mmu_data_in; // Set data to write
        dev_write();
        
    }
}