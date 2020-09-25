#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

// int uniquePaths(int m, int n) {
//     if (!m || !n) return -1;

//     std::vector<std::vector<int>> matrix(n);
//     for (int i(0); i<n; ++i) {
//         std::vector<int> column_i(m,-1);
//         matrix[i] = column_i;
//     }
    
//     int & start(matrix[0][0]);
//     int & finish(matrix[n-1][m-1]);
    
//     start = 1;

//     for (int j(0); j<n; ++j) {
//         for (int i(0); i<m; ++i) {
//             int & curr(matrix[j][i]);

//             int left_prev((j>0) ? matrix[j-1][i] : 0);
//             int top_prev((i>0) ? matrix[j][i-1] : 0);
        
//             if (curr == -1) curr = left_prev + top_prev;
//         }
//     }

//     return finish;
// }

template<class T>
void swap(T & a, T & b) {
    T placeHolder(a);
    a = b;
    b = placeHolder;
    return;
}

int uniquePaths(int m, int n) {
    if (!m || !n) return -1;
    if (m > n) swap<int>(m,n);

    vector<int> * prevCol = new vector<int>(m,0);
    vector<int> * currCol = new vector<int>(m);
    
    int & leftOfStart((*prevCol)[0]);
    leftOfStart = 1;
    
    for (int j(0); j<n; ++j) {
        for (int i(0); i<m; ++i) {
            int topPrev((i>0) ? (*currCol)[i-1] : 0);
            int leftPrev((*prevCol)[i]);

            (*currCol)[i] = topPrev + leftPrev;
        }

        swap<vector<int> *>(currCol,prevCol);
    }
    
    return (*prevCol)[m-1];
}

int main() {
    int test0(uniquePaths(0,0));
    int test1(uniquePaths(1,1));
    int test2(uniquePaths(2,2));
    int test3(uniquePaths(3,7));

    printf("%i\n",test0);
    printf("%i\n",test1);
    printf("%i\n",test2);
    printf("%i\n",test3);

    return 0;
}