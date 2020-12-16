/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Gabriel Jonay Vera Estévez
 * @date 16.dic.2020
 * @brief This file declares the "Help Text" constant and two functions
 *
 */

#include <iostream>

const std::string kHelpText = "./cripto -- Cifrado de ficheros\n\
Modo de uso: ./cripto fichero_entrada fichero_salida método password operación\n\n\
fichero_entrada: Fichero a codificar\n\
fichero_salida:  Fichero codificado\n\
método:          Indica el método de encriptado\n\
                   1: Cifrado_xor \n\
                   2: Cifrado_Cesar\n\
password:        Palabra secreta en el caso de método 1, Valor de K en el método 2\n\
operación:       Operación a realizar en el fichero\n\
                   +: encriptar el fichero\n\
                   -: desencriptar el fichero;\n";

void Usage(int argc, char *argv[]);
bool IsFileOpen(std::string input_file);
void EncryptCesar(std::string input_file, std::string output_file, int key);
void DecryptCesar(std::string input_file, std::string output_file, int key);
void EncryptXor(std::string input_file, std::string output_file, std::string password, const int KconstNumber);
void DecryptXor(std::string input_file, std::string output_file, std::string password, const int KconstNumber);