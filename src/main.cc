#include <iostream>
#include <filesystem>
#include <string>
#include "FolderClass.h"
#include "FileClass.h"

std::string RemplaceFor(std::regex const &regular_expression, std::string const &original_string, std::string const &replacement);
std::string RemoveAccents(std::string const &input);

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
    std::string file_path = folder_path + "\\\\" + files_names[i];
    File file{file_path};
    file.ChangeName((folder_path + "\\\\" + RemoveAccents(files_names[i])));
    file.ChangeName(regular_expression, "");
  }
  return 0;
}

std::string RemplaceFor(std::regex const &regular_expression, std::string const &original_string, std::string const &replacement) {
  return std::regex_replace(original_string, regular_expression, replacement);
}

std::string RemoveAccents(const std::string& text) {
  std::string text_without_accent = text;
  // Reemplazar las vocales acentuadas con las vocales sin acentuación
  for (char& c : text_without_accent) {
    switch (c) {
      case 'á':
        c = 'a';
        break;
      case 'é':
        c = 'e';
        break;
      case 'í':
        c = 'i';
        break;
      case 'ó':
        c = 'o';
        break;
      case 'ú':
        c = 'u';
        break;
      case 'Á':
        c = 'A';
        break;
      case 'É':
        c = 'E';
        break;
      case 'Í':
        c = 'I';
        break;
      case 'Ó':
        c = 'O';
        break;
      case 'Ú':
        c = 'U';
        break;
      // Añadir aquí más casos para otros caracteres acentuados si es necesario
    }
  }

  return text_without_accent;
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