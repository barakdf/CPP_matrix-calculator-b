#include <iostream>


/** TODO:
 * check about converts for other types to double
 * */


/**
 * (a+=b) --> Matrix& operator+=(const Matrix& other){.... return *this}
 * (a-=b) --> Matrix& operator-=(const Matrix& other){.... return *this}
 * (a*=b) --> Matrix& operator*=(const Matrix& other){.... return *this}
 * (a*=(scalar)) --> Matrix& operator*=(const double& scalar){.... return *this}
 * --prefix--
 * (++a)  --> Matrix& operator++(){.... return *this}
 * (--a)  --> Matrix& operator--(){.... return *this}
 * --prefix--
 * */

/** Arithmetic operations between matrices with new object return:
 * (a+b) -->friend Matrix operator+(const Matrix& a, const Matrix& b) {.... return ~new matrix~}
 * (a-b) -->friend Matrix operator-(const Matrix& a, const Matrix& b) {.... return ~new matrix~}
 * (a*b) -->friend Matrix operator*(const Matrix& a, const Matrix& b) {.... return ~new matrix~}
 * ((scalar)*a) --> friend Matrix operator*(double (scalar),const Matrix& a) {.... return ~new matrix~}
 *
 * --postfix--
 * (a++)  --> Matrix operator++(int dummy){.... return copy_mat}
 * (a--)  --> Matrix operator--(int dummy){.... return copy_mat}
 *--postfix--
 *
 * (-a) --> Matrix operator-() const{} --> a.operator-()
 * (+a) --> Matrix operator+() const{} --> a.operator+()
 *
 * */

/** Boolean expressions between matrices:
 * (a==b) --> friend bool operator==(const Matrix& other) {.... return ~true/false~}
 * (a<=b) --> friend bool operator<=(const Matrix& other) {.... return ~true/false~}
 * (a>=b) --> friend bool operator>=(const Matrix& other) {.... return ~true/false~}
 * (a<b)  --> friend bool operator< (const Matrix& other) {.... return ~true/false~}
 * (a>b)  --> friend bool operator> (const Matrix& other) {.... return ~true/false~}
 * */

/** IOstream
 * friend std::ostream& operator<<(std::ostream& os, const Matrix& other){... return os}
 * friend std::istream& operator>>(std::istream& input, Matrix& other){... return input}
 *
 * Test Methods:
 * 'ostringstream' for output --> || ostringstream soutput << a ||--> assert(soutput.str() == "~expected string")
 * 'istringstream' for input --> || istringstream sinput("~string input~") >> a ||
 *
 * */


int test(std::string &str) {
    str = "DAMN";
    return 2;
}


int main() {
    int a = 5;
    std::string t = "hello";
    std::cout << a << std::endl;
    std::cout << test(t) << std::endl;
    std::cout << t << std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}