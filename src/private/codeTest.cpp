#include "../public/codeTest.h"


int codeTest::compute_closest_to_zero(std::vector<int> ts)
{
    // Write your code here
    if(ts.empty()){
        std::cout << "EMPTY" << std::endl;
        return 0;
    }
    std::sort(ts.begin(), ts.end());
    int maxSize = 10000;
    int closestToZero = ts[0];
    for(int i = 1; i <= maxSize; i++) {
        // if(ts[i] == 0) {
        //     std::cout << "ZERO" << endl;
        //     closestToZero = ts[i];
        //     return closestToZero;
        // }
        std::cout << "ts[" << i << "] = " << ts[i] << std::endl;
        if(std::abs(ts[i]) != std::abs(closestToZero)) {
            if(ts[i] < 0 && closestToZero < ts[i]) {
                closestToZero = ts[i];
            }
            if(ts[i] > 0) {
              if(std::abs(closestToZero) > ts[i]){
                closestToZero = ts[i];
              }
                return closestToZero;
            }
        } else {
            closestToZero = (closestToZero > ts[i]) ? closestToZero : ts[i];
            return closestToZero;
        }
    }
    return closestToZero;
}
bool codeTest::exists(int ints[], int size, int k)
{
    std::sort(ints, ints + size);

    for(int i = 0; i < size; i++){
        if(ints[i] > k)
            return false;
        if(ints[i] == k)
            return true;
        // std::cout << "i = " << i << std::endl;
    }
    return false;
}

bool codeTest::existsBS(int ints[], int size, int k) {
    std::sort(ints, ints + size);
    
    return std::binary_search(ints , ints + size, k);
}


std::vector<int> filter_duplicates(std::vector<int> data)
{
    // Write your code here
    // To debug: cerr << "Debug messages..." << endl;
    
    if(data.size() == 0 || data.size() == 1)
        return data;
    std::vector<int> filteredArr;
    for(int item : data)
    {
        if(std::find(filteredArr.begin(), filteredArr.end(), item) != filteredArr.end())
        filteredArr.emplace_back(item);
    }
    return filteredArr;
}

int find_smallest_interval(std::vector<int> numbers)
{
    int smallestInterval = -1;
    for(int i = 0 ; numbers.size(); i++){
        for(int j = 0; j < numbers.size(); j++){
            if((numbers[i] - numbers[j]) > 0 && (numbers[i] - numbers[j]) < smallestInterval)
                     smallestInterval = (numbers[i] - numbers[j]);
        }
    }
    return smallestInterval;
}


codeTest::Node* find(int v, codeTest::Node* root){
    codeTest::Node* node = root->left;
    while(node != NULL && node->value != v) {
        if(node->value < v)
            node = node->right;
         else
            node = node->left;
    }
    return node;
}

//calc the sum between two intervals
int calc(const std::vector<int>& array, int n1, int n2) {
    return std::accumulate(array.begin() + n1 , array.begin() + n2, 0);
}

//-----------> MAIN for code test <-----------

//using namespace std;
//
//int main() {
//    //const int size = 100;
//    //int ints[size];
//    std::vector<int> ints = {1, 2, 3, 4, 5};
//    //for(int i = 0 ; i < size; i++) {
//    //    ints[i] = std::rand();
//    //    if(i == size - 1)
//    //        ints[i] = size - 1;
//    //}
//    //int val = size - 1;
//    //std::cout << "Has val = " << val << " | " << codeTest::existsBS(ints, size, val) << std::endl;
//    //std::cout << "Closer to Zero = " << codeTest::compute_closest_to_zero(ints) << std::endl;
//    std::cout << "sum = " << calc(ints, 0.0f, 5) << std::endl;
//
//
//    //int n;
//    //cin >> n; cin.ignore();
//    //vector<int> numbers;
//    //for (int i = 0; i < n; i++) {
//    //    int numbers_tmp;
//    //    cin >> numbers_tmp;
//    //    numbers.push_back(numbers_tmp);
//    //}
//    //// int std_out_fd = dup(1);
//    //// dup2(2, 1);
//    //int res = find_smallest_interval(ints);
//    ////dup2(std_out_fd, 1);
//    //cout << res << endl;
//
//
//    return 0;
//}
