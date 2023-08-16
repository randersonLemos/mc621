#include <iostream>

struct node {
  long long int a;
  long long int p;
};

int f(node* nodes, long long int x, long long int y)
{
  std::cout << x+1 << " " << y+1 << std::endl;
  if( x+1 != 0 and y+1 != 0)
  {
    return nodes[x].a * nodes[y].a + f(nodes, nodes[x].p-1, nodes[y].p-1);
  }
  return 0;
};


int main() {
  int n, q = 0;
  std::cin >> n >> q;
 
  node* nodes = new node[n];

  nodes[0].p = 0;
  for(int i=0; i<n; i++)
  {
    std::cin >> nodes[i].a;
  }

  for(int i=0; i<n-1; i++)
  {
    std::cin >> nodes[i+1].p;
  }


  //for(int i=0; i<n; i++)
  //{
  //  std::cout << nodes[i].a << " " << nodes[i].p << std::endl;
  //}
  //std::cout << "---" << std::endl;
  

  for(int i=0; i<q; i++)
  {
    int x, y;
    std::cin >> x >> y;
    std::cout << f(nodes, x-1, y-1) << std::endl;

  }


  return 0;
}
