#include <iostream>
#include <memory>
#include <vector>
#include <deque>
#include "./datastructures/Array.hpp"
#include "./datastructures/SparseMatrix.hpp"
#include "./datastructures/LinkedList.hpp"

// using namespace std;
using std::cout, std::cin, std::endl;

int main()
{
    cout << std::boolalpha;
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
    // mds::SparseMatrix sm{
    //     {1, 0, 0, 0, 1, 0},
    //     {0, 0, 0, 0, 1, 0},
    //     {0, 1, 0, 0, 0, 0},
    //     {2, 0, 0, 0, 0, 0},
    //     {0, 0, 0, 3, 0, 0},
    //     {0, 0, 0, 0, 0, 1}};

    // cout << sm << endl;

    // sm.transpose();

    // cout << sm << endl;

    // sm.transpose();

    // cout << sm << endl;

    /***************************************************************************/
    // mds::LinkedList ls{2, 8, 5, 4, 7, 3, 9, 12};

    // for (auto &&i : ls)
    // {
    //     cout << i << endl;
    // }

    // cout << ls << endl;
    // cout << ls.size() << endl;

    // ls.clear();
    // cout << ls << endl;
    // cout << ls.size() << endl;

    // ls.push_back(1, 2, 3);
    // cout << ls << endl;
    // cout << ls.size() << endl;

    // ls.push_front(15, 16, 17);
    // cout << ls << endl;
    // cout << ls.size() << endl;

    // while (ls.pop_back())
    // {
    //     cout << ls << endl;
    //     cout << ls.size() << endl;
    // }

    // ls.push_back(1, 2, 3);
    // cout << ls << endl;
    // cout << ls.size() << endl;

    // ls.push_front(15, 16, 17);
    // cout << ls << endl;
    // cout << ls.size() << endl;

    // while (ls.pop_front())
    // {
    //     cout << ls << endl;
    //     cout << ls.size() << endl;
    // }

    /***************************************************************************/

    // mds::LinkedList<int> ls;

    // cout << ls << endl;
    // cout << ls.size() << endl;

    // ls.insert(ls.begin(), 2);
    // cout << ls << endl;
    // cout << ls.size() << endl;

    // ls.insert(ls.begin(), {6, 2, 4, 3, 5});
    // cout << ls << endl;
    // cout << ls.size() << endl;

    // ls.insert(ls.begin() + 3, {7, 7, 7});
    // cout << ls << endl;
    // cout << ls.size() << endl;

    // ls.insert(ls.end(), {8, 8, 8});
    // cout << ls << endl;
    // cout << ls.size() << endl;

    /***************************************************************************/
    // std::deque<int> deq{2, 5, 4, 8, 6};
    // // deq.erase(deq.begin(), deq.begin() + 5);
    // deq.erase(deq.begin(), deq.end());
    // for (auto &&i : deq)
    // {
    //     cout << i << endl;
    // }

    // mds::LinkedList ls{2, 5, 4, 8, 6};
    // ls.erase(ls.begin(), ls.begin() + 5);
    // // ls.erase(ls.begin(), ls.end());
    // cout << ls << endl;
    // cout << ls.size() << endl;
    /***************************************************************************/

    // mds::LinkedList ls1 = {2, 3, 6, 4, 5};
    // cout << ls1 << endl;
    // cout << ls1.size() << endl;
    // mds::LinkedList ls2 = ls1;
    // // ls2.insert(ls2.begin() + 2, 88);
    // cout << ls2 << endl;
    // cout << ls2.size() << endl;
    // cout << (ls1 == ls2) << endl;

    // ls1[0] = 77;

    // cout << ls1 << endl;
    // cout << ls1.size() << endl;
    // cout << ls2 << endl;
    // cout << ls2.size() << endl;
    // cout << (ls1 == ls2) << endl;

    // ls2 = ls1;

    // cout << ls1 << endl;
    // cout << ls1.size() << endl;
    // cout << ls2 << endl;
    // cout << ls2.size() << endl;
    // cout << (ls1 == ls2) << endl;
    /***************************************************************************/
    // mds::LinkedList ls = {2, 3, 6, 4, 5};
    // cout << ls << endl;
    // cout << ls.size() << endl;
    // cout << ls.front() << endl;
    // cout << ls.back() << endl;

    // ls.reverse();
    // cout << ls << endl;
    // cout << ls.size() << endl;
    // cout << ls.front() << endl;
    // cout << ls.back() << endl;
    /***************************************************************************/

    return 0;
}