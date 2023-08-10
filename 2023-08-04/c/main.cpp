#include <iostream>


void printMatrix(char **mat, int L, int C)
{
    for(int l=0; l<L; l++)
    {
      for(int c=0; c<C; c++) 
      {
        std::cout << mat[l][c];
      }
      std::cout << "\n";
    }
}


char** createMatrix(int L, int C)
{
  char** p = new char*[L];
  for(int l=0; l<L; l++)
  {
    p[l] = new char[C];
  }
  return p;
}


void destroyMatrix(char** mat, int L)
{
  for(int l=0; l<L; l++)
  {
    delete[] mat[l];
  }
  delete [] mat;
}


char** fractal( char** model, int& n, int k, int factor )
{
  if( k == 1 )
  {
    return model; 
  }

  int nn = factor*n;
  char** modelmodel = createMatrix(nn, nn);

  for(int l=0; l<n; l++)
  {
    for(int c=0; c<n; c++) 
    {
      char sign = model[l][c];
      if(sign=='.') // white space
      {
        for(int ll=factor*l; ll<factor*(l+1); ll++)  
        {
          for(int cc=factor*c; cc<factor*(c+1); cc++)
          {
            modelmodel[ll][cc] = model[ll%2][cc%2];
          }
        }        
      }
      else // black space
      {
        for(int ll=factor*l; ll<factor*(l+1); ll++)  
        {
          for(int cc=factor*c; cc<factor*(c+1); cc++)
          {
            modelmodel[ll][cc] = sign;
          }
        }
      }
    }
  }

  //destroyMatrix( model, n );
  n = nn;
  model = modelmodel;
  return fractal( model, n, k-1, factor );
}


int main() {
    int n, k;

    std::cin >> n >> k;

    int factor = n;
    
    char** model = createMatrix(n, n);

    for(int l=0; l<n; l++)
    {
      for(int c=0; c<n; c++) 
      {
        std::cin >> model[l][c];
      }
    }
    
    model = fractal( model, n, k, factor );

    printMatrix( model, n, n );
    //destroyMatrix( model, n );

    return 0;
}
