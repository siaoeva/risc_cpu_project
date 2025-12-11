// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_regfile.h for the primary calling header

#include "Vtb_regfile__pch.h"

void Vtb_regfile___024root___ctor_var_reset(Vtb_regfile___024root* vlSelf);

Vtb_regfile___024root::Vtb_regfile___024root(Vtb_regfile__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtb_regfile___024root___ctor_var_reset(this);
}

void Vtb_regfile___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtb_regfile___024root::~Vtb_regfile___024root() {
}
