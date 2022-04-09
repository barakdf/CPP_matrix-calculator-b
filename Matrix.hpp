#include <iostream>
#include <vector>
#ifndef CPP_MATRIX_CALCULATOR_B_MATRIX_HPP
#define CPP_MATRIX_CALCULATOR_B_MATRIX_HPP

namespace zich {
    class Matrix {
    private:
        size_t r;
        size_t c;
        double sum_val = 0;
        std::vector<std::vector<double>> matrix;
        std::string str;
    public:
        /* constructor */
        Matrix(const std::vector<double> &mat, int row, int col);

        /* destructor */
        /* getters */
        size_t row() const {return r;};
        size_t col() const {return c;};
        double sum_value() const {return sum_val;};

        /* setters */
        size_t & row(){ return this->r;};
        size_t & col(){ return this->c;};
        double& sum_value(){ return this->sum_val;};



        /* self-object arithmetic operators */
        Matrix& operator+=(const Matrix &other);
        Matrix& operator-=(const Matrix &other);
        Matrix& operator*=(const Matrix &other);
        Matrix& operator*=(const double& scalar);

        /* Prefix */
        Matrix& operator--();
        Matrix& operator++();

        /* Postfix */
        Matrix operator--(int flag);
        Matrix operator++(int flag);

        /* Arithmetic Operators */
        friend Matrix operator+(const Matrix &a, const Matrix &b);
        friend Matrix operator-(const Matrix &a, const Matrix &b);
        friend Matrix operator*(const Matrix &a, const Matrix &b);
        friend Matrix operator*(const double &scalar, const Matrix &a);
        friend Matrix operator*(const Matrix &a, const double &scalar);


        Matrix operator-() const;
        Matrix operator+() const;


        /*Boolean Expressions */
        friend bool operator==(const Matrix &a, const Matrix &b);
        friend bool operator!=(const Matrix &a, const Matrix &b);
        friend bool operator<=(const Matrix &a, const Matrix &b);
        friend bool operator>=(const Matrix &a, const Matrix &b);
        friend bool operator< (const Matrix &a, const Matrix &b);
        friend bool operator> (const Matrix &a, const Matrix &b);

        /*end boolean expressions*/


        /* IO Operators*/
        friend std::ostream& operator<<(std::ostream& os, Matrix& other);
        friend std::istream& operator>>(std::istream& input, Matrix& other);



    };
};

#endif //CPP_MATRIX_CALCULATOR_B_MATRIX_HPP
