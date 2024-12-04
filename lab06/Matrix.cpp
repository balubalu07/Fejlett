//
// Created by Balazs on 2024. 10. 30..
//

#include "Matrix.h"

Matrix::Matrix(int mRows, int mCols) {
    this->mRows = mRows;
    this->mCols = mCols;
    this->mElements = new double *[mRows];
    for (int i = 0; i < mRows; ++i) {
        mElements[i] = new double[mCols];
    }
}

Matrix::~Matrix() {
    cout << *this << endl;
    for (int i = 0; i < mRows; ++i) {
        delete[] this->mElements[i];
    }
    delete[] this->mElements;
    this->mRows = 0;
    this->mCols = 0;
}

void Matrix::fillMatrix(double value) {
    for (int i = 0; i < this->mRows; ++i) {
        for (int j = 0; j < this->mCols; ++j) {
            this->mElements[i][j] = value;
        }
    }
}

void Matrix::printMatrix(ostream &os) const {
    for (int i = 0; i < this->mRows; ++i) {
        for (int j = 0; j < this->mCols; ++j) {
            os << setw(5) << this->mElements[i][j];
        }
        os << endl;
    }
}

ostream &operator<<(ostream &os, const Matrix &mat) {
    mat.printMatrix(os);
    return os;
}

Matrix::Matrix(const Matrix &what) {
    this->mRows = what.mRows;
    this->mCols = what.mCols;
    this->mElements = new double *[mRows];
    for (int i = 0; i < mRows; ++i) {
        mElements[i] = new double[mCols];
    }
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            this->mElements[i][j] = what.mElements[i][j];
        }
    }
}

Matrix::Matrix(Matrix &&what) {
    cout << "moveConst" << endl;
    this->mRows = what.mRows;
    this->mCols = what.mCols;
    this->mElements = what.mElements;
    what.mElements = nullptr;
    what.mRows = 0;
    what.mCols = 0;

}

void Matrix::randomMatrix(int a, int b) {
    for (int i = 0; i < this->mRows; ++i) {
        for (int j = 0; j < this->mCols; ++j) {
            this->mElements[i][j] = rand() % (b - a + 1) + a;
        }
    }
}

bool Matrix::isSquare() const {
    return this->mRows == this->mCols;
}

Matrix operator+(const Matrix &x, const Matrix &y) {
    if (x.mRows != y.mRows || x.mCols != y.mCols) {
        throw invalid_argument("Matrixes are not the same size");
    }
    Matrix z(x.mRows, x.mCols);
    for (int i = 0; i < z.mRows; i++) {
        for (int j = 0; j < z.mCols; j++) {
            z.mElements[i][j] = x.mElements[i][j] + y.mElements[i][j];
        }
    }
    return z;
}

Matrix operator*(const Matrix &x, const Matrix &y) {
    if (x.mCols != y.mRows) {
        throw invalid_argument("Matrixes are not the same size");
    }
    Matrix z(x.mRows, y.mCols);
    for (int i = 0; i < x.mRows; i++) {
        for (int j = 0; j < y.mCols; j++) {
            z.mElements[i][j] = 0;
            for (int k = 0; k < x.mCols; k++) {
                z.mElements[i][j] += x.mElements[i][k] * y.mElements[k][j];
            }
        }
    }
    cout << "operator*" << endl;
    z.printMatrix();
    cout << endl;
    return z;
}

istream &operator>>(istream &is, Matrix &mat) {
    for (int i = 0; i < mat.mRows; ++i) {
        for (int j = 0; j < mat.mCols; ++j) {
            is >> mat.mElements[i][j];
        }
    }
    return is;
}

Matrix &Matrix::operator=(const Matrix &mat) {
    if (this != &mat) {
        for (int i = 0; i < this->mRows; ++i) {
            delete[] this->mElements[i];
        }
        delete[] this->mElements;
        this->mRows = mat.mRows;
        this->mCols = mat.mCols;
        this->mElements = new double *[mRows];
        for (int i = 0; i < mRows; ++i) {
            this->mElements[i] = new double[mCols];
        }
        for (int i = 0; i < mRows; ++i) {
            for (int j = 0; j < mCols; ++j) {
                this->mElements[i][j] = mat.mElements[i][j];
            }
        }
    }
    return *this;
}

Matrix &Matrix::operator=(Matrix &&mat) {

    for (int i = 0; i < this->mRows; ++i) {
        delete[] this->mElements[i];
    }
    delete[] this->mElements;

    this->mRows = mat.mRows;
    this->mCols = mat.mCols;
    this->mElements = mat.mElements;

    mat.mElements = nullptr;
    mat.mRows = 0;
    mat.mCols = 0;

    return *this;
}

double *Matrix::operator[](int index) {
    if (index < 0 || index >= this->mRows) {
        throw out_of_range("Index out of range");
    }
    return this->mElements[index];
}

double *Matrix::operator[](int index) const {
    if (index < 0 || index >= this->mRows) {
        throw out_of_range("Index out of range");
    }
    return this->mElements[index];
}

