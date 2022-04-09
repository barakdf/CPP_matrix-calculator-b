#include <iostream>
#include <vector>
#ifndef CPP_MATRIX_CALCULATOR_B_MATRIX_HPP
#define CPP_MATRIX_CALCULATOR_B_MATRIX_HPP

namespace zich {
    class Matrix {
    private:
        std::vector<std::vector<double>> matrix;
        int r;
        int c;
    public:
        /* constructor */
        Matrix(const std::vector<double> &mat, int row, int col );

        /* destructor */
        ~Matrix();

        /* getters */
        int row() const {return r;};
        int col() const {return c;};

        /* setters */
        int& row(){ return this->r;};
        int& col(){ return this->c;};



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
        friend std::ostream& operator<<(std::ostream& os, const Matrix& other);
        friend std::istream& operator>>(std::istream& input, Matrix& other);



    };
}

#endif //CPP_MATRIX_CALCULATOR_B_MATRIX_HPP
