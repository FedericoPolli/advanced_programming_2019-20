#include <iostream>
#include <string>

int main()
{
  std::string previous{" "};
  std::string line;
  while(std::getline(std::cin,line))
    {
      if (previous != line)
	{
	  previous=line;
	  std::cout << line << '\n';
        }
    }
      


}
