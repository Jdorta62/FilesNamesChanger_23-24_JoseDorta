#include <iostream>
#include <filesystem>
#include <string>

#ifndef __FOLDER_CLASS__
#define __FOLDER_CLASS__

class Folder {
 public:
  std::string List();
 private:
  std::string folder_path_;
};

#endif