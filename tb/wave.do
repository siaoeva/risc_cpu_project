onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -divider CPU_INPUT
add wave -noupdate -label clock /tb_cpu/clk
add wave -noupdate -label reset /tb_cpu/reset

add wave -noupdate -divider PROGRAM_COUNTER
add wave -noupdate -label pc /tb_cpu/cpu/pc
add wave -noupdate -label pc_next /tb_cpu/cpu/pc_next

add wave -noupdate -divider RAW_INSTRUCTIONS
add wave -noupdate -label instr -radix hexadecimal /tb_cpu/cpu/instr
add wave -noupdate -label opcode -radix binary /tb_cpu/cpu/opcode
add wave -noupdate -label funct3 /tb_cpu/cpu/funct3
add wave -noupdate -label funct7 /tb_cpu/cpu/funct7
add wave -noupdate -label reg1_addr /tb_cpu/cpu/rs1
add wave -noupdate -label reg2_addr /tb_cpu/cpu/rs2
add wave -noupdate -label reg_destination /tb_cpu/cpu/rd

add wave -noupdate -divider CONTROL_SIGNALS
add wave -noupdate -label reg_write_en /tb_cpu/cpu/reg_write
add wave -noupdate -label mem_write_en /tb_cpu/cpu/mem_write
add wave -noupdate -label alu_op /tb_cpu/cpu/alu_op
add wave -noupdate -label alu_a_pc /tb_cpu/cpu/alu_a_pc
add wave -noupdate -label alu_b_imm /tb_cpu/cpu/alu_b_imm
add wave -noupdate -label branch /tb_cpu/cpu/branch
add wave -noupdate -label jal /tb_cpu/cpu/jal
add wave -noupdate -label jalr /tb_cpu/cpu/jalr
add wave -noupdate -label imm_type_sel /tb_cpu/cpu/imm_sel
add wave -noupdate -label writeback_sel /tb_cpu/cpu/wb_sel

add wave -noupdate -divider REGFILE
add wave -noupdate -label reg1_data /tb_cpu/cpu/rs1_data
add wave -noupdate -label reg2_data /tb_cpu/cpu/rs2_data
add wave -noupdate -label wb_data /tb_cpu/cpu/wb_data

add wave -noupdate -divider IMMEDIATE
add wave -noupdate -label imm /tb_cpu/cpu/imm

add wave -noupdate -divider ALU
add wave -noupdate -label alu_a /tb_cpu/cpu/alu_a
add wave -noupdate -label alu_b /tb_cpu/cpu/alu_b
add wave -noupdate -label alu_result /tb_cpu/cpu/alu_result
add wave -noupdate -label zero_flag /tb_cpu/cpu/zero

add wave -noupdate -divider EXECUTE_GEN
add wave -noupdate -label take_branch /tb_cpu/cpu/take_branch
add wave -noupdate -label raw_mem_data_loaded /tb_cpu/cpu/mem_data
add wave -noupdate -label formatted_mem_data /tb_cpu/cpu/load_data

add wave -noupdate -divider WRITEBACK
add wave -noupdate -label reg_write_en /tb_cpu/cpu/reg_write
add wave -noupdate -label writeback_sel /tb_cpu/cpu/wb_sel
add wave -noupdate -label wb_data /tb_cpu/cpu/wb_data

add wave -noupdate -divider REGISTERS
add wave -noupdate -label x0 -radix decimal /tb_cpu/cpu/rf/regs[0]
add wave -noupdate -label x1 -radix decimal /tb_cpu/cpu/rf/regs[1]
add wave -noupdate -label x2 -radix decimal /tb_cpu/cpu/rf/regs[2]
add wave -noupdate -label x3 -radix decimal /tb_cpu/cpu/rf/regs[3]
add wave -noupdate -label x4 -radix decimal /tb_cpu/cpu/rf/regs[4]
add wave -noupdate -label x5 -radix decimal /tb_cpu/cpu/rf/regs[5]
add wave -noupdate -label x6 -radix decimal /tb_cpu/cpu/rf/regs[6]
add wave -noupdate -label x7 -radix decimal /tb_cpu/cpu/rf/regs[7]
add wave -noupdate -label x8 -radix decimal /tb_cpu/cpu/rf/regs[8]
add wave -noupdate -label x9 -radix decimal /tb_cpu/cpu/rf/regs[9]
add wave -noupdate -label x10 -radix decimal /tb_cpu/cpu/rf/regs[10]
add wave -noupdate -label x11 -radix decimal /tb_cpu/cpu/rf/regs[11]
add wave -noupdate -label sig_base_addr -radix decimal /tb_cpu/cpu/rf/regs[12]

TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {80000 ps} 0}
quietly wave cursor active 1
configure wave -namecolwidth 77
configure wave -valuecolwidth 49
configure wave -justifyvalue left
configure wave -signalnamewidth 0
configure wave -snapdistance 10
configure wave -datasetprefix 0
configure wave -rowmargin 4
configure wave -childrowmargin 2
configure wave -gridoffset 0
configure wave -gridperiod 1
configure wave -griddelta 40
configure wave -timeline 0
configure wave -timelineunits ns
update
WaveRestoreZoom {0 ps} {280 ns}
