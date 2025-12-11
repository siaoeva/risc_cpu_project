// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vcpu_defs__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vcpu_defs::Vcpu_defs(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vcpu_defs__Syms(contextp(), _vcname__, this)}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vcpu_defs::Vcpu_defs(const char* _vcname__)
    : Vcpu_defs(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vcpu_defs::~Vcpu_defs() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vcpu_defs___024root___eval_debug_assertions(Vcpu_defs___024root* vlSelf);
#endif  // VL_DEBUG
void Vcpu_defs___024root___eval_static(Vcpu_defs___024root* vlSelf);
void Vcpu_defs___024root___eval_initial(Vcpu_defs___024root* vlSelf);
void Vcpu_defs___024root___eval_settle(Vcpu_defs___024root* vlSelf);
void Vcpu_defs___024root___eval(Vcpu_defs___024root* vlSelf);

void Vcpu_defs::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vcpu_defs::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vcpu_defs___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vcpu_defs___024root___eval_static(&(vlSymsp->TOP));
        Vcpu_defs___024root___eval_initial(&(vlSymsp->TOP));
        Vcpu_defs___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vcpu_defs___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

void Vcpu_defs::eval_end_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+eval_end_step Vcpu_defs::eval_end_step\n"); );
#ifdef VM_TRACE
    // Tracing
    if (VL_UNLIKELY(vlSymsp->__Vm_dumping)) vlSymsp->_traceDump();
#endif  // VM_TRACE
}

//============================================================
// Events and timing
bool Vcpu_defs::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty(); }

uint64_t Vcpu_defs::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vcpu_defs::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vcpu_defs___024root___eval_final(Vcpu_defs___024root* vlSelf);

VL_ATTR_COLD void Vcpu_defs::final() {
    Vcpu_defs___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vcpu_defs::hierName() const { return vlSymsp->name(); }
const char* Vcpu_defs::modelName() const { return "Vcpu_defs"; }
unsigned Vcpu_defs::threads() const { return 1; }
void Vcpu_defs::prepareClone() const { contextp()->prepareClone(); }
void Vcpu_defs::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vcpu_defs::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vcpu_defs___024root__trace_decl_types(VerilatedVcd* tracep);

void Vcpu_defs___024root__trace_init_top(Vcpu_defs___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vcpu_defs___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vcpu_defs___024root*>(voidSelf);
    Vcpu_defs__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vcpu_defs___024root__trace_decl_types(tracep);
    Vcpu_defs___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vcpu_defs___024root__trace_register(Vcpu_defs___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vcpu_defs::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vcpu_defs::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vcpu_defs___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
