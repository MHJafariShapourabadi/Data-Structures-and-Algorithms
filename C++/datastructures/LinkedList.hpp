#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>

namespace mds
{
    template <class T>
    class LinkedList;
}

template <class T>
class mds::LinkedList
{
private:
    struct BaseNode;
    using pointer = BaseNode *;
    struct BaseNode
    {
        pointer left = nullptr;
        pointer right = nullptr;
        virtual ~BaseNode() = default;
    };

    struct Node : public BaseNode
    {
        T data;
        Node(T data)
            : BaseNode(), data(data)
        {
        }
        virtual ~Node() = default;
    };

    pointer base;
    pointer head;
    pointer tail;
    size_t length;

public:
    class iterator;

    LinkedList()
        : base(new BaseNode), head(nullptr), tail(nullptr), length(0)
    {
    }
    LinkedList(std::initializer_list<T> list)
        : LinkedList()
    {
        for (const T &data : list)
            push_back(data);
    }
    LinkedList(const LinkedList &other)
        : LinkedList()
    {
        if (other.head != nullptr)
        {
            // for (auto &&i : other)
            // {
            //     push_back(i);
            // }
            pointer p = other.head;
            pointer q = new Node(dynamic_cast<Node *>(p)->data);
            p = p->right;
            pointer r = nullptr;
            head = q;
            tail = q;
            q->left = base;
            q->right = base;
            base->right = q;
            base->left = q;
            ++length;
            while (p != other.base)
            {
                r = new Node(dynamic_cast<Node *>(p)->data);
                p = p->right;
                r->left = q;
                r->right = base;
                q->right = r;
                base->left = r;
                tail = r;
                ++length;
                q = r;
            }
        }
    }
    ~LinkedList()
    {
        clear();
    }

    void clear()
    {
        if (head != nullptr)
        {
            base->right = nullptr;
            base->left = nullptr;
            head->left = nullptr;
            tail->right = nullptr;
            pointer p = head;
            pointer q = head->right;
            head = nullptr;
            tail = nullptr;
            if (q != nullptr)
                q->left = nullptr;
            delete p;
            while (q != nullptr)
            {
                p = q;
                q = q->right;
                if (q != nullptr)
                    q->left = nullptr;
                delete p;
            }
            length = 0;
        }
    }

    LinkedList &operator=(const LinkedList &other)
    {
        clear();
        for (auto &&i : other)
        {
            push_back(i);
        }
        return *this;
    }

    void push_back(const T &data)
    {
        pointer p = new Node(data);

        if (head == nullptr)
        {
            head = p;
            tail = head;
            head->left = base;
            head->right = base;
            base->right = head;
            base->left = tail;
        }
        else
        {
            p->left = tail;
            p->right = base;
            tail->right = p;
            base->left = p;
            tail = p;
        }
        ++length;
    }

    template <class... Ts>
    void push_back(const T &data, const Ts &...rest)
    {
        push_back(data);
        push_back(rest...);
    }

    void push_front(const T &data)
    {
        pointer p = new Node(data);
        if (head == nullptr)
        {
            head = p;
            tail = head;
            head->left = base;
            head->right = base;
            base->right = head;
            base->left = tail;
        }
        else
        {
            p->right = head;
            p->left = base;
            head->left = p;
            base->right = p;
            head = p;
        }
        ++length;
    }

    template <class... Ts>
    void push_front(const T &data, const Ts &...rest)
    {
        push_front(rest...);
        push_front(data);
    }

    bool pop_back()
    {
        if (tail != nullptr)
        {
            if (tail != head)
            {
                pointer p = tail;
                tail = tail->left;
                tail->right = base;
                base->left = tail;
                delete p;
                --length;
                return true;
            }
            else
            {
                pointer p = tail;
                tail = nullptr;
                head = nullptr;
                base->right = nullptr;
                base->left = nullptr;
                delete p;
                --length;
                return true;
            }
        }
        else
        {
            return false;
        }
    }

    bool pop_front()
    {
        if (head != nullptr)
        {
            if (head != tail)
            {
                pointer p = head;
                head = head->right;
                head->left = base;
                base->right = head;
                delete p;
                --length;
                return true;
            }
            else
            {
                pointer p = head;
                head = nullptr;
                tail = nullptr;
                base->right = nullptr;
                base->left = nullptr;
                delete p;
                --length;
                return true;
            }
        }
        else
        {
            return false;
        }
    }

    iterator insert(iterator where, const T &data)
    {
        iterator now = nullptr;

        if (where.ptr == head)
        {
            push_front(data);
            now = head;
        }
        else if (where.ptr == base)
        {
            push_back(data);
            now = base;
        }
        else
        {
            pointer p = new Node(data);
            p->left = where.ptr->left;
            p->right = where.ptr;
            where.ptr->left->right = p;
            where.ptr->left = p;
            now = p;
            ++length;
        }

        return now;
    }

    iterator insert(iterator where, std::initializer_list<T> list)
    {
        for (const T *iter = list.end() - 1; iter != list.begin() - 1; --iter)
        {
            const T &data = *iter;
            where = insert(where, data);
        }
        return where;
    }

    iterator erase(const iterator where)
    {
        iterator now = nullptr;

        if (head != nullptr)
        {
            if (where.ptr == head)
            {
                pop_front();
                now = head;
            }
            else if (where.ptr == tail)
            {
                pop_back();
                now = tail;
            }
            else if (where.ptr == base)
            {
                now = base;
            }
            else
            {
                pointer p = where.ptr->right;
                p->left = where.ptr->left;
                p->left->right = p;
                delete where.ptr;
                --length;
                now = p;
            }
        }

        if (head == nullptr)
            now = base;

        return now;
    }

    iterator erase(const iterator first_arg, const iterator second_arg)
    {
        iterator now = first_arg;
        while (now != second_arg)
            now = erase(now);
        return now;
    }

    T back() const
    {
        if (tail == nullptr)
        {
            throw std::exception("Empty list");
        }
        return dynamic_cast<Node *>(tail)->data;
    }

    T front() const
    {
        if (head == nullptr)
        {
            throw std::exception("Empty list");
        }
        return dynamic_cast<Node *>(head)->data;
    }

    size_t size() const
    {
        return length;
    }

    T &operator[](size_t index)
    {
        if (index >= length)
            throw std::exception("Index out of range");

        pointer p = head;
        for (size_t i = 0; i < index; ++i)
            p = p->right;
        return dynamic_cast<Node *>(p)->data;
    }

    iterator begin() const
    {
        return iterator(head);
    }

    iterator end() const
    {
        return iterator(base);
    }

    const iterator cbegin() const
    {
        return iterator(head);
    }

    const iterator cend() const
    {
        return iterator(base);
    }

    void reverse()
    {
        if (head != nullptr)
        {
            base->right = tail;
            base->left = head;
            tail = head;
            pointer p = head;
            pointer q = head->right;
            pointer r = head->right->right;
            p->right = base;
            p->left = q;
            while (q != base)
            {
                q->right = p;
                q->left = r;
                p = q;
                q = r;
                r = r->right;
            }
            head = p;
        }
    }

    template <class T>
    friend LinkedList operator+(const LinkedList<T> &rhs, const LinkedList<T> &lhs)
    {
        LinkedList<T> new_list;
        for (auto &&i : rhs)
        {
            new_list.push_back(i);
        }
        for (auto &&i : lhs)
        {
            new_list.push_back(i);
        }

        return new_list;
    }

    friend bool operator==(const LinkedList<T> &rhs, const LinkedList<T> &lhs)
    {
        if (rhs.size() != lhs.size())
            return false;
        for (auto iter_r = rhs.begin(), iter_l = lhs.begin(); iter_r != rhs.end() && iter_l != lhs.end(); ++iter_r, ++iter_l)
        {
            if (*iter_r != *iter_l)
                return false;
        }
        return true;
    }

    friend std::ostream &
    operator<<(std::ostream &os, const LinkedList<T> &ls)
    {
        os << "[";
        if (ls.head != nullptr)
        {
            pointer p = ls.head;
            while (p != ls.tail)
            {
                os << dynamic_cast<Node *>(p)->data;
                os << ", ";
                p = p->right;
            }
            os << dynamic_cast<Node *>(p)->data;
        }
        os << "]";
        return os;
    }
};

template <class T>
class mds::LinkedList<T>::iterator
{
private:
    pointer ptr;

public:
    friend class LinkedList;
    using iterator_category = std::bidirectional_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = T;

    iterator(pointer ptr)
        : ptr(ptr)
    {
    }

    T &operator*() const
    {
        return dynamic_cast<Node *>(ptr)->data;
    }

    T *operator->() const
    {
        return &(dynamic_cast<Node *>(ptr)->data);
    }

    iterator &operator++()
    {
        ptr = ptr->right;
        return *this;
    }

    iterator operator++(int)
    {
        iterator tmp = *this;
        ptr = ptr->right;
        return tmp;
    }

    iterator &operator--()
    {
        ptr = ptr->left;
        return *this;
    }

    iterator operator--(int)
    {
        iterator tmp = *this;
        ptr = ptr->left;
        return tmp;
    }

    friend iterator operator+(const iterator &iter, const difference_type &d)
    {
        iterator tmp = iter;
        for (size_t i = 0; i < d; ++i)
            ++tmp;
        return tmp;
    }
    friend iterator operator+(const difference_type &d, const iterator &iter)
    {
        iterator tmp = iter;
        for (size_t i = 0; i < d; ++i)
            ++tmp;
        return tmp;
    }

    friend iterator operator-(const iterator &iter, const difference_type &d)
    {
        iterator tmp = iter;
        for (size_t i = 0; i < d; ++i)
            --tmp;
        return tmp;
    }
    friend iterator operator-(const difference_type &d, const iterator &iter)
    {
        iterator tmp = iter;
        for (size_t i = 0; i < d; ++i)
            --tmp;
        return tmp;
    }

    friend bool operator==(const iterator &lhs, const iterator &rhs)
    {
        return lhs.ptr == rhs.ptr;
    }

    friend bool operator!=(const iterator &lhs, const iterator &rhs)
    {
        return lhs.ptr != rhs.ptr;
    }
};

#endif