#include <iostream>

long long n;

long countDigits(int number) {
    long count = 0;
    while (number != 0) {
        number /= 10;
        count++;
    }
    return count;
}


long long Ones( long long ones ){
  return ones*10 + 1;
}

int main() {
  while (true) {
    std::cin >> n;
    if (std::cin.eof())
      break;

    long long ones = 1;
    long long size = 1;

    while( ones%n ){
      ones = Ones(ones); 
      std::cout << ones << std::endl;
      size++;
    }

    std::cout << size << std::endl;

  }
  return 0;
}
