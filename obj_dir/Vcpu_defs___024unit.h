// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vcpu_defs.h for the primary calling header

#ifndef VERILATED_VCPU_DEFS___024UNIT_H_
#define VERILATED_VCPU_DEFS___024UNIT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vcpu_defs__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vcpu_defs___024unit final : public VerilatedModule {
  public:

    // INTERNAL VARIABLES
    Vcpu_defs__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vcpu_defs___024unit(Vcpu_defs__Syms* symsp, const char* v__name);
    ~Vcpu_defs___024unit();
    VL_UNCOPYABLE(Vcpu_defs___024unit);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
