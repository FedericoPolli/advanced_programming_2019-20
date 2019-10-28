#include <iostream>

int main() {
  int n;
  std::cout << "Insert number" << '\n';
  std::cin >> n;
  std::cout << 2 << '\n';
  for (std::size_t k{3}; k < n+1; ++k)
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
      std::cout << k << '\n';
    }

}
