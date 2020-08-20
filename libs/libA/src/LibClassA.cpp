#include "LibClassA.hpp"
#include <iostream>

#include "PrivClass/LibAPrivClass.hpp"
#include "libB/include/LibClassB.hpp"

void LibClassA::test_libA_out()
{
    std::cout << "test from lib A\n";
}

void LibClassA::test_libA_private_out()
{
    LibAPrivClass priv;
    priv.test_priv();
}

void LibClassA::test_libA_libB_out()
{
    std::cout << "libA call libB: ";
    LibClassB lb;
    lb.test_libB_out();
}