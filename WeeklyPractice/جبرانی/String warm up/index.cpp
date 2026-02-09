#include <iostream>
#include <string>
#include <iomanip>

int main()
{
    std::string word;
    std::string sentence;
    int number;

    std::cin >> word;
    std::getline(std::cin >> std::ws, sentence);
    std::cin >> number;

    std::cout << std::left << std::setw(10) << "WORD" << ": " << word << "\n";
    std::cout << std::left << std::setw(10) << "SENTENCE" << ": " << sentence << "\n";
    std::cout << std::left << std::setw(10) << "DEC" << ": " << std::dec << number << "\n";
    std::cout << std::left << std::setw(10) << "OCT" << ": " << std::oct << number << "\n";
    std::cout << std::left << std::setw(10) << "HEX" << ": " << std::hex << number << "\n";

    return 0;
}