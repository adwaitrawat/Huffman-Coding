#include <iostream>
#include <string>

#pragma once
#ifndef NODE_HPP
#define NODE_HPP

namespace Huffman
{
  enum NodeState
  {
    LEAF,
    BRANCH,
  };

  class NodeData
  {
  public:
    std::string label;
    std::string coding;
    float prob;

    NodeData () {}
    NodeData (std::string label, float prob): label (label), prob (prob) {}

    inline NodeData operator+ (NodeData &obj)
    {
      return NodeData (label + obj.label, prob + obj.prob);
    }

    inline void print ()
    {
      std::cout << label << " " << coding << std::endl;
    }

    inline void append_code (int c)
    {
      coding = std::to_string (c) + coding;
    }
  };

  class Node
  {
    NodeData data;
    NodeState state;
    Node **ptr;
    int _n;

  public:
    Node () {}
    Node (NodeData data, int _n = 2, bool degub = false);

    ~Node ();

    inline std::string label ()
    const
    {
      return data.label;
    }

    inline float prob ()
    const
    {
      return data.prob;
    }

    void print ();

    void append_code (int c);

    bool insert (Node *n);
  };

  /**
   * INFO: Can use lambda function instead of Compare ()
   * [](const Node* left, const Node* right) {return left->prob () < right->prob ();}
   */
  struct Compare
  {
    bool operator() (const Node* left, const Node* right)
    {
      return left->prob () < right->prob ();
    }
  };
}
#endif
