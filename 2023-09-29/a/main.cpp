#include <iostream>


struct F{
  long int value;
  long int index;
};


void printF(F f){
  std::cout << f.value << "(" << f.index << ")" << std::endl;
}


F fibonacciNext( F fn, F fnn ){
  F fnnn;
  fnnn.value = fn.value + fnn.value;
  fnnn.index = fnn.index + 1;
  return fnnn;
}


int main(){

  long int n;
  std::cin >> n;

  while(n)
  {
    n--;
    long int mod;
    std::cin >> mod;

    long int* table = new long int[mod];
    for(int i=0; i<mod; i++)
    {
      table[i] = 0; 
    }

    F fn;
    fn.value = 1;
    fn.index = 0;  

    F fnn;
    fnn.value = 1;
    fnn.index = 1;

    F fnnn;

    while(true)
    {
      fnnn       = fibonacciNext( fn, fnn ); 
      fnnn.value = fnnn.value % mod;

      if(table[fnnn.value])
      {
        std::cout << table[fnnn.value] << std::endl;

        break;
      }
      table[fnnn.value] = fnnn.index;

      fn  = fnn;
      fnn = fnnn;
    }

    delete[] table;
  }

  return 0;

}
