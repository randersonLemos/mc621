#include <iostream>

/* recebe inteiro positivo n e imprime o n-ésimo living number*/
void mostra_living(unsigned n) {
    unsigned long int rep[32];
    unsigned long int tamanho = 0;
    while (n) {
        unsigned long int digito = n % 9;
        if (digito < 4) {
            rep[tamanho] = digito;
        } else {
            rep[tamanho] = digito + 1;
        }
        tamanho++;
        n = n/9;
    }

    while (tamanho) {
        std::cout << rep[tamanho - 1];
        tamanho--;    
    }
    std::cout << std::endl;
}


int main(){
  int t;
  std::cin >> t;
  while(t)
  {
    t = t - 1; 
    unsigned k;
    std::cin >> k;
    mostra_living( k );
  }

  return 0;
}
