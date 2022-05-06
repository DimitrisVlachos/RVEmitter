/*
    Description
    Register allocator for RV32E ISA.

    Author
    Dimitrios Vlachos.

    Linkedin
    @dimitris-vlachos-mt

    License
    See /root/LICENSE
*/

#include "core/inc/regalloc/arch/rv32/rv32e_regalloc.hpp"

RV32E_SimpleRegisterAllocator::RV32E_SimpleRegisterAllocator() {

}

RV32E_SimpleRegisterAllocator::~RV32E_SimpleRegisterAllocator() {

}

const reg_ctx_t RV32E_SimpleRegisterAllocator::GetRA() {
    return static_cast<reg_ctx_t>(1);
}

const reg_ctx_t RV32E_SimpleRegisterAllocator::GetSP() {
    return static_cast<reg_ctx_t>(2);
}

const reg_ctx_t RV32E_SimpleRegisterAllocator::GetGP() {
    return static_cast<reg_ctx_t>(3);
}

const reg_ctx_t RV32E_SimpleRegisterAllocator::GetFP() {
    assert (false);
    return k_invalid_reg_index;
}

const reg_ctx_t RV32E_SimpleRegisterAllocator::GetTP() {
    return static_cast<reg_ctx_t>(4);
}

const reg_ctx_t RV32E_SimpleRegisterAllocator::GetNextGPR(const gpr_register_class_e reg_cls) {

    switch (reg_cls) {
        case rcls_temp: return this->RegAllocInternal(k_temp_start, k_temp_end + 1);
        case rcls_farg: return this->RegAllocInternal(k_farg_start, k_farg_end + 1);
        default: assert (false);
    }

    // Never reach
    return k_invalid_reg_index;
}

const reg_ctx_t RV32E_SimpleRegisterAllocator::GetNextFPR() {
    assert (false);
    return k_invalid_reg_index;
}

const reg_ctx_t RV32E_SimpleRegisterAllocator::GetNextTemporaryGPR() {
    return k_invalid_reg_index;
}

void RV32E_SimpleRegisterAllocator::FreeGPR(const reg_ctx_t which) {
    assert(m_allocated_regs[which] == true);
}

const size_t RV32E_SimpleRegisterAllocator::PushSP(const size_t depth) {
    m_sp += depth;
    return m_sp;
}

const size_t RV32E_SimpleRegisterAllocator::PopSP(const size_t depth) {
    assert (m_sp > depth);
    m_sp -= depth;
    return m_sp;
}

const size_t RV32E_SimpleRegisterAllocator::GetSPValue() const {
    return m_sp;
}

const bool RV32E_SimpleRegisterAllocator::Initialize(  const reg_ctx_t sp, 
                                const reg_ctx_t gp, 
                                const reg_ctx_t fp, 
                                const reg_ctx_t tp) {

    for (auto& t: m_allocated_regs) { t = false; }
    m_sp = sp;
    m_gp = gp;
    m_fp = fp;
    m_tp = tp;
    return true;
}
