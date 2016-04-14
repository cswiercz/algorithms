#include "algorithms/matrix.hpp"

#include <cassert>
#include <iostream>
#include <tuple>

int main(int argc, char** argv)
{
  std::cout << "===----- Matrices -----===" << std::endl;

  std::cout << "A = " << std::endl;
  Matrix<int> A(2,2);
  std::cout << A;

  std::cout << "B = " << std::endl;
  auto B = identity_matrix<int>(4);
  std::cout << B;

  std::cout << "Z = " << std::endl;
  auto Z = zero_matrix<int>(4,8);
  std::cout << Z;

  // -------------------- test shape
  size_t M,N;
  std::tie(M,N) = A.shape();
  assert(M == 2);
  assert(N == 2);

  std::tie(M,N) = B.shape();
  assert(M == 4);
  assert(N == 4);

  std::tie(M,N) = Z.shape();
  assert(M == 4);
  assert(N == 8);

  // -------------------- test element access
  int v1;
  int& r1 = Z(0,0);
  assert(B(0,0) == 1);
  assert(B(0,1) == 0);
  assert(Z(0,0) == 0);

  v1 = Z(0,0);
  v1 = -42;
  assert(Z(0,0) == 0);

  r1 = -42;
  assert(Z(0,0) == -42);
  r1 = 0;

  // -------------------- test references
  std::cout << "...testing references" << std::endl;
  Matrix<int>& R = B;
  R(0,1) = 1;

  // -------------------- test equality
  std::cout << "...testing equality" << std::endl;
  Matrix<int> C = zero_matrix<int>(2,2);
  Matrix<int> D(2,2);

  C(0,0) = 1; D(0,0) = 1;
  C(0,1) = 2; D(0,1) = 2;
  C(1,0) = 3; D(1,0) = 3;
  C(1,1) = 4; D(1,1) = 4;
  assert(C == D);

  D(0,0) = 0;
  assert(C != D);
  assert(C != Z);

  std::cout << "===-----   Done   -----===" << std::endl;
}
