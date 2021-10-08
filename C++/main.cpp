#include <iostream>
#include <vector>
#include <queue>
#include "./datastructures/Array.hpp"
#include "./datastructures/SparseMatrix.hpp"

// using namespace std;
using std::cout, std::cin, std::endl;

int main()
{
    /***************************************************************************/
    // std::vector arr1{2, 8, 7, 5, 6};
    // std::vector arr2{4, 6, 8, 12, 14, 16, 21};

    // int n{0};
    // n = mds::array::linear_search(arr1, 7);
    // cout << n << endl;

    // n = mds::array::binary_search_recursive(arr2, 21);
    // cout << n << endl;

    // n = mds::array::binary_search_iterative(arr2, 21);
    // cout << n << endl;
    /***************************************************************************/
    mds::SparseMatrix sm{
        {1, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0, 0},
        {2, 0, 0, 0, 0, 0},
        {0, 0, 0, 3, 0, 0},
        {0, 0, 0, 0, 0, 1}};

    cout << sm << endl;

    sm.transpose();

    cout << sm << endl;

    sm.transpose();

    cout << sm << endl;

    /***************************************************************************/

    return 0;
}