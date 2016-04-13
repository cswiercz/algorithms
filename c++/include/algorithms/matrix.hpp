#ifndef __algorithms_matrix_hpp
#define __algorithms_matrix_hpp

#include <cstddef>
#include <iostream>
#include <tuple>
#include <vector>

template <class T>
class Matrix
{
public:
  Matrix(const size_t &M, const size_t &N);
  Matrix(const size_t &M, const size_t &N, T &data);

  std::tuple<size_t,size_t> shape() const;

  /**
   * Read access to the i,j element
   *
   * For T small returning a copy of T can have better performance because the
   * returned value can live in the stack of the calling function as opposed to
   * having to navigate some pointer/referencing path.
   *
   * Additionally, the fact that this method is `const` makes it so that any
   * const Matrix& references to this object call this particular method, not
   * the return by reference one, below.
   *
   * However, we expect T to be a large object (which we don't with matrices) we
   * wouldn't want to return a copy.
   */
  T operator()(const size_t i, const size_t j) const;

  /**
   * Read and write access to the i,j element
   *
   * We return by reference so the calling function can modify the data.
   */
  T& operator()(const size_t i, const size_t j);


  /**
   * Read access to the k'th element of the underlying data vector.
   *
   * See operator() for explanation of return types.
   */
  T operator[](size_t index) const;

  /**
   * Read and write access to the k'th element of the underlying data vector.
   */
  T& operator[](size_t index);

private:
  size_t nrows_;
  size_t ncols_;
  size_t size_;
  std::vector<T> data_;
};


/* ---------------------------- Matrix Functions ---------------------------- */
template <class T>
Matrix<T>::Matrix(const size_t &M, const size_t &N)
  :
  nrows_(M),
  ncols_(N)
{
  size_ = nrows_ * ncols_;
  data_.reserve(size_);
}

template <class T>
std::tuple<size_t,size_t> Matrix<T>::shape() const
{
  return std::make_tuple(nrows_, ncols_);
}

template <class T>
std::ostream& operator<<(std::ostream& out, const Matrix<T>& A)
{
  size_t M,N;
  size_t size;
  std::tie(M,N) = A.shape();
  size = M*N;

  for (size_t k=0; k<size; ++k)
    {
      out << A[k] << "\t";
      if ((k % N) == (N-1))
        out << std::endl;
    }
  return out;
}


template <class T>
T Matrix<T>::operator()(const size_t i, const size_t j) const
{
  return data_[i*ncols_ + j];
}

template <class T>
T& Matrix<T>::operator()(const size_t i, const size_t j)
{
  return data_[i*ncols_ + j];
}


template <class T>
T Matrix<T>::operator[](size_t index) const
{
  return data_[index];
}

template <class T>
T& Matrix<T>::operator[](size_t index)
{
  return data_[index];
}


/* ---------------------------- Helper Functions ---------------------------- */
template <class T>
Matrix<T> zero_matrix(const size_t &M, const size_t &N)
{
  Matrix<T> matrix(M,N);
  for (size_t i=0; i<M*N; ++i)
    matrix[i] = 0;
  return matrix;
}

template <class T>
Matrix<T> identity_matrix(const size_t &M)
{
  Matrix<T> matrix(M,M);
  for (size_t i=0; i<M; ++i)
    for (size_t j=0; j<M; ++j)
      if (i == j)
        matrix(i,j) = 1;
      else
        matrix(i,j) = 0;
  return matrix;
}


#endif
