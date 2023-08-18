#include <iostream>

struct node {
  long long int a;
  long long int p;
};

long long int f(node* nodes, long long int x, long long int y)
{
  //std::cout << x+1 << " " << y+1 << std::endl;
  if( x > 0 and y > 0)
  {
    return nodes[x-1].a * nodes[y-1].a + f(nodes, nodes[x-1].p, nodes[y-1].p);
  }
  return 0;
};

long long int fIt(node* nodes, long long int x, long long int y)
{
  long long int ans=0;
  while(true)
  {
    if( x > 0 and y > 0)
    {
      ans += nodes[x-1].a * nodes[y-1].a;
      x = nodes[x-1].p;
      y = nodes[y-1].p;
      continue;
    }
    return ans;
  }
};


int main() {
  int n, q = 0;
  std::cin >> n >> q;
 
  node* nodes = new node[n];

  for(int i=0; i<n; i++)
  {
    std::cin >> nodes[i].a;
  }

  nodes[0].p = 0;
  for(int i=1; i<n; i++)
  {
    std::cin >> nodes[i].p;
  }

  for(int i=0; i<q; i++)
  {
    int x, y;
    std::cin >> x >> y;
    std::cout << fIt(nodes, x, y) << std::endl;

  }
  return 0;
}
