/*
    Description
    Register allocation interface class

    Author
    Dimitrios Vlachos.

    Linkedin
    @dimitris-vlachos-mt

    License
    See /root/LICENSE
*/

#pragma once

// Placeholder. Expand to structure later.
using reg_ctx_t = size_t;

enum gpr_register_class_e {

    // Any register
    rcls_any = 0,

    // Temporary
    rcls_temp,

    // Function argument
    rcls_farg,

    // Saved registers
    rcls_saved,
};

static constexpr reg_ctx_t k_invalid_reg_index = static_cast<reg_ctx_t>(-1U);

class RegisterAllocatorInterface {
    public:
    virtual ~RegisterAllocatorInterface() {}
    virtual const bool Initialize(  const reg_ctx_t sp, 
                                    const reg_ctx_t gp, 
                                    const reg_ctx_t fp, 
                                    const reg_ctx_t tp) = 0;
    virtual const size_t PushSP(const size_t depth) = 0;
    virtual const size_t PopSP(const size_t depth) = 0;
    virtual const size_t GetSPValue() const = 0;
    virtual const reg_ctx_t GetRA() = 0;
    virtual const reg_ctx_t GetSP() = 0;
    virtual const reg_ctx_t GetGP() = 0;
    virtual const reg_ctx_t GetFP() = 0;
    virtual const reg_ctx_t GetTP() = 0;
    virtual const reg_ctx_t GetNextGPR(const gpr_register_class_e reg_cls) = 0;
    virtual const reg_ctx_t GetNextFPR() = 0;
    virtual const reg_ctx_t GetNextTemporaryGPR() = 0;
    virtual void FreeGPR(const reg_ctx_t which) = 0;
    private:
};