#include <iostream>


long long xx0;
long long yy0;
long long d;


long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}


// Store x0, y0, and d as global variables
void extendedEuclid(long long a, long long b) {
    if (b == 0) {
        xx0 = 1;
        yy0 = 0;
        d = a;
        return;
    }
    // Recursive call, similar to the original gcd
    extendedEuclid(b, a % b);
    long long x1 = yy0;
    long long y1 = xx0 - (a / b) * yy0;
    xx0 = x1;
    yy0 = y1;
}


int main(){
  while (true) {
    long long int a, b;
    std::cin >> a;
    if (std::cin.eof())
      break;
    std::cin >> b;

    extendedEuclid( a, b );
    std::cout << xx0 << " " << yy0 << " " << d << std::endl;
  }
  return 0;
}
