# 📦 Basic MMIO Device Simulator

## 🧠 Overview

This project is a **cycle-driven system simulator** that models interactions between a CPU, memory, and memory-mapped I/O (MMIO) devices. It demonstrates both **CPU-driven data movement** and **DMA-based offloading**, along with **interrupt-driven synchronization**.

The simulator is designed to explore core system-level concepts such as:
- Memory vs device access via MMIO
- Event-driven execution
- Interrupt handling
- DMA vs CPU-based data transfer

---

## 🔧 Components

### CPU
- Fetches and executes instructions
- Supports LOAD, STORE, STOREI, MOVI, BRANCH, DMA, and DEV_OP
- Handles interrupts via ISR

### MMU
- Routes accesses based on address
- Differentiates between memory and MMIO regions

### Memory
- Array-based main memory (10 locations: 0–9)

### Device (MMIO)
- Memory-mapped device (10 locations: 10–19)
- Receives data via MMIO writes
- Performs computation on input data **5 Cycles (assumed)**
- Signals completion using interrupts

### DMA Engine

- Performs bulk data transfers  
- Operates independently of the CPU  
- Transfer latency: **2 cycles (assumed)**  

#### Working

- Load `register[0]` with the control type:
  - `1` → Memory-to-device transfer  
  - `2` → Device-to-memory transfer  

- Load the data length into `register[1]`.

- The data length is copied to the DMA data length register.

- The control type is copied to the DMA control register.

### Event Queue
- Drives simulation cycle-by-cycle
- Enables asynchronous execution across components
---
## 📜 Execution Trace

- The simulator generates a **cycle-by-cycle execution trace**
- Logs include:
  - Instruction fetch and execution
  - MMU memory/device accesses
  - Event scheduling
  - Device execution timing
  - Interrupt generation and handling

## ⚙️ Features

- Event-driven simulation (cycle-based)
- MMIO-based device interaction
- Interrupt-driven execution
- DMA support for bulk transfers
- Branching and control flow support

---

## 🔔 Interrupt Handling

- Devices signal completion using interrupts
- CPU handles interrupts via ISR (Interrupt Service Routine)
- Enables asynchronous coordination between components

---
## 📁 Example Programs

Example instruction sequences are provided for in examplet_instructions.txt:

- ✅ **DMA-based execution**
- ✅ **CPU-driven (non-DMA) execution**

These demonstrate:
- Difference in execution flow
- CPU involvement vs offloading
- Asynchronous vs synchronous behavior

## 🧩 Instruction Set

| Instruction | Opcode | Description | Example Encoding | Meaning |
|------------|--------|------------|------------------|---------|
| LOAD       | 0x01   | Load from memory/device to register | `0x0001000A` | R ← MEM[0] |
| STORE      | 0x02   | Store register to memory/device | `0x0002000A` | MEM[10] ← R |
| STOREI     | 0x03   | Store immediate to memory | `0x00030100` | MEM[0] ← 1 |
| DEV_OP     | 0x04   | Trigger device computation | `0x00040000` | Start device operation |
| MOVI       | 0x05   | Move immediate to register | `0x00050103` | R[3] ← 1 |
| DMA        | 0x06   | Trigger DMA transfer | `0x0006000A` | DMA MEM[0] → MEM[10] |
| BRANCH     | 0x08   | Conditional jump | `0x00080309` | if R[3]==1 → PC=9 |
| NOP/HALT   | 0x00   | Terminate execution | `0x00000000` | Stop execution |

## 🚀 How to Run

```bash
git clone https://github.com/SaiSrikarDokka/Basic_MMIO_Device_Sim.git
cd Basic_MMIO_Device_Sim
gcc main.c -o sim
./sim

