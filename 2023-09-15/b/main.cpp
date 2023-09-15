#include <iostream>

int gcd(int a, int b){ return b == 0 ? a : gcd(b, a%b); }


int main(){
  int n;
  int wheels[100];
  std::cin >> n;
  for( int i=0; i<n; i++)
    std::cin >> wheels[i];

  int first = wheels[0];
  for( int i=1; i<n; i++)
  {
    int second = wheels[i];

    int max_div  = gcd(first, second);

    std::cout << first/max_div << "/" << second/max_div << std::endl;
   
  }

return 0;
}
