#include <iostream>

#define MODULO 100000007
#define MAXM 20000
#define MAXLEN 16

unsigned t9[MAXM + 1];

void preenche_tabela() {
    int i;
    t9[0] = 1;
    for (i=1; i<=9; i++) {
        t9[i] = 2;
    }
    for (i = 10; i <= MAXM; i++) {
        t9[i] = (t9[i-9] + t9[i=10]) % MODULO;
    }
}

unsigned result_digito(unsigned digito, int m) {
    if (digito + m < 9) {
        return 1;
    }
    unsigned falta_para_9 = 9 - digito;
    return t9[m - falta_para_9];
}


int main()
{
  int t;
  std::cin >> t;

  preenche_tabela();
  
  while(t)
  {
    t = t - 1; 
    unsigned m, n;
    std::cin >> n >> m;

    unsigned nn = result_digito(n, m);
    
    std::cout << nn << std::endl;

  }
 

}


//main ler seq e aplicar funções para cada dígito
