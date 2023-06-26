/**
 * @file FileClass.cc
 * @author José Gregorio Dorta Luis (dortajose499@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-06-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "FileClass.h"

void File::ChangeName(std::string const &new_path_name) {
  std::filesystem::path old_path(file_path_);
  std::filesystem::path new_path(new_path_name);
  std::filesystem::rename(old_path, new_path);
  file_path_ = new_path_name;
}

void File::ChangeName(std::regex const &regular_expression, std::string const &replacement_string) {
  std::string new_path_name = std::regex_replace(file_path_, regular_expression, replacement_string);
  std::filesystem::path old_path(file_path_);
  std::filesystem::path new_path(new_path_name);
  try {
    std::filesystem::rename(old_path, new_path);
    file_path_ = new_path_name;
  } catch (...) {
    std::cerr << "Error desconocido" << std::endl;
  }
}
