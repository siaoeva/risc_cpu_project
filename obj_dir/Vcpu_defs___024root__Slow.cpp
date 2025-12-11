// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcpu_defs.h for the primary calling header

#include "Vcpu_defs__pch.h"

void Vcpu_defs___024root___ctor_var_reset(Vcpu_defs___024root* vlSelf);

Vcpu_defs___024root::Vcpu_defs___024root(Vcpu_defs__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vcpu_defs___024root___ctor_var_reset(this);
}

void Vcpu_defs___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vcpu_defs___024root::~Vcpu_defs___024root() {
}
