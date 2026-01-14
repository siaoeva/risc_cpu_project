# Single-Cycle RISC-V CPU (RV32I)

## 1. Project Overview

**Project Name:** Single-Cycle RISC-V CPU  
**Target Roles:** FPGA / RTL Design Co-op Student  
**Implementation Language:** SystemVerilog  
**Verification:** Assembly-level testing in Questa (simulation-only)

This project implements a **single-cycle RV32I-compatible RISC-V CPU** designed to demonstrate a clear understanding of CPU microarchitecture, control logic, and RTL design fundamentals. The processor executes each instruction in a single clock cycle and is fully synthesizable, though currently verified through simulation only.

The design emphasizes:
- Clean, modular RTL structure
- Explicit control signal generation
- Instruction-accurate execution verified via waveforms

---

## 2. Supported ISA Scope

The CPU supports a substantial subset of the **RV32I base integer instruction set**:

### Arithmetic & Logical Instructions
- **R-type (OP):** `add`, `sub`, `and`, `or`, `xor`, `sll`, `srl`, `sra`, `slt`, `sltu`
- **I-type (OP-IMM):** `addi`, `andi`, `ori`, `xori`, `slli`, `srli`, `srai`, `slti`, `sltiu`

### Memory Access
- **Load:** `lw`, `lh`, `lhu`, `lb`, `lbu`
- **Store:** `sw`, `sh`, `sb`

### Control Flow
- **Branch:** `beq`, `bne`, `blt`, `bge`, `bltu`, `bgeu`
- **Jump:** `jal`, `jalr`

### Upper Immediate
- `lui`
- `auipc`

**Word Size:** 32-bit  
**Endianness:** Little-endian

---

## 3. Clocking and Reset

- **Clock:** Single global clock
- **Reset:** Synchronous, active-high
- **Execution Model:** One instruction completes fully in a single rising clock edge

---

## 4. High-Level Architecture

The CPU follows a **single-cycle datapath**, conceptually divided into:

1. Instruction Fetch (IF)
2. Instruction Decode / Register Fetch (ID)
3. Execute (EX)
4. Memory Access (MEM)
5. Writeback (WB)

Although these stages are not pipelined, the structure mirrors a standard RISC datapath, making the design easy to extend to a multi-cycle or pipelined implementation.

---

## 5. Datapath Description

### 5.1 Program Counter (PC)
- 32-bit register updated every clock cycle
- Reset initializes PC to `0x00000000`
- Next PC logic supports:
  - Sequential execution (`PC + 4`)
  - Conditional branches
  - Unconditional jumps (`JAL`, `JALR`)

```text
pc_next =
  jalr   ? {alu_result[31:1], 1'b0} :
  (take_branch | jal) ? (PC + immediate) :
  (PC + 4)
```

---

### 5.2 Instruction Fetch
- Instruction memory is word-addressed
- PC is byte-addressed; `pc[9:2]` is used to index instruction memory
- Supports up to 256 instructions

---

### 5.3 Instruction Decode & Register File

Decoded instruction fields:
- `opcode   = instr[6:0]`
- `rd       = instr[11:7]`
- `funct3   = instr[14:12]`
- `rs1      = instr[19:15]`
- `rs2      = instr[24:20]`
- `funct7   = instr[31:25]`

The register file:
- 32 registers, 32-bit wide
- Two asynchronous read ports (`rs1`, `rs2`)
- One synchronous write port (`rd`)
- Write enabled by `reg_write`

---

### 5.4 Immediate Generation

An `imm_gen` module extracts and sign-extends immediates based on instruction type:

- I-type
- S-type
- B-type
- U-type
- J-type

Immediate selection is controlled via `imm_sel` from the control unit.

---

### 5.5 Execute Stage (ALU)

The ALU performs all arithmetic, logical, and comparison operations.

**ALU Operand Selection:**
- Operand A: `rs1_data` or `PC` (`alu_a_pc`)
- Operand B: `rs2_data` or `immediate` (`alu_b_imm`)

**ALU Functions:**
- Arithmetic: ADD, SUB
- Logical: AND, OR, XOR
- Shifts: SLL, SRL, SRA
- Comparisons: SLT, SLTU

The ALU also produces:
- `zero` flag (used for equality-based branches)

---

### 5.6 Branch Unit

Branch decisions are handled by a dedicated `branch_unit`:
- Uses `funct3` to determine branch type
- Uses ALU outputs (`zero`, comparison result)
- Outputs `take_branch` signal

This separation simplifies control logic and improves readability.

---

### 5.7 Data Memory Access

- Word-addressed data memory (`alu_result[9:2]`)
- Write enabled by `mem_write`
- Load data is post-processed by `load_unit` to handle:
  - Byte vs halfword vs word loads
  - Signed vs unsigned extension

---

### 5.8 Writeback Stage

Writeback data is selected via `wb_sel`:

| Source | Description |
|------|------------|
| `WB_ALU` | ALU result |
| `WB_MEM` | Loaded memory data |
| `WB_PC4` | `PC + 4` (JAL/JALR link) |
| `WB_IMM` | Immediate value (LUI) |

---

## 6. Control Unit Design

The control unit is a **fully combinational decoder** driven by `opcode`, `funct3`, and `funct7`.

### 6.1 Control Signals Generated

- `reg_write` – Register file write enable
- `mem_write` – Data memory write enable
- `alu_op` – ALU operation select
- `alu_a_pc` – ALU operand A source
- `alu_b_imm` – ALU operand B source
- `branch` – Branch instruction indicator
- `jal`, `jalr` – Jump control signals
- `imm_sel` – Immediate format select
- `wb_sel` – Writeback data select

### 6.2 Decoding Strategy

- **Opcode-level decoding** selects instruction class
- **funct3/funct7 decoding** refines ALU operation
- Default-safe values are assigned to prevent unintended latches

This explicit decoding approach improves readability and debuggability, which is especially valuable in FPGA and RTL development.

---

## 7. Design Characteristics

- Single-cycle execution (CPI = 1)
- No hazard handling (not required)
- No forwarding or stalling logic
- Deterministic timing and control

---

## 8. Limitations and Future Work

**Current Limitations:**
- Simulation-only verification
- No pipeline or multi-cycle support
- No exception or interrupt handling
- No CSR support

**Potential Extensions:**
- Multi-cycle or pipelined implementation
- FPGA synthesis and timing closure
- Instruction and data cache support
- Formal verification of control logic

---

## 9. Verification Strategy and Results

Verification was performed entirely in simulation using **Questa**, with **hand-written RV32I assembly programs** executed on the CPU and validated through waveform inspection. The goal of verification was to ensure correctness of:
- Instruction decoding and control signal generation
- ALU operations
- Register file read/write behavior
- Branch and jump control flow
- Load/store data formatting and sign extension

Rather than relying on isolated unit tests, the CPU was verified using **instruction-level programs**, closely resembling real software execution on hardware.

---

### 9.1 Arithmetic and Logical Instruction Test (sanity.s)

The `sanity.s` program validates immediate arithmetic, register-register ALU operations, and shift instructions.

Example instructions exercised:
- `addi`, `add`, `sub`
- `and`, `or`, `xor`
- `sll`, `srl`, `sra`

**Expected behavior:**
- Correct ALU operation selected via `alu_op`
- Proper register writeback (`reg_write` asserted)
- Correct signed behavior for arithmetic right shifts

**Observed waveform behavior:**
- `alu_op` transitions match the decoded instruction (ADD → SUB → AND → OR → XOR → shifts)
- `wb_sel = WB_ALU` during arithmetic instructions
- Destination registers (`x1`–`x11`) update with expected values on the rising clock edge

This confirms correct ALU control decoding and writeback functionality.

---

### 9.2 Load and Store Verification (load_store.s)

The `load_store.s` program verifies data memory access and load formatting logic.

Instructions tested:
- Stores: `sw`
- Loads: `lw`, `lb`, `lbu`, `lh`, `lhu`

**Key verification points:**
- Effective address calculation using `rs1 + immediate`
- Correct assertion of `mem_write` during stores
- Correct byte/halfword extraction in `load_unit`
- Proper sign and zero extension based on `funct3`

**Observed waveform behavior:**
- `mem_write` asserted only for store instructions
- Load data correctly sign-extended (`lb`, `lh`) or zero-extended (`lbu`, `lhu`)
- Loaded values written back to the destination register via `WB_MEM`

This confirms correctness of the memory datapath and load formatting logic.

---

### 9.3 Branch Instruction Verification (branch.s)

The `branch.s` program validates all supported branch types:
- `beq`, `bne`
- `blt`, `bge`
- `bltu`, `bgeu`

**Verification method:**
- Programs are written such that incorrect branch behavior would execute visible “marker” instructions
- Correct execution skips or executes these markers based on branch outcome

**Observed waveform behavior:**
- `branch` asserted only for branch instructions
- ALU comparison results correctly interpreted by `branch_unit`
- `take_branch` asserted only when conditions are met
- `pc_next` reflects either `PC + immediate` (taken) or `PC + 4` (not taken)

This demonstrates correct branch decision logic and PC control.

---

### 9.4 Jump and Link Verification (jump.s)

The `jump.s` program verifies `JAL` and `JALR` behavior.

**Verification points:**
- Correct jump target calculation
- Proper masking of JALR target LSB
- Correct writeback of return address (`PC + 4`)

**Observed waveform behavior:**
- `jal` / `jalr` asserted appropriately
- `wb_sel = WB_PC4` during jump instructions
- Destination registers receive correct return addresses
- Instructions following the jump are correctly skipped

This confirms correct implementation of control-flow-changing instructions.

---

### 9.5 Representative Waveform Analysis

Waveform inspection shows:
- Correct sequencing of PC values
- Proper alignment between instruction decode, ALU operation, and writeback
- Register file updates occurring synchronously on the clock edge

A representative waveform snapshot demonstrates multiple ALU operations executed sequentially, with `alu_op`, `alu_result`, and register values matching expected architectural behavior.

---

## 10. Limitations and Future Work

**Current Limitations:**
- Single-cycle design (no pipelining)
- No hazard handling or forwarding
- No exceptions, interrupts, or CSRs
- Simulation-only verification

**Potential Extensions:**
- FPGA synthesis and on-board verification
- Multi-cycle or pipelined datapath
- Formal verification of control logic
- Memory-mapped I/O and peripheral integration

---

## 11. Why This Project Is Relevant for FPGA Intern Roles

This project demonstrates:
- Strong understanding of RTL-based CPU design
- Explicit control signal generation and decoding
- Instruction-level verification methodology
- Clean, modular SystemVerilog suitable for FPGA workflows

The verification approach mirrors real-world hardware validation practices, making this project directly relevant to FPGA and RTL design internship roles.


