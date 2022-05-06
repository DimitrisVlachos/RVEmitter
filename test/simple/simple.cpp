/*
    Description
    Simple emitter test demonstrating indended use.

    Author
    Dimitrios Vlachos.

    Linkedin
    @dimitris-vlachos-mt

    License
    See /root/LICENSE
*/

#include "simple.hpp"
#include "core/inc/common/basic_block.hpp"
#include "core/inc/emitter/emitter_if.hpp"
#include "core/inc/emitter/arch/rv32/rv32e_emitter.hpp"
#include "core/inc/regalloc/arch/rv32/rv32e_regalloc.hpp"

const int32_t SimpleTest::Run(const int argc, const char** argv) {
    fmt::print("Simple test start..\n");

    // Create a basic block to emit instructions & Define label and offset.
    constexpr const std::string_view bb_label = "main";
    constexpr const size_t bb_offset = 0;
    std::unique_ptr< BasicBlock >  bb { std::make_unique<BasicBlock>(bb_label, bb_offset) };

    // Create a register allocator
    std::unique_ptr< RegisterAllocatorInterface > ralloc { std::make_unique<RV32E_SimpleRegisterAllocator>() };

    // Create an emitter and pass in the block & reg allocator
    std::unique_ptr< EmitterInterface > emitter { std::make_unique<RV32E_Emitter>( bb.get(), ralloc.get()) };

    // Get 2 available registers to work
    const auto lhs = ralloc->GetNextGPR(rcls_temp);
    const auto rhs = ralloc->GetNextGPR(rcls_temp);
    assert ((lhs != k_invalid_reg_index) && (rhs != k_invalid_reg_index) );

    // Move data
    emitter->LoadImmediate(lhs, 64);
    emitter->LoadImmediate(rhs, 32);

    // Perform lhs(rd) = lhs(rs1) + rhs(rs2) 
    emitter->AddRmRn(lhs, lhs, rhs);

    // Free registers
    ralloc->FreeGPR(lhs);
    ralloc->FreeGPR(rhs);

    // Code is now stored in bb->GetCode()
    fmt::print("Simple test end..\n");

    // Done
    return 0;
}

SimpleTest::~SimpleTest() {}
