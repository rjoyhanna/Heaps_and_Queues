#include <iostream>
#include <fstream>
#include "priorityqueue.h"
#include "json.hpp"

void ApplyOperation(nlohmann::json operation, PriorityQueue* queue);

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
    int maxHeapSize = jsonObject["metadata"]["maxHeapSize"];
    PriorityQueue queue(maxHeapSize);
    for (auto itr = jsonObject.begin(); itr != jsonObject.end() && itr.key() != "metadata"; itr++) {
        ApplyOperation(itr.value(), &queue);
    }
    queue.JSON(maxHeapSize, jsonObject["metadata"]["numOperations"]);
    return 0;
}

void ApplyOperation(nlohmann::json operation, PriorityQueue* queue) {
    if (operation["operation"] == "insert") {
        queue->insert(operation["key"]);
    }
    else if (operation["operation"] == "removeMax") {
        queue->removeMax();
    }
    else if (operation["operation"] == "change") {
        queue->change(operation["key"], operation["newKey"]);
    }
    else if (operation["operation"] == "removeKey") {
        queue->removeKey(operation["key"]);
    }
}