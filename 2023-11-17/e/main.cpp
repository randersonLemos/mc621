#include <iostream>
#include <cmath>


int main(){
  double a, b, c;
  while(true){
    std::cin >> a >> b >> c; 

    if( a==0 && b==0 && c==0 )
      break;
  
    double h, c1, c2;
    if( a>b && a>c){
      h=a;
      c1=b;
      c2=c; 
    }

    else if( b>a && b>c ) {
      h=b;
      c1=a;
      c2=c; 
    }

    else{
      h=c;
      c1=a;
      c2=b; 
    }


    if( std::pow(h,2) == std::pow(c1,2) + std::pow(c2,2) )
      std::cout << "right"  << std::endl;
    else
      std::cout << "wrong"  << std::endl;

  }



return 0;
}
