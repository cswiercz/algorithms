#include "google/list.hpp"
#include <iostream>
#include <cassert>

using std::cout;
using std::endl;

int main(int argc, char** argv)
{
  Node<int> a(1);
  Node<int> b(2);
  assert(a.data == 1);
  assert(a.next() == nullptr);
  assert(b.data == 2);
  assert(b.next() == nullptr);

  a.set_next(b);
  Node<int>* c = a.next();
  assert(c == &b);

  // LinkedList<int> l;
  // assert(l.front == 0);
  // assert(l.back == 0);

  // l.insert_node(a);
  // assert(l.front->data == a.data);
  // assert(l.back->data == a.data);
}
