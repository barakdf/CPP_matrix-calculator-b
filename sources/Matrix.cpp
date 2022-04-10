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
            this->matrix.at(i).at(j) += 1;
        }
    }
    return *this;
}

/* Postfix */
const Matrix Matrix::operator--(int dummy_flag_for_postfix_increment) {
    Matrix copy = *this;
    --(*this);
    return copy;
}

const Matrix Matrix::operator++(int dummy_flag_for_postfix_increment) {
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
    if ((a.col() != b.col()) || a.row() != b.row()) {
        throw std::invalid_argument("Matrices size should be equal!");
    }
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
    if ((a.col() != b.col()) || a.row() != b.row()) {
        throw std::invalid_argument("Matrices size should be equal!");
    }

    return a.sum_value() < b.sum_value();
}

bool zich::operator>(const Matrix &a, const Matrix &b) {
    if ((a.col() != b.col()) || a.row() != b.row()) {
        throw std::invalid_argument("Matrices size should be equal!");
    }
    return a.sum_value() > b.sum_value();
}

bool zich::operator<=(const Matrix &a, const Matrix &b) {
    if ((a.col() != b.col()) || a.row() != b.row()) {
        throw std::invalid_argument("Matrices size should be equal!");
    }
    return (a < b) || (a == b);
}

bool zich::operator>=(const Matrix &a, const Matrix &b) {
    if ((a.col() != b.col()) || a.row() != b.row()) {
        throw std::invalid_argument("Matrices size should be equal!");
    }
    return (a > b) || (a == b);
}

std::ostream &zich::operator<<(std::ostream &os, zich::Matrix &other) {
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

static istream &getAndCheckNextCharIs(istream &input, char expectedChar) {
    char actualChar;
    input >> actualChar;
    if (!input) { return input; }

    if (actualChar != expectedChar) {
        // failbit is for format error
        input.setstate(ios::failbit);
    }
    return input;
}


std::istream &zich::operator>>(std::istream &input, Matrix &other) {

    std::string inputstr;
    getline(input, inputstr);
    size_t row_cout = 0;
    size_t col_count = 0;
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
                    string error = "wrong format in open the value is ";
                    error.push_back(inputstr.at(i));
                    error.append("and the i is ");
                    cout << "HERE" << i << endl;
                    throw invalid_argument(error);
                }
                state = digit;
                break;

            case close:
                if (inputstr.at(i + 1) != ',') {
                    throw invalid_argument("wrong format in close");
                }
                i++;
                state = space;
                break;
            case space:
                if (isdigit(inputstr.at(i + 1))) {
                    state = digit;
                } else if (inputstr.at(i + 1) != ']') {
                    state = open;
                } else {
                    cout << "HERE " << i << endl;

                    string error = "wrong format in space ";
                    error.push_back(inputstr.at(i));
                    throw invalid_argument(error);
                };
                break;
            case digit:
                if (!isdigit(inputstr.at(i)) || i == inputstr.size() - 1) {
                    throw invalid_argument("wrong format in digit");
                }
                string s;
                s+= inputstr.at(i);
                temp_col.push_back(stod(s));
                if (inputstr.at(i + 1) == ']') {
                    row_cout++;
                    temp_row.push_back(temp_col);
                    if (i + 1 == inputstr.size() - 1) {
                        final = true;
                        break;
                    }
                    temp_col.clear();
                    col_count = 0;
                    state = close;
                } else {
                    col_count++;
                    state = space;
                }
                break;
        }
//        if (inputstr.at(i) == '[') {
//              row_cout++;
//        }
//        else if (isdigit(inputstr.at(i))) {
//            temp.push_back((double )inputstr.at(i));
//        } else if (inputstr.at(i) == ']') {
//            if (inputstr.at(i+1) != ',') {
//                break;
//            }
//
//        }
//        else if (inputstr.at(i+1) != ' ') {
//            if (inputstr.at(i+1) != ']') {
//                throw invalid_argument("wrong format");
//            }
//            col_count++;
//        }
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






