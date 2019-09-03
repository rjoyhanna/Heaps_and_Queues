#include <iostream>
#include <fstream>
#include "json.hpp"
#include "priorityqueue.h"

int main(int argc, char** argv) {
    ifstream file;
    file.open(argv[1]);
    nlohmann::json jsonObject;
    if(file.is_open()) {
        file >> jsonObject;
    }
    else {
        cout << "Something went wrong, try with a different file name?" << endl;
        return 1;
    }
    int arraySize = jsonObject["metadata"]["arraySize"];
    for (auto itr = jsonObject.begin(); itr != jsonObject.end() && itr.key() != "metadata"; itr++) {
        PriorityQueue queue(arraySize);
        for (int i = 0; i < arraySize; ++i) {
            queue.insert(itr.value()[i]);
        }
        for (int i = 0; i < arraySize; ++i) {
            itr.value()[arraySize-i-1]=queue.removeMax();
        }
    }
    cout << jsonObject.dump(2);
}