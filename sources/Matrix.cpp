//
// Created by barak on 08/04/2022.
//
#include <sstream>
#include "Matrix.hpp"

using namespace zich;

/* constructor for building new matrix object, get vector<double> and two integers as parameters
 * vector defines the values of the matrix,
 * and the integer parameters defines the size of the matrix, by rows and cols.
 * dealing with invalid parameters with throwing exception.
 * the matrix build is implemented by iterating the given vector and pushing values into 2D vector (the matrix).
 * */
Matrix::Matrix(const std::vector<double> &mat, int row, int col) {
    /* check if the size parameters is matching the length of the vector to be able to build matrix
     * if false --> throwing error
     * ~~ this check is dealing also with negative size etc*/
    if (row * col != mat.size()) {
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
    /* check if the operation is valid by comparing the matrices size, if size is not equal throwing error */
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
    /* check if the operation is valid by comparing the matrices size, if size is not equal throwing error */
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


/* because of student1 TEST ! */
Matrix &Matrix::operator+=(const double &scalar) {
    if (scalar == 0) {
        return *this;
    }
    for (size_t i = 0; i < this->row(); ++i) {
        for (size_t j = 0; j < this->col(); ++j) {
            this->matrix.at(i).at(j) -= scalar;
        }
    }
    return *this;
}

/* because of student1 TEST ! */
Matrix &Matrix::operator-=(const double &scalar) {
    if (scalar == 0) {
        return *this;
    }
    for (size_t i = 0; i < this->row(); ++i) {
        for (size_t j = 0; j < this->col(); ++j) {
            this->matrix.at(i).at(j) -= scalar;
        }
    }
    return *this;
}


Matrix &Matrix::operator*=(const Matrix &other) {
    /* check if the operation is valid by comparing the matrices size,
     * if the right matrix col size is not equal to the left matrix row size throwing error */
    if (this->col() != other.row()) {
        throw std::invalid_argument("Illegal matrix multiplication!");
    }

    /* using temp matrix with size that match the new matrix size after the multiplication,
     * fill all the new values in the temp matrix, and then change the (this) matrix sizes to match new temp size
     * fill the (this) matrix with values of the temp matrix while clearing the prev rows (vector<double>).*/
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
    /*iterating each value in the matrix and assign the curr value to be itself multiply the give scalar*/
    for (size_t i = 0; i < row(); ++i) {
        for (size_t j = 0; j < col(); ++j) {
            this->matrix.at(i)[j] *= scalar;
        }
    }
    return *this;
}

/*--prefix--*/
Matrix &Matrix::operator--() {
    /* iterating the matrix and change each value x to be x-1, returning the reference of (this) matrix after changes. */
    for (size_t i = 0; i < this->row(); ++i) {
        for (size_t j = 0; j < this->col(); ++j) {
            this->matrix.at(i).at(j) -= 1;
        }
    }
    return *this;
}

Matrix &Matrix::operator++() {
    /* iterating the matrix and change each value x to be x+1, returning the reference of (this) matrix after changes. */
    for (size_t i = 0; i < this->row(); ++i) {
        for (size_t j = 0; j < this->col(); ++j) {
            this->matrix.at(i).at(j) += 1;
        }
    }
    return *this;
}

/* Postfix */
Matrix Matrix::operator--(int dummy_flag_for_postfix_increment) {
    /*make a new copy of (this) matrix, decreasing each value of (this) matrix by 1 (does not affect (this) matrix),
     * and returning the copy matrix*/
    Matrix copy = *this;
    --(*this);
    return copy;
}

Matrix Matrix::operator++(int dummy_flag_for_postfix_increment) {
    /*make a new copy of (this) matrix, increasing each value of (this) matrix by 1 (does not affect (this) matrix),
     * and returning the copy matrix*/
    Matrix copy = *this;
    ++(*this);
    return copy;
}

/* Arithmetic Operators */
Matrix zich::operator+(const Matrix &a, const Matrix &b) {
    /* check if the operation is valid by comparing the matrices size, if size is not equal throwing error */
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
    /* check if the operation is valid by comparing the matrices size, if size is not equal throwing error */
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
    /* check if the operation is valid by comparing the matrices size,
     * if the right matrix col size is not equal to the left matrix row size throwing error */
    if (a.col() != b.row()) {
        throw std::invalid_argument("Illegal matrix multiplication!");
    }
    /* init a new temp vector<double> and pushing all the matrices' multiplication values,
     * when finished, the temp vector is formatted as the input of a new matrix object vector,
     * returning new matrix object with the new size (calculated by first mat->row and second mat->col)*/
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

Matrix zich::operator*(const double &scalar, const zich::Matrix &a) {
    /*iterating each value in the (this)matrix and copy each value to a new matrix
     * while assign each value to be itself multiply the give scalar*/
    std::vector<double> temp;
    for (size_t i = 0; i < a.row(); ++i) {
        for (size_t j = 0; j < a.col(); ++j) {
            temp.push_back(a.matrix.at(i)[j] * scalar);
        }
    }
    return Matrix{temp, (int) a.row(), (int) a.col()};

}

Matrix zich::operator*(const Matrix &a, const double &scalar) {
    /*iterating each value in the (this)matrix and copy each value to a new matrix
     * while assign each value to be itself multiply the give scalar*/
    std::vector<double> temp;
    for (size_t i = 0; i < a.row(); ++i) {
        for (size_t j = 0; j < a.col(); ++j) {
            temp.push_back(a.matrix.at(i)[j] * scalar);
        }
    }
    return Matrix{temp, (int) a.row(), (int) a.col()};
}

Matrix Matrix::operator-() const {
    /* multiply each value of the matrix by -1 */
    double s = -1;
    return (s * (*this));
}

Matrix Matrix::operator+() const {
    return (*this);
}

/* a measure for more accurate comparing between real numbers */
const float TOLERANCE = 0.001;

/*Boolean Expressions */
bool zich::operator==(const Matrix &a, const Matrix &b) {
    /* check if the operation is valid by comparing the matrices size, if size is not equal throwing error */
    if ((a.col() != b.col()) || a.row() != b.row()) {
        throw std::invalid_argument("Matrices size should be equal!");
    }
    /* iterating each index of the matrices and compare equality of the values using
     * TOLERANCE const for more accurate result (real numbers comparing can have deviation)*/
    for (size_t i = 0; i < a.row(); ++i) {
        for (size_t j = 0; j < a.col(); ++j) {
            if (abs(a.matrix[i][j] - b.matrix[i][j]) > TOLERANCE) {
                return false;
            }
        }

    }
    return true;
}

bool zich::operator!=(const Matrix &a, const Matrix &b) {
    /* checking the opposite of the equal operator ( dealing with exceptions at the equal operator implementation)*/
    return !(a == b);
}

bool zich::operator<(const Matrix &a, const Matrix &b) {
    /* check if the operation is valid by comparing the matrices size, if size is not equal throwing error */
    if ((a.col() != b.col()) || a.row() != b.row()) {
        throw std::invalid_argument("Matrices size should be equal!");
    }
    /* each matrix store the sum of their values, so we can compare for each matrix the sum_value field*/
    return a.sum_value() < b.sum_value();
}

bool zich::operator>(const Matrix &a, const Matrix &b) {
    /* check if the operation is valid by comparing the matrices size, if size is not equal throwing error */
    if ((a.col() != b.col()) || a.row() != b.row()) {
        throw std::invalid_argument("Matrices size should be equal!");
    }
    /* each matrix store the sum of their values, so we can compare for each matrix the sum_value field*/
    return a.sum_value() > b.sum_value();
}

bool zich::operator<=(const Matrix &a, const Matrix &b) {
    /* check if the operation is valid by comparing the matrices size, if size is not equal throwing error */
    if ((a.col() != b.col()) || a.row() != b.row()) {
        throw std::invalid_argument("Matrices size should be equal!");
    }
    /* checking if one of the conditions is met, less than or equal */
    return (a < b) || (a == b);
}

bool zich::operator>=(const Matrix &a, const Matrix &b) {
    /* check if the operation is valid by comparing the matrices size, if size is not equal throwing error */
    if ((a.col() != b.col()) || a.row() != b.row()) {
        throw std::invalid_argument("Matrices size should be equal!");
    }
    /* checking if one of the conditions is met, less than or equal */
    return (a > b) || (a == b);
}

std::ostream &zich::operator<<(std::ostream &os, zich::Matrix &other) {
    /* this method is implementing by iterating each row of the matrix
     * and delimits each row with '[' and the beginning and ']' at the end
     * while assigning all the values inside seperated by single space (' ').
     * return the ostream.*/
    for (size_t r = 0; r < other.row(); ++r) {
        os << '[';
        for (size_t i = 0; i < other.col(); ++i) {
            os << other._matrix()[r][i];
            if (i < other.col() - 1) {
                os << ' ';
            }
        }
        if (r == other.row() - 1) {
            os << "]";
        } else {
            os << "]\n";
        }
    }
    return os;
}


std::istream &zich::operator>>(std::istream &input, Matrix &other) {

    /* in this method we get the whole input as a string and then iterate by every char.
     * the input format is very clear, we have specific rules for every type of char.
     * the rules are :
     * start with '[', and can be ended all values or finish row with ']',
     * after '[' next char is a number, after ']' can be ',' to start new row or end values.
     * after number next char can be '.' to have a decimal fraction number, or ' ' to check other number or ']' to finish row.
     *
     * I used switch case to handle each of the cases, and every number will be pushed to a vector, while counting the rows and columns.
     * ~~ if one of the rules does not match the method will throw exception with error about wrong format.
     *
     * after we finished to read the input and push the number to the vector, we will adjust the (other& matrix)
     * if necessary we will clear the current rows and replace the values and the current size.
     * */

    std::string inputstr;
    getline(input, inputstr);
    size_t row_cout = 0;
    size_t col_count = 1;
    bool final = false;
    const int open = 1;
    const int digit = 2;
    const int close = 3;
    const int space = 4;
    int state = 1;

    std::vector<std::vector<double>> temp_row;
    std::vector<double> temp_col;

    vector<double> temp;
    for (size_t i = 0; i < inputstr.size() - 1 && !final; ++i) {
        switch (state) {
            case open:
                if (inputstr.at(i) != '[') {
                    cout << inputstr.at(i) << endl;
                    string error = "wrong format in open";
                    error.push_back(inputstr.at(i));
                    throw invalid_argument(error);
                }
                state = digit;
                break;

            case close:
                if (inputstr.at(i + 1) != ',') {
                    throw invalid_argument("wrong format in close");
                }
                i++;
                if (inputstr.at(i+1) != ' '){
                    throw invalid_argument("wrong format in close");
                }
                state = space;
                break;
            case space:
                if (isdigit(inputstr.at(i + 1)) != 0 || inputstr.at(i + 1) == '-') {
                    state = digit;
                } else if (inputstr.at(i + 1) != ']') {
                    state = open;
                } else {
                    string error = "wrong format in space ";
                    error.push_back(inputstr.at(i));
                    throw invalid_argument(error);
                };
                break;
            case digit:
                if ((isdigit(inputstr.at(i)) == 0 || i == inputstr.size() - 3) && inputstr.at(i) != '-') {
                    throw invalid_argument("wrong format in digit");
                }
                string s;
                s+= inputstr.at(i);
                if (inputstr.at(i+1) == '.' || isdigit(inputstr.at(i+1)) != 0) {
                    i++;
                    s+= inputstr.at(i);
                    while (isdigit(inputstr.at(i+1)) != 0) {
                        s+= inputstr.at(++i);
                    }
                }
                temp_col.push_back(stod(s));
                if (inputstr.at(i + 1) == ']') {
                    row_cout++;
                    temp_row.push_back(temp_col);
                    if (i + 1 == inputstr.size() - 1) {
                        final = true;
                        break;
                    }
                    temp_col.clear();
                    col_count = 1;
                    state = close;
                } else {
                    col_count++;
                    state = space;
                }
                break;
        }
    }
    other.sum_value() = 0;

    for (size_t i = 0; i < row_cout; ++i) {
        if (i < other.row()) {
            other.matrix.at(i).clear();
        } else {
            other.matrix.push_back(temp_row.at(i));
        }
        for (size_t j = 0; j < col_count; ++j) {
            other.matrix.at(i).push_back(temp_row.at(i).at(j));
            other.sum_value() += temp_row.at(i).at(j);
        }
    }
    other.row() = row_cout;
    other.col() = col_count;
    return input;
}






