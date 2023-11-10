#include <iostream>
#include <cstring>


// Function to compute Longest Prefix Suffix (LPS) array
void computeLPSArray(char *P, int M, int *lps) {
    int len = 0;
    lps[0] = 0;
    int i = 1;
    
    while (i < M) {
        if (P[i] == P[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}



// Function to perform pattern matching using KMP algorithm
void KMPSearch(char *P, char *T) {
    int M = strlen(P);
    int N = strlen(T);
    int lps[M];
    
    // Preprocess the pattern to calculate the LPS array
    computeLPSArray(P, M, lps);
    
    int i = 0; // Index for T
    int j = 0; // Index for P
    
    while (i < N) {
        if (P[j] == T[i]) {
            j++;
            i++;
        }
        
        if (j == M) {
            //printf("Found pattern at index %d\n", i - j);
            printf("YES\n");
            return;
            j = lps[j - 1];
        } else if (i < N && P[j] != T[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i = i + 1;
            }
        }
    }
    printf("NO\n");
}



int main(){
  int N;
  std::cin >> N;

  std::string word;
  std::getline(std::cin, word);

  while(N){
    N--; 

    std::string pattern = "Simon says";

    std::getline(std::cin, word);

    //std::cout << word << std::endl;

    int match = 0;

    for(int i=0; i < pattern.length(); i++) {
      if( word[i] == pattern[i] )
        match++;
    }

    //std::cout << match << std::endl;

    if( match == pattern.length() ){
      for(int i=pattern.length(); i<word.length(); i++){
        std::cout << word[i];
      }
      std::cout << std::endl;
    }
  }

}
