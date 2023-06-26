/**
 * @file FileClass.h
 * @author José Gregorio Dorta Luis (dortajose499@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-06-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __FILE_CLASS_H__
#define __FILE_CLASS_H__

#include <string>
#include <iostream>
#include <filesystem>
#include <regex>

class File {
 public:
  File(std::string const &file_path) : file_path_(file_path) {};
  void ChangeName(std::string const &new_path_name);
  void ChangeName(std::regex const &regular_expression, std::string const &replacement_string);
 private:
  std::string file_path_;
};

#endif