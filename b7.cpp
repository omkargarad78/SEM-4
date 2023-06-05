#include <iostream>
#include <stack>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
};

//----------------------------------------------------------------------------------------
// Function to create a new node with the given data
Node* newnode(char data) {
    Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

//---------------------------------------------------------------------------------------------
// Function to construct the expression tree from the prefix expression
Node* constructTree(string prefix) {
    stack<Node*> st;

    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];

        if (isalnum(c)) {
            st.push(newnode(c));
        }
        else {
            Node* node = newnode(c);
            node->left = st.top();
            st.pop();
            node->right = st.top();
            st.pop();
            st.push(node);
        }
    }
    Node* root = st.top();
    
//--------------------------------------------------------------------------------------------

    stack<Node*> ps;                        // Postorder traversal
    ps.push(root);

    while (!ps.empty()) {
        Node* current = ps.top();
        ps.pop();

        cout << current->data;

        if (current->left)
            ps.push(current->left);
        if (current->right)
            ps.push(current->right);
    }

    return root;
}


//---------------------------------------------------------------------------------------------

int main() {
    string prefix;
    cout<<"Enter prefix expression";
    cin>>prefix;
    cout << "Postorder traversal of the expression tree: ";
    constructTree(prefix);
    return 0;
}