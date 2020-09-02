// Student ID: 20274909

#include <string>
#include <sstream>
#include <math.h>
#include <vector>
#include <iostream>
#include <list>
#include <iterator>
#include <climits>
#include "Heap.h"

using namespace std;

#ifndef Special_Heap_h
#define Special_Heap_h

// This is a sub-class of Heap that provides a single extra method called
// get_k_smallest(size_t k), which has a worst-case performance of O(k log N)
template <typename T>
class Special_Heap : public Heap<T> {
public:
   Special_Heap() : Heap<T>() {};
   Special_Heap(const vector<T>& vec) : Heap<T>(vec) {}

   const vector<T>& get_least_k(size_t k) {
      if (k > this->_size) {
         return this->_elems;
      }

      for (size_t i = 0; i < k; i++) {
         T min = this->_elems[1];
         this->delete_min();
         this->_elems[this->_size + 1] = min;
      }
      this->_size = 0;
      return this->_elems;
   }

   friend class Tests; // Don't remove this line
};

#endif
