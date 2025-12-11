// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vregfile__Syms.h"


VL_ATTR_COLD void Vregfile___024root__trace_init_sub__TOP__0(Vregfile___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregfile___024root__trace_init_sub__TOP__0\n"); );
    Vregfile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->pushPrefix("tb_regfile", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+38,0,"clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+2,0,"rs1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+3,0,"rs2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+4,0,"rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+5,0,"wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+39,0,"rs1_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+40,0,"rs2_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("uut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+38,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+2,0,"rs1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+3,0,"rs2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+4,0,"rd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+5,0,"wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+39,0,"rs1_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+40,0,"rs2_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("regs", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+6+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vregfile___024root__trace_init_top(Vregfile___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregfile___024root__trace_init_top\n"); );
    Vregfile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vregfile___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vregfile___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vregfile___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vregfile___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vregfile___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vregfile___024root__trace_register(Vregfile___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregfile___024root__trace_register\n"); );
    Vregfile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vregfile___024root__trace_const_0, 0, vlSelf);
    tracep->addFullCb(&Vregfile___024root__trace_full_0, 0, vlSelf);
    tracep->addChgCb(&Vregfile___024root__trace_chg_0, 0, vlSelf);
    tracep->addCleanupCb(&Vregfile___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vregfile___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregfile___024root__trace_const_0\n"); );
    // Body
    Vregfile___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vregfile___024root*>(voidSelf);
    Vregfile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
}

VL_ATTR_COLD void Vregfile___024root__trace_full_0_sub_0(Vregfile___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vregfile___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregfile___024root__trace_full_0\n"); );
    // Body
    Vregfile___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vregfile___024root*>(voidSelf);
    Vregfile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vregfile___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vregfile___024root__trace_full_0_sub_0(Vregfile___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregfile___024root__trace_full_0_sub_0\n"); );
    Vregfile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullBit(oldp+1,(vlSelfRef.tb_regfile__DOT__we));
    bufp->fullCData(oldp+2,(vlSelfRef.tb_regfile__DOT__rs1),5);
    bufp->fullCData(oldp+3,(vlSelfRef.tb_regfile__DOT__rs2),5);
    bufp->fullCData(oldp+4,(vlSelfRef.tb_regfile__DOT__rd),5);
    bufp->fullIData(oldp+5,(vlSelfRef.tb_regfile__DOT__wdata),32);
    bufp->fullIData(oldp+6,(vlSelfRef.tb_regfile__DOT__uut__DOT__regs[0]),32);
    bufp->fullIData(oldp+7,(vlSelfRef.tb_regfile__DOT__uut__DOT__regs[1]),32);
    bufp->fullIData(oldp+8,(vlSelfRef.tb_regfile__DOT__uut__DOT__regs[2]),32);
    bufp->fullIData(oldp+9,(vlSelfRef.tb_regfile__DOT__uut__DOT__regs[3]),32);
    bufp->fullIData(oldp+10,(vlSelfRef.tb_regfile__DOT__uut__DOT__regs[4]),32);
    bufp->fullIData(oldp+11,(vlSelfRef.tb_regfile__DOT__uut__DOT__regs[5]),32);
    bufp->fullIData(oldp+12,(vlSelfRef.tb_regfile__DOT__uut__DOT__regs[6]),32);
    bufp->fullIData(oldp+13,(vlSelfRef.tb_regfile__DOT__uut__DOT__regs[7]),32);
    bufp->fullIData(oldp+14,(vlSelfRef.tb_regfile__DOT__uut__DOT__regs[8]),32);
    bufp->fullIData(oldp+15,(vlSelfRef.tb_regfile__DOT__uut__DOT__regs[9]),32);
    bufp->fullIData(oldp+16,(vlSelfRef.tb_regfile__DOT__uut__DOT__regs[10]),32);
    bufp->fullIData(oldp+17,(vlSelfRef.tb_regfile__DOT__uut__DOT__regs[11]),32);
    bufp->fullIData(oldp+18,(vlSelfRef.tb_regfile__DOT__uut__DOT__regs[12]),32);
    bufp->fullIData(oldp+19,(vlSelfRef.tb_regfile__DOT__uut__DOT__regs[13]),32);
    bufp->fullIData(oldp+20,(vlSelfRef.tb_regfile__DOT__uut__DOT__regs[14]),32);
    bufp->fullIData(oldp+21,(vlSelfRef.tb_regfile__DOT__uut__DOT__regs[15]),32);
    bufp->fullIData(oldp+22,(vlSelfRef.tb_regfile__DOT__uut__DOT__regs[16]),32);
    bufp->fullIData(oldp+23,(vlSelfRef.tb_regfile__DOT__uut__DOT__regs[17]),32);
    bufp->fullIData(oldp+24,(vlSelfRef.tb_regfile__DOT__uut__DOT__regs[18]),32);
    bufp->fullIData(oldp+25,(vlSelfRef.tb_regfile__DOT__uut__DOT__regs[19]),32);
    bufp->fullIData(oldp+26,(vlSelfRef.tb_regfile__DOT__uut__DOT__regs[20]),32);
    bufp->fullIData(oldp+27,(vlSelfRef.tb_regfile__DOT__uut__DOT__regs[21]),32);
    bufp->fullIData(oldp+28,(vlSelfRef.tb_regfile__DOT__uut__DOT__regs[22]),32);
    bufp->fullIData(oldp+29,(vlSelfRef.tb_regfile__DOT__uut__DOT__regs[23]),32);
    bufp->fullIData(oldp+30,(vlSelfRef.tb_regfile__DOT__uut__DOT__regs[24]),32);
    bufp->fullIData(oldp+31,(vlSelfRef.tb_regfile__DOT__uut__DOT__regs[25]),32);
    bufp->fullIData(oldp+32,(vlSelfRef.tb_regfile__DOT__uut__DOT__regs[26]),32);
    bufp->fullIData(oldp+33,(vlSelfRef.tb_regfile__DOT__uut__DOT__regs[27]),32);
    bufp->fullIData(oldp+34,(vlSelfRef.tb_regfile__DOT__uut__DOT__regs[28]),32);
    bufp->fullIData(oldp+35,(vlSelfRef.tb_regfile__DOT__uut__DOT__regs[29]),32);
    bufp->fullIData(oldp+36,(vlSelfRef.tb_regfile__DOT__uut__DOT__regs[30]),32);
    bufp->fullIData(oldp+37,(vlSelfRef.tb_regfile__DOT__uut__DOT__regs[31]),32);
    bufp->fullBit(oldp+38,(vlSelfRef.tb_regfile__DOT__clk));
    bufp->fullIData(oldp+39,(((0U == (IData)(vlSelfRef.tb_regfile__DOT__rs1))
                               ? 0U : vlSelfRef.tb_regfile__DOT__uut__DOT__regs
                              [vlSelfRef.tb_regfile__DOT__rs1])),32);
    bufp->fullIData(oldp+40,(((0U == (IData)(vlSelfRef.tb_regfile__DOT__rs2))
                               ? 0U : vlSelfRef.tb_regfile__DOT__uut__DOT__regs
                              [vlSelfRef.tb_regfile__DOT__rs2])),32);
}
