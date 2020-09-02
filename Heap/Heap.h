// Student ID: 20274909

#include <string>
#include <sstream>
#include <math.h>
#include <vector>
#include <iostream>
#include <list>
#include <iterator>
#include <climits>

using namespace std;

#ifndef Heap_h
#define Heap_h

// Extern - must be defined by client
template <typename T> T get_sentinel();

// Notes:
// - T must implement operator<() via get_sentinel<T>() { return min possible }
// - The max sizeof a heap = capacity - 1 because elem 0 is a sentinel
// - Capacity is simply elems.size() (= max_size + 1)
template <typename T>
class Heap {
protected:
   vector<T> _elems;
   size_t _size;
   static const int INIT_HEAP_CAPACITY = 128;
public:
   // private helpers
   bool _percolate_down(size_t pos) {
      if (pos <= 0 || pos > _size) {
         return false;
      }

      size_t smallest = pos;
      size_t left_index = 2 * pos;
      size_t right_index = 2 * pos + 1;

      if (left_index <= _size && _elems[left_index] < _elems[smallest])
         smallest = left_index;

      if (right_index <= _size && _elems[right_index] < _elems[smallest])
         smallest = right_index;

      if (smallest != pos) {
         T temp = _elems[pos];
         _elems[pos] = _elems[smallest];
         _elems[smallest] = temp;

         _percolate_down(smallest);
      }
      
      return true;
   }

   bool _heapify() {
      if (!is_empty()) {
         for (size_t i = (_size / 2 + 1); i > 0; i--)
            _percolate_down(i);
         return true;
      }
      return false;
   }
   
public:
   Heap() {
      _elems.resize(INIT_HEAP_CAPACITY);
      _elems[0] = get_sentinel<T>();
      _size = 0;
   }

   Heap(const vector<T>& vec) {
      _size = vec.size();
      _elems.resize(_size + 1);
      _elems[0] = get_sentinel<T>();
      for (size_t i = 0; i < vec.size(); i++)
         _elems[i + 1] = vec[i];
      this->_heapify();
   }

   virtual bool is_empty() const { return _size == 0; }

   virtual bool insert(const T& elem) {
      if (elem < _elems[0]) {
         return false;
      }
      
      _size++;

      if (_size >= _elems.size())
         _elems.resize(_elems.size() * 2);

      size_t index = _size;                                             
      size_t parent_index = index / 2;

      while (elem < _elems[parent_index]) {
         _elems[index] = _elems[parent_index];
         index = parent_index;
         parent_index = index / 2;
      }
      _elems[index] = elem;
      return true;
   }

   virtual bool delete_min() {
      if (is_empty()) {
         return false;
      }
      _elems[1] = _elems[_size];
      _size--;
      _percolate_down(1);
      return true;
   }

   virtual const T& peek_min() const {
      if (is_empty()) {
         return _elems[0];
      }

      return _elems[1];
   }

   virtual string to_string() const {
      stringstream current, left, right;
      current << _elems[1];
      string output = "# Heap with min = " + current.str() + "\n";
      output += "# Size = " + std::to_string(_size) + "\n";

      for (size_t i = 1; i <= _size; i++) {
         size_t left_index = 2 * i;
         size_t right_index = 2 * i + 1;
         string left_child = "-";
         string right_child = "-";

         if (left_index > _size && right_index > _size) {
            continue;
         }
         if (left_index <= _size) {
            left.str(std::string());
            left << _elems[left_index];
            left_child = left.str();
         }
         if (right_index <= _size) {
            right.str(std::string());
            right << _elems[right_index];
            right_child = right.str();
         }
         current.str(std::string());
         current << _elems[i];
         output += current.str() + " : " + left_child + " " + right_child + "\n";
      }

      output += "# End of heap\n";
      return output;
   }

   friend class Tests; // Don't remove this line
};

#endif
