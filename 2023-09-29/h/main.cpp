#include <iostream>
#include <bitset>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef map<int, int> mii;

ll _sieve_size;
bitset<10000010> bs; // 10^7 should be enough for most cases
vi primes; // compact list of primes in form of vector<int>

void sieve(ll upperbound) {
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i <= _sieve_size; i++) 
        if (bs[i]) {
            for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
            primes.push_back((int)i);
        }
}

bool isPrime(ll N) {
    if (N <= _sieve_size) return bs[N];
    for (int i = 0; i < (int)primes.size(); i++)
        if (N % primes[i] == 0) return false;
    return true;
}

ll happyNumber(ll number)
{
  ll happy = 0;
  while(number)
  {
    ll lastDigit = number % 10;
    number = ( number - lastDigit ) / 10;
    happy = happy + ( lastDigit*lastDigit );
  }
  return happy;
}


int main() {

    sieve(11000); // can go up to 10^7 (needs a few seconds)
 

    ll n;
    ll idx, number, candidate, happy;

    std::cin >> n;
    while(n)
    {

      std::map<ll, bool> myMap;

      //std::cout << "-------" << std::endl;
      n--; 
      std::cin >> idx >> number;
      if( isPrime(number) )
      {
        myMap[number] = true; 
        candidate = number;
        while(true)
        {
          happy = happyNumber( candidate );
          //std::cout << "number: " << candidate << " happy: " << happy << std::endl;
         
          if(happy == 1)
          {
            std::cout << idx << " " << number << " YES" << std::endl;
            break;
          }
          if( ! ( myMap.find( happy ) == myMap.end() ) )
          {
            std::cout << idx << " " << number << " NO" << std::endl;
            break;
          }

          myMap[happy] = true; 

          candidate = happy;

        }
      }
      else
      {
        std::cout << idx << " " << number << " NO" << std::endl;
      }
    }

   return 0;
}
