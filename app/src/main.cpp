#include "TestClass.hpp"

int main(int argc, char** argv)
{
    TestClass tc;
    tc.test_out();

    tc.test_libA_out();

    tc.test_libA_priv_out();
    return 0;
}