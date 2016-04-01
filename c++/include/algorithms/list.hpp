#ifndef __google_vector_hpp
#define __google_vector_hpp


/*
  Node
*/
template <class T>
class Node
{
private:
  Node<T>* next_;
public:
  T data;
  Node<T>() : data(0), next_(nullptr) {}
  Node<T>(const T& d) : data(d), next_(nullptr) {}
  Node<T>(const Node<T>& copynode) : data(copynode.data), next_(nullptr) {}

  // ~Node() {
  //   if (next_)
  //     delete next_;
  // }

  void set_next(Node<T>& node) { next_ = &node; }
  Node* next() { return next_; }

  // do not allow direct assignment
  Node<T>& operator=(const Node<T>&) = delete;
};



// /*
//   LinkedList

//   A custom and personal implementation of linked lists in C++.

//   * insert(T value)
//   * insert_node(LinkedListNode<T>)
// */
// template <class T>
// class LinkedList
// {
// private:

  

// public:
//   Node* front;
//   Node* back;

//   LinkedList<T>() : front(0), back(0) {};
//   LinkedList<T>(const T* f) : front(f), back(f) {};
//   ~LinkedList<T>() {
//     // fill with destructor
//   };

//   // Create an iterator for this class

//   void insert_node(LinkedListNode<T>& node) {
//     back->next = &node;
//     back = &node;
//   };

//   void insert(const T& data) {
//     LinkedListNode<T> node(data);
//     insert_node(node);
//   };

// };


// // Make linked lists work with ostreams
// template<typename T>
// std::ostream& operator<<(std::ostream& s, const LinkedList<T>& v) {
//   s.put('[');
//   char comma[3] = {'\0', ' ', '\0'};
//   for (const auto& e : v) {
//     s << comma << e;
//     comma[0] = ',';
//   }
//   return s << ']';
// }

#endif
