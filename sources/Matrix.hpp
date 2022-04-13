#include "vector"
#include <iostream>

namespace zich
{
    class Matrix
    {
    private:
        std::vector<std::vector<double>> mat;
        
    public:

        // constructors
        Matrix();
        Matrix(int rows, int cols);
        Matrix(const std::vector<double> &vec, int rows, int cols);

        Matrix operator+(const Matrix &other); // c = a+b
        Matrix operator+();                    // unary
        Matrix operator+=(const Matrix &other);  // a = a+b

        Matrix operator-(const Matrix &other); // c = a-b
        Matrix operator-();                    // unary
        Matrix operator-=(const Matrix &other);  // a = a-b

        Matrix operator*(const Matrix &other);                        // c = a*b
        friend Matrix operator*(const double num, const Matrix &other);
        friend Matrix operator*( const Matrix &other, const double num); // b = num*a
        Matrix operator*=(const Matrix &other);                         // a = a*b
        Matrix operator*=(const double num);                            // a = a*num

        Matrix& operator++();
        Matrix& operator--();
        Matrix operator++(int);
        Matrix operator--(int);

        bool operator>(const Matrix &other)const;
        bool operator>=(const Matrix &other)const;
        bool operator<(const Matrix &other)const;
        bool operator<=(const Matrix &other)const;
        bool operator==(const Matrix &other);
        bool operator!=(const Matrix &other);

        friend bool operator==(const Matrix&mat1 ,const Matrix&mat2);
        friend std::ostream &operator<<(std::ostream &os, const Matrix &M); // cout
        friend std::istream &operator>>(std::istream &is, const Matrix &M); // cin
    };
}