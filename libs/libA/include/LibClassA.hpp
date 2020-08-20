#pragma once

class LibClassA
{
public:
    LibClassA() = default;
    void test_libA_out();
    void test_libA_private_out();

    void test_libA_libB_out();
};