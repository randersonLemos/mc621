#include <iostream>
#include <string>

//
// https://www.geeksforgeeks.org/prime-numbers/
//
bool is_prime(int n, int i)
{
  if( n == 0 || n == 1 )
    return false;

  if( n == i )
    return true;

  if( n % i == 0)
    return false;

  i += 1;

  return is_prime(n,i);

}

int main() {
    int n; 
    std::cin >> n;

    for( int m = 1; m < 1001; m++)
    {
      int p = n*m + 1;
      if( ! is_prime( p, 2 ) )
      {
          std::cout << m << std::endl;
          break;
      }
    }
    return 0;
}
