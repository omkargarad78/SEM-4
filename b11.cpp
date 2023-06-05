#include <iostream>
#include <string>
using namespace std;
//--------------------------------------------------------------------------------

struct Node {
    string keyword;
    string meaning;
    Node* left;
    Node* right;

    Node(string key, string val) {
        keyword = key;
        meaning = val;
        left = right = NULL;
    }
};
//--------------------------------------------------------------------------------

Node* addNode(Node* node, string key, string val) {
    if (node == NULL) {
        node = new Node(key, val);
        return node;
    }
    if (key < node->keyword) {
        node->left = addNode(node->left, key, val);
    }
    else if (key > node->keyword) {
        node->right = addNode(node->right, key, val);
    }
    else {
        node->meaning = val;
    }
    return node;
}
//--------------------------------------------------------------------------------

Node* deleteNode(Node* node, string key) {
    if (node == NULL) {
        return node;
    }
    if (key < node->keyword) {
        node->left = deleteNode(node->left, key);
    }
    else if (key > node->keyword) {
        node->right = deleteNode(node->right, key);
    }
    else {
        if (node->left == NULL) {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == NULL) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
    }
    return node;
}
//------------------------------------------------------------------------------------
void displayAsc(Node* node) {
    if (node != NULL) {
        displayAsc(node->left);
        cout << "Keyword: " << node->keyword << ", Meaning: " << node->meaning << endl;
        displayAsc(node->right);
    }
}
//------------------------------------------------------------------------------------
void displayDesc(Node* node) {
    if (node != NULL) {
        displayDesc(node->right);
        cout << "Keyword: " << node->keyword << ", Meaning: " << node->meaning << endl;
        displayDesc(node->left);
    }
}
//-------------------------------------------------------------------------------------

int main() {
    Node* root = NULL;

    root = addNode(root, "apple", "a fruit with red or green skin and a round shape");
    root = addNode(root, "banana", "a long curved fruit which is yellow when ripe");
    root = addNode(root, "carrot", "a long, thin, orange vegetable");
    root = addNode(root, "date", "the sweet fruit of the date palm");

    cout << "Ascending order:" << endl;
    displayAsc(root);

    cout << "\nDescending order:" << endl;
    displayDesc(root);

    root = deleteNode(root, "carrot");
    cout << "\nAfter deleting carrot:" << endl;
    displayAsc(root);

    return 0;
}
//--------------------------------------------------------------------------------------