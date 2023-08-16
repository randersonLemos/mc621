#include <iostream>
#include <fstream>


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



void printMatrixFile(char **mat, int L, int C)
{
    std::fstream outputFile;
    outputFile.open("output.txt", std::ios::out);

    for(int l=0; l<L; l++)
    {
      for(int c=0; c<C; c++) 
      {
       outputFile << mat[l][c];
      }
      outputFile << "\n";
    }
    outputFile.close();
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
  std::cout << "+++" << "k=" << k << "+++" << std::endl;
  printMatrix( model, n, n );
  if( k == 1 )
  {
    return model; 
  }

  int nn = factor*n;

  for(int l=(n-1); l>=0; l--)
  {
    for(int c=(n-1); c>=0; c--) 
    {
      char sign = model[l][c];
      if(sign=='.') // white space
      {
        for(int ll=factor*l; ll<factor*(l+1); ll++)  
        {
          for(int cc=factor*c; cc<factor*(c+1); cc++)
          {
            std::cout << "l=" << l << "c=" << c << "ll=" << ll << "cc=" << cc << std::endl;
            model[ll][cc] = model[ll%2][cc%2];
          }
        }        
      }
      else // black space
      {
        for(int ll=factor*l; ll<factor*(l+1); ll++)  
        {
          for(int cc=factor*c; cc<factor*(c+1); cc++)
          {
            model[ll][cc] = sign;
          }
        }
      }
    }
  }

  n = nn;
  
  std::cout << "---" << std::endl;
  printMatrix( model, n, n );

  return fractal( model, n, k-1, factor );
}


int main() {
    std::ifstream inputFile ("input.txt");

    int n, k;

    //std::cin >> n >> k;
    inputFile >> n >> k;

    int factor = n;

    std::cout << "n=" << n << "k=" << k << "n*k*factor=" << n*k*factor << std::endl;
    
    char** model = createMatrix(n*k*factor, n*k*factor);

    for(int l=0; l<n; l++)
    {
      for(int c=0; c<n; c++) 
      {
        //std::cin >> model[l][c];
        inputFile >> model[l][c];
      }
    }

    inputFile.close();
    
    model = fractal( model, n, k, factor );

    std::cout << "---" << std::endl;
    
    printMatrix( model, n, n );
    destroyMatrix( model, n );

    return 0;
}
