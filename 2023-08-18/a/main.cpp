#include <iostream>
#include <string>
#include <map>

std::string key(std::string name1, std::string name2)
{
  return name1 + " " + name2;
}


int main()
{
  int count = 0;
  while(true)
  {
    int n, t, value;
    std::string name, name1, name2;
    std::string names[20];

    std::cin >> n >> t;

    if(n==0 and t==0)
      break;

    for(int i=0; i<n; i++)
    {
      std::cin >> names[i];
    }

    std::map<std::string, int> map;

    //for(int i=0; i<n; i++)
    //{
    //  for(int j=i+1; j<n; j++)
    //  {
    //    map.insert( { names[i] + " " + names[j], 0 } );
    //  }
    //}


   for(int i=0; i<t; i++)
   {
      std::cin >> name1 >> name2 >> value;
      if( map.count( key(name1, name2) ) )
      {
        map[key(name1, name2)] += value;
      
      }
      else if( map.count(key(name2, name1)))
      {
        map[key(name2, name1)] -= value;
      
      }
      else
      {
        map[key(name1, name2)] += value;
      }
    }

    std::map<std::string, int>::iterator it;
    std::cout << "+++" << std::endl;
    for(it = map.begin(); it != map.end(); it++)
    {
      std::cout << it->first    // string (key)
                << " "
                << it->second   // string's value 
                << std::endl;   
    }
    std::cout << "+++" << std::endl;
    
  }
  return 0;
}
