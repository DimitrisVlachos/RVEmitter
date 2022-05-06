
/*
    Description
    Code block logic. No endianess handing.
    
    Author
    Dimitrios Vlachos.

    Linkedin
    @dimitris-vlachos-mt

    License
    See /root/LICENSE
*/

#pragma once

#include "common.hpp"

class BasicBlock {
    public:
    BasicBlock(const std::string_view label, const size_t offset): m_label(label), m_offs(offset) {}
    ~BasicBlock() {}

    template <typename base_t>
    inline void Write(const base_t v) {
        // Compile time checks 
        if constexpr(std::is_same_v<base_t, int8_t> || std::is_same_v<base_t, uint8_t>)
            this->m_code.push_back( v ); 
        else if constexpr(std::is_same_v<base_t, int16_t> || std::is_same_v<base_t, uint16_t> || std::is_same_v<base_t, uint32_t> || std::is_same_v<base_t, int32_t> ) {
            const uint8_t* p = reinterpret_cast<const uint8_t*>(&v);
            this->WriteRange(p, sizeof(v));
        }
    }

    template <typename base_t>
    inline void WriteRange(const std::vector<base_t>& data) {
        this->WriteRange( static_cast<const uint8_t>(&data[0]), data.size());
    }

    inline void WriteRange(const uint8_t* src, const size_t len) {
        // TODO optimize
        for (size_t i = 0;i < len; ++i)
            this->m_code.push_back( src[i] ); 
    }

    inline const size_t GetBaseOffset() const { 
        return this->m_offs; 
    }
    
    inline const size_t GetRange() const { 
        return this->GetBaseOffset() + m_code.size(); 
    }
    
    inline void UpdateOffset(const size_t new_offs) { 
        this->m_offs = new_offs; 
    }

    bool ExportToFile(const std::string_view path) {
        if (m_code.empty()) {
            return false;
        }
        FILE* f = fopen(path.data(), "wb");
        if (!f) {
            return false;
        }
        const size_t w = fwrite( &m_code[0], 1, m_code.size(), f);
        fclose(f);
        return (w == m_code.size());
    }

    inline const std::vector< uint8_t >& GetCode() const {
        return m_code;
    }

    inline const std::string_view GetLAbel() const {
        return m_label;
    }

    private:
    std::string_view m_label;
    std::vector< uint8_t > m_code;
    size_t m_offs;
};

