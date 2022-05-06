/*
    Description
    Main entrypoint for tests.

    Author
    Dimitrios Vlachos.

    Linkedin
    @dimitris-vlachos-mt

    License
    See /root/LICENSE
*/

#include "core/inc/common/common.hpp"
#include "core/inc/common/task_if.hpp"
#include "simple/simple.hpp"
 

int main(const int argc, const char** argv) {
    std::vector< std::unique_ptr< TaskInterface > > tasks; 
    
    tasks.push_back( { std::make_unique< SimpleTest >() } );
    for (auto& t: tasks) {
        const auto ret =  t->Run(argc, argv);
        assert(ret == 0);
    }

    return 0;
}