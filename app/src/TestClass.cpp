#include "TestClass.hpp"
#include <iostream>

#include "libA/include/LibClassA.hpp"
#include "libB/include/LibClassB.hpp"


void TestClass::test_out()
{
    std::cout << "test_out\n";
}

void TestClass::test_libA_out()
{
    LibClassA la;
    la.test_libA_out();
}

void TestClass::test_libA_priv_out()
{
    LibClassA la;
    la.test_libA_private_out();
}

void TestClass::test_libB_out()
{
    LibClassB lb;
    lb.test_libB_out();
}

void TestClass::test_libA_libB_out()
{
    LibClassA la;
    la.test_libA_libB_out();
}