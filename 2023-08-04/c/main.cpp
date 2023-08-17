#include <cmath>
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
    std::fstream file;
    file.open("output.txt", std::ios::out);

    for(int l=0; l<L; l++)
    {
      for(int c=0; c<C; c++) 
      {
       file << mat[l][c];
      }
      file << "\n";
    }
    file.close();
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


void  fillMatrix(char **mat, int L, int C)
{
  for(int l=0; l<L; l++)
  {
    for(int c=0; c<C; c++) 
    {
      mat[l][c] = '-'; 
    }
  }
}


void destroyMatrix(char** mat, int L)
{
  for(int l=0; l<L; l++)
  {
    delete[] mat[l];
  }
  delete [] mat;
}


char** fractal( char** model, int n, int k, int factor )
{

  std::cout << "+++MODEL+++" << std::endl;
  printMatrix( model, n, n );
  std::cout << "+++++++++++" << std::endl;

  if( k == 1 )
  {
    return model; 
  }

  int nn = factor*n;
  char  **modelmodel = createMatrix( nn, nn );
  fillMatrix(modelmodel, nn, nn);

  for(int l=0; l<n; l++)
  {
    for(int c=0; c<n; c++) 
    {
      char sign = model[l][c];
      std::cout << sign << std::endl;
      if(sign=='.') // white space
      {
        for(int ll=factor*l; ll<factor*(l+1); ll++)  
        {
          for(int cc=factor*c; cc<factor*(c+1); cc++)
          {
            modelmodel[ll][cc] = model[ll%factor][cc%factor];
            //model[ll][cc] = '.';
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
            //model[ll][cc] = '*';
          }
        }
      }
    std::cout << "###" << std::endl;
    printMatrix( modelmodel, nn, nn );
    std::cout << "###" << std::endl;
    }
  }
  
  destroyMatrix( model, n );
  n = nn;
  model = modelmodel;

  return fractal( model, n, k-1, factor);
}


int main() {
    std::ifstream file ("input.txt");

    int n, k;
    int& factor = n;

    file >> n >> k;

    char** model = createMatrix(n, n);

    for(int l=0; l<n; l++)
    {
      for(int c=0; c<n; c++) 
      {
        file >> model[l][c];
      }
    }

    file.close();
    
    model = fractal( model, n, k, factor );

    //printMatrixFile( model, n, n );
    //destroyMatrix( model, n );

    return 0;
}
