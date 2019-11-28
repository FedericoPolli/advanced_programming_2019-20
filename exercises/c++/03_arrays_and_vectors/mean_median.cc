#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>
#include <algorithm>

int main() {
  std::vector<double> temperatures;
  std::ifstream myfile("Temperatures.txt");
  std::string line;
  
  while (getline (myfile, line)){
    double data;
    std::stringstream linestream{line};
    linestream >> data;
    temperatures.push_back(data);
  }
  myfile.close();
  
  double mean{0}, median{0};
  for (auto x:temperatures)
    mean+=x;
  mean/=temperatures.size();

  std::sort(temperatures.begin(), temperatures.end());
  if (temperatures.size() % 2 == 1)
    median=temperatures[(temperatures.size()-1)/2];
  else
    median=(temperatures[temperatures.size()/2-1]+temperatures[temperatures.size()/2])/2;
  std::cout << mean << " " << median << "\n";
}
