#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <iostream>

template <typename T, int N>
class Array
{
public:
    T &operator[](int index);
    const T &operator[](int index) const;
    T &at(int index);
    const T &at(int index) const;
    T *data();
    const T *data() const;
    bool empty() const;
    int size() const;
    void fill(const T &value);
    void print() const;

private:
    T m_data[N];
};

template <typename T, int N>
T &Array<T, N>::operator[](int index)
{
    return m_data[index];
}

template <typename T, int N>
const T &Array<T, N>::operator[](int index) const
{
    return m_data[index];
}

template <typename T, int N>
T &Array<T, N>::at(int index)
{
    if (index >= N || index < 0)
    {
        throw std::out_of_range("Index out of range");
    }
    return m_data[index];
}

template <typename T, int N>
const T &Array<T, N>::at(int index) const
{
    if (index >= N || index < 0)
    {
        throw std::out_of_range("Index out of range");
    }
    return m_data[index];
}

template <typename T, int N>
T *Array<T, N>::data()
{
    return m_data;
}

template <typename T, int N>
const T *Array<T, N>::data() const
{
    return m_data;
}

template <typename T, int N>
bool Array<T, N>::empty() const
{
    return N == 0;
}

template <typename T, int N>
int Array<T, N>::size() const
{
    return N;
}

template <typename T, int N>
void Array<T, N>::fill(const T &value)
{
    for (int i = 0; i < N; ++i)
    {
        m_data[i] = value;
    }
}

template <typename T, int N>
void Array<T, N>::print() const
{
    for (int i = 0; i < N; ++i)
    {
        std::cout << m_data[i] << " ";
    }
    std::cout << std::endl;
}

#endif // ARRAY_HPP
