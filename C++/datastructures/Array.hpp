#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <vector>

namespace mds
{
    namespace array
    {
        template <class T>
        int linear_search(std::vector<T> arr, T key)
        {
            for (size_t i = 0; i < arr.size(); i++)
            {
                if (arr[i] == key)
                {
                    return i;
                }
            }
            return -1;
        }

        template <class T>
        int binary_search_recursive(std::vector<T> arr, size_t low, size_t high, T key)
        {
            size_t mid = static_cast<size_t>((low + high) / 2);
            if (low <= high)
            {
                if (key == arr[mid])
                    return mid;

                if (key < arr[mid])
                    return binary_search_recursive(arr, low, mid - 1, key);

                if (key > arr[mid])
                    return binary_search_recursive(arr, mid + 1, high, key);
            }
            return -1;
        }
        template <class T>
        int binary_search_recursive(std::vector<T> arr, T key)
        {
            return binary_search_recursive(arr, 0, arr.size() - 1, key);
        }

        template <class T>
        int binary_search_iterative(std::vector<T> arr, size_t low, size_t high, T key)
        {
            size_t mid{0};

            while (low <= high)
            {
                mid = static_cast<size_t>((low + high) / 2);

                if (key == arr[mid])
                    return mid;

                else if (key < arr[mid])
                    high = mid - 1;

                else
                    low = mid + 1;
            }
            return -1;
        }
        template <class T>
        int binary_search_iterative(std::vector<T> arr, T key)
        {
            return binary_search_iterative(arr, 0, arr.size() - 1, key);
        }
    }
}

#endif