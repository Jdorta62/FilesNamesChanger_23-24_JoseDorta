/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  *
  * @file ErrorManagerClass.h
  * @author Jose Dorta Luis alu0101414676@ull.edu.es
  * @date 03 April 2022.
  * @brief fichero de cabezera que contiene la declaración de la clase Exception_d.
  * @bug ningún bug conocido.
  * 
  */

#ifndef __ERROR_MANAGER_CLASS_H__
#define __ERROR_MANAGER_CLASS_H__

#include <string>
#include <iostream>
#include <exception>

class Exception_d {
 public:
  Exception_d(std::string file_name, std::string error_description, int error_line, int error_code) : file_name_(file_name), error_description_(error_description), error_line_(error_line), error_code_(error_code) {}
  ~Exception_d() {}
  std::string GetFileName() const {return file_name_;}
  std::string GetErrorDescription() const {return error_description_;}
  int GetErrorLine() const {return error_line_;}
  int GetErrorCode() const {return error_code_;}
 private:
  std::string file_name_;
  std::string error_description_;
  int error_line_;
  int error_code_;
};

std::ostream& operator<<(std::ostream &os, Exception_d const &exeption);

#endif