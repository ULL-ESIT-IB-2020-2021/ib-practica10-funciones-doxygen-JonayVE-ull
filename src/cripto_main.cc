/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Gabriel Jonay Vera Estévez
 * @date 7.nov.2020
 * @brief Este programa encripta/desencripta la información de un fichero
 * haciendo uso del metodo CESAR o XOR.
 *
 */

#include <fstream>  /// exit
#include <iostream>
#include <string>

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
    if (method == '2') {
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

  std::cout << "Hay " << VocalCount(input_file)
            << " repeticiones de la vocal 'u'.\n";

  return 0;
}
