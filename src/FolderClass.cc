/**
 * @file FolderClass.cc
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-06-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "FolderClass.h"

std::vector<std::string> Folder::List() {
  std::vector<std::string> list_result;
  for (const auto& entry : std::filesystem::directory_iterator(folder_path_)) {
    if (std::filesystem::is_regular_file(entry)) {
      // Convertir el nombre del archivo a secuencia UTF-8 antes de almacenarlo en la lista
      std::string filename_utf8 = entry.path().filename().u8string();
      list_result.push_back(filename_utf8);
    }
  }
  return list_result;
}