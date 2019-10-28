#include <iostream>

int main() {
  int primes[50];
  primes[0] = 2;
  std::size_t i{1}; 
  for (std::size_t k{3}; k < 101; ++k)
    {
    int c{0};
    for (std::size_t j{2}; j <= k/2; ++j)
      {
	if (k%j == 0)  {
	++c;
        break;
	}
      }
    if (c==0)
      {
      primes[i] = k;
      ++i;
      }
    }
  for (std::size_t l{0}; l < i; ++l)
    std::cout << primes[l] << '\n';

}
