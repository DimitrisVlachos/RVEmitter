/*
    Description
    Simple emitter test.

    Author
    Dimitrios Vlachos.

    Linkedin
    @dimitris-vlachos-mt

    License
    See /root/LICENSE
*/

#pragma once
#include "core/inc/common/common.hpp"
#include "core/inc/common/task_if.hpp"


class SimpleTest: public TaskInterface {
    public:
    const int32_t Run(const int argc, const char** argv) override;
    ~SimpleTest() override;

    private:
};