#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using std::vector;
using std::unordered_map;

typedef struct HeapNode {
    char character;

    unsigned int frequency;

    HeapNode* left;
    HeapNode* right;

    HeapNode(char c, unsigned int f): character(c), frequency(f) {
        left = right = NULL;
    }
} HeapNode;

typedef struct MinHeap {
    unsigned int size;
    unsigned int capacity;

    HeapNode** array;

    // Initially both size and capacity are equal
    MinHeap(unsigned int cap): capacity(cap), size(cap) {
        this->array = (HeapNode**)malloc(cap * sizeof(HeapNode*));
    }

    void buildMinHeap() {
        int lastElemIndex = this->size - 1;

        for (int i = (lastElemIndex - 1) / 2; i >= 0; i--) {
            minHeapify(i);
        }
    }

    HeapNode* getNodeAt(unsigned int index) {
        if (index > this->size)
            std::cout << "Index out of bounds of heap size" << std::endl;

        return this->array[index];
    }

    void setNodeAt(unsigned int index, HeapNode* node) {
        if (index > this->size)
            std::cout << "Index out of bounds of heap size" << std::endl;

        this->array[index] = node;
    }

    void addNode(HeapNode* node) {
        ++this->size;

        int i = this->size - 1;

        // Note: (i - 1) / 2 works to get the parent node of a right or left child node. 
        // (because of integer type truncating decimals)
        while (i && node->frequency < this->getNodeAt((i - 1) / 2)->frequency) {
            this->setNodeAt(i, this->getNodeAt((i - 1) / 2));
            i = (i - 1) / 2; // go up one level
        }

        this->setNodeAt(i, node);
    }

    HeapNode* extractMin() {
        HeapNode* min = this->array[0];

        // put last element at top, thus removing the existing top element (which is the smallest in a min heap)
        this->array[0] = this->getNodeAt(this->size - 1);
        --this->size; // decrement size

        minHeapify(0);

        return min;
    }
    void swapNodes(int first, int second) {
        HeapNode* firstNode = this->getNodeAt(first);
        HeapNode* secondNode = this->getNodeAt(second);

        HeapNode* temp = firstNode;

        this->setNodeAt(first, secondNode);
        this->setNodeAt(second, temp);
    }

    void minHeapify(int idx) {
        int smallest = idx;
        int left = idx * 2 + 1;
        int right = idx * 2 + 2;


        if (left < this->size && this->getNodeAt(left)->frequency < this->getNodeAt(smallest)->frequency) {
            smallest = left;
        }
        if (right < this->size && this->getNodeAt(right)->frequency < this->getNodeAt(smallest)->frequency) {
            smallest = right;
        }

        if (smallest != idx) {
            // if the left or right nodes are smaller
            swapNodes(smallest, idx);
            minHeapify(smallest);
        }
    }
} MinHeap;

unordered_map<char, int> getFrequencies(std::string text) {

    unordered_map<char, int> data;

    for (int i = 0; i < text.size(); i++) {
        char c = text.at(i);

        if (!data[c])
            data[c] = 0;

        data[c] += 1;
    }

    return data;
}

MinHeap* buildHuffmanTree(vector<char> data, vector<int> frequency) {
    MinHeap* heap = new MinHeap(data.size());

    for (int i = 0; i < heap->size; i++) {
        HeapNode* node = new HeapNode(data[i], frequency[i]);
        heap->setNodeAt(i, node);
    }

    heap->buildMinHeap();

    while (heap->size > 1) {

        HeapNode* left = heap->extractMin();
        HeapNode* right = heap->extractMin();

        HeapNode* top = new HeapNode('~', left->frequency + right->frequency);
        top->right = right;
        top->left = left;

        heap->addNode(top);
    }

    return heap;
}

std::string arrToString(int arr[], int size) {
    std::string s = "";
    for (int i = 0; i < size; i++) {
        s.append(std::to_string(arr[i]));
    }
    return s;
}
void printCodes(HeapNode* root, int codes[], int top = 0)  {
    if (root->left) {
        codes[top] = 0;
        printCodes(root->left, codes, top + 1);
    }

    if (root->right) {
        codes[top] = 1;
        printCodes(root->right, codes, top + 1);
    }

    if (!(root->left || root->right)) {
        std::cout << root->character << " : " << arrToString(codes, top) << std::endl;
    }
}

void printTree(HeapNode* root) {
    if (root->left)
        printTree(root->left);

    if (root->right)
        printTree(root->right);

    std::cout << root->frequency << std::endl;

}

int main(int argc, char const* argv[])
{
    std::cout << "Enter string to get huffman table for: " << std::endl;

    std::string text;
    std::getline(std::cin, text);

    //std::string test_string = "aaaaabbbbbbbbbccccccccccccdddddddddddddeeeeeeeeeeeeeeeefffffffffffffffffffffffffffffffffffffffffffff";

    unordered_map<char, int> data = getFrequencies(text);

    vector<char> characters;
    vector<int> frequencies;

    for (auto& it : data) {
        characters.push_back(it.first);
        frequencies.push_back(it.second);
    }

    MinHeap* heap = buildHuffmanTree(characters, frequencies);
    HeapNode* root = heap->getNodeAt(0);

    std::cout << "\n-----HUFFMAN TABLE-----" << std::endl;
    printCodes(root, new int[characters.size()]);
    std::cout << "-----------------------";

    return 0;
}
