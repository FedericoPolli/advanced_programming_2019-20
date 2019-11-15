#include <iostream>
#include <sstream>
#include <string>

int get_int();

double get_double();

int main()
{
  int a;
  double b;
  a=get_int();
  b=get_double();
  std::cout << "You entered the integer: " << a << std::endl;
  std::cout << "You entered the double: " << b << std::endl;
}

int get_int()
{
  int i=0;
  std::cout << "Enter an integer number \n";
  for(std::string line; std::getline(std::cin, line);)
    {
        if((std::istringstream(line) >> i >> std::ws).eof())
            break;
	
        std::cout << "Not an integer please try again: " << std::flush;
    }
  return i;
}     

double get_double()
{
  double i=0;
  std::cout << "Enter a real number \n";
  for(std::string line; std::getline(std::cin, line);)
    {
        if((std::istringstream(line) >> i >> std::ws).eof())
            break;
	
        std::cout << "Not a real number please try again: " << std::flush;
    }
  return i;
}    
