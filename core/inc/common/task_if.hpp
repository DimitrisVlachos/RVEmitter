/*
    Description
    Task interface class.

    Author
    Dimitrios Vlachos.

    Linkedin
    @dimitris-vlachos-mt

    License
    See /root/LICENSE
*/

#pragma once

class TaskInterface {
    public:
    virtual const int32_t Run(const int argc, const char** argv) = 0;
    virtual ~TaskInterface() {}
    private:
};