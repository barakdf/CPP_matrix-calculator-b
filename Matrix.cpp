//
// Created by barak on 08/04/2022.
//
#include <sstream>
#include "Matrix.hpp"

using namespace zich;

Matrix::Matrix(const std::vector<double> &mat, int row, int col) {
    if (row * col != mat.size()) {
        std::cout << "row*col = " << row * col << "Mat.size = " << mat.size() << std::endl;
        throw std::invalid_argument("size does not match the vector!");
    }
    this->r = (size_t) row;
    this->c = (size_t) col;
    std::vector<double> temp;
    for (size_t i = 0; i < this->r; ++i) {
        for (size_t j = i * this->c; j < (i + 1) * this->c; ++j) {
            temp.push_back(mat.at(j));
            sum_val += mat.at(j);
        }
        this->matrix.push_back(temp);
        temp.clear();
    }
}


/* self-object arithmetic operators */

Matrix &Matrix::operator+=(const Matrix &other) {
    if (this->col() != other.col() || this->row() != other.row()) {
        throw std::invalid_argument("Matrices must be the same size!");
    }
    for (size_t i = 0; i < this->row(); ++i) {
        for (size_t j = 0; j < this->col(); ++j) {
            this->matrix.at(i).at(j) += other.matrix.at(i).at(j);
        }
    }
    return *this;
}

Matrix &Matrix::operator-=(const Matrix &other) {
    if (this->col() != other.col() || this->row() != other.row()) {
        throw std::invalid_argument("Matrices must be the same size!");
    }
    for (size_t i = 0; i < this->row(); ++i) {
        for (size_t j = 0; j < this->col(); ++j) {
            this->matrix.at(i).at(j) -= other.matrix.at(i).at(j);
        }
    }
    return *this;
}

Matrix &Matrix::operator*=(const Matrix &other) {
    if (this->col() != other.row()) {
        throw std::invalid_argument("Illegal matrix multiplication!");
    }

    std::vector<std::vector<double>> temp_row;
    std::vector<double> temp_col;
    for (size_t i = 0; i < this->row(); ++i) {
        for (size_t j = 0; j < other.col(); ++j) {
            double block = 0;

            for (size_t k = 0; k < this->col(); ++k) {
                block += this->matrix.at(i)[k] * other.matrix.at(k)[j];
            }
            temp_col.push_back(block);
        }
        temp_row.push_back(temp_col);
        temp_col.clear();
    }
    this->col() = other.col();
    sum_value() = 0;

    for (size_t i = 0; i < this->row(); ++i) {
        this->matrix.at(i).clear();
        for (size_t j = 0; j < this->col(); ++j) {
            this->matrix.at(i).push_back(temp_row.at(i).at(j));
            sum_value() += temp_row.at(i).at(j);
        }
    }
    return *this;


}

Matrix &Matrix::operator*=(const double &scalar) {
    for (size_t i = 0; i < row(); ++i) {
        for (size_t j = 0; j < col(); ++j) {
            this->matrix.at(i)[j] *= scalar;
        }
    }
    return *this;
}

/*--prefix--*/
Matrix &Matrix::operator--() {
    for (size_t i = 0; i < this->row(); ++i) {
        for (size_t j = 0; j < this->col(); ++j) {
            this->matrix.at(i).at(j) -= 1;
        }
    }
    return *this;
}

Matrix &Matrix::operator++() {
    for (size_t i = 0; i < this->row(); ++i) {
        for (size_t j = 0; j < this->col(); ++j) {
            this->matrix.at(i).at(j) -= 1;
        }
    }
    return *this;
}

/* Postfix */
Matrix Matrix::operator--(int dummy_flag_for_postfix_increment) {
    Matrix copy = *this;
    --(*this);
    return copy;
}

Matrix Matrix::operator++(int dummy_flag_for_postfix_increment) {
    Matrix copy = *this;
    ++(*this);
    return copy;
}

/* Arithmetic Operators */
Matrix zich::operator+(const Matrix &a, const Matrix &b) {
    if (a.col() != b.col() || a.row() != b.row()) {
        throw std::invalid_argument("Matrices must be the same size!");
    }
    size_t temp_row = a.row();
    size_t temp_col = a.col();
    std::vector<double> temp_vec;
    for (size_t i = 0; i < temp_row; ++i) {
        for (size_t j = 0; j < temp_col; ++j) {
            temp_vec.push_back(a.matrix.at(i).at(j) + b.matrix.at(i).at(j));
        }
    }
    return Matrix{temp_vec, (int) temp_row, (int) temp_col};

}

Matrix zich::operator-(const Matrix &a, const Matrix &b) {
    if (a.col() != b.col() || a.row() != b.row()) {
        throw std::invalid_argument("Matrices must be the same size!");
    }
    size_t temp_row = a.row();
    size_t temp_col = a.col();
    std::vector<double> temp_vec;
    for (size_t i = 0; i < temp_row; ++i) {
        for (size_t j = 0; j < temp_col; ++j) {
            temp_vec.push_back(a.matrix.at(i).at(j) - b.matrix.at(i).at(j));
        }
    }
    return Matrix{temp_vec, (int) temp_row, (int) temp_col};
}

Matrix zich::operator*(const Matrix &a, const Matrix &b) {
    if (a.col() != b.row()) {
        throw std::invalid_argument("Illegal matrix multiplication!");
    }
    std::vector<double> temp;
    for (size_t i = 0; i < a.row(); ++i) {
        for (size_t j = 0; j < b.col(); ++j) {
            double block = 0;
            for (size_t k = 0; k < a.col(); ++k) {
                block += a.matrix.at(i)[k] * b.matrix.at(k)[j];
            }
            temp.push_back(block);
        }
    }

    return Matrix{temp, (int) a.row(), (int) b.col()};
}

Matrix zich::operator*(const double &scalar, const Matrix &a) {
    std::vector<double> temp;
    for (size_t i = 0; i < a.row(); ++i) {
        for (size_t j = 0; j < a.col(); ++j) {
            temp.push_back(a.matrix.at(i)[j] * scalar);
        }
    }
    return Matrix{temp, (int) a.row(), (int) a.col()};

}

Matrix zich::operator*(const Matrix &a, const double &scalar) {
    std::vector<double> temp;
    for (size_t i = 0; i < a.row(); ++i) {
        for (size_t j = 0; j < a.col(); ++j) {
            temp.push_back(a.matrix.at(i)[j] * scalar);
        }
    }
    return Matrix{temp, (int) a.row(), (int) a.col()};
}

Matrix Matrix::operator-() const {
    double s = -1;
    return (s * (*this));
}

Matrix Matrix::operator+() const {
    return (*this);
}

/*Boolean Expressions */
bool zich::operator==(const Matrix &a, const Matrix &b) {
    for (size_t i = 0; i < a.row(); ++i) {
        for (size_t j = 0; j < a.col(); ++j) {
            if (a.matrix[i][j] != b.matrix[i][j]) {
                return false;
            }
        }

    }
    return true;
}

bool zich::operator!=(const Matrix &a, const Matrix &b) {
    return !(a == b);
}

bool zich::operator<(const Matrix &a, const Matrix &b) {
    return a.sum_value() < b.sum_value();
}

bool zich::operator>(const Matrix &a, const Matrix &b) {
    return a.sum_value() > b.sum_value();
}

bool zich::operator<=(const Matrix &a, const Matrix &b) {
    return (a < b) || (a == b);
}

bool zich::operator>=(const Matrix &a, const Matrix &b) {
    return (a > b) || (a == b);
}

std::ostream &operator<<(std::ostream &os, zich::Matrix &other) {
    for (size_t r = 0; r < other.row(); ++r) {
        os << '[';
        for (size_t i = 0; i < other.col(); ++i) {
            os << other._matrix()[r][i];
            if (i < other.col() - 1) {
                os << ' ';
            }
        }
        os << "]\n";
    }
    return os ;
}

std::istream &zich::operator>>(std::istream &input, Matrix &other) {
    return input;
}






