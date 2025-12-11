// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_regfile.h for the primary calling header

#include "Vtb_regfile__pch.h"

VL_ATTR_COLD void Vtb_regfile___024root___eval_initial__TOP(Vtb_regfile___024root* vlSelf);
VlCoroutine Vtb_regfile___024root___eval_initial__TOP__Vtiming__0(Vtb_regfile___024root* vlSelf);
VlCoroutine Vtb_regfile___024root___eval_initial__TOP__Vtiming__1(Vtb_regfile___024root* vlSelf);

void Vtb_regfile___024root___eval_initial(Vtb_regfile___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_regfile___024root___eval_initial\n"); );
    Vtb_regfile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_regfile___024root___eval_initial__TOP(vlSelf);
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    Vtb_regfile___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb_regfile___024root___eval_initial__TOP__Vtiming__1(vlSelf);
}

VlCoroutine Vtb_regfile___024root___eval_initial__TOP__Vtiming__0(Vtb_regfile___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_regfile___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vtb_regfile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_WRITEF_NX("=== Register File Test ===\n",0);
    vlSelfRef.tb_regfile__DOT__rs1 = 1U;
    vlSelfRef.tb_regfile__DOT__rs2 = 2U;
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_regfile.sv", 
                                         44);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_WRITEF_NX("Read x1 = %0#, x2= %0#. Expected x1 = x2 = 0.\n",0,
                 32,vlSelfRef.tb_regfile__DOT__uut__DOT__rs1_data,
                 32,vlSelfRef.tb_regfile__DOT__uut__DOT__rs2_data);
    vlSelfRef.tb_regfile__DOT__rd = 1U;
    vlSelfRef.tb_regfile__DOT__wdata = 0x0000002aU;
    vlSelfRef.tb_regfile__DOT__we = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x0000000000002710ULL, 
                                         nullptr, "tb/tb_regfile.sv", 
                                         49);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb_regfile__DOT__we = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_regfile.sv", 
                                         51);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_WRITEF_NX("After write: x1 = %0#, x2 = %0#. Expected x1 = 42, x2 = 0.\n",0,
                 32,vlSelfRef.tb_regfile__DOT__uut__DOT__rs1_data,
                 32,vlSelfRef.tb_regfile__DOT__uut__DOT__rs2_data);
    vlSelfRef.tb_regfile__DOT__rd = 0U;
    vlSelfRef.tb_regfile__DOT__wdata = 0x00000063U;
    vlSelfRef.tb_regfile__DOT__we = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x0000000000002710ULL, 
                                         nullptr, "tb/tb_regfile.sv", 
                                         56);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb_regfile__DOT__we = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_regfile.sv", 
                                         57);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_WRITEF_NX("After write: x0 = %0#. Expected always x0 = 0.\n",0,
                 32,vlSelfRef.tb_regfile__DOT__uut__DOT__regs
                 [0U]);
    vlSelfRef.tb_regfile__DOT__rd = 2U;
    vlSelfRef.tb_regfile__DOT__wdata = 5U;
    vlSelfRef.tb_regfile__DOT__we = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x0000000000002710ULL, 
                                         nullptr, "tb/tb_regfile.sv", 
                                         62);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb_regfile__DOT__we = 0U;
    vlSelfRef.tb_regfile__DOT__rs1 = 1U;
    vlSelfRef.tb_regfile__DOT__rs2 = 2U;
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_regfile.sv", 
                                         64);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_WRITEF_NX("After write: x1 = %0#, x2 = %0#. Expected x1 = 42, x2 = 5.\n=== Register File Test Complete ===\n",0,
                 32,vlSelfRef.tb_regfile__DOT__uut__DOT__rs1_data,
                 32,vlSelfRef.tb_regfile__DOT__uut__DOT__rs2_data);
    VL_FINISH_MT("tb/tb_regfile.sv", 69, "");
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
}

VlCoroutine Vtb_regfile___024root___eval_initial__TOP__Vtiming__1(Vtb_regfile___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_regfile___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vtb_regfile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        co_await vlSelfRef.__VdlySched.delay(0x0000000000001388ULL, 
                                             nullptr, 
                                             "tb/tb_regfile.sv", 
                                             37);
        vlSelfRef.tb_regfile__DOT__clk = (1U & (~ (IData)(vlSelfRef.tb_regfile__DOT__clk)));
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_regfile___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void Vtb_regfile___024root___eval_triggers__act(Vtb_regfile___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_regfile___024root___eval_triggers__act\n"); );
    Vtb_regfile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    ((vlSelfRef.__VdlySched.awaitingCurrentTime() 
                                                      << 1U) 
                                                     | ((IData)(vlSelfRef.tb_regfile__DOT__clk) 
                                                        & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_regfile__DOT__clk__0))))));
    vlSelfRef.__Vtrigprevexpr___TOP__tb_regfile__DOT__clk__0 
        = vlSelfRef.tb_regfile__DOT__clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_regfile___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
}

bool Vtb_regfile___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_regfile___024root___trigger_anySet__act\n"); );
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

void Vtb_regfile___024root___act_sequent__TOP__0(Vtb_regfile___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_regfile___024root___act_sequent__TOP__0\n"); );
    Vtb_regfile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_regfile__DOT__uut__DOT__rs1_data = 
        ((0U == (IData)(vlSelfRef.tb_regfile__DOT__rs1))
          ? 0U : vlSelfRef.tb_regfile__DOT__uut__DOT__regs
         [vlSelfRef.tb_regfile__DOT__rs1]);
    vlSelfRef.tb_regfile__DOT__uut__DOT__rs2_data = 
        ((0U == (IData)(vlSelfRef.tb_regfile__DOT__rs2))
          ? 0U : vlSelfRef.tb_regfile__DOT__uut__DOT__regs
         [vlSelfRef.tb_regfile__DOT__rs2]);
}

void Vtb_regfile___024root___eval_act(Vtb_regfile___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_regfile___024root___eval_act\n"); );
    Vtb_regfile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((2ULL & vlSelfRef.__VactTriggered[0U])) {
        Vtb_regfile___024root___act_sequent__TOP__0(vlSelf);
    }
}

void Vtb_regfile___024root___nba_sequent__TOP__0(Vtb_regfile___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_regfile___024root___nba_sequent__TOP__0\n"); );
    Vtb_regfile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VdlyVal__tb_regfile__DOT__uut__DOT__regs__v0;
    __VdlyVal__tb_regfile__DOT__uut__DOT__regs__v0 = 0;
    CData/*4:0*/ __VdlyDim0__tb_regfile__DOT__uut__DOT__regs__v0;
    __VdlyDim0__tb_regfile__DOT__uut__DOT__regs__v0 = 0;
    CData/*0:0*/ __VdlySet__tb_regfile__DOT__uut__DOT__regs__v0;
    __VdlySet__tb_regfile__DOT__uut__DOT__regs__v0 = 0;
    // Body
    __VdlySet__tb_regfile__DOT__uut__DOT__regs__v0 = 0U;
    if (((IData)(vlSelfRef.tb_regfile__DOT__we) & (0U 
                                                   != (IData)(vlSelfRef.tb_regfile__DOT__rd)))) {
        __VdlyVal__tb_regfile__DOT__uut__DOT__regs__v0 
            = vlSelfRef.tb_regfile__DOT__wdata;
        __VdlyDim0__tb_regfile__DOT__uut__DOT__regs__v0 
            = vlSelfRef.tb_regfile__DOT__rd;
        __VdlySet__tb_regfile__DOT__uut__DOT__regs__v0 = 1U;
    }
    if (__VdlySet__tb_regfile__DOT__uut__DOT__regs__v0) {
        vlSelfRef.tb_regfile__DOT__uut__DOT__regs[__VdlyDim0__tb_regfile__DOT__uut__DOT__regs__v0] 
            = __VdlyVal__tb_regfile__DOT__uut__DOT__regs__v0;
    }
}

void Vtb_regfile___024root___eval_nba(Vtb_regfile___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_regfile___024root___eval_nba\n"); );
    Vtb_regfile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtb_regfile___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtb_regfile___024root___act_sequent__TOP__0(vlSelf);
    }
}

void Vtb_regfile___024root___timing_resume(Vtb_regfile___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_regfile___024root___timing_resume\n"); );
    Vtb_regfile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((2ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vtb_regfile___024root___trigger_orInto__act(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_regfile___024root___trigger_orInto__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vtb_regfile___024root___eval_phase__act(Vtb_regfile___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_regfile___024root___eval_phase__act\n"); );
    Vtb_regfile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_regfile___024root___eval_triggers__act(vlSelf);
    Vtb_regfile___024root___trigger_orInto__act(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    __VactExecute = Vtb_regfile___024root___trigger_anySet__act(vlSelfRef.__VactTriggered);
    if (__VactExecute) {
        Vtb_regfile___024root___timing_resume(vlSelf);
        Vtb_regfile___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

void Vtb_regfile___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_regfile___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vtb_regfile___024root___eval_phase__nba(Vtb_regfile___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_regfile___024root___eval_phase__nba\n"); );
    Vtb_regfile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtb_regfile___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vtb_regfile___024root___eval_nba(vlSelf);
        Vtb_regfile___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vtb_regfile___024root___eval(Vtb_regfile___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_regfile___024root___eval\n"); );
    Vtb_regfile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtb_regfile___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("tb/tb_regfile.sv", 5, "", "NBA region did not converge after 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtb_regfile___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("tb/tb_regfile.sv", 5, "", "Active region did not converge after 100 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
        } while (Vtb_regfile___024root___eval_phase__act(vlSelf));
    } while (Vtb_regfile___024root___eval_phase__nba(vlSelf));
}

#ifdef VL_DEBUG
void Vtb_regfile___024root___eval_debug_assertions(Vtb_regfile___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_regfile___024root___eval_debug_assertions\n"); );
    Vtb_regfile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
