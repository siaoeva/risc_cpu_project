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

add wave -noupdate -divider IMMEDIATE

add wave -noupdate -divider ALU

add wave -noupdate -divider EXECUTE_GEN

add wave -noupdate -divider WRITEBACK

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
WaveRestoreZoom {0 ps} {180 ns}
