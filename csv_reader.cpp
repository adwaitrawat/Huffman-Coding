#include "csv_reader.hpp"

CSV_Reader::CSV_Reader (std::string *filename)
{
  std::ifstream file (*filename);
  if (!file.is_open ())
  {
    std::string err_msg = "Could not open file \"" + *filename + "\".";
    throw std::runtime_error (err_msg);
  }

  std::string line;

  if (file.good ())
  {
    _length = 0;
    while (std::getline (file, line))
    {
      _length++;
    }

    file.clear ();
    file.seekg (0, file.beg);
    _symbols = new std::string[_length];
    _probability = new float[_length];

    for (int i = 0; i < _length && std::getline (file, line); i++)
    {
      std::string symbol;
      float prob;

      auto tokens = split (line, ',');
      symbol = tokens[0];

      std::stringstream sstream (tokens[1]);
      sstream >> prob;

      if (symbol == "")
      {
        throw std::runtime_error ("Null identifier not allowed.");
      }

      _symbols[i] = symbol;
      _probability[i] = prob;
    }
  }

  file.close ();
}

CSV_Reader::~CSV_Reader ()
{
  delete[] _symbols;
  delete[] _probability;
}
