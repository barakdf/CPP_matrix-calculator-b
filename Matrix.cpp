//
// Created by barak on 08/04/2022.
//

#include "Matrix.hpp"

using namespace zich;

Matrix::Matrix(const std::vector<double> &mat, int row, int col) {
    if (row * col != mat.size()) {
        throw std::invalid_argument("size does not match the vector!");
    }
    this->r = row;
    this->c = col;
    for (int i = 0; i < row; ++i) {
        for (int j = i * (col); j < (i + 1) * col; ++j) {
            this->matrix.at(i).push_back(mat.at(j));
        }
    }
}

Matrix::~Matrix() {
}

/* self-object arithmetic operators */

Matrix &Matrix::operator+=(const Matrix &other) {
    if (this->col() != other.col() || this->row() != other.row()) {
        throw std::invalid_argument("Matrices must be the same size!");
    }
    for (int i = 0; i < this->row(); ++i) {
        for (int j = 0; j < this->col(); ++j) {
            this->matrix.at(i).at(j) += other.matrix.at(i).at(j);
        }
    }
    return *this;
}

Matrix &Matrix::operator-=(const Matrix &other) {
    if (this->col() != other.col() || this->row() != other.row()) {
        throw std::invalid_argument("Matrices must be the same size!");
    }
    for (int i = 0; i < this->row(); ++i) {
        for (int j = 0; j < this->col(); ++j) {
            this->matrix.at(i).at(j) -= other.matrix.at(i).at(j);
        }
    }
    return *this;
}

Matrix &Matrix::operator*=(const Matrix &other) {
    if (this->col() != other.row()) {
        throw std::invalid_argument("Illegal matrix multiplication!");
    }
    std::vector<std::vector<double>> temp;
    for (int i = 0; i < this->row(); ++i) {
        for (int j = 0; j < other.col(); ++j) {
            double block = 0;
            for (int k = 0; k < this->col(); ++k) {
                block += this->matrix.at(i)[k] * other.matrix.at(k)[j];
            }
            temp.at(i).push_back(block);
        }
    }
    this->col() = other.col();
    for (int i = 0; i < this->row(); ++i) {
        for (int j = 0; j < this->col(); ++j) {
            this->matrix.at(i).at(j) = temp.at(i).at(j);
        }
    }
    return *this;


}

Matrix &Matrix::operator*=(const double &scalar) {
    for (int i = 0; i < row(); ++i) {
        for (int j = 0; j < col(); ++j) {
            this->matrix.at(i)[j] *= scalar;
        }
    }
    return *this;
}

/*--prefix--*/
Matrix &Matrix::operator--() {
    for (int i = 0; i < this->row(); ++i) {
        for (int j = 0; j < this->col(); ++j) {
            this->matrix.at(i).at(j) -= 1;
        }
    }
    return *this;
}

Matrix &Matrix::operator++() {
    for (int i = 0; i < this->row(); ++i) {
        for (int j = 0; j < this->col(); ++j) {
            this->matrix.at(i).at(j) -= 1;
        }
    }
    return *this;
}

/* Postfix */
Matrix Matrix::operator--(int flag) {
    Matrix copy = *this;
    --(*this);
    return copy;
}

Matrix Matrix::operator++(int flag) {
    Matrix copy = *this;
    ++(*this);
    return copy;
}

/* Arithmetic Operators */
Matrix zich::operator+(const Matrix &a, const Matrix &b) {
    if (a.col() != b.col() || a.row() != b.row()) {
        throw std::invalid_argument("Matrices must be the same size!");
    }
    int temp_row = a.row();
    int temp_col = a.col();
    std::vector<double> temp_vec;
    for (int i = 0; i < temp_row; ++i) {
        for (int j = 0; j < temp_col; ++j) {
            temp_vec.push_back(a.matrix.at(i).at(j) + b.matrix.at(i).at(j));
        }
    }
    return Matrix{temp_vec, temp_row, temp_col};

}

Matrix zich::operator-(const Matrix &a, const Matrix &b) {
    if (a.col() != b.col() || a.row() != b.row()) {
        throw std::invalid_argument("Matrices must be the same size!");
    }
    int temp_row = a.row();
    int temp_col = a.col();
    std::vector<double> temp_vec;
    for (int i = 0; i < temp_row; ++i) {
        for (int j = 0; j < temp_col; ++j) {
            temp_vec.push_back(a.matrix.at(i).at(j) - b.matrix.at(i).at(j));
        }
    }
    return Matrix{temp_vec, temp_row, temp_col};
}

Matrix zich::operator*(const Matrix &a, const Matrix &b) {
    if (a.col() != b.row()) {
        throw std::invalid_argument("Illegal matrix multiplication!");
    }
    std::vector<double> temp;
    for (int i = 0; i < a.row(); ++i) {
        for (int j = 0; j < b.col(); ++j) {
            double block = 0;
            for (int k = 0; k < a.col(); ++k) {
                block += a.matrix.at(i)[k] * b.matrix.at(k)[j];
            }
            temp.push_back(block);
        }
    }

    return Matrix{temp, a.row(), b.col()};
}

Matrix zich::operator*(const double &scalar, const Matrix &a) {
    std::vector<double> temp;
    for (int i = 0; i < a.row(); ++i) {
        for (int j = 0; j < a.col(); ++j) {
            temp.push_back(a.matrix.at(i)[j] * scalar);
        }
    }
    return Matrix{temp, a.row(), a.col()};

}
Matrix zich::operator*(const Matrix &a,const double &scalar) {
    std::vector<double> temp;
    for (int i = 0; i < a.row(); ++i) {
        for (int j = 0; j < a.col(); ++j) {
            temp.push_back(a.matrix.at(i)[j] * scalar);
        }
    }
    return Matrix{temp, a.row(), a.col()};
}

Matrix Matrix::operator-() const {
    double s = -1;
    return (s * (*this) );
}
Matrix Matrix::operator+() const {
    return (*this);
}




