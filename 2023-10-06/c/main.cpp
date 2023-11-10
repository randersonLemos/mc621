#include <iostream>
#include <string>


int main(){
  int N;
  std::cin >> N;

  while(N){
    N--;
    int length; std::string number;
    std::cin >> length; std::cin >> number;
    
    //std::cout << length << number << std::endl;
    
    int i = 0; int j = length - 1;

    while(i<j){
      if(number[i] != number[j]){
        i++; j--;
        continue;
      }
      break;
    }

    if(j<i){
      std::cout << "0" << std::endl;
    }
    else{
      std::cout << j-i+1 << std::endl;
    }



  }



  return 0;
}
