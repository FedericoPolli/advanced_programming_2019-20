#include <iostream>

void get_int();

void get_double();

int main()
{
  get_int();
  get_double();
}

void get_int()
{
  int i=0;
    std::cout << "Digita un numero intero \n";
    std::cin >> i;
    while (!std::cin)
    {
      std::cin.clear();
      std::cin.ignore();
      std::cout << "Il numero digitato non è un intero, digitarne un altro \n";
      std::cin >> i;
    }
}     

void get_double()
{
  double i=0;
    std::cout << "Digita un numero reale \n";
    std::cin >> i;
    while (!std::cin)
    {
      std::cin.clear();
      std::cin.ignore();
      std::cout << "Il numero digitato non è un numero reale, digitarne un altro \n";
      std::cin >> i;
    }
}    
