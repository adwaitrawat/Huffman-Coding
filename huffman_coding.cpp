/*
 * Program to produce n-th array huffman encoding.
 *
 * Default value of n is 2.
 *
 * Execution method: ./huffman_coding
 * Execution method using commandline without n: ./huffman_coding.exe "filename.csv"
 * Execution method using commandline with n: ./huffman_coding.exe "filename.csv" "n"
 *
 * csv file example:
 *
 * |A|0.5|
 * |B|0.3|
 * |C|0.2|
 *
 * Author: Adwait Rawat
*/

#include <iostream>
#include "tree.hpp"
#include "csv_reader.hpp"

int main(int argc, char const *argv[])
{
  std::string filename;
  int n = 2;

  std::string *symbols = nullptr;
  float *prob = nullptr;
  int length;
  CSV_Reader *reader = nullptr;

  if (argc > 2)
  {
    n = std::atoi (argv[2]);

    if (n <= 1)
    {
      throw std::runtime_error ("\"n\" should be >= 2.");
    }
  }

  if (argc > 1)
  {
    filename = argv[1];

    reader = new CSV_Reader (&filename);
    symbols = reader->symbols ();
    prob = reader->probability ();
    length = reader->length ();
  }
  else
  {
    std::cout << "Enter n (default: 2): ";
    std::string input;
    std::getline (std::cin, input);

    if (!input.empty ())
    {
      std::stringstream sstream (input);
      sstream >> n;
      if (n < 2)
      {
        throw std::runtime_error ("\"n\" can not be less than 2.");
      }
    }

    std::cout << "Enter number of elements: ";
    std::cin >> length;

    symbols = new std::string[length];
    prob = new float[length];

    for (int i = 0; i < length; i++)
    {
      std::cout << "Enter letter: ";
      std::cin >> symbols[i];

      std::cout << "Enter probability: ";
      std::cin >> prob[i];
    }
  }

  Huffman::Tree tree (length, symbols, prob, n);
  tree.print ();

  if (argc > 1)
  {
    delete reader;
  }
  else
  {
    delete[] symbols;
    delete[] prob;
  }

  exit (EXIT_SUCCESS);
}
