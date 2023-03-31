#include <iostream>
#include <queue>

using namespace std;

// Định nghĩa một nút trong cây nhị phân
struct Node {
    int data;
    Node* left;
    Node* right;
};
typedef struct Node NODE;
typedef NODE* TREE;

// Hàm tạo một nút mới trong cây
NODE* createNode(int data) {
    NODE* p = new NODE;
    p->data = data;
    p->left = nullptr;
    p->right = nullptr;
    return p;
}

// Hàm thêm một nút mới vào cây nhị phân
void insertNode(TREE& root, int data) {
    if (root == nullptr) {
        root = createNode(data);
        return;
    }
    queue<NODE*> q;
    q.push(root);
    while (!q.empty()) {
        NODE* currentNode = q.front();
        q.pop();
        if (currentNode->left == nullptr) {
            currentNode->left = createNode(data);
            return;
        } else {
            q.push(currentNode->left);
        }
        if (currentNode->right == nullptr) {
            currentNode->right = createNode(data);
            return;
        } else {
            q.push(currentNode->right);
        }
    }
}

int main() {
    NODE* root = nullptr;
    int n, data;
    queue<int> q;
    cout << "Nhap so luong phan tu muon them vao cay: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Nhap phan tu thu " << i + 1 << ": ";
        cin >> data;
        insertNode(root, data);
        q.push(data);
    }
    cout << "Cay nhap vao: ";
    while (!q.empty()) {
        /* code */
        int frontElement = q.front();
        q.pop();
        cout << frontElement << " ";
    }

    // int* arr = new int[n];
    // cout << "Nhap so luong phan tu muon them vao cay: ";
    // cin >> n;
    // for (int i = 0; i < n; i++) {
    //     cout << "Nhap phan tu thu " << i + 1 << ": ";
    //     cin >> arr[i];
    //     insertNode(root, arr[i]);
    // }
    // cout << "Cay nhap vao: ";
    // for (int i = 0; i < n; i++) {
    //     cout << arr[i] << "  ";
    // }
    return 0;
}
