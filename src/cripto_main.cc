/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 7.nov.2020
 * @brief Cada nuevo término de la serie de Fibonacci se genera sumando los dos
 * anteriores. Comenzando con 0 y 1, los primeros 10 términos serán: 0, 1, 1, 2,
 * 3, 5, 8, 13, 21, 34 Desarrolle en C++ un programa que calcule la suma de
 * todos los términos de valor par de la serie que sean menores que 1000.
 * @see
 * https://docs.google.com/document/d/1-3hTIVf8tPrbn9u0vs0Cm2IGyX1XBgv8hReVU0KOSUQ/edit?usp=sharing
 * @see stoi http://www.cplusplus.com/reference/string/stoi/
 * An Object Oriented Version of the program:
 * @see
 * https://stackoverflow.com/questions/21360694/sum-of-even-fibonacci-numbers-under-1000
 *
 */

#include <fstream>  /// exit
#include <iostream>
#include <string>
#include <vector>

#include "cripto.h"

/** Main function
 *  @param[in] argc Number of command line parameters
 *  @param[in] argv Vector containing (char*) the parameters
 */
int main(int argc, char* argv[]) {
  Usage(argc, argv);

  std::string input_file = argv[1];
  std::string output_file = argv[2];
  char method = argv[3][0];
  std::string password = argv[4];
  int key{0};
  char operation = argv[5][0];
  const int KconstNumber = 128;

  IsFileOpen(input_file);

  if (operation == '+') {
    if (method =='2') {
      key = std::stoi(password);
      EncryptCesar(input_file, output_file, key);
    } else if (method == '1') {
      EncryptXor(input_file, output_file, password, KconstNumber);
    }
  } else if (operation == '-') {
    if (method == '2') {
      key = std::stoi(password);
      DecryptCesar(input_file, output_file, key);
    } else if (method == '1') {
      DecryptXor(input_file, output_file, password, KconstNumber);
    }
  }

  return 0;
}
