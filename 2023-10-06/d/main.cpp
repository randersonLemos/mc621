#include <iostream>
#include <cstring>
#include <vector>


// Function to fill lps array for given pattern pat[0..M-1]
void computeLPSArray(char* pat, int M, int* lps) {
    // Length of the previous longest prefix suffix
    int len = 0;
    lps[0] = 0; // lps[0] is always 0

    // The loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            // If the current character matches with the character in the prefix
            len++;
            lps[i] = len;
            i++;
        } else { // If the current character does not match
            if (len != 0) {
                // This is tricky. Consider the example "AAACAAAA"
                // and i = 7. We did not find a match, but we do not
                // want to match lps[0..2] characters with pat[3..i-1],
                // because they will match anyway. We use lps[len-1]
                // which will take us to the prefix of the prefix.
                len = lps[len - 1];
            } else { // If len is 0
                lps[i] = 0;
                i++;
            }
        }
    }
}



// Prints occurrences of P in T
void KMPSearch(char* P, char* T, std::vector<int> &matches) {
    int M = strlen(P); // Length of the pattern
    int N = strlen(T); // Length of the text
    int lps[M]; // Create lps[] that will hold the longest prefix suffix values for pattern

    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(P, M, lps);

    int i = 0; // index for T[]
    int j = 0; // index for P[]

    while (i < N) {
        if (P[j] == T[i]) {
            j++;
            i++;
        }

        if (j == M) {
            //printf("Found pattern at index %d\n", i - j);
            matches.push_back(i-j);
            j = lps[j - 1]; // Continue the search with the next character in T
        }

        // Mismatch after j matches
        else if (i < N && P[j] != T[i]) {
            // Do not need to match lps[0..lps[j-1]] characters
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1; // Move to the next character in T
        }
    }
}




int main(){
  std::string T;
  while(true){
    std::cin >> T;
    if(T[0] == '.')
      break;


    int len = 1;

    if(T.size() % 2 != 0){
      std::vector<int> matches;
      std::string P = T.substr(0, len);
      KMPSearch( const_cast<char*>(P.c_str()), const_cast<char*>(T.c_str()), matches ) ;

      if( matches.size()*P.size() == T.size() )
        std::cout << matches.size() << std::endl;
 
    }
    else{
      while(len <= int(T.size()) ){
        std::vector<int> matches;
        std::string P = T.substr(0, len);
        //KMPSearch( const_cast<char*>(P.c_str()), const_cast<char*>(T.c_str()), matches ) ;
        KMPSearch( const_cast<char*>(P.c_str()), const_cast<char*>(T.c_str()), matches ) ;

        //std::cout << P << std::endl; 
        //std::cout << matches.size() << std::endl;

        if( matches.size()*P.size() == T.size()  ){
          std::cout << matches.size() << std::endl;
          break;
        }
        len++;
      }
    }
  }
}


