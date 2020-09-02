// Student ID: 20274909

#include <string>
#include <sstream>
#include <math.h>
#include <vector>
#include <iostream>
#include <list>
#include <iterator>
#include "Heap.h"
#include "Special_Heap.h"

using namespace std;

template<> int get_sentinel<int>() {
   return 0;
}

int main()
{
   Special_Heap<int> test = Special_Heap<int>({14, 7, 2, 8, 22});
   Special_Heap<int> test2 = Special_Heap<int>();

   test.get_least_k(1);

   cout << test.to_string();

   test.delete_min();
   //cout << test.peek_min() << endl;
   //cout << test.to_string() << endl;
   //test.insert(6);
   //cout << test.to_string() << endl;
   ////test.get_least_k(1);
   //cout << test.to_string() << endl;
   ////test.get_least_k(2);
   //test.get_least_k(3);


}

