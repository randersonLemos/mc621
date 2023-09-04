/* recebe inteiro positivo n e imprime o n-ésimo living number*/
void mostra_living(unsigned n) {
    unsigned rep[16];
    unsigned tamanho = 0;
    while (n) {
        unsigned digito = n % 9;
        if (digito < 4) {
            rep[tamanho] = digito;
        } else {
            rep[tamanho] = digito + 1;
        }
        tamanho++;
        n = n/9;
    }

    while (tamanho) {
        cout << rep[tamanho - 1];
        tamanho--;    
    }
    cout << endl;
}
