// 链表的模板类实现

#include "list.h"

template <typename T>
list<T>::list() : head(nullptr), tail(nullptr), listSize(0) {}

// Destructor to free memory
template <typename T>
list<T>::~list() {
  clear();
}

// Copy constructor
template <typename T>
list<T>::list(const list<T>& other) : head(nullptr), tail(nullptr), listSize(0) {
  for (const T& item : other) {
    push_back(item);
  }
}

// Copy assignment operator
template <typename T>
list<T>& list<T>::operator=(const list<T>& other) {
  if (this != &other) {
    clear();
    for (const T& item : other) {
      push_back(item);
    }
  }
  return *this;
}

// Move constructor
template <typename T>
list<T>::list(list<T>&& other) noexcept
    : head(other.head), tail(other.tail), listSize(other.listSize) {
  other.head = nullptr;
  other.tail = nullptr;
  other.listSize = 0;
}

// Move assignment operator
template <typename T>
list<T>& list<T>::operator=(list<T>&& other) noexcept {
  if (this != &other) {
    clear();
    head = other.head;
    tail = other.tail;
    listSize = other.listSize;
    other.head = nullptr;
    other.tail = nullptr;
    other.listSize = 0;
  }
  return *this;
}

// Returns the number of elements in the list
template <typename T>
size_t list<T>::size() const {
  return listSize;
}

template <typename T>
bool list<T>::empty() const {
  return listSize == 0;
}

// Adds an element to the end of the list
template <typename T>
void list<T>::push_back(const T& value) {
  Node* newNode = new Node(value);
  if (!tail) {
    head = tail = newNode;
  } else {
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
  }
  listSize++;
}

// Adds an element to the beginning of the list
template <typename T>
void list<T>::push_front(const T& value) {
  Node* newNode = new Node(value);
  if (!head) {
    head = tail = newNode;
  } else {
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
  }
  listSize++;
}

// Removes the last element from the list
template <typename T>
void list<T>::pop_back() {
  if (!tail) {
    throw std::out_of_range("pop_back on empty list");
  }
  Node* oldTail = tail;
  tail = tail->prev;
  if (tail) {
    tail->next = nullptr;
  } else {
    head = nullptr; // list is now empty
  }
  delete oldTail;
  listSize--;
}

// Removes the first element from the list
template <typename T>
void list<T>::pop_front() {
  if (!head) {
    throw std::out_of_range("pop_front on empty list");
  }
  Node* oldHead = head;
  head = head->next;
  if (head) {
    head->prev = nullptr;
  } else {
    tail = nullptr; // list is now empty
  }
  delete oldHead;
  listSize--;
}

// Returns a reference to the last element in the list
template <typename T>
T& list<T>::back() {
  if (!tail) {
    throw std::out_of_range("back on empty list");
  }
  return tail->data;
}

// Returns a const reference to the last element in the list
template <typename T>
const T& list<T>::back() const {
  if (!tail) {
    throw std::out_of_range("back on empty list");
  }
  return tail->data;
}

// Returns a reference to the first element in the list
template <typename T>
T& list<T>::front() {
  if (!head) {
    throw std::out_of_range("front on empty list");
  }
  return head->data;
}

// Returns a const reference to the first element in the list
template <typename T>
const T& list<T>::front() const {
  if (!head) {
    throw std::out_of_range("front on empty list");
  }
  return head->data;
}

// Iterator class implementation
template <typename T>
list<T>::Iterator::Iterator(Node* node) : current(node) {}

// Dereference operator
template <typename T>
T& list<T>::Iterator::operator*() const {
  if (!current) {
    throw std::out_of_range("Dereferencing a null iterator");
  }
  return current->data;
}

// Arrow operator
template <typename T>
T* list<T>::Iterator::operator->() const {
  if (!current) {
    throw std::out_of_range("Dereferencing a null iterator");
  }
  return &(current->data);
}

// Pre-increment operator
template <typename T>
typename list<T>::Iterator& list<T>::Iterator::operator++() {
  if (current) {
    current = current->next;
  }
  return *this;
}

// Post-increment operator
template <typename T>
typename list<T>::Iterator list<T>::Iterator::operator++(int) {
  Iterator temp = *this;
  ++(*this);
  return temp;
}

// Pre-decrement operator
template <typename T>
typename list<T>::Iterator& list<T>::Iterator::operator--() {
 if (current) {
      current = current->prev;
    }
     return *this;
}

// Post-decrement operator
template <typename T>
typename list<T>::Iterator list<T>::Iterator::operator--(int) {
    Iterator temp = *this;
    --(*this);
    return temp;
}

// Equality operator
template <typename T>
bool list<T>::Iterator::operator==(const Iterator& other) const {
  return current == other.current;
}

// Inequality operator
template <typename T>
bool list<T>::Iterator::operator!=(const Iterator& other) const {
  return !(*this == other);
}

// Returns an iterator pointing to the beginning of the list
template <typename T>
typename list<T>::Iterator list<T>::begin() const {
  return Iterator(head);
}

// Returns an iterator pointing to one past the end of the list
template <typename T>
typename list<T>::Iterator list<T>::end() const {
  return Iterator(nullptr);
}

template <typename T>
typename list<T>::Iterator list<T>::rbegin() const {
    return Iterator(tail);
}

template <typename T>
void list<T>::clear() {
  Node* current = head;
  while (current) {
    Node* next = current->next;
    delete current;
    current = next;
  }
  head = tail = nullptr;
  listSize = 0;
}
