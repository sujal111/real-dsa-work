#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
public:
    vector<int> heap;

    // Return index helpers
    int parent(int i) { return (i - 1) / 2; }
    int left(int i)   { return 2 * i + 1; }
    int right(int i)  { return 2 * i + 2; }

    // Heapify down (for deletion / building heap)
    void heapify(int i) {
        int largest = i;
        int l = left(i);
        int r = right(i);

        if (l < heap.size() && heap[l] > heap[largest])
            largest = l;

        if (r < heap.size() && heap[r] > heap[largest])
            largest = r;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapify(largest);
        }
    }

    // Insert a new key
    void insert(int key) {
        heap.push_back(key);
        int i = heap.size() - 1;

        // Heapify up
        while (i != 0 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    // Delete element at index i
    void deleteKey(int i) {
        if (i >= heap.size()) return;

        // Replace with last element
        heap[i] = heap.back();
        heap.pop_back();

        // Fix heap (either go up or down)
        if (i != 0 && heap[i] > heap[parent(i)]) {
            // Heapify up
            while (i != 0 && heap[parent(i)] < heap[i]) {
                swap(heap[i], heap[parent(i)]);
                i = parent(i);
            }
        } else {
            // Heapify down
            heapify(i);
        }
    }

    // Extract the maximum value (root)
    int extractMax() {
        if (heap.empty()) {
            cout << "Heap is empty\n";
            return -1;
        }

        int root = heap[0];
        deleteKey(0);
        return root;
    }

    // Utility function to print heap
    void printHeap() {
        for (int x : heap) cout << x << " ";
        cout << "\n";
    }
};

int main() {
    MaxHeap h;

    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(7);
    h.insert(30);

    cout << "Heap: ";
    h.printHeap();

    cout << "Extract Max: " << h.extractMax() << endl;

    cout << "Heap after extraction: ";
    h.printHeap();

    h.deleteKey(1);

    cout << "Heap after deleting index 1: ";
    h.printHeap();

    return 0;
}
