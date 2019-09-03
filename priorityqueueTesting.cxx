#include <iostream>
#include "priorityqueue.h"
using namespace std;


int main() {
   PriorityQueue x(18);
   x.insert(4);
   x.insert(6);
   x.insert(5);
   x.insert(7);
   x.insert(3);
   x.insert(8);
   x.PrintData();
   x.insert(30);
   x.PrintData();
   x.removeKey(5);
   x.insert(21);
   x.insert(12);
   x.PrintData();
   x.change(12, 13);
   x.change(14, 25);
   x.change(6, 15);
   x.PrintData();
   x.change(21, 4);
   x.insert(50);
   x.insert(25);
   cout << "Final data: " << endl;
   x.PrintData();
   x.JSON();
   return 0;
}
