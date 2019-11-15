#include <iostream>
#include <string>
#include <algorithm>

int main () {
  const double inchestometres=0.0254;
  std::cout << "Accepted units of measure: inches, metres" << std::endl; 
  while (true) {
    std::cout << "Enter the number with its unit of measure" << std::endl;
    std::string line="";
    std::getline(std::cin, line);
    std::string value(line.cbegin(), std::find(line.cbegin(), line.cend(), ' '));
    std::string unit(std::find(line.cbegin(), line.cend(), ' ')+1, line.cend());
    if (unit=="inches")
      {
      std::cout << std::stof(value)*inchestometres << " metres" << std::endl;
      break;
	}
    if (unit=="metres"){
      std::cout << std::stof(value) << " metres" << std::endl;
      break;
	}
    else
      std::cout << "Unknown unit of measure" << std::endl;

  }

}
