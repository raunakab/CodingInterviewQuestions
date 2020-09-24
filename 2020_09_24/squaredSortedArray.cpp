/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int square(int const val) {
    return val*val;
}

bool compareAbsValue(int const a, int const b) {
    return abs(a) < abs(b);
}

void printVector(vector<int> const & vecToPrint) {
    unsigned int const length(vecToPrint.size());
    for (unsigned int i(0); i<length; ++i) std::cout << vecToPrint[i] << " ";
    std::cout << "\n";
    return;
}

vector<int> sortedSquaredArray(vector<int> const & arr) {
    int const length(arr.size());
    int pos(0);
    int neg(0);

    while (pos < length) {
        if (arr[pos] >= 0) {
            break;
        } else {
            ++pos;
        }
    }
    neg = pos - 1;

    vector<int> result(length);
    int curr(0);

    while ((pos < length) && (neg >= 0)) {
        int pval(arr[pos]);
        int nval(arr[neg]);

        if (compareAbsValue(pval, nval)) {
            result[curr] = square(pval);
            ++pos;
        } else {
            result[curr] = square(nval);
            --neg;
        }

        ++curr;
    }

    for (; pos<length; ++pos, ++curr) result[curr] = square(arr[pos]);
    for (; neg>=0; --neg, ++curr) {
        result[curr] = square(arr[neg]);
    }

    return result;
}

int main() {
    vector<int> test_0({1, 2, 3, 4, 5});
    vector<int> test_1({-1, -2, -3, -4, -5});
    vector<int> test_2({-5, -1, 2, 4});
    
    vector<int> result_0(sortedSquaredArray(test_0));
    vector<int> result_1(sortedSquaredArray(test_1));
    vector<int> result_2(sortedSquaredArray(test_2));
    
    std::cout << "Test 0:\n";
    printVector(test_0);
    std::cout << "Result 0:\n";
    printVector(result_0);
    
    std::cout << "\n";
    
    std::cout << "Test 1:\n";
    printVector(test_1);
    std::cout << "Result 1:\n";
    printVector(result_1);
    
    std::cout << "\n";
    
    std::cout << "Test 2:\n";
    printVector(test_2);
    std::cout << "Result 2:\n";
    printVector(result_2);
    
    return 0;
}
