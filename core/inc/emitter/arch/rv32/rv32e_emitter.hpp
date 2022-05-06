/*
    Description
    RV32E Emitter implementation.
    
    Author
    Dimitrios Vlachos.

    Linkedin
    @dimitris-vlachos-mt

    License
    See /root/LICENSE
*/

#pragma once

#include "core/inc/common/common.hpp"
#include "core/inc/emitter/emitter_if.hpp"

class RV32E_Emitter: public EmitterInterface {
    public:
    RV32E_Emitter(BasicBlock* block = nullptr, RegisterAllocatorInterface* ralloc = nullptr) : m_reg_alloc(ralloc), m_bb(block) {}
    ~RV32E_Emitter() override {}
    void BindBlock(BasicBlock* block) override {
        m_bb = block;
    }

    void BindRegisterAllocator(RegisterAllocatorInterface* ralloc) override {
        m_reg_alloc = ralloc;
    }

    reg_ctx_t AddRmRn(const reg_ctx_t& rd, const reg_ctx_t rs0, const reg_ctx_t& rs1) override {
        assert( (m_reg_alloc != nullptr) && (m_bb != nullptr) );
        return 0;
    }
    
    reg_ctx_t LoadImmediate(const reg_ctx_t& rd, const uint32_t val) override {
        assert (false);
    }

    private:
    RegisterAllocatorInterface* m_reg_alloc;
    BasicBlock* m_bb;
};