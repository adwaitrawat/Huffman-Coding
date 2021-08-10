#include "node.hpp"

Huffman::Node::Node (NodeData data, int _n, bool degub): data (data), _n (_n)
{
  if (data.prob > 0 && data.label != "")
  {
    state = LEAF;
  }
  else
  {
    state = BRANCH;
  }

  ptr = new Node*[_n];
  for (int i = 0; i < _n; i++)
  {
    ptr[i] = nullptr;
  }
}

Huffman::Node::~Node ()
{
  for (int i = 0; i < _n; i++)
  {
    delete ptr[i];
  }
}

void
Huffman::Node::print ()
{
  if (state == LEAF)
  {
    data.print ();
  }

  for (int i = 0; i < _n; i++)
  {
    if (ptr[i])
    {
      ptr[i]->print ();
    }
  }
}

void
Huffman::Node::append_code (int c)
{
  data.append_code (c);
  for (int i = 0; i < _n; i++)
  {
    if (ptr[i])
    {
      ptr[i]->append_code (c);
    }
  }
}

bool
Huffman::Node::insert (Node *n)
{
  for (int i = 0; i < _n; i++)
  {
    if (!ptr[i])
    {
      ptr[i] = n;
      n->append_code (i);
      data = data + n->data;
      return true;
    }
  }
  return false;
}
