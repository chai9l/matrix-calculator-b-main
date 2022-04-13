#include <iostream>
#include <stdexcept>
#include "Matrix.hpp"

using namespace zich;
using namespace std;

// ---------------- Constructors ------------- //
Matrix::Matrix() {}

Matrix::Matrix(int rows, int cols)
{
    this->mat.resize((u_int)rows, vector<double>((u_int)cols));
}

Matrix::Matrix(const vector<double> &vec, int rows, int cols)
{
    if (vec.size() != rows * cols)
    {
        throw invalid_argument("");
    }
    if (rows <= 0 or cols <= 0)
    {
        throw invalid_argument("Row or Col cannot be zero or negative");
    }
    this->mat.resize((u_int)rows, vector<double>((u_int)cols));
    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < cols; j++)
        {
            mat[i][j] = vec[i * (u_int)cols + j];
        }
    }
}

////////////// ---------------- Operators ------------- ///////////////

/// -------------------- Plus ------------------ ///
Matrix Matrix::operator+()
{
    Matrix Ret;
    Ret.mat.resize(this->mat.size());
    for (u_int i = 0; i < mat.size(); i++)
    {
        for (u_int j = 0; j < mat[0].size(); j++)
        {
            Ret.mat[i].push_back(this->mat[i][j]);
        }
    }
    return Ret;
}

Matrix Matrix::operator+(const Matrix &other)
{
    if ((this->mat.size() != other.mat.size()) || (this->mat[0].size() != other.mat[0].size()))
    {
        throw logic_error("Matrices of different size cannot be summed");
    }
    Matrix Res;
    Res.mat.resize(this->mat.size());
    for (u_int i = 0; i < this->mat.size(); i++)
    {
        for (u_int j = 0; j < this->mat[0].size(); j++)
        {
            int val = this->mat[i][j] + other.mat[i][j];
            Res.mat[i].push_back(val);
        }
    }
    return Res;
}

Matrix Matrix::operator+=(const Matrix &other)
{
    return *this = *this + other;
}

/// -------------------- Minus ------------------ ///
Matrix Matrix::operator-()
{
    Matrix Ret;
    Ret.mat.resize(this->mat.size());
    for (u_int i = 0; i < mat.size(); i++)
    {
        for (u_int j = 0; j < mat[0].size(); j++)
        {
            int val = this->mat[i][j] * (-1);
            Ret.mat[i].push_back(val);
        }
    }
    return Ret;
}

Matrix Matrix::operator-(const Matrix &other)
{
    if ((this->mat.size() != other.mat.size()) || (this->mat[0].size() != other.mat[0].size()))
    {
        throw logic_error("Matrices of different size cannot be differenced");
    }
    Matrix Res;
    Res.mat.resize(this->mat.size());
    for (u_int i = 0; i < this->mat.size(); i++)
    {
        for (u_int j = 0; j < this->mat[0].size(); j++)
        {
            int val = this->mat[i][j] - other.mat[i][j];
            Res.mat[i].push_back(val);
        }
    }
    return Res;
}

Matrix Matrix::operator-=(const Matrix &other)
{
    return *this = *this - other;
}

/// -------------------- Multiplication ------------------ ///
Matrix Matrix::operator*(const Matrix &other)
{
    if (this->mat[0].size() != other.mat.size())
    {
        throw logic_error("Matrices of different size cannot be multiplied");
    }
    Matrix Res;
    Res.mat.resize(this->mat.size(), vector<double>(other.mat[0].size()));
    for (u_int i = 0; i < Res.mat.size(); i++)
    {
        for (u_int j = 0; j < other.mat[0].size(); j++)
        {
            for (u_int k = 0; k < other.mat.size(); k++)
            {
                Res.mat[i][j] += this->mat[i][k] * other.mat[k][j];
            }
        }
    }
    return Res;
}

Matrix Matrix::operator*=(const Matrix &other)
{
    return *this = *this * other;
}

Matrix Matrix::operator*=(const double num)
{
    for (u_int i = 0; i < this->mat.size(); i++)
    {
        for (u_int j = 0; j < this->mat[0].size(); j++)
        {
            this->mat[i][j] *= num;
        }
    }
    return *this;
}

/// -------------------- Increment and Decrement ------------------ ///
Matrix &Matrix::operator++()
{
    for (u_int i = 0; i < this->mat.size(); i++)
    {
        for (u_int j = 0; j < this->mat[0].size(); j++)
        {
            this->mat[i][j]++;
        }
    }
    return *this;
}

Matrix &Matrix::operator--()
{
    for (u_int i = 0; i < this->mat.size(); i++)
    {
        for (u_int j = 0; j < this->mat[0].size(); j++)
        {
            this->mat[i][j]--;
        }
    }
    return *this;
}

Matrix Matrix::operator++(int)
{
    Matrix temp = *this;
    ++*this;
    return temp;
}

Matrix Matrix::operator--(int)
{
    Matrix temp = *this;
    --*this;
    return temp;
}

/// -------------------- Boolean ------------------ ///
bool Matrix::operator>(const Matrix &other)const
{
    if ((this->mat.size() != other.mat.size()) || (this->mat[0].size() != other.mat[0].size()))
    {
        throw logic_error("Matrices of different size cannot be compared");
    }
    int sum1 = 0;
    for (u_int i = 0; i < this->mat.size(); i++)
    {
        for (u_int j = 0; j < this->mat[0].size(); j++)
        {
            sum1 += this->mat[i][j];
        }
    }
    int sum2 = 0;
    for (u_int i = 0; i < other.mat.size(); i++)
    {
        for (u_int j = 0; j < other.mat[0].size(); j++)
        {
            sum2 += other.mat[i][j];
        }
    }
    return sum1 > sum2;
}

bool Matrix::operator>=(const Matrix &other)const
{
    return !(*this < other);
}

bool Matrix::operator<(const Matrix &other)const
{
    if ((this->mat.size() != other.mat.size()) || (this->mat[0].size() != other.mat[0].size()))
    {
        throw logic_error("Matrices of different size cannot be compared");
    }
    int sum1 = 0;
    for (u_int i = 0; i < this->mat.size(); i++)
    {
        for (u_int j = 0; j < this->mat[0].size(); j++)
        {
            sum1 += this->mat[i][j];
        }
    }
    int sum2 = 0;
    for (u_int i = 0; i < other.mat.size(); i++)
    {
        for (u_int j = 0; j < other.mat[0].size(); j++)
        {
            sum2 += other.mat[i][j];
        }
    }
    return sum1 < sum2;
}

bool Matrix::operator<=(const Matrix &other)const
{
    return !(*this > other);
}

bool Matrix::operator==(const Matrix &other)
{
    if ((this->mat.size() != other.mat.size()) || (this->mat[0].size() != other.mat[0].size()))
    {
        throw logic_error("Matrices of different size cannot be compared");
    }
    for (u_int i = 0; i < this->mat.size(); i++)
    {
        for (u_int j = 0; j < this->mat[0].size(); j++)
        {
            if (this->mat[i][j] != other.mat[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

bool Matrix::operator!=(const Matrix &other)
{
    return !(*this == other);
}

// --------------------------------------------------------------------

namespace zich
{
    Matrix operator*(const double num, const Matrix &other)
    {
        Matrix Res = Matrix(other.mat.size(), other.mat[0].size());
        for (u_int i = 0; i < other.mat.size(); i++)
        {
            for (u_int j = 0; j < other.mat[0].size(); j++)
            {
                Res.mat[i][j] = other.mat[i][j] * num;
            }
        }
        return Res;
    }

    Matrix operator*(const Matrix &other, const double num)
    {
        return num * other;
    }

    std::ostream &operator<<(std::ostream &os, const Matrix &M)
    {
        for (u_int i = 0; i < M.mat.size(); i++)
        {
            os << '[';
            for (u_int j = 0; j < M.mat[0].size(); j++)
            {
                if ((int)M.mat[i][j] == M.mat[i][j])
                {

                    os << (int)M.mat[i][j];
                }
                else
                {
                    os << M.mat[i][j];
                }
                if (j != M.mat[0].size() - 1)
                {
                    os << " ";
                }
            }
            os << ']';
            if (i != M.mat.size() - 1)
            {
                os << '\n';
            }
        }
        return os;
    }
    vector<string> split(string const &str, string const &to_split)
    {
        vector<string> tokens;
        size_t begin = 0;
        size_t end = 0;
        while ((begin = str.find_first_not_of(to_split, end)) != string::npos)
        {
            end = str.find(to_split, begin);
            tokens.push_back(str.substr(begin, end - begin));
        }
        return tokens;
    }

    std::istream &operator>>(std::istream &is, const Matrix &M)
    {
        string input;
        getline(is, input);
        vector<string> mat_vec = split(input, ", ");
        if (input[0] != '[') {
            throw invalid_argument("Rows always start with '[' ");
        }
        for(string row : mat_vec ) {
            if (row[0] != '[') {
                throw invalid_argument("Rows always start with '[' ");
            }
            size_t begin = 1;
            size_t len = row.length() - 1;
            while (begin < len) {
                if ( (row[begin] < 48 and row[begin] != ' ') or row[begin] > 56) {
                    throw invalid_argument("Invalid character found, matrix cannot contain characters other than 0-9 or space");
                }
                if ( row[begin] == ' ' and row[begin - 1] == ' ') {
                    throw invalid_argument("Two consecutive spaces found, number must have 1 space between them");
                }
                begin++;
            }
        }
        return is;
    }

    bool operator==(const Matrix &mat1, const Matrix &mat2)
    {
        if ((mat1.mat.size() != mat2.mat.size()) || (mat1.mat[0].size() != mat2.mat[0].size()))
        {
            throw logic_error("Matrices of different size cannot be compared");
        }
        for (u_int i = 0; i < mat1.mat.size(); i++)
        {
            for (u_int j = 0; j < mat1.mat[0].size(); j++)
            {
                if (mat1.mat[i][j] != mat2.mat[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }
}