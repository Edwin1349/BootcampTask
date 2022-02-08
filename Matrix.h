#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <cstdlib>

class Matrix{
public:
    Matrix(int rows, int columns);
    Matrix(int rows, int columns, int number);

    int GetRows(){
        return this->rows;
    }

    int GetColumns(){
        return this->columns;
    }

    Matrix& operator+=(const Matrix& mat);

    Matrix& operator-= (const Matrix& mat);

    Matrix operator* (const Matrix& mat);

    double *SumRows();
    double *SumColumns();

    Matrix Transpose();

    void PrintMatrix();

    ~Matrix();


private:
    int rows, columns;
    double **matrix;
};
#endif // MATRIX_H
