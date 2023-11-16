#include <iostream>
#include <cstring>



int main(){
  int n;
  std::string s;

  std::cin >> n;
  std::cin >> s;

  int i = 0;
  int j = n;
  int swaps = 0;

  while(i<j){
    std::cout << i << ' ' << j << std::endl; 
    if(s[i] != s[j]){
      swaps += j-i-1;
    }
    i++; j--; 
  }

  std::cout << swaps << std::endl;




return 0;
}
