#include "Matrix.h"

Matrix::Matrix(int rows, int columns):rows(rows), columns(columns){
    this->matrix = new double *[this->rows];
    for(int i = 0; i < this->rows; i++){
        this->matrix[i] = new double[this->columns];
        for(int j = 0; j < this->columns; j++){
            this->matrix[i][j] = rand() % 10 + 1;
        }
    }
}

Matrix::Matrix(int rows, int columns, int number):rows(rows), columns(columns){
    this->matrix = new double *[this->rows];
    for(int i = 0; i < this->rows; i++){
        this->matrix[i] = new double[this->columns];
        for(int j = 0; j < this->columns; j++){
            if(i == j){
                this->matrix[i][j] = number;
            }
            else{
                this->matrix[i][j] = 0;
            }
        }
    }
}

Matrix& Matrix::operator+=(const Matrix& mat){
    std::cout << "Func: " << __FUNCTION__ << std::endl;

    if(this->rows == mat.rows && this->columns == mat.columns){
        for(int i = 0; i < this->rows; i++){
            for(int j = 0; j < this->columns; j++){
                 this->matrix[i][j] += mat.matrix[i][j];
            }
        }
    }
    return *this;
}

Matrix& Matrix::operator-=(const Matrix& mat){
    std::cout << "Func: " << __FUNCTION__ << std::endl;

    if(this->rows == mat.rows && this->columns == mat.columns){
        for(int i = 0; i < this->rows; i++){
            for(int j = 0; j < this->columns; j++){
                 this->matrix[i][j] -= mat.matrix[i][j];
            }
        }
    }
    return *this;
}

Matrix Matrix::operator*(const Matrix& mat){
    std::cout << "Func: " << __FUNCTION__ << std::endl;

    Matrix res(this->rows, mat.columns, 0);
    if(this->rows == mat.columns){
        for(int i = 0; i < this->rows; i++){
            for(int j = 0; j < mat.columns; j++){
                for(int k = 0; k < mat.rows; k++){
                    res.matrix[i][j] += this->matrix[i][k] * mat.matrix[k][j];
                }
            }
        }
    }
    return res;
}

Matrix& Matrix::operator*=(const double &number){
    std::cout << "Func: " << __FUNCTION__ << std::endl;

    for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->columns; j++){
             this->matrix[i][j] *= number;
        }
    }
    return *this;
}

double *Matrix::SumRows(){
    std::cout << "Func: " << __FUNCTION__ << std::endl;

    double *res = new double[this->rows];
    for(int i = 0; i < this->rows; i++){
        res[i] = 0;
        for(int j = 0; j < this->columns; j++){
            res[i] += this->matrix[i][j];
        }
    }
    return res;
}

double *Matrix::SumColumns(){
    std::cout << "Func: " << __FUNCTION__ << std::endl;

    double *res = new double[this->columns];
    for(int i = 0; i < this->columns; i++){
        res[i] = 0;
        for(int j = 0; j < this->rows; j++){
            res[i] += this->matrix[j][i];
        }
    }
    return res;
}

Matrix Matrix::Transpose(){
    std::cout << "Func: " << __FUNCTION__ << std::endl;

    Matrix res(this->columns, this->rows, 0);
    for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->columns; j++){
            res.matrix[j][i] = this->matrix[i][j];
        }
    }
    return res;
}

void Matrix::PrintMatrix(){
    std::cout << "Func: " << __FUNCTION__ << std::endl;

    for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->columns; j++){
             std::cout << this->matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

Matrix::~Matrix(){
    std::cout << "Destructor\n";
    for(int i = 0; i < this->rows; i++){
        delete[] this->matrix[i];
    }
    delete[] this->matrix;
}
