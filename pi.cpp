#include <iostream>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <iomanip>

using namespace boost::multiprecision;

template <typename T>

T factorial(int n)
{
    T result = 1;
    for (int i = 1; i <= n; ++i)
    {
        result *= i;
    }
    return result;
}

int main()
{
    cpp_dec_float_50 pi = 0;
    cpp_dec_float_50 sqrt_2 = sqrt(cpp_dec_float_50(2));


    for (int k = 0; k < 10; ++k)
    {
        cpp_dec_float_50 numerator = factorial<cpp_dec_float_50>(4 * k) * (1103 + 26390 * k);
        cpp_dec_float_50 denominator = pow(factorial<cpp_dec_float_50>(k), 4) * pow(cpp_dec_float_50(394), 4 * k);
        pi += numerator / denominator;
    }

    pi = 1 / ((2 * sqrt_2 / 9801) * pi);

    std::cout << "Pi number with precision in 50 digits : " << std::setprecision(50) << pi << std::endl;

    return 0;
}