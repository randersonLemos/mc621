#include <iostream>


int main(){
 long long N; std::cin >> N; 

  while(N){
    N--; 

    long long n; std::cin >> n;
    long long length = 0;

    for(long long i=1; i<=n; i++)
    {

      if( n%i == 0 ){
        length++;
        continue;
      }
      break;
    }
    std::cout << length << std::endl;
  }

return 0;
}
