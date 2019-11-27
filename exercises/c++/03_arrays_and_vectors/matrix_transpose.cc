#include <utility>
#include <iostream>
#include <array>

void transpose(std::array<double, 10>& matrix, int rows, int columns);

int main() {
  std::array<double, 10> matrix{1,2,3,4,5,6,7,8,9,0};
  int rows{2};
  int columns{5};
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
