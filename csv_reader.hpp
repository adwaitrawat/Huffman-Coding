#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#pragma once
#ifndef CSV_READER_HPP
#define CSV_READER_HPP

class CSV_Reader
{
  std::string *_symbols;
  float *_probability;
  int _length;

  std::vector<std::string> split (std::string str, char delimiter)
  {
    std::string token;
    std::vector<std::string> tokens;
    std::stringstream sstream (str);

    while (std::getline (sstream, token, delimiter))
    {
      tokens.push_back (token);
    }

    return tokens;
  }

public:

  CSV_Reader () {}
  CSV_Reader (std::string *filename);

  ~CSV_Reader ();

  inline std::string* symbols ()
  {
    return _symbols;
  }

  inline float* probability ()
  {
    return _probability;
  }

  inline int length ()
  {
    return _length;
  }
};
#endif
