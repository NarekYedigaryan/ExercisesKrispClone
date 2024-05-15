#ifndef MATRIX_H
#define MATRIX_h

#include <iostream>
#include <algorithm>
#include <vector>
class Proxy
{
  public:
    Proxy(int* arr);
    int& operator[](size_t ind);

  private:
    int* arr; 
};

struct Matrix 
{
  private:
    int row;
    int col;
    int** matric;
  public:
    Proxy operator[](size_t ind);
    Matrix(int a ,int b);
    Matrix() = default;
    ~Matrix();

    friend class MatrixFunctions;
};

class MatrixFunctions
{
  
    public:
      MatrixFunctions() {}
      Matrix add(Matrix matrix1,Matrix matrix2);
      Matrix multiplication(Matrix matrix1,Matrix matrix2);
      Matrix getTranspose(Matrix matrix);
      bool isSymmetric(Matrix matrix);
      bool isSkewSymmetric(Matrix matrix);
      std::vector<std::vector<int>> getAllPermutations(int n);
      int sign(std::vector<int>);
      int determinant(Matrix matrix);
      void print(Matrix ob);
    private:
};

#endif