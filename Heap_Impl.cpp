#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
    vector<int> heap;

    // Move element up to maintain heap property
    void heapifyUp(int index) {
        while (index != 0) {
            int parent = (index - 1) / 2;
            if (heap[parent] > heap[index]) {
                swap(heap[parent], heap[index]);
                index = parent;
            } else {
                return;
            }
        }
    }

    // Move element down to maintain heap property
    void heapifyDown(int index) {
        int size = heap.size();
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int smallest = index;

            if (left < size && heap[left] < heap[smallest]) {
                smallest = left;
            }
            if (right < size && heap[right] < heap[smallest]) {
                smallest = right;
            }
            if (smallest != index) {
                swap(heap[index], heap[smallest]);
                index = smallest;
            } else {
                break;
            }
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int extractMin() {
        if (heap.size() == 0) {
            cout << "Heap is empty!" << endl;
            return -1;
        }
        int minValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return minValue;
    }

    void printHeap() {
        for (int x : heap) cout << x << " ";
        cout << endl;
    }
};

int main() {
    MinHeap h;

    h.insert(10);
    h.insert(5);
    h.insert(30);
    h.insert(2);
    h.insert(8);

    cout << "Heap: ";
    h.printHeap();

    cout << "Extracted Min: " << h.extractMin() << endl;

    cout << "Heap after deletion: ";
    h.printHeap();
}
