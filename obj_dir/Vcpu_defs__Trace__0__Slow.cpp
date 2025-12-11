// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vcpu_defs__Syms.h"


VL_ATTR_COLD void Vcpu_defs___024root__trace_init_sub__TOP__0(Vcpu_defs___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_defs___024root__trace_init_sub__TOP__0\n"); );
    Vcpu_defs__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->pushPrefix("tb_alu", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1,0,"a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+2,0,"b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+3,0,"alu_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+4,0,"result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("uut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+2,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+3,0,"alu_op",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+4,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vcpu_defs___024root__trace_init_top(Vcpu_defs___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_defs___024root__trace_init_top\n"); );
    Vcpu_defs__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vcpu_defs___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vcpu_defs___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vcpu_defs___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vcpu_defs___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vcpu_defs___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vcpu_defs___024root__trace_register(Vcpu_defs___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_defs___024root__trace_register\n"); );
    Vcpu_defs__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vcpu_defs___024root__trace_const_0, 0, vlSelf);
    tracep->addFullCb(&Vcpu_defs___024root__trace_full_0, 0, vlSelf);
    tracep->addChgCb(&Vcpu_defs___024root__trace_chg_0, 0, vlSelf);
    tracep->addCleanupCb(&Vcpu_defs___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vcpu_defs___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_defs___024root__trace_const_0\n"); );
    // Body
    Vcpu_defs___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vcpu_defs___024root*>(voidSelf);
    Vcpu_defs__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
}

VL_ATTR_COLD void Vcpu_defs___024root__trace_full_0_sub_0(Vcpu_defs___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vcpu_defs___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_defs___024root__trace_full_0\n"); );
    // Body
    Vcpu_defs___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vcpu_defs___024root*>(voidSelf);
    Vcpu_defs__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vcpu_defs___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vcpu_defs___024root__trace_full_0_sub_0(Vcpu_defs___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_defs___024root__trace_full_0_sub_0\n"); );
    Vcpu_defs__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullIData(oldp+1,(vlSelfRef.tb_alu__DOT__a),32);
    bufp->fullIData(oldp+2,(vlSelfRef.tb_alu__DOT__b),32);
    bufp->fullCData(oldp+3,(vlSelfRef.tb_alu__DOT__alu_op),4);
    bufp->fullIData(oldp+4,(((8U & (IData)(vlSelfRef.tb_alu__DOT__alu_op))
                              ? ((4U & (IData)(vlSelfRef.tb_alu__DOT__alu_op))
                                  ? 0U : ((2U & (IData)(vlSelfRef.tb_alu__DOT__alu_op))
                                           ? 0U : (
                                                   (1U 
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
