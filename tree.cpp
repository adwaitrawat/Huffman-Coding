#include "tree.hpp"

Huffman::Tree::Tree (int length, std::string *symbols, float *probs, int _n): _n (_n)
{
  for (int i = 0; i < length; i++)
  {
    data.push_back (new Node (NodeData(symbols[i], probs[i]), _n));
  }

  std::sort (data.rbegin (), data.rend (), Compare ());

  while (data.size () > 1)
  {
    auto temp = new Node (NodeData ("", 0), _n);

    for (int i = 0; i < _n && data.size () > 0; i++)
    {
      temp->insert (data[data.size () - 1]);
      data.pop_back ();
    }

    data.push_back (temp);
    std::sort (data.rbegin (), data.rend (), Compare ());
  }
}

void
Huffman::Tree::print ()
{
  for (int i = 0; i < data.size (); i++)
  {
    data[i]->print ();
  }
}
