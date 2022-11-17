#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>


namespace codeTest {

// Tutorial test
int compute_closest_to_zero(std::vector<int> ts);

bool exists(int ints[], int size, int k);
bool existsBS(int ints[], int size, int k);

class Node
{
    public:
        int value;
        Node *left;
        Node *right;

        //! This method returns a pointer to the node with the given​​​​​​‌​​‌‌‌​‌​‌​​​​‌​​‌​‌​​​​​ value.
        Node* find(int v, Node* root);
};

}