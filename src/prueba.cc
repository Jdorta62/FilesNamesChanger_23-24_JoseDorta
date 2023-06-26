#include <iostream>
#include <regex>
#include <string>

int main() {
    std::string input = "Hello123 World456";
    const std::regex pattern("\\d+");
    const std::string replacement = "###";

    input = std::regex_replace(input, pattern, replacement);

    std::cout << "Resultado: " << input << std::endl;

    return 0;
}