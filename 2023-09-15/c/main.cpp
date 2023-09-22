#include <iostream>
#include <bitset>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef map<int, int> mii;

ll _sieve_size;
bitset<35001> bs; // 10^7 should be enough for most cases
vi primes; // compact list of primes in form of vector<int>

void sieve(ll upperbound) {
    _sieve_size = upperbound + 1; // add 1 to include upperbound
    bs.set(); // set all bits to 1
    bs[0] = bs[1] = 0; // except index 0 and 1
    for (ll i = 2; i < _sieve_size; i++)
        if (bs[i]) {
            // cross out multiples of i starting from i*i!
            for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
            primes.push_back((int)i); // also add this vector containing list of primes
        }
}

bool isPrime(ll N) {
    if (N < _sieve_size) return bs[N]; // O(1) for small primes
    for (int i = 0; i < (int)primes.size(); i++)
        if (N % primes[i] == 0) return false;
    return true; // it takes longer time if N is a large prime!
}


vi primeFactors(ll N) {
    vi factors;
    ll PF_idx = 0, PF = primes[PF_idx]; // using PF = 2, 3, 4, ..., is also ok
    while (N != 1 && (PF * PF <= N)) { // stop at sqrt(N), but N can get smaller
        while (N % PF == 0) { N /= PF; factors.push_back(PF); return factors; } // remove this PF
        PF = primes[++PF_idx]; // only consider primes!
    }
    if (N != 1) { factors.push_back(N); return factors; }// special case if N is actually a prime
    return factors; // if pf exceeds 32-bit integer, you have to change vi
}


int main(){
  sieve (35000);

  long n; 
  std::cin >> n;

  if( n == 1)
  {
    cout << 0 << endl;
    return 0;
  } 

  vi res = primeFactors(n); // slowest, 2147483647 is a prime
  //for (vi::iterator i = res.begin(); i != res.end(); i++)
  //    printf("> %d\n", *i);
  cout << n - (n / res[0]) << endl;


  return 0;
}
