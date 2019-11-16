#include <iostream>

template <typename T>
T* heap_allocation(std::size_t N) {
  T* array{new T[N]};
  for (std::size_t i=0; i<N; ++i) {
    std::cout << "Enter the " << i+1 << "th element of the array: ";
    std::cin >> array[i];
    std::cout << std::endl;
  }
  return array;
}

template <typename T>
T* reverse_order(T* pointer, std::size_t N){
  T* reversed_array{new T[N]};
  for (std::size_t i=0; i<N; ++i)
    reversed_array[i]=*(pointer+N-1-i);
  return reversed_array;
}

int main() {
  std::cout << "Enter the length of the array: ";
  std::size_t N;
  std::cin >> N;
  std::cout << std::endl;
  int* p1=heap_allocation<int>(N);
  int* p2=reverse_order<int>(p1, N);
  std::cout << "This is the reversed array: ";
  for (std::size_t i=0; i<N; ++i)
    std::cout << *(p2+i) << " ";
  delete[] p1;
  delete[] p2;
}
