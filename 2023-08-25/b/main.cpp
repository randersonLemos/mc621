#include <iostream>
#include <vector>
#include <map>

class Frog 
{
private:
  int hop=0;
  int pos=0;
  int wei=0;

public:
  Frog () {};
  Frog (int hop) : hop(hop) {}

  void describe () const
  {
    std::cout << "hop: " << this->hop << ", pos: " << this->pos << ", wei: " << this->wei << std::endl; 
  }
    
  void increaseWeight()
  {
    this->wei++; 
  }

  int jump()
  {
    this->pos += this->hop;
    return this->pos;
  }

  int getWeight()
  {
    return this->wei;    
  }

  int getPosition()
  {
    return this->pos;
  }

};

int main()
{
  int N; std::cin >> N;

  while(N)
  {
    N--; 
    int n; std::cin >> n;


    std::map< int, Frog > frogMap;


    for(int i=0; i<n; i++) 
    {
      int hop; std::cin >> hop;
      if( !frogMap.count(hop) )
        frogMap[hop] = Frog(hop);
      frogMap[hop].increaseWeight();
    }


    int *arr = new int[n+1];
    for(int i=0; i<n+1; i++)
      arr[i] = 0;

    int maxWeight = 0;

    for( auto& pair : frogMap )
    {
      Frog& frog = pair.second;      
      while(true)
      {
        int pos = frog.jump();
        if(pos > n)
          break;
        arr[pos] += frog.getWeight();
        if(maxWeight < arr[pos])
          maxWeight = arr[pos];        
      }
    }


    delete[] arr;


    std::cout << maxWeight << std::endl;
  }
}
