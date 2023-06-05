#include <iostream>
#define SIZE 10
using namespace std;


void get_data(int a[], int p[], int q[], int& n) {
    cout << "\nOptimal Binary Search Tree\n";
    cout << "\nEnter the number of nodes: ";
    cin >> n;
    cout << "\nEnter the data as:\n";
    for (int i = 1; i <= n; i++) {
        cout << "\na[" << i << "]: ";
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cout << "\np[" << i << "]: ";
        cin >> p[i];
    }
    for (int i = 0; i <= n; i++) {
        cout << "\nq[" << i << "]: ";
        cin >> q[i];
    }
}

int min_value(int c[][SIZE], int r[][SIZE], int i, int j) {
    int minimum = 32000;
    for (int m = r[i][j - 1]; m <= r[i + 1][j]; m++) {
        int cost = c[i][m - 1] + c[m][j];
        if (cost < minimum) {
            minimum = cost;
        }
    }
    return minimum;
}

void build_obst(int a[], int p[], int q[], int n, int w[][SIZE], int c[][SIZE], int r[][SIZE]) {
    for (int i = 0; i < n; i++) {
        w[i][i] = q[i];
        r[i][i] = c[i][i] = 0;
        w[i][i + 1] = q[i] + q[i + 1] + p[i + 1];
        r[i][i + 1] = i + 1;
        c[i][i + 1] = q[i] + q[i + 1] + p[i + 1];
    }
    w[n][n] = q[n];
    r[n][n] = c[n][n] = 0;
    for (int m = 2; m <= n; m++) {
        for (int i = 0; i <= n - m; i++) {
            int j = i + m;
            w[i][j] = w[i][j - 1] + p[j] + q[j];
            int k = min_value(c, r, i, j);
            c[i][j] = w[i][j] + c[i][k - 1] + c[k][j];
            r[i][j] = k;
        }
    }
}

void build_tree(int r[][SIZE], int i, int j, int c[][SIZE]) {
    int k = r[i][j];
    cout << "\n\t" << k;
    if (r[i][k - 1] != 0) {
        cout << "\t" << r[i][k - 1];
        build_tree(r, i, k - 1, c);
    }
    else {
        cout << "\t";
    }
    if (r[k][j] != 0) {
        cout << "\t" << r[k][j];
        build_tree(r, k, j, c);
    }
    else {
        cout << "\t";
    }
}

void print_tree(int r[][SIZE], int n, int c[][SIZE]) {
    cout << "The Optimal Binary Search Tree For the Given Node Is\n";
    cout << "\nThe Root of this OBST is: " << r[0][n];
    cout << "\nThe Cost of this OBST is: " << c[0][n];
    cout << "\n\n\t NODE \t LEFT CHILD \t RIGHT CHILD ";
    cout << "\n";
    build_tree(r, 0, n, c);
    cout << "\n";
}

int main() {
    int a[SIZE], p[SIZE], q[SIZE];
    int w[SIZE][SIZE], c[SIZE][SIZE], r[SIZE][SIZE];
    int n;

    get_data(a, p, q, n);
    build_obst(a, p, q, n, w, c, r);
    print_tree(r, n, c);

    return 0;
}
