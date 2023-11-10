#include <iostream>
#include <string>
#include <cmath>

// Function to calculate distance
double distanceToHyperplane(double W[1000], 
                            double d,
                            double P[1000],
                            int N
                            
                            ) {
    // Calculate the numerator |ax1 + bx2 + cx3 + d|
    double numerator = 0;
    for(int i=0; i<N; i++){
      numerator = numerator + W[i]*P[i];
    }
    //numerator = std::abs( numerator + d ); 
    numerator = numerator + d;


    double denominator= 0;
    for(int i=0; i<N; i++){
      denominator = denominator + W[i]*W[i];
    }
    denominator = std::sqrt( denominator ); 

    return numerator / denominator;
}


int main(){
  double W[1000];
  double d;
  double P[1000];
  int N;
  std::cin >> N;

  for(int i=0; i<N; i++){
    std::cin >> W[i];
  }

  std::cin >> d;

  bool inputFailed = false;
  while(true){
   for(int i=0; i<N; i++){
       if(!(std::cin >> P[i])) {
            inputFailed = true;
            break;
        }
    }

    if(inputFailed) {
        break;
    }


    //for(int i=0; i<N; i++){
    //  std::cout << W[i] << " ";  
    //}
    //std::cout << d << " " << std::endl;
    //for(int i=0; i<N; i++){
    //  std::cout << P[i] << " ";  
    //}
    //std::cout << std::endl;

    double dist = distanceToHyperplane(W,d,P,N);

    std::cout << dist << std::endl;

  }






return 0;
}


