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

#pragma once
#include "core/inc/common/common.hpp"
#include "core/inc/regalloc/regalloc_if.hpp"

/*
    5-bit Encoding (rx) 	3-bit Compressed Encoding (rx') 	Register 	ABI Name 	Description 	Saved by Calle-
    0 	- 	x0 	zero 	hardwired zero 	-
    1 	- 	x1 	ra 	return address 	-R
    2 	- 	x2 	sp 	stack pointer 	-E
    3 	- 	x3 	gp 	global pointer 	-
    4 	- 	x4 	tp 	thread pointer 	-
    5 	- 	x5 	t0 	temporary register 0 	-R
    6 	- 	x6 	t1 	temporary register 1 	-R
    7 	- 	x7 	t2 	temporary register 2 	-R
    8 	0 	x8 	s0 / fp 	saved register 0 / frame pointer 	-E
    9 	1 	x9 	s1 	saved register 1 	-E
    10 	2 	x10 	a0 	function argument 0 / return value 0 	-R
    11 	3 	x11 	a1 	function argument 1 / return value 1 	-R
    12 	4 	x12 	a2 	function argument 2 	-R
    13 	5 	x13 	a3 	function argument 3 	-R
    14 	6 	x14 	a4 	function argument 4 	-R
    15 	7 	x15 	a5 	function argument 5 	-R 
*/

class RV32E_SimpleRegisterAllocator: public RegisterAllocatorInterface {
    public:
    RV32E_SimpleRegisterAllocator();
    ~RV32E_SimpleRegisterAllocator() override;

    const reg_ctx_t GetRA() override;
    const reg_ctx_t GetSP() override;
    const reg_ctx_t GetGP() override;
    const reg_ctx_t GetFP() override;
    const reg_ctx_t GetTP() override;
    const reg_ctx_t GetNextGPR(const gpr_register_class_e reg_cls) override;
    const reg_ctx_t GetNextFPR() override;
    const reg_ctx_t GetNextTemporaryGPR() override;
    void FreeGPR(const reg_ctx_t which) override;
    const bool Initialize(  const reg_ctx_t sp, 
                                    const reg_ctx_t gp, 
                                    const reg_ctx_t fp, 
                                    const reg_ctx_t tp) override;

    const size_t PushSP(const size_t depth) override;
    const size_t PopSP(const size_t depth) override;
    const size_t GetSPValue() const override;

    private:
    const size_t k_temp_start = 5;
    const size_t k_temp_end = 7;
    const size_t k_farg_start = 10;
    const size_t k_farg_end = 15;

    reg_ctx_t m_sp;
    reg_ctx_t m_gp;
    reg_ctx_t m_fp;
    reg_ctx_t m_tp;
    std::array<bool, 16> m_allocated_regs { false };


    // Private member functions
    private:
    inline const reg_ctx_t RegAllocInternal(const size_t start, const size_t end) {
        for (size_t x = start; x < end; ++x) {
            if (!m_allocated_regs[x]) {
                m_allocated_regs[x] = true;
                return x;
            }
        }
        // Ideally we would want to allocate stack frames :)
        return k_invalid_reg_index;
    }
};