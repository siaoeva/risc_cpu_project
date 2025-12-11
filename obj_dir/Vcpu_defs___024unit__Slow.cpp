// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcpu_defs.h for the primary calling header

#include "Vcpu_defs__pch.h"

void Vcpu_defs___024unit___ctor_var_reset(Vcpu_defs___024unit* vlSelf);

Vcpu_defs___024unit::Vcpu_defs___024unit(Vcpu_defs__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vcpu_defs___024unit___ctor_var_reset(this);
}

void Vcpu_defs___024unit::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vcpu_defs___024unit::~Vcpu_defs___024unit() {
}
