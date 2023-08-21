#include <iostream>
#include <cmath>


long int mod(long int dividend, long int divider)
{
    long int n = dividend / divider;

    // std::cout << dividend << " " << divider << " " << n << " " << n*dividend << std::endl;

    long int remainder = dividend - n*divider;

    // std::cout << remainder << std::endl;

    return remainder;
}

int main(){
    int n, m;

    std::cin >> n >> m;
    // std::cout << m << " " << n << std::endl;

    long int dividend = m;
    long int divider = std::pow(2, n);

    // std::cout << dividend << " " << divider << std::endl;

    std::cout << mod(dividend, divider);

return 0;
}
