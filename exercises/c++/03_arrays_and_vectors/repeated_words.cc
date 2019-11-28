#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

int main() {
  std::cout << "Enter your words, they will be printed back without repetitions \n";
  std::string input{""};
  std::vector<std::string> words;
  getline(std::cin, input);
  std::istringstream iss(input);
  std::string s;
  while (getline(iss, s, ' '))
    words.push_back(s);
  std::sort(words.begin(), words.end());
  std::cout << words[0];
  for (auto i=1; i<words.size(); ++i)
    if (words[i] != words[i-1])
      std::cout << " " << words[i];
  std::cout << std::endl;
}
