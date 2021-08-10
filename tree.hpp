#include <algorithm>
#include <vector>
#include "node.hpp"

#pragma once
#ifndef TREE_HPP
#define TREE_HPP

namespace Huffman
{
  class Tree
  {
    std::vector<Node*> data;
    int _n;

  public:

    Tree () {}
    Tree (int length, std::string *symbols, float *probs, int _n = 2);

    void print ();
  };
}
#endif
