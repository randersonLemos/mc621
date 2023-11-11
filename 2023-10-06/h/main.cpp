#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>


// Function to compute the LPS array
void computeLPSArray(char *P, int M, int *lps) {
    // Length of the previous longest prefix suffix
    int len = 0;
    lps[0] = 0; // lps[0] is always 0

    // The loop calculates lps[i] for i = 1 to M-1
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


// Prints occurrences of P in T
int KMPSearch(char *P, char *T) {
    int M = strlen(P);
    int N = strlen(T);

    // Create lps[] that will hold the longest prefix suffix values for pattern
    int lps[M];

    // Preprocess the pattern (calculate lps[] array)
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
            j = lps[j - 1];
            return 1;
        }

        // Mismatch after j matches
        else if (i < N && P[j] != T[i]) {
            // Do not need to match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    return 0;
}


int main(){
  
  bool inputFailed = false;
  int count = 0;
  std::vector<int> matches;

  while(true){
    count++;
    std::string T;
    std::string P = "FBI";

    if(!(std::cin >> T)) {
      inputFailed = true;
     }

    if(inputFailed) {
        break;
    }
    //std::cout << T << std::endl;
    if(KMPSearch( const_cast<char*>(P.c_str()), const_cast<char*>(T.c_str()) )){
      //std::cout << count << std::endl;
      matches.push_back( count );
    }
  }

  int size = matches.size();
  if(size){
    //std::cout << size << std::endl;
    int i;
    for(i=0; i<size-1; i++) {
      std::cout <<  matches[i] << " ";
    }
    std::cout << matches[i] << std::endl;
  }
  else{
    std::cout << "HE GOT AWAY!" << std::endl;
  }



return 0;
}
