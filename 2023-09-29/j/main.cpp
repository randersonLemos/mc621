#include <iostream>
#include <string>
#include <cmath>

double nextF(double prevF)
{
  double num = std::pow( prevF, 2) - 5;
  double den = 2*prevF + 4;
  return num/den;
}

int main(){
  std::string input;
  std::string pattern = "problem"

  while(true){
    std::getline(std::cin, input);
    
    if( input == "")
      break;

    double F0 = std::pow(2, 0.5) + std::pow(3, 0.5) + std::pow(6, 0.5);

  }





return 0;
}
