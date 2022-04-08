
#ifndef CPP_MATRIX_CALCULATOR_B_MATRIX_HPP
#define CPP_MATRIX_CALCULATOR_B_MATRIX_HPP

namespace zich {
    class Matrix {
    private:
        std::vector<double> matrix;
        int r;
        int c;
    public:
        Matrix(const std::vector<double> &mat, int row, int col );

        /* self-object arithmetic operators */
        Matrix& operator+=(const Matrix &other);
        Matrix& operator-=(const Matrix &other);
        Matrix& operator*=(const Matrix &other);
        Matrix& operator*=(double scalar);

        /* Arithmetic Operators */
        Matrix operator-(const Matrix &other);
        Matrix operator+(const Matrix &other);
        Matrix operator*(const Matrix &other);

        void operator--();
        void operator++();




        /*Boolean Expressions */
        bool operator==(const Matrix &other);
        bool operator!=(const Matrix &other);

        bool operator<=(const Matrix &other);
        bool operator>=(const Matrix &other);

        bool operator<(const Matrix &other);
        bool operator>(const Matrix &other);

        /*end boolean expressions*/


        friend Matrix operator*(double scalar, const Matrix &other);

        friend Matrix operator+(Matrix &matrix);
        friend Matrix operator-(Matrix &matrix);



        /* IO Operators*/
        friend std::ostream& operator<<(std::ostream& ostream, const Matrix& other);
        friend std::ostream& operator>>(std::ostream& ostream, const Matrix& other);



    };
}

#endif //CPP_MATRIX_CALCULATOR_B_MATRIX_HPP
