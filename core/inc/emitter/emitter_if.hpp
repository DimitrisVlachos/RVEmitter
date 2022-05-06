/*
    Description
    Emitter interface class
    
    Author
    Dimitrios Vlachos.

    Linkedin
    @dimitris-vlachos-mt

    License
    See /root/LICENSE
*/

#pragma once
#include "core/inc/regalloc/regalloc_if.hpp"
#include "core/inc/common/basic_block.hpp"

class EmitterInterface {
    public:
    virtual ~EmitterInterface() {}
    virtual void BindBlock(BasicBlock* block) = 0;
    virtual void BindRegisterAllocator(RegisterAllocatorInterface* ralloc) = 0;
    virtual reg_ctx_t AddRmRn(const reg_ctx_t& rd, const reg_ctx_t rs0, const reg_ctx_t& rs1) = 0;
    virtual reg_ctx_t LoadImmediate(const reg_ctx_t& rd, const uint32_t val) = 0;
    private:
};
