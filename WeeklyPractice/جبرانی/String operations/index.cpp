#include <iostream>
#include <string>

int main()
{
    std::string sentence, search_phrase, replacement, suffix;

    std::getline(std::cin, sentence);
    std::getline(std::cin, search_phrase);
    std::getline(std::cin, replacement);
    std::getline(std::cin, suffix);

    sentence += suffix;

    size_t pos = sentence.rfind(search_phrase);

    if (pos != std::string::npos)
    {
        std::string result = sentence.substr(0, pos) + replacement + sentence.substr(pos + search_phrase.length());
        std::cout << result << std::endl;
    }
    else
    {
        std::cout << sentence << std::endl;
        std::cout << -1 << std::endl;
    }

    return 0;
}