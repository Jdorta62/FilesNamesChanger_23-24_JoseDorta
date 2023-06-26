#include <iostream>
#include <filesystem>
#include <string>
#include "FolderClass.h"
#include "FileClass.h"

std::string RemplaceFor(std::regex const &regular_expression, std::string const &original_string, std::string const &replacement);
std::string removeAccents(std::string const &input);

int main() {
  std::string folder_path, pattern_to_remplace;
  std::cout << "Ingrese el path de la carpeta: ";
  std::cin >> folder_path;
  std::regex inverse_bar_expression{"\\\\"};
  folder_path = RemplaceFor(inverse_bar_expression, folder_path, "\\\\");
  std::cout << "Inserte la expresion regular que capture el patron que desea reemplazar: ";
  std::cin.ignore();
  std::getline(std::cin, pattern_to_remplace);
  std::cout << "Patron a reconocer: " << pattern_to_remplace << std::endl;
  Folder folder{folder_path};
  std::vector<std::string> files_names = folder.List();
  std::regex regular_expression{pattern_to_remplace};
  int number_of_file = files_names.size();
  for (int i = 0; i < number_of_file; ++i) {
    std::string file_path = folder_path + "\\\\" + removeAccents(files_names[i]);
    File file{file_path};
    file.ChangeName(regular_expression, "");
  }
  return 0;
}

std::string RemplaceFor(std::regex const &regular_expression, std::string const &original_string, std::string const &replacement) {
  return std::regex_replace(original_string, regular_expression, replacement);
}

std::string removeAccents(std::string const &input) {
    std::string result = input;

    for (char& c : result) {
        switch (c) {
            case '\xC3\xA1': case '\xC3\xA0': case '\xC3\xA4': case '\xC3\xA2':
                c = 'a';
                break;
            case '\xC3\xA9': case '\xC3\xA8': case '\xC3\xAB': case '\xC3\xAA':
                c = 'e';
                break;
            case '\xC3\xAD': case '\xC3\xAC': case '\xC3\xAF': case '\xC3\xAE':
                c = 'i';
                break;
            case '\xC3\xB3': case '\xC3\xB2': case '\xC3\xB6': case '\xC3\xB4':
                c = 'o';
                break;
            case '\xC3\xBA': case '\xC3\xB9': case '\xC3\xBC': case '\xC3\xBB':
                c = 'u';
                break;
            case '\xC3\xB1':
                c = 'n';
                break;
            case '\xC3\xA7':
                c = 'c';
                break;
            case '\xC3\x81': case '\xC3\x80': case '\xC3\x84': case '\xC3\x82':
                c = 'A';
                break;
            case '\xC3\x89': case '\xC3\x88': case '\xC3\x8B': case '\xC3\x8A':
                c = 'E';
                break;
            case '\xC3\x8D': case '\xC3\x8C': case '\xC3\x8F': case '\xC3\x8E':
                c = 'I';
                break;
            case '\xC3\x93': case '\xC3\x92': case '\xC3\x96': case '\xC3\x94':
                c = 'O';
                break;
            case '\xC3\x9A': case '\xC3\x99': case '\xC3\x9C': case '\xC3\x9B':
                c = 'U';
                break;
            case '\xC3\x91':
                c = 'N';
                break;
            case '\xC3\x87':
                c = 'C';
                break;
        }
    }

    return result;
}

/*
const std::string folderPath = "C:\\Users\\zenit\\Documents\\UDRambla";
SpotifyMate.com - 
    for (const auto& entry : std::filesystem::directory_iterator(folderPath)) {
        if (std::filesystem::is_regular_file(entry)) {
            std::cout << entry.path().filename().string() << std::endl;
        }
    }

    return 0;
*/