#include "Matrix.h"

Proxy::Proxy(int* arr)
:arr(arr)
{}

int& Proxy::operator[](size_t ind)
{
      return arr[ind];
}

Matrix::Matrix(int a ,int b)
:row(a)
,col(b)
{
   matric = new int*[row];
   for (int i = 0; i < row; ++i)
   {
    matric[i] = new int[col];
   }
}

Proxy Matrix::operator[](size_t ind)
{
    return matric[ind];
}


Matrix::~Matrix()
{
    for (int i = 0; i < row; ++i)
    {
       delete [] matric[i];
    }
    delete [] matric;
}

Matrix MatrixFunctions::add(Matrix matrix1, Matrix matrix2)
{
    if (matrix1.col != matrix2.col || matrix1.row != matrix2.row)
    {
        std::cerr << "Matrix sizes are not the same" << std::endl;
    }

    Matrix result(matrix1.row, matrix1.col); 

    for (size_t i = 0; i < matrix1.row; i++)
    {
        for (size_t j = 0; j < matrix1.col; j++)
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    return result; 
}

Matrix MatrixFunctions::multiplication(Matrix matrix1, Matrix matrix2)
{
    if (matrix1.col != matrix2.row)
    {
        std::cerr << "The matrix sizes are not correct" << std::endl;
    }

    Matrix result(matrix1.row, matrix2.col);

    for (size_t i = 0; i < matrix1.row; i++)
    {
        for (size_t j = 0; j < matrix2.col; j++)
        {
            result[i][j] = 0;

            for (size_t k = 0; k < matrix1.col; k++)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result; 
}

Matrix MatrixFunctions::getTranspose(Matrix matrix)
{
    Matrix transpose(matrix.col, matrix.row);

    for (size_t i = 0; i < matrix.row; ++i)
    {
        for (size_t j = 0; j < matrix.col; ++j)
        {
            transpose[j][i] = matrix[i][j];
        }
    }

    return transpose;
}

bool MatrixFunctions::isSymmetric(Matrix matrix)
{
    Matrix transposeMatrix = getTranspose(matrix);

    for (size_t i = 0; i < matrix.row; ++i)
    {
        for (size_t j = 0; j < matrix.col; ++j)
        {
            if (matrix[i][j] != transposeMatrix[i][j])
            {
                return false;
            }
        }
    }

    return true;
}


bool MatrixFunctions::isSkewSymmetric(Matrix matrix)
{
    Matrix transposeMatrix = getTranspose(matrix);

    for (size_t i = 0; i < matrix.row; ++i)
    {
        for (size_t j = 0; j < matrix.col; ++j)
        {
            if (matrix[i][j] != -transposeMatrix[i][j])
            {
                return false;
            }
        }
    }

    return true;
}


std::vector<std::vector<int>> MatrixFunctions::getAllPermutations(int n)
{
    std::vector<std::vector<int>> permutations;

    std::vector<int> sequence;
    for (int i = 1; i <= n; ++i)
    {
        sequence.push_back(i);
    }

    do
    {
        permutations.push_back(sequence);
    } while (std::next_permutation(sequence.begin(), sequence.end()));

    return permutations;
}

int MatrixFunctions::sign( std::vector<int> permutation)
{
    int inversionCount = 0;
    int n = permutation.size();

    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (permutation[i] > permutation[j])
            {
                inversionCount++;
            }
        }
    }

    return (inversionCount % 2 == 0) ? 1 : -1;
}
int MatrixFunctions::determinant(Matrix matrix)
{
    if (matrix.row != matrix.col)
    {
        return 0;
    }

    if (matrix.row == 1)
    {
        return matrix[0][0];
    }

    int det = 0;

    for (size_t j = 0; j < matrix.col; ++j)
    {
        Matrix minor(matrix.row - 1, matrix.col - 1);
        for (size_t i = 1; i < matrix.row; ++i)
        {
            for (size_t k = 0; k < matrix.col; ++k)
            {
                if (k < j)
                {
                    minor[i - 1][k] = matrix[i][k];
                }
                else if (k > j)
                {
                    minor[i - 1][k - 1] = matrix[i][k];
                }
            }
        }

        int sign = (j % 2 == 0) ? 1 : -1;
        int cofactor = sign * determinant(minor);

        det += matrix[0][j] * cofactor;
    }

    return det;
}

void MatrixFunctions::print(Matrix ob)
{
    for (size_t i = 0; i < ob.row; i++)
    {
        for (size_t j = 0; j < ob.col; j++)
        {
            std::cout << ob[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

