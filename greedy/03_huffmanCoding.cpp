#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// A Huffman tree node
struct MinHeapNode
{
    char data;
    unsigned freq;
    MinHeapNode *left, *right;

    MinHeapNode(char data, unsigned freq)
    {
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

struct compare
{
    bool operator()(MinHeapNode *l, MinHeapNode *r)
    {
        return (l->freq > r->freq);
    }
};

void printCodes(struct MinHeapNode *root, string str)
{
    if (!root)
        return;

    if (root->data != '$')
        cout << root->data << ": " << str << "\n";

    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

string decode(struct MinHeapNode* root, string s)
{
    string ans = "";
    struct MinHeapNode* curr = root;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0')
            curr = curr->left;
        else
            curr = curr->right;
 
        // reached leaf node
        if (curr->left == NULL and curr->right == NULL) {
            ans += curr->data;
            curr = root;
        }
    }
    return ans;
}

// The main function that builds a Huffman Tree and
// print codes by traversing the built Huffman Tree
void HuffmanCodes(char data[], int freq[], int size)
{
    priority_queue<MinHeapNode *, vector<MinHeapNode *>, compare> minHeap;
    for (int i = 0; i < size; ++i)
        minHeap.push(new MinHeapNode(data[i], freq[i]));

    struct MinHeapNode *left, *right, *top;
    while (minHeap.size() != 1)
    {
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        top = new MinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        minHeap.push(top);
    }
    printCodes(minHeap.top(), "");
    cout<<decode(minHeap.top(), "110011011001011110");
}

int main()
{

    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(arr) / sizeof(arr[0]);
    HuffmanCodes(arr, freq, size);

    return 0;
}
