// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtb_alu__Syms.h"


void Vtb_alu___024root__trace_chg_0_sub_0(Vtb_alu___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtb_alu___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_alu___024root__trace_chg_0\n"); );
    // Body
    Vtb_alu___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_alu___024root*>(voidSelf);
    Vtb_alu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vtb_alu___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtb_alu___024root__trace_chg_0_sub_0(Vtb_alu___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_alu___024root__trace_chg_0_sub_0\n"); );
    Vtb_alu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    bufp->chgIData(oldp+0,(vlSelfRef.tb_alu__DOT__a),32);
    bufp->chgIData(oldp+1,(vlSelfRef.tb_alu__DOT__b),32);
    bufp->chgCData(oldp+2,(vlSelfRef.tb_alu__DOT__alu_op),4);
    bufp->chgIData(oldp+3,(((8U & (IData)(vlSelfRef.tb_alu__DOT__alu_op))
                             ? ((4U & (IData)(vlSelfRef.tb_alu__DOT__alu_op))
                                 ? 0U : ((2U & (IData)(vlSelfRef.tb_alu__DOT__alu_op))
                                          ? 0U : ((1U 
                                                   & (IData)(vlSelfRef.tb_alu__DOT__alu_op))
                                                   ? 0U
                                                   : 
                                                  ((vlSelfRef.tb_alu__DOT__a 
                                                    < vlSelfRef.tb_alu__DOT__b)
                                                    ? 1U
                                                    : 0U))))
                             : ((4U & (IData)(vlSelfRef.tb_alu__DOT__alu_op))
                                 ? ((2U & (IData)(vlSelfRef.tb_alu__DOT__alu_op))
                                     ? ((1U & (IData)(vlSelfRef.tb_alu__DOT__alu_op))
                                         ? (VL_LTS_III(32, vlSelfRef.tb_alu__DOT__a, vlSelfRef.tb_alu__DOT__b)
                                             ? 1U : 0U)
                                         : (vlSelfRef.tb_alu__DOT__a 
                                            >> (0x0000001fU 
                                                & vlSelfRef.tb_alu__DOT__b)))
                                     : ((1U & (IData)(vlSelfRef.tb_alu__DOT__alu_op))
                                         ? (vlSelfRef.tb_alu__DOT__a 
                                            << (0x0000001fU 
                                                & vlSelfRef.tb_alu__DOT__b))
                                         : (vlSelfRef.tb_alu__DOT__a 
                                            ^ vlSelfRef.tb_alu__DOT__b)))
                                 : ((2U & (IData)(vlSelfRef.tb_alu__DOT__alu_op))
                                     ? ((1U & (IData)(vlSelfRef.tb_alu__DOT__alu_op))
                                         ? (vlSelfRef.tb_alu__DOT__a 
                                            | vlSelfRef.tb_alu__DOT__b)
                                         : (vlSelfRef.tb_alu__DOT__a 
                                            & vlSelfRef.tb_alu__DOT__b))
                                     : ((1U & (IData)(vlSelfRef.tb_alu__DOT__alu_op))
                                         ? (vlSelfRef.tb_alu__DOT__a 
                                            - vlSelfRef.tb_alu__DOT__b)
                                         : (vlSelfRef.tb_alu__DOT__a 
                                            + vlSelfRef.tb_alu__DOT__b)))))),32);
}

void Vtb_alu___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_alu___024root__trace_cleanup\n"); );
    // Locals
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    Vtb_alu___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_alu___024root*>(voidSelf);
    Vtb_alu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
