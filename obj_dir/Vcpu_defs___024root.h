// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vcpu_defs.h for the primary calling header

#ifndef VERILATED_VCPU_DEFS___024ROOT_H_
#define VERILATED_VCPU_DEFS___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vcpu_defs__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vcpu_defs___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*3:0*/ tb_alu__DOT__alu_op;
    CData/*0:0*/ __VstlFirstIteration;
    IData/*31:0*/ tb_alu__DOT__a;
    IData/*31:0*/ tb_alu__DOT__b;
    IData/*31:0*/ tb_alu__DOT__uut__DOT__result;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    VlDelayScheduler __VdlySched;

    // INTERNAL VARIABLES
    Vcpu_defs__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vcpu_defs___024root(Vcpu_defs__Syms* symsp, const char* v__name);
    ~Vcpu_defs___024root();
    VL_UNCOPYABLE(Vcpu_defs___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
