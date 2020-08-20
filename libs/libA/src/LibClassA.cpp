#include "LibClassA.hpp"
#include <iostream>

#include "PrivClass/LibAPrivClass.hpp"

void LibClassA::test_libA_out()
{
    std::cout << "test from lib A\n";
}

void LibClassA::test_libA_private_out()
{
    LibAPrivClass priv;
    priv.test_priv();
}