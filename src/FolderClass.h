/**
 * @file FolderClass.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-06-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <filesystem>
#include <string>
#include <vector>

#include "ErrorManageClass.h"

#ifndef __FOLDER_CLASS__
#define __FOLDER_CLASS__

class Folder {
 public:
  Folder(std::string folder_path) : folder_path_(folder_path) {};
  std::vector<std::string> List();
 private:
  std::string folder_path_;
};

#endif