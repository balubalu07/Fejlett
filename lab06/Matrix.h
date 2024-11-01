//
// Created by Balazs on 2024. 10. 30..
//

#ifndef LAB5_MATRIX_H
#define LAB5_MATRIX_H

#include <iostream>
#include <stdexcept>
#include <iomanip>

using namespace std;


class Matrix {
public:
    Matrix(int mRows = 10, int mCols = 10);

    Matrix(const Matrix &what);

    Matrix(Matrix &&what);

    ~Matrix();

    void fillMatrix(double value);

    void randomMatrix(int a, int b);

    void printMatrix(ostream &os = cout) const;

    bool isSquare() const;

    int getRows() const { return this->mRows; }

    int getCols() const { return this->mCols; }

    friend Matrix operator+(const Matrix &x, const Matrix &y);

    double *operator[](int index);

    double *operator[](int index) const;

    friend Matrix operator*(const Matrix &x, const Matrix &y);

    friend istream &operator>>(istream &is, Matrix &mat);

    friend ostream &operator<<(ostream &os, const Matrix &mat);

    Matrix &operator=(const Matrix &mat);

    Matrix &operator=(Matrix &&mat);

private:
    double **mElements;
    int mRows;
    int mCols;

};


#endif //LAB5_MATRIX_H
