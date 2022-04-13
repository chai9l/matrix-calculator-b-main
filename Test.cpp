#include "doctest.h"
#include "Matrix.hpp"
#include <iostream>

using namespace zich;

TEST_CASE("Good Input")
{
    std::vector<double> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    Matrix mat1{vec1, 3, 3};
    std::vector<double> vec2 = {3, 0, 0, 0, 3, 0, 0, 0, 3};
    Matrix mat2{vec2, 3, 3};
    std::vector<double> vec_sum = {4, 0, 0, 0, 4, 0, 0, 0, 4};
    Matrix mat_sum{vec_sum, 3, 3};

    std::vector<double> vec_diff = {-2, 0, 0, 0, -2, 0, 0, 0, -2};
    Matrix mat_diff{vec_diff, 3, 3};

    std::vector<double> vec_diff2 = {2, 0, 0, 0, 2, 0, 0, 0, 2};
    Matrix mat_diff2{vec_diff2, 3, 3};

    std::vector<double> vec_mult = {6, 0, 0, 0, 6, 0, 0, 0, 6};
    Matrix mat_mult{vec_mult, 3, 3};

    std::vector<double> zero_vec = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    Matrix zero_mat{zero_vec, 3, 3};

    std::vector<double> one_vec = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    Matrix one_mat{one_vec, 3, 3};

    Matrix b = mat1;
    Matrix c = mat1 + mat2;
    Matrix d = mat1 - mat2;
    Matrix e = mat2 - mat1;
    Matrix f = mat2 * mat_diff2;

    Matrix g = mat2 * zero_mat;
    Matrix h = zero_mat;
    ++h;
    Matrix i = one_mat;

    CHECK( (c == mat_sum) == true);
    CHECK( (d == mat_diff) == true);
    d*=-1;
    CHECK( (d == e) == true);
    d*=0;
    CHECK( (d == zero_mat) == true);
    CHECK( (e == mat_diff2) == true);
    CHECK( (f == mat_mult) == true); 
    CHECK( (g == zero_mat) == true);
    CHECK( (h == one_mat) == true);
    CHECK( (zero_mat <= one_mat) == true);
    CHECK( (g >= zero_mat) == true);
    CHECK( (one_mat >= zero_mat) == true);
    CHECK( (h >= one_mat) == true);
    CHECK( (zero_mat > h) == false);
    CHECK( (mat1 < h) == true);
    zero_mat += one_mat;
    CHECK( (i == zero_mat) == true);
    zero_mat -= one_mat;
    CHECK( (i != zero_mat) == true);
    zero_mat++;
    CHECK( (one_mat == zero_mat) == true);
    zero_mat--;
    CHECK( (d == zero_mat) == true);
    b *= 4;
    CHECK( (b == mat_sum) == true);

}

TEST_CASE("Bad Input")
{
    std::vector<double> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    Matrix mat1{vec1, 3, 3};
    std::vector<double> vec2 = {3, 0, 0, 3};
    Matrix mat2{vec2, 2, 2};
    // Bad Sizes
    CHECK_THROWS(Matrix *t = new Matrix(vec1, -3, -3));
    CHECK_THROWS(Matrix *t = new Matrix(vec1, 0, 2));
    CHECK_THROWS(Matrix *t = new Matrix(vec1, 3, 0));
    CHECK_THROWS(mat1 + mat2);
    CHECK_THROWS(mat1 - mat2);
    CHECK_THROWS(mat1 * mat2);

}