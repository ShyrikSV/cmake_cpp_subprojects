#pragma once

class TestClass
{
public:
    TestClass() = default;
    void test_out();
    void test_libA_out();
    void test_libA_priv_out();

    void test_libB_out();
    
    void test_libA_libB_out();
};