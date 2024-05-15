#include "Matrix.h"

int main() {
    Matrix matrix1(3, 3); 
    Matrix matrix2(2, 2); 

    
    
    
    matrix1[0][0] = 1; matrix1[0][1] = 2;matrix1[0][2] = 3; matrix1[1][0] = 4; matrix1[1][1] = 5;
    matrix1[1][2] = 6 ;matrix1[2][0] = 7; matrix1[2][1] = 8; matrix1[2][2] = 9;
    matrix2[0][0] = 5; matrix2[0][1] = 6; matrix2[1][0] = 7; matrix2[1][1] = 8;

    MatrixFunctions functions;
    // Matrix result = functions.getTranspose(matrix1);
    // functions.print(result);
    std::cout<<functions.determinant(matrix1);
    return 0;
}
