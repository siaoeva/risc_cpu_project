# stop any simulation that is currently running
quit -sim


# create the default "work" library
vlib work;

# compile the systemverilog source code in the parent folder
vlog -sv +acc ../rtl/*.sv
# compile the systemverilog code of the testbench
vlog -sv +acc *.sv
# start the Simulator
vsim +acc work.tb_cpu -Lf 220model_ver -Lf altera_mf_ver -Lf verilog
# show waveforms specified in wave.do
do wave.do
# advance the simulation the desired amount of time
run 360 ns
