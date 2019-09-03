#include <iostream>
#include <math.h>
#include "priorityqueue.h"
using namespace std;

PriorityQueue::PriorityQueue(unsigned int max_size): max_size(max_size),lastIndex(0) {
    data = new unsigned int[this->max_size+1]{};
};

void PriorityQueue::PrintData() {
    cout << "Queue:" << endl;
    for (unsigned int i = 1; i <=lastIndex; ++i) {
        cout << "Index at " << i << ": " << data[i] << endl;
    }
    cout << "Size = " <<lastIndex << endl;
};

void PriorityQueue::insert(unsigned int key) {
    if (lastIndex < max_size && lastIndex > 0) {
        data[++lastIndex] = key;
        //bool reached2or3 = false;
        //unsigned int index = lastIndex;
        // old for-loop
        // for (unsigned int i = 1; data[lastIndex/((int)pow(2,i))] < data[index] && lastIndex/((int)pow(2,i)) != 0; ++i) {
        //     swapKey(index,lastIndex/((int)pow(2,i)));
        //     index =lastIndex/((int)pow(2,i));
        // }

        heapifyUp(lastIndex);

        // if (index == 2 || index == 3) {
        //     reached2or3 = true;
        // }
        // for (unsigned int i = 1; data[lastIndex/(2*i)] < data[index] && !reached2or3; ++i) {
        //     swapKey(index,lastIndex/(2*i));
        //     index =lastIndex/(2*i);
        //     if (index == 2 || index == 3) {
        //         reached2or3 = true;
        //     }
        // }
        // if (reached2or3 && data[1] < data[index]) {
        //     swapKey(index,1);
        // }
        /* when index SHOULD be 1, we are getting errors - it compares to [2] instead of [1]
        ** so we need to change the for loop to exclude these cases and then check at the very end
        ** before i tried changing < to <= but that does not solve it if the node is 
        ** percolating up as the right child
        */
    }
    else if (lastIndex == 0) {
        data[1] = key;
       lastIndex = 1;
    }
    else {
        cout << "PriorityQueue::insert called on full priority queue" << endl;
    }
};

int PriorityQueue::removeMax() {
    int result = -1;
    if (lastIndex == 0){
        cout << "PriorityQueue::removeMax called on an empty priority queue" << endl;
    }
    else {
        result = data[1];
        swapKey(1,lastIndex);
        lastIndex--; //effectively deletes the last element
        heapifyDown(1);
    }
    return result;
};

bool PriorityQueue::removeKey(unsigned int key) {
    unsigned int index = 0;
    for (unsigned int i=1; i <=lastIndex; i++) {
        if (data[i]==key) {
            index = i;
            break;
        }
    }
    if (index) {
        swapKey(index, lastIndex);
        lastIndex--;

        // bool reached2or3 = false;
        // if (index == 2 || index == 3 || index == 1) {
        //     reached2or3 = true;
        // }
        // for (unsigned int i = 1; data[index/(2*i)] < data[index] && !reached2or3; ++i) {
        //     swapKey(index,index/(2*i));
        //     index =index/(2*i);
        //     if (index == 2 || index == 3) {
        //         reached2or3 = true;
        //     }
        // }
        // if (reached2or3 && data[1] < data[index]) {
        //     swapKey(index,1);
        //     index = 1;
        // }

        /* when index SHOULD be 1, we are getting errors - it compares to [2] instead of [1]
        ** so we need to change the for loop to exclude these cases and then check at the very end
        ** before i tried changing < to <= but that does not solve it if the node is 
        ** percolating up as the right child
        */

        // old for-loop
        // for (unsigned int i = 1; data[index/((int)pow(2,i))] < data[index] && index/((int)pow(2,i)) != 0; ++i) {
        //     swapKey(index,index/((int)pow(2,i)));
        //     index =index/((int)pow(2,i));
        // }
        // unsigned int greaterChild = getGreaterChild(index);
        // while (data[greaterChild] > data[index] && greaterChild !=0) {
        //     swapKey(greaterChild, index);
        //     index = greaterChild;
        //     greaterChild = getGreaterChild(index);
        // }
        if (index>0 && index<= lastIndex) {
        heapifyUp(index);
        heapifyDown(index);
        }

        return true;
    }
    else {
        cout << "PriorityQueue::removeKey key " << key << " not found" << endl;
        return false;
    }
};

bool PriorityQueue::change(unsigned int key, unsigned int newKey){
    unsigned int index = 0;
    for (unsigned int i=1; i <=lastIndex; i++) {
        if (data[i]==key) {
            index = i;
            break;
        }
    }
    if (index) {
        data[index] = newKey;

        // bool reached2or3 = false;
        // if (index == 2 || index == 3 || index == 1) {
        //     reached2or3 = true;
        // }
        // for (unsigned int i = 1; data[index/(2*i)] < data[index] && !reached2or3; ++i) {
        //     swapKey(index,index/(2*i));
        //     index =index/(2*i);
        //     if (index == 2 || index == 3) {
        //         reached2or3 = true;
        //     }
        // }
        // if (reached2or3 && data[1] < data[index]) {
        //     swapKey(index,1);
        //     index = 1;
        // }

        /* when index SHOULD be 1, we are getting errors - it compares to [2] instead of [1]
        ** so we need to change the for loop to exclude these cases and then check at the very end
        ** before i tried changing < to <= but that does not solve it if the node is 
        ** percolating up as the right child
        */

        // old for-loop
        // for (unsigned int i = 1; data[index/((int)pow(2,i))] < data[index] && index/((int)pow(2,i)) != 0; ++i) {
        //     swapKey(index,index/((int)pow(2,i)));
        //     index =index/((int)pow(2,i));
        // }
        // unsigned int greaterChild = getGreaterChild(index);
        // while (data[greaterChild] > data[index] && greaterChild !=0) {
        //     swapKey(greaterChild, index);
        //     index = greaterChild;
        //     greaterChild = getGreaterChild(index);
        // }
        if (index>0 && index<= lastIndex) {
        heapifyUp(index);
        heapifyDown(index);
        }

        return true;
    }
    else {
        cout << "PriorityQueue::change key " << key << " not found" << endl;
        return false;
    }
};

void PriorityQueue::JSON(int maxHeapSize, int numOperations) {
    cout << "{" << endl;
    for (unsigned int index = 1; index <= lastIndex; index++) {
        cout << "  \"" << index << "\": {\n    \"key\": " << data[index];
        if(index != 1) {
            cout << ",\n    \"parent\": \"" << index/2 << "\"";
        }
        if(2*index <= lastIndex) {
            cout << ",\n    \"leftChild\": \"" << index*2 << "\"";
        }
        if (2*index+1 <= lastIndex) {
            cout << ",\n    \"rightChild\": \"" << index*2+1 << "\"";
        }
        cout << "\n  }," << endl;
    }
    cout << "  \"metadata\": {" << endl;
    cout << "    \"maxHeapSize\": " << maxHeapSize << "," <<endl;
    cout << "    \"max_size\": " << max_size << "," <<endl;
    cout << "    \"numOperations\": " << numOperations << "," <<endl;
    cout << "    \"size\": " << lastIndex << endl;
    cout << "  }\n}" <<endl;
};

void PriorityQueue::swapKey(unsigned int index1, unsigned int index2) {
    unsigned int temp = data[index1];
    data[index1] = data[index2];
    data[index2] = temp;
};

unsigned int PriorityQueue::getGreaterChild(unsigned int index) {
    if (2*index == lastIndex) {
        return lastIndex;
    }
    if (2*index+1 > lastIndex) {
        return 0;
    }
    if (data[2*index] > data[2*index+1]) {
        return 2*index;
    }
    else {
        return 2*index+1;
    }
}

void PriorityQueue::heapifyUp(unsigned int index) {
    for (unsigned int parentIndex = index/2; index != 1 && data[parentIndex] < data[index];) {
            swapKey(index,parentIndex);
            index = parentIndex;
            parentIndex = index/2;
    }
}

void PriorityQueue::heapifyDown(unsigned int index) {
    unsigned int greaterChild = getGreaterChild(index);
    while (data[greaterChild] > data[index] && greaterChild !=0) {
            swapKey(greaterChild, index);
            index = greaterChild;
            greaterChild = getGreaterChild(index);
    }
}