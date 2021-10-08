#ifndef SPARSEMATRIX_HPP
#define SPARSEMATRIX_HPP

#include <iostream>
#include <vector>

namespace mds
{
    class SparseMatrix
    {
    private:
        struct MatrixTerm
        {
            size_t row{0};
            size_t col{0};
            int value{0};
        };

        std::vector<MatrixTerm> arr;
        size_t rows;
        size_t cols;

    public:
        SparseMatrix(std::initializer_list<std::initializer_list<int>> list)
            : arr(), rows(list.size()), cols(list.begin()->size())
        {
            // arr.emplace_back(list.size(), list.begin()->size(), 0);
            size_t i = 0, j = 0;
            for (auto row = list.begin(); row != list.end(); ++i, ++row)
            {
                j = 0;
                for (auto col = row->begin(); col != row->end(); ++j, ++col)
                {
                    int value = *col;
                    if (value != 0)
                    {
                        arr.emplace_back(i, j, value);
                    }
                }
            }
        }

        size_t size() const
        {
            return arr.size();
        }

        void transpose()
        {
            std::vector<size_t> Rowsize(cols);
            std::vector<size_t> Rowstart(cols);

            for (size_t i = 0; i < size(); i++)
            {
                ++Rowsize.at(arr.at(i).col);
            }

            Rowstart.at(0) = 0;
            for (size_t i = 1; i < cols; i++)
            {
                Rowstart.at(i) = Rowstart.at(i - 1) + Rowsize.at(i - 1);
            }

            std::vector<MatrixTerm> t_arr(size());

            for (size_t i = 0; i < size(); i++)
            {
                size_t col = arr.at(i).col;
                size_t index = Rowstart.at(col);
                t_arr.at(index).row = arr.at(i).col;
                t_arr.at(index).col = arr.at(i).row;
                t_arr.at(index).value = arr.at(i).value;
                ++Rowstart.at(col);
            }

            arr = t_arr;
        }

        friend std::ostream &operator<<(std::ostream &os, const SparseMatrix sm)
        {
            std::cout << "SparseMatrix with " << sm.rows << " rows, " << sm.cols << " columns, "
                      << sm.size() << " values" << std::endl;
            std::cout << "   row"
                      << "   col"
                      << "   value" << std::endl;

            size_t n = 0;
            for (auto &&i : sm.arr)
            {
                std::cout << n << " | " << i.row << ",     " << i.col << ",      " << i.value << std::endl;
                ++n;
            }

            return os;
        }
    };
}

#endif