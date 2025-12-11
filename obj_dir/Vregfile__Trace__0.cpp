// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vregfile__Syms.h"


void Vregfile___024root__trace_chg_0_sub_0(Vregfile___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vregfile___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregfile___024root__trace_chg_0\n"); );
    // Body
    Vregfile___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vregfile___024root*>(voidSelf);
    Vregfile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vregfile___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vregfile___024root__trace_chg_0_sub_0(Vregfile___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregfile___024root__trace_chg_0_sub_0\n"); );
    Vregfile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity
                      [2U])))) {
        bufp->chgBit(oldp+0,(vlSelfRef.tb_regfile__DOT__we));
        bufp->chgCData(oldp+1,(vlSelfRef.tb_regfile__DOT__rs1),5);
        bufp->chgCData(oldp+2,(vlSelfRef.tb_regfile__DOT__rs2),5);
        bufp->chgCData(oldp+3,(vlSelfRef.tb_regfile__DOT__rd),5);
        bufp->chgIData(oldp+4,(vlSelfRef.tb_regfile__DOT__wdata),32);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[3U]))) {
        bufp->chgIData(oldp+5,(vlSelfRef.tb_regfile__DOT__uut__DOT__regs[0]),32);
        bufp->chgIData(oldp+6,(vlSelfRef.tb_regfile__DOT__uut__DOT__regs[1]),32);
        bufp->chgIData(oldp+7,(vlSelfRef.tb_regfile__DOT__uut__DOT__regs[2]),32);
        bufp->chgIData(oldp+8,(vlSelfRef.tb_regfile__DOT__uut__DOT__regs[3]),32);
        bufp->chgIData(oldp+9,(vlSelfRef.tb_regfile__DOT__uut__DOT__regs[4]),32);
        bufp->chgIData(oldp+10,(vlSelfRef.tb_regfile__DOT__uut__DOT__regs[5]),32);
        bufp->chgIData(oldp+11,(vlSelfRef.tb_regfile__DOT__uut__DOT__regs[6]),32);
        bufp->chgIData(oldp+12,(vlSelfRef.tb_regfile__DOT__uut__DOT__regs[7]),32);
        bufp->chgIData(oldp+13,(vlSelfRef.tb_regfile__DOT__uut__DOT__regs[8]),32);
        bufp->chgIData(oldp+14,(vlSelfRef.tb_regfile__DOT__uut__DOT__regs[9]),32);
        bufp->chgIData(oldp+15,(vlSelfRef.tb_regfile__DOT__uut__DOT__regs[10]),32);
        bufp->chgIData(oldp+16,(vlSelfRef.tb_regfile__DOT__uut__DOT__regs[11]),32);
        bufp->chgIData(oldp+17,(vlSelfRef.tb_regfile__DOT__uut__DOT__regs[12]),32);
        bufp->chgIData(oldp+18,(vlSelfRef.tb_regfile__DOT__uut__DOT__regs[13]),32);
        bufp->chgIData(oldp+19,(vlSelfRef.tb_regfile__DOT__uut__DOT__regs[14]),32);
        bufp->chgIData(oldp+20,(vlSelfRef.tb_regfile__DOT__uut__DOT__regs[15]),32);
        bufp->chgIData(oldp+21,(vlSelfRef.tb_regfile__DOT__uut__DOT__regs[16]),32);
        bufp->chgIData(oldp+22,(vlSelfRef.tb_regfile__DOT__uut__DOT__regs[17]),32);
        bufp->chgIData(oldp+23,(vlSelfRef.tb_regfile__DOT__uut__DOT__regs[18]),32);
        bufp->chgIData(oldp+24,(vlSelfRef.tb_regfile__DOT__uut__DOT__regs[19]),32);
        bufp->chgIData(oldp+25,(vlSelfRef.tb_regfile__DOT__uut__DOT__regs[20]),32);
        bufp->chgIData(oldp+26,(vlSelfRef.tb_regfile__DOT__uut__DOT__regs[21]),32);
        bufp->chgIData(oldp+27,(vlSelfRef.tb_regfile__DOT__uut__DOT__regs[22]),32);
        bufp->chgIData(oldp+28,(vlSelfRef.tb_regfile__DOT__uut__DOT__regs[23]),32);
        bufp->chgIData(oldp+29,(vlSelfRef.tb_regfile__DOT__uut__DOT__regs[24]),32);
        bufp->chgIData(oldp+30,(vlSelfRef.tb_regfile__DOT__uut__DOT__regs[25]),32);
        bufp->chgIData(oldp+31,(vlSelfRef.tb_regfile__DOT__uut__DOT__regs[26]),32);
        bufp->chgIData(oldp+32,(vlSelfRef.tb_regfile__DOT__uut__DOT__regs[27]),32);
        bufp->chgIData(oldp+33,(vlSelfRef.tb_regfile__DOT__uut__DOT__regs[28]),32);
        bufp->chgIData(oldp+34,(vlSelfRef.tb_regfile__DOT__uut__DOT__regs[29]),32);
        bufp->chgIData(oldp+35,(vlSelfRef.tb_regfile__DOT__uut__DOT__regs[30]),32);
        bufp->chgIData(oldp+36,(vlSelfRef.tb_regfile__DOT__uut__DOT__regs[31]),32);
    }
    bufp->chgBit(oldp+37,(vlSelfRef.tb_regfile__DOT__clk));
    bufp->chgIData(oldp+38,(((0U == (IData)(vlSelfRef.tb_regfile__DOT__rs1))
                              ? 0U : vlSelfRef.tb_regfile__DOT__uut__DOT__regs
                             [vlSelfRef.tb_regfile__DOT__rs1])),32);
    bufp->chgIData(oldp+39,(((0U == (IData)(vlSelfRef.tb_regfile__DOT__rs2))
                              ? 0U : vlSelfRef.tb_regfile__DOT__uut__DOT__regs
                             [vlSelfRef.tb_regfile__DOT__rs2])),32);
}

void Vregfile___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregfile___024root__trace_cleanup\n"); );
    // Body
    Vregfile___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vregfile___024root*>(voidSelf);
    Vregfile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
}
