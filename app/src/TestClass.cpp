#include "TestClass.hpp"
#include <iostream>

#include "libA/include/LibClassA.hpp"

void TestClass::test_out()
{
    std::cout << "test_out\n";
}

void TestClass::test_libA_out()
{
    LibClassA la;
    la.test_libA_out();
}