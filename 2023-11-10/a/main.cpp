#include <iostream>
#include <cmath>


int main(){
  int N;
  std::cin >> N;
  while(N){
    N--; 
    double bx, by;
    std::cin >> bx >> by;

    int C;
    std::cin >> C;

    bool light = false;

    while(C){
      C--; 
      double cx, cy;
      std::cin >> cx >> cy;

      double dist;
      dist = sqrt(pow((bx-cx),2) + pow((by-cy),2));
      if(dist < 8.0)
        light = true;
    }

    if(light){
      std::cout << "light a candle" << std::endl;
    }
    else{
      std::cout << "curse the darkness"  << std::endl;
    }

  }
  return 0;
}

