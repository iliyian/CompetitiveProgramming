#ifndef LIST_H
#define LIST_H

#include <stdexcept> // For std::out_of_range

template <typename T> class list {
private:
  struct Node {
    T data;
    Node *next;
    Node *prev;
    Node(const T &value) : data(value), next(nullptr), prev(nullptr) {}
  };

public:

  Node *head;
  Node *tail;
  size_t listSize;

  // Constructor
  list();

  // Destructor to free memory
  ~list();

  // Copy constructor
  list(const list &other);

  // Copy assignment operator
  list &operator=(const list &other);

  // Move constructor
  list(list &&other) noexcept;

  // Move assignment operator
  list &operator=(list &&other) noexcept;

  // Returns the number of elements in the list
  size_t size() const;

  bool empty() const;

  // Adds an element to the end of the list
  void push_back(const T &value);

  // Adds an element to the beginning of the list
  void push_front(const T &value);

  // Removes the last element from the list
  void pop_back();

  // Removes the first element from the list
  void pop_front();

  // Returns a reference to the last element in the list
  T &back();

  // Returns a const reference to the last element in the list
  const T &back() const;

  // Returns a reference to the first element in the list
  T &front();

  // Returns a const reference to the first element in the list
  const T &front() const;

  // Iterator class
  class Iterator {
  private:
    Node *current;

  public:
    Iterator(Node *node);

    // Dereference operator
    T &operator*() const;

    // Arrow operator
    T *operator->() const;

    // Pre-increment operator
    Iterator &operator++();

    // Post-increment operator
    Iterator operator++(int);

    // Pre-decrement operator
    Iterator &operator--();

    // Post-decrement operator
    Iterator operator--(int);

    // Equality operator
    bool operator==(const Iterator &other) const;

    // Inequality operator
    bool operator!=(const Iterator &other) const;
  };

  // Returns an iterator pointing to the beginning of the list
  Iterator begin() const;

  // Returns an iterator pointing to one past the end of the list
  Iterator end() const;

  Iterator rbegin() const;

  void clear();
};
#endif