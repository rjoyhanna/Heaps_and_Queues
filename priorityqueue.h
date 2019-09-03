#ifndef PRIORITY_H
#define PRIORITY_H

#include <iostream>
using namespace std;

class PriorityQueue{
   public:
      PriorityQueue(unsigned int max_size);
      void PrintData();
      void insert(unsigned int key);
      int removeMax();
      bool removeKey(unsigned int key);
      bool change(unsigned int key, unsigned int newKey);
      unsigned int getGreaterChild(unsigned int index);
      void JSON(int maxHeapSize = 0, int numOperations = 0);
      void heapifyUp(unsigned int index);
      void heapifyDown(unsigned int index);
     
    private:
      unsigned int* data;
      unsigned int max_size;
      unsigned int lastIndex;
      void swapKey(unsigned int index1, unsigned int index2);
};

#endif