#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 100010 // Maximum length of the string

char T[MAX_N]; // The input string, up to 100K characters
int n; // The length of input string
int RA[MAX_N], tempRA[MAX_N]; // Rank array and temporary rank array
int SA[MAX_N], tempSA[MAX_N]; // Suffix array and temporary suffix array
int c[MAX_N]; // For counting/radix sort

void countingSort(int k) {
    int i, sum, maxi = max(300, n); // Up to 255 ASCII chars or length of n
    memset(c, 0, sizeof c); // Clear frequency table

    for (i = 0; i < n; i++) // Count the frequency of each rank
        c[i + k < n ? RA[i + k] : 0]++;

    for (i = sum = 0; i < maxi; i++) {
        int t = c[i]; c[i] = sum; sum += t;
    }

    for (i = 0; i < n; i++) // Shuffle the suffix array if necessary
        tempSA[c[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];

    for (i = 0; i < n; i++) // Update the suffix array SA
        SA[i] = tempSA[i];
}

void constructSA() {
    int i, k, r;
    for (i = 0; i < n; i++) RA[i] = T[i]; // Initial rankings
    for (i = 0; i < n; i++) SA[i] = i; // Initial SA: {0, 1, 2, ..., n-1}
    for (k = 1; k < n; k <<= 1) { // Repeat sorting process log n times
        countingSort(k); // Sort SA based on the second item
        countingSort(0); // Stable sort SA based on the first item
        tempRA[SA[0]] = r = 0; // Re-ranking; start from rank r = 0
        for (i = 1; i < n; i++) // Compare adjacent suffixes
            tempRA[SA[i]] = // If same pair => same rank r; otherwise, increase r
                (RA[SA[i]] == RA[SA[i - 1]] && RA[SA[i] + k] == RA[SA[i - 1] + k]) ? r : ++r;
        for (i = 0; i < n; i++) // Update the rank array RA
            RA[i] = tempRA[i];
        if (RA[SA[n - 1]] == n - 1) break; // Optimization: stop if all ranks are distinct
    }
}

int main() {
    // Example usage
    strcpy(T, "banana");
    n = strlen(T);
    constructSA();

    cout << "Suffix Array for 'banana' is: ";
    for (int i = 0; i < n; i++)
        cout << SA[i] << " ";
    cout << endl;

    return 0;
}
