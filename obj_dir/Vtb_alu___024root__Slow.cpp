// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_alu.h for the primary calling header

#include "Vtb_alu__pch.h"

void Vtb_alu___024root___ctor_var_reset(Vtb_alu___024root* vlSelf);

Vtb_alu___024root::Vtb_alu___024root(Vtb_alu__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtb_alu___024root___ctor_var_reset(this);
}

void Vtb_alu___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtb_alu___024root::~Vtb_alu___024root() {
}
