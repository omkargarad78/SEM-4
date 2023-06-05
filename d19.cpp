#include <iostream>
#include <string>

using namespace std;

struct TreeNode {
    string keyword;
    string meaning;
    TreeNode* left;
    TreeNode* right;
    int height;

    TreeNode(const string& keyword, const string& meaning)
        : keyword(keyword), meaning(meaning), left(nullptr), right(nullptr), height(1) {}
};

class Dictionary {
public:
    Dictionary() : root(nullptr) {}

    void insert(const string& keyword, const string& meaning) {
        root = insertNode(root, keyword, meaning);
    }

    void remove(const string& keyword) {
        root = removeNode(root, keyword);
    }

    void update(const string& keyword, const string& newMeaning) {
        TreeNode* node = findNode(root, keyword);
        if (node) {
            node->meaning = newMeaning;
        }
    }

    void displayAscending() {
        displayAscendingHelper(root);
    }

    void displayDescending() {
        displayDescendingHelper(root);
    }

    int getMaxComparisons(const string& keyword) {
        return getMaxComparisonsHelper(root, keyword);
    }

private:
    TreeNode* root;

    int getHeight(TreeNode* node) {
        return node ? node->height : 0;
    }

    int getBalanceFactor(TreeNode* node) {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    TreeNode* rotateRight(TreeNode* y) {
        TreeNode* x = y->left;
        TreeNode* T3 = x->right;

        x->right = y;
        y->left = T3;

        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    TreeNode* rotateLeft(TreeNode* x) {
        TreeNode* y = x->right;
        TreeNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    TreeNode* insertNode(TreeNode* node, const string& keyword, const string& meaning) {
        if (node == nullptr)
            return new TreeNode(keyword, meaning);

        if (keyword < node->keyword)
            node->left = insertNode(node->left, keyword, meaning);
        else if (keyword > node->keyword)
            node->right = insertNode(node->right, keyword, meaning);
        else
            node->meaning = meaning;

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        int balanceFactor = getBalanceFactor(node);

        if (balanceFactor > 1) {
            if (keyword < node->left->keyword)
                return rotateRight(node);
            else {
                node->left = rotateLeft(node->left);
                return rotateRight(node);
            }
        }

        if (balanceFactor < -1) {
            if (keyword > node->right->keyword)
                return rotateLeft(node);
            else {
                node->right = rotateRight(node->right);
                return rotateLeft(node);
            }
        }

        return node;
    }

    TreeNode* findMinValueNode(TreeNode* node) {
        while (node->left != nullptr)
            node = node->left;
        return node;
    }

    TreeNode* removeNode(TreeNode* node, const string& keyword) {
        if (node == nullptr)
            return node;

        if (keyword < node->keyword)
            node->left = removeNode(node->left, keyword);
        else if (keyword > node->keyword)
            node->right = removeNode(node->right, keyword);
        else {
            if (node->left == nullptr || node->right == nullptr) {
                TreeNode* temp = node->left ? node->left : node->right;
                delete node;
                return temp;
            } else {
                TreeNode* temp = findMinValueNode(node->right);
                node->keyword = temp->keyword;
                node->meaning = temp->meaning;
                node->right = removeNode(node->right, temp->keyword);
            }
        }

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        int balanceFactor = getBalanceFactor(node);

        if (balanceFactor > 1) {
            if (getBalanceFactor(node->left) < 0)
                node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        if (balanceFactor < -1) {
            if (getBalanceFactor(node->right) > 0)
                node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    TreeNode* findNode(TreeNode* node, const string& keyword) {
        if (node == nullptr || node->keyword == keyword)
            return node;

        if (keyword < node->keyword)
            return findNode(node->left, keyword);
        else
            return findNode(node->right, keyword);
    }

    void displayAscendingHelper(TreeNode* node) {
        if (node == nullptr)
            return;

        displayAscendingHelper(node->left);
        cout << node->keyword << ": " << node->meaning << endl;
        displayAscendingHelper(node->right);
    }

    void displayDescendingHelper(TreeNode* node) {
        if (node == nullptr)
            return;

        displayDescendingHelper(node->right);
        cout << node->keyword << ": " << node->meaning << endl;
        displayDescendingHelper(node->left);
    }

    int getMaxComparisonsHelper(TreeNode* node, const string& keyword) {
        if (node == nullptr)
            return 0;

        if (node->keyword == keyword)
            return 1;

        if (keyword < node->keyword)
            return 1 + getMaxComparisonsHelper(node->left, keyword);

        return 1 + getMaxComparisonsHelper(node->right, keyword);
    }
};

int main() {
    Dictionary dict;

    dict.insert("apple", "A fruit");
    dict.insert("banana", "A tropical fruit");
    dict.insert("cat", "A domestic animal");
    dict.insert("dog", "A domestic animal");
    dict.insert("zebra", "A wild animal");

    cout << "Dictionary in ascending order:" << endl;
    dict.displayAscending();

    cout << "\nDictionary in descending order:" << endl;
    dict.displayDescending();

    cout << "\nMax comparisons required to find 'banana': " << dict.getMaxComparisons("banana") << endl;

    dict.update("apple", "A delicious fruit");

    cout << "\nUpdated meaning of 'apple': " << dict.getMaxComparisons("apple") << endl;

    dict.remove("cat");

    cout << "\nDictionary after removing 'cat':" << endl;
    dict.displayAscending();

    return 0;
}
