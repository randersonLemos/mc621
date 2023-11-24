#include <iostream>
#include <cmath>
#include <iomanip> // Needed for setprecision
                   //
#define M_PI 3.14159265358979323846

double circleArea(double r){
  return std::pow(r,2)*M_PI;


}

int main(){
  double r, m ,c;
  while(std::cin >> r >> m >> c){
    if( r==0 && m==0 && c==0) 
      break;

    double areaR = circleArea(r);
    double areaE = (2*r)*(2*r)*c/m;
    //std::cout << areaR << std::endl;
    //std::cout << areaE << std::endl;

    std::cout << std::fixed << std::setprecision(7) << areaR << " " <<areaE << std::endl;

  
  }

return 0;
}
