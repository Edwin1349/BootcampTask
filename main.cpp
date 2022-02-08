#include "Timer.h"
#include "Matrix.h"

#define PrintArray(arr, n) for(int i = 0; i < n; i++) std::cout << arr[i] << " ";

int main(){
    Matrix *m1 = new Matrix(4, 4);
    m1->PrintMatrix();

    Matrix *m2 = new Matrix(4, 4);
    m2->PrintMatrix();

    //Addition
    {
        Timer timer;
        (*m1) += (*m2);
        m1->PrintMatrix();
    }

    //Substraction
    {
        Timer timer;
        (*m1) -= (*m2);
        m1->PrintMatrix();
    }

    //Sum by Columns
    {
        Timer timer;
        double *sum = m1->SumColumns();

        PrintArray(sum, m1->GetColumns());
        std::cout << "\n\n";

        delete[] sum;
    }

    //Sum by Rows
    {
        Timer timer;
        double *sum = m1->SumRows();

        PrintArray(sum, m1->GetRows());
        std::cout << "\n\n";

        delete[] sum;
    }

    //Transpose
    {
        Timer timer;
        m1->Transpose();
        m1->PrintMatrix();
    }

    //Multiplication
    {
        Timer timer;
        Matrix m3 = (*m1) * (*m2);
        m3.PrintMatrix();
    }

    delete m1;
    delete m2;
    getchar();
    return 0;
}
