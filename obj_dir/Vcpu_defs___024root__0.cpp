// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcpu_defs.h for the primary calling header

#include "Vcpu_defs__pch.h"

VL_ATTR_COLD void Vcpu_defs___024root___eval_initial__TOP(Vcpu_defs___024root* vlSelf);
VlCoroutine Vcpu_defs___024root___eval_initial__TOP__Vtiming__0(Vcpu_defs___024root* vlSelf);

void Vcpu_defs___024root___eval_initial(Vcpu_defs___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_defs___024root___eval_initial\n"); );
    Vcpu_defs__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vcpu_defs___024root___eval_initial__TOP(vlSelf);
    Vcpu_defs___024root___eval_initial__TOP__Vtiming__0(vlSelf);
}

VlCoroutine Vcpu_defs___024root___eval_initial__TOP__Vtiming__0(Vcpu_defs___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_defs___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vcpu_defs__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_WRITEF_NX("=== ALU Unit Test ===\n",0);
    vlSelfRef.tb_alu__DOT__a = 0x0000000aU;
    vlSelfRef.tb_alu__DOT__b = 5U;
    vlSelfRef.tb_alu__DOT__alu_op = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_alu.sv", 
                                         38);
    VL_WRITEF_NX("ADD: %0# + %0# = %0#\n",0,32,vlSelfRef.tb_alu__DOT__a,
                 32,vlSelfRef.tb_alu__DOT__b,32,vlSelfRef.tb_alu__DOT__uut__DOT__result);
    vlSelfRef.tb_alu__DOT__alu_op = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_alu.sv", 
                                         42);
    VL_WRITEF_NX("SUB: %0# - %0# = %0#\n",0,32,vlSelfRef.tb_alu__DOT__a,
                 32,vlSelfRef.tb_alu__DOT__b,32,vlSelfRef.tb_alu__DOT__uut__DOT__result);
    vlSelfRef.tb_alu__DOT__alu_op = 2U;
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_alu.sv", 
                                         46);
    VL_WRITEF_NX("AND: %0# & %0# = %0#\n",0,32,vlSelfRef.tb_alu__DOT__a,
                 32,vlSelfRef.tb_alu__DOT__b,32,vlSelfRef.tb_alu__DOT__uut__DOT__result);
    vlSelfRef.tb_alu__DOT__alu_op = 3U;
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_alu.sv", 
                                         50);
    VL_WRITEF_NX("OR: %0# | %0# = %0#\n",0,32,vlSelfRef.tb_alu__DOT__a,
                 32,vlSelfRef.tb_alu__DOT__b,32,vlSelfRef.tb_alu__DOT__uut__DOT__result);
    vlSelfRef.tb_alu__DOT__alu_op = 4U;
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_alu.sv", 
                                         54);
    VL_WRITEF_NX("XOR: %0# ^ %0# = %0#\n",0,32,vlSelfRef.tb_alu__DOT__a,
                 32,vlSelfRef.tb_alu__DOT__b,32,vlSelfRef.tb_alu__DOT__uut__DOT__result);
    vlSelfRef.tb_alu__DOT__alu_op = 5U;
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_alu.sv", 
                                         58);
    VL_WRITEF_NX("SLL: %0# << %0# = %0#\n",0,32,vlSelfRef.tb_alu__DOT__a,
                 5,(0x0000001fU & vlSelfRef.tb_alu__DOT__b),
                 32,vlSelfRef.tb_alu__DOT__uut__DOT__result);
    vlSelfRef.tb_alu__DOT__alu_op = 6U;
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_alu.sv", 
                                         62);
    VL_WRITEF_NX("SRL: %0# >> %0# = %0#\n",0,32,vlSelfRef.tb_alu__DOT__a,
                 5,(0x0000001fU & vlSelfRef.tb_alu__DOT__b),
                 32,vlSelfRef.tb_alu__DOT__uut__DOT__result);
    vlSelfRef.tb_alu__DOT__a = 0xfffffffbU;
    vlSelfRef.tb_alu__DOT__b = 3U;
    vlSelfRef.tb_alu__DOT__alu_op = 7U;
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_alu.sv", 
                                         67);
    VL_WRITEF_NX("SLT: %0# < %0# ? 1:0 = %0#\n",0,32,
                 vlSelfRef.tb_alu__DOT__a,32,vlSelfRef.tb_alu__DOT__b,
                 32,vlSelfRef.tb_alu__DOT__uut__DOT__result);
    vlSelfRef.tb_alu__DOT__a = 0xffffffffU;
    vlSelfRef.tb_alu__DOT__b = 1U;
    vlSelfRef.tb_alu__DOT__alu_op = 8U;
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_alu.sv", 
                                         72);
    VL_WRITEF_NX("SLTU: %0# < %0# ? 1:0 = %0#\n=== ALU Test Complete ===\n",0,
                 32,vlSelfRef.tb_alu__DOT__a,32,vlSelfRef.tb_alu__DOT__b,
                 32,vlSelfRef.tb_alu__DOT__uut__DOT__result);
    VL_FINISH_MT("tb/tb_alu.sv", 76, "");
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vcpu_defs___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void Vcpu_defs___024root___eval_triggers__act(Vcpu_defs___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_defs___024root___eval_triggers__act\n"); );
    Vcpu_defs__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(vlSelfRef.__VdlySched.awaitingCurrentTime()));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vcpu_defs___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
}

bool Vcpu_defs___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_defs___024root___trigger_anySet__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void Vcpu_defs___024root___act_sequent__TOP__0(Vcpu_defs___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_defs___024root___act_sequent__TOP__0\n"); );
    Vcpu_defs__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_alu__DOT__uut__DOT__result = ((8U 
                                                & (IData)(vlSelfRef.tb_alu__DOT__alu_op))
                                                ? (
                                                   (4U 
                                                    & (IData)(vlSelfRef.tb_alu__DOT__alu_op))
                                                    ? 0U
                                                    : 
                                                   ((2U 
                                                     & (IData)(vlSelfRef.tb_alu__DOT__alu_op))
                                                     ? 0U
                                                     : 
                                                    ((1U 
                                                      & (IData)(vlSelfRef.tb_alu__DOT__alu_op))
                                                      ? 0U
                                                      : 
                                                     ((vlSelfRef.tb_alu__DOT__a 
                                                       < vlSelfRef.tb_alu__DOT__b)
                                                       ? 1U
                                                       : 0U))))
                                                : (
                                                   (4U 
                                                    & (IData)(vlSelfRef.tb_alu__DOT__alu_op))
                                                    ? 
                                                   ((2U 
                                                     & (IData)(vlSelfRef.tb_alu__DOT__alu_op))
                                                     ? 
                                                    ((1U 
                                                      & (IData)(vlSelfRef.tb_alu__DOT__alu_op))
                                                      ? 
                                                     (VL_LTS_III(32, vlSelfRef.tb_alu__DOT__a, vlSelfRef.tb_alu__DOT__b)
                                                       ? 1U
                                                       : 0U)
                                                      : 
                                                     (vlSelfRef.tb_alu__DOT__a 
                                                      >> 
                                                      (0x0000001fU 
                                                       & vlSelfRef.tb_alu__DOT__b)))
                                                     : 
                                                    ((1U 
                                                      & (IData)(vlSelfRef.tb_alu__DOT__alu_op))
                                                      ? 
                                                     (vlSelfRef.tb_alu__DOT__a 
                                                      << 
                                                      (0x0000001fU 
                                                       & vlSelfRef.tb_alu__DOT__b))
                                                      : 
                                                     (vlSelfRef.tb_alu__DOT__a 
                                                      ^ vlSelfRef.tb_alu__DOT__b)))
                                                    : 
                                                   ((2U 
                                                     & (IData)(vlSelfRef.tb_alu__DOT__alu_op))
                                                     ? 
                                                    ((1U 
                                                      & (IData)(vlSelfRef.tb_alu__DOT__alu_op))
                                                      ? 
                                                     (vlSelfRef.tb_alu__DOT__a 
                                                      | vlSelfRef.tb_alu__DOT__b)
                                                      : 
                                                     (vlSelfRef.tb_alu__DOT__a 
                                                      & vlSelfRef.tb_alu__DOT__b))
                                                     : 
                                                    ((1U 
                                                      & (IData)(vlSelfRef.tb_alu__DOT__alu_op))
                                                      ? 
                                                     (vlSelfRef.tb_alu__DOT__a 
                                                      - vlSelfRef.tb_alu__DOT__b)
                                                      : 
                                                     (vlSelfRef.tb_alu__DOT__a 
                                                      + vlSelfRef.tb_alu__DOT__b)))));
}

void Vcpu_defs___024root___eval_act(Vcpu_defs___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_defs___024root___eval_act\n"); );
    Vcpu_defs__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered[0U])) {
        Vcpu_defs___024root___act_sequent__TOP__0(vlSelf);
    }
}

void Vcpu_defs___024root___eval_nba(Vcpu_defs___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_defs___024root___eval_nba\n"); );
    Vcpu_defs__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vcpu_defs___024root___act_sequent__TOP__0(vlSelf);
    }
}

void Vcpu_defs___024root___timing_resume(Vcpu_defs___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_defs___024root___timing_resume\n"); );
    Vcpu_defs__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vcpu_defs___024root___trigger_orInto__act(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_defs___024root___trigger_orInto__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vcpu_defs___024root___eval_phase__act(Vcpu_defs___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_defs___024root___eval_phase__act\n"); );
    Vcpu_defs__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VactExecute;
    // Body
    Vcpu_defs___024root___eval_triggers__act(vlSelf);
    Vcpu_defs___024root___trigger_orInto__act(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    __VactExecute = Vcpu_defs___024root___trigger_anySet__act(vlSelfRef.__VactTriggered);
    if (__VactExecute) {
        Vcpu_defs___024root___timing_resume(vlSelf);
        Vcpu_defs___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

void Vcpu_defs___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_defs___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vcpu_defs___024root___eval_phase__nba(Vcpu_defs___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_defs___024root___eval_phase__nba\n"); );
    Vcpu_defs__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vcpu_defs___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vcpu_defs___024root___eval_nba(vlSelf);
        Vcpu_defs___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vcpu_defs___024root___eval(Vcpu_defs___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_defs___024root___eval\n"); );
    Vcpu_defs__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vcpu_defs___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("tb/tb_alu.sv", 6, "", "NBA region did not converge after 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vcpu_defs___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("tb/tb_alu.sv", 6, "", "Active region did not converge after 100 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
        } while (Vcpu_defs___024root___eval_phase__act(vlSelf));
    } while (Vcpu_defs___024root___eval_phase__nba(vlSelf));
}

#ifdef VL_DEBUG
void Vcpu_defs___024root___eval_debug_assertions(Vcpu_defs___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_defs___024root___eval_debug_assertions\n"); );
    Vcpu_defs__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
