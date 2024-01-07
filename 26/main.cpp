#include <iostream>
#include <vector>

typedef int64_t ll;

using namespace std;

struct Node {
    Node* left = nullptr;
    Node* right = nullptr;
    ll key;
    ll sz = -1;

    explicit Node(ll key) : key(key) {}

    Node(ll key, ll sz) : key(key), sz(sz) {}
};

Node* main_root = nullptr;

ll getSize(Node* a) {
    if (a == nullptr) {
        return 0;
    }
    if (a->sz != -1)
        return a->sz;
    return a->sz = 1 + getSize(a->left) + getSize(a->right);
}

Node* deleteNode(Node* root, ll key) {
    if (root == nullptr) {
        return root;
    }

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    }
    else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            return temp;
        }

        Node* minValueNode = root->right;
        while (minValueNode->left != nullptr) {
            minValueNode = minValueNode->left;
        }

        root->key = minValueNode->key;
        root->right = deleteNode(root->right, minValueNode->key);
    }

    return root;
}

Node* insert(Node* root, ll val) {
    if (root == nullptr) {
        return new Node(val);
    }
    else if (val < root->key) {
        root->left = insert(root->left, val);
    }
    else if (root->key < val) {
        root->right = insert(root->right, val);
    }
    else {
        return root;
    }
    return root;
}

ll max_diff = -1;
vector<Node*> best_nodes;

void inorder(Node* root) {
    if (root == nullptr)
        return;
    ll cur_diff = abs(getSize(root->right) - getSize(root->left));
    if (cur_diff > max_diff) {
        max_diff = cur_diff;
        best_nodes.clear();
        best_nodes.push_back(root);
    }
    else if (cur_diff == max_diff) {
        best_nodes.push_back(root);
    }
    inorder(root->left);
    inorder(root->right);
}

void outputInorder(Node* root) {
    if (root == nullptr)
        return;
    cout << root->key << '\n';
    outputInorder(root->left);
    outputInorder(root->right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("tst.in", "r", stdin);
    freopen("tst.out", "w", stdout);
    ll cur;

    while (cin >> cur) {
        main_root = insert(main_root, cur);
    }
    getSize(main_root);
    inorder(main_root);
    Node* best = new Node(-1e10);

    for (auto& node : best_nodes) {
        if (node->key > best->key) {
            best = node;
        }
    }

    main_root = deleteNode(main_root, best->key);

    outputInorder(main_root);


    return 0;
}
