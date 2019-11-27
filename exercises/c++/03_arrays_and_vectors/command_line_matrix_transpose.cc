#include <utility>
#include <iostream>
#include <array>
#include <sstream>
#include <random>

void transpose(std::array<double, 10>& matrix, int rows, int columns);

int main(int argc, char* argv[]) {
  std::uniform_real_distribution<double> unif(0, 100);
  std::default_random_engine re;
  std::size_t rows{2}, columns{5};
  
  //  std::cout << "Enter the number of rows and of columns of the matrix \n";
  //  std::istringstream is1{argv[1]};
  //  is1 >> rows;
  // std::istringstream is2{argv[2]};
  //is2 >> columns;
  
  //unsigned long long N=rows*columns;
  std::array<double, 10> matrix;
  for (auto i=0u; i<matrix.size(); ++i)
    matrix[i]=unif(re);
  
  std::cout << "Before transposing \n";
  for (auto x:matrix)
    std::cout << x << " ";
  
  transpose(matrix, rows, columns);
  
  std::cout << "\nAfter transposing \n";
  for (auto x:matrix)
    std::cout << x << " ";
}

void transpose(std::array<double, 10>& matrix, int rows, int columns)
{
  std::array<double, 10> new_matrix;
  for (auto i=0; i<rows; ++i)
    {
      for (auto j=0; j<columns; ++j)
        new_matrix[j*rows+i]=matrix[i*columns+j];
    }
  matrix=new_matrix;
}
