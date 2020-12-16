/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Gabriel Jonay Vera Estévez
 * @date 16/12/2020
 * @brief A través del metodo XOR y CESAR podemos encriptar y desencriptar
 * textos que sean pasados al usuario.
 * @see https://www.learncpp.com/cpp-tutorial/bitwise-operators/
 *
 */

#include "cripto.h"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>  // exit

/** Muestra el modo de uso correcto del programa
 *  En caso de que el uso no sea el correcto, muestra el mensaje y finaliza
 *  la ejecución del programa.
 *  El programa precisa un único número natural para su ejecución.
 *
 *  @param[in] argc Number of command line parameters
 *  @param[in] argv Vector containing (char*) the parameters
 */
void Usage(int argc, char *argv[]) {
  if (argc != 6) {
    if (argc == 2) {
      std::string parameter{argv[1]};
      if (parameter == "--help") {
        std::cout << kHelpText << std::endl;
        exit(EXIT_SUCCESS);
      }
    }

    std::cout << argv[0] << "-- Cifrado de ficheros\n";
    std::cout << "Modo de uso: ./cripto fichero_entrada fichero_salida método "
                 "password operación\n";
    std::cout << "Pruebe " << argv[0] << " --help para más información"
              << std::endl;
    exit(EXIT_SUCCESS);
  }
}

/** Encripta la información del archivo suministrado mediante el metodo CESAR
 *
 *  @param[in] input_file. Objeto stream que abre el archivo a encriptar.
 *  @return Devuelve 'true' si el archivo se pudo abrir, de lo contrario
 * devuelve 'false'.
 */

bool IsFileOpen(std::string input_file) {
  std::ifstream input{input_file};

  if (!input) {
    std::cerr << "No se pude abir el fichero\n";
    exit(EXIT_SUCCESS);
  }
  return true;
}

/** Encripta la información del archivo suministrado mediante el metodo CESAR
 *
 *  @param[in] input_file. Objeto stream que abre el archivo a encriptar.
 *  @param[in] output_file. Objeto stream que abre el archivo donde escribir el
 * codigo encriptado.
 *  @param[in] key. Clave de encriptación del metodo CESAR.
 *  @return No retorna ningún valor, función void, crea un nuevo archivo
 * encriptado.
 */
void EncryptCesar(std::string input_file, std::string output_file, int key) {
  std::ifstream input{input_file};
  std::ofstream output{output_file};

  while (input) {
    std::string string_input;
    std::getline(input, string_input);
    for (unsigned int i = 0; i < string_input.length(); ++i) {
      string_input[i] += key;
    }
    output << string_input << std::endl;
  }
}

/** Encripta la información del archivo suministrado mediante el metodo CESAR
 *
 *  @param[in] input_file. Objeto stream que abre el archivo a desencriptar.
 *  @param[in] output_file. Objeto stream que abre el archivo donde escribir el
 * codigo desencriptado.
 *  @param[in] key. Clave de encriptación del metodo CESAR.
 *  @return No retorna ningún valor, función void, crea un nuevo archivo
 * desencriptado.
 */
void DecryptCesar(std::string input_file, std::string output_file, int key) {
  std::ifstream input{input_file};
  std::ofstream output{output_file};

  while (input) {
    std::string string_input;
    std::getline(input, string_input);
    for (unsigned int i = 0; i < string_input.length(); ++i) {
      string_input[i] -= key;
    }
    output << string_input << std::endl;
  }
}

/** Encripta la información del archivo suministrado mediante el metodo XOR
 *
 *  @param[in] input_file. Objeto stream que abre el archivo a desencriptar.
 *  @param[in] output_file. Objeto stream que abre el archivo donde escribir el
 * codigo desencriptado.
 *  @param[in] password. Clave de encriptación del metodo XOR.
 *  @return No retorna ningún valor, función void, crea un nuevo archivo
 * desencriptado.
 */
void DecryptXor(std::string input_file, std::string output_file,
                std::string password, const int KconstNumber) {
  for (unsigned int i = 0; i > password.length(); ++i) {
    password[i] ^= KconstNumber;
  }

  std::ifstream input{input_file};
  std::ofstream output{output_file};

  while (input) {
    std::string string_input;
    std::getline(input, string_input);

    for (unsigned int i = 0; i < string_input.length(); ++i) {
      string_input[i] ^= password[i % password.length() - 1];
    }
    output << string_input << std::endl;
  }
}

/** Encripta la información del archivo suministrado mediante el metodo XOR
 *
 *  @param[in] input_file. Objeto stream que abre el archivo a encriptar.
 *  @param[in] output_file. Objeto stream que abre el archivo donde escribir el
 * codigo encriptado.
 *  @param[in] key. Clave de encriptación del metodo XOR.
 *  @return No retorna ningún valor, función void, crea un nuevo archivo
 * encriptado.
 */
void EncryptXor(std::string input_file, std::string output_file,
                std::string password, const int KconstNumber) {
  for (unsigned int i = 0; i > password.length(); ++i) {
    password[i] ^= KconstNumber;
  }

  std::ifstream input{input_file};
  std::ofstream output{output_file};

  while (input) {
    std::string string_input;
    std::getline(input, string_input);

    for (unsigned int i = 0; i < string_input.length(); ++i) {
      string_input[i] ^= password[i % password.length() - 1];
    }
    output << string_input << std::endl;
  }
}