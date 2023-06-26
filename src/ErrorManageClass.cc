/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  *
  * @file ErrorManagerClass.cc
  * @author Jose Dorta Luis alu0101414676@ull.edu.es
  * @date 03 April 2022.
  * @brief fichero de cabezera que contiene la implementación de la clase Exception_d.
  * @bug ningún bug conocido.
  * 
  */

#include "ErrorManageClass.h"

std::ostream& operator<<(std::ostream &os, Exception_d const &exeption) {
  os << exeption.GetFileName() << " " << exeption.GetErrorLine() << ": " << exeption.GetErrorDescription() << ". Error code (" << exeption.GetErrorCode() << ")";
  return os;
}