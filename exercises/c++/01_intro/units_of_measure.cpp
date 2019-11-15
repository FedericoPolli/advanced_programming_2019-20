#include <iostream>
#include <string>
#include <algorithm>

int main () {
  enum constants {inchtometre=0.0254}
  std::cout << "Enter the number with its unit of measure" << std::endl;
  std::string line="";
  std::getline(std::cin, line);
  std::string value(line.cbegin(), std::find(line.cbegin(), line.cend(), ' '));
  std::string unit(std::find(line.cbegin(), line.cend(), ' ')+1, line.cend());
  switch(unit) {
  case 'inch':
    std::cout << std::stof(value)*inchtometre << " m" << std::endl;

  default:
    std::cout << "Unknown unit of measure" << std::endl;





}
