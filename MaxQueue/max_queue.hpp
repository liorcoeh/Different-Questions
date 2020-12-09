/*
 * Implement a Queue that will have a function that gets the max value inside
 * of the queue in O(1).
 */

#include <iostream>

template <typename T>
class QueueMax
{
public:
    QueueMax();
    ~QueueMax();

    void Push(const T& value);
    void Pop();
    const T& Peek();
    size_t Size();
    bool IsEmpty();

    const T& GetMax();

private:
    T m_max;
    size_t m_capacity;
    size_t m_pop;
    size_t m_push;
    T* m_container;

    void Resize(size_t new_capacity);
    void FindMax();
};

template <typename T>
QueueMax<T>::QueueMax() : m_capacity(5), m_pop(0), m_push(0)
{
    m_container = new T[m_capacity];
}

template <typename T>
QueueMax<T>::~QueueMax()
{
    delete[] m_container;
}

template <typename T>
void QueueMax<T>::Push(const T& value)
{
    if (m_push == m_capacity)
    {
        Resize(m_capacity * 2);
    }

    if (IsEmpty())
    {
        m_max = value;
    }
    else if (m_max < value)
    {
        m_max = value;
    }

    m_container[m_push] = value;
    ++m_push;
}

template <typename T>
void QueueMax<T>::Pop()
{
    if (IsEmpty())
    {
        throw ("Queue is empty");
    }

    if (m_pop > (m_capacity / 2))
    {
        Resize(m_capacity / 2);
    }

    if (Peek() == m_max)
    {
        FindMax();
    }

    ++m_pop;
}

template <typename T>
const T& QueueMax<T>::Peek()
{
    return (m_container[m_pop]);
}

template <typename T>
size_t QueueMax<T>::Size()
{
    return (m_push - m_pop);
}

template <typename T>
bool QueueMax<T>::IsEmpty()
{
    return (0 == (m_push - m_pop));
}

template <typename T>
const T& QueueMax<T>::GetMax()
{
    return (m_max);
}

template <typename T>
void QueueMax<T>::Resize(size_t new_capacity)
{
    if (0 == new_capacity)
    {
        new_capacity = 1;
    }

    T* new_container = new T[new_capacity];

    for (size_t i = 0; i < Size(); ++i)
    {
        new_container[i] = m_container[m_pop + i];
    }

    m_capacity = new_capacity;
    m_push -= m_pop;
    m_pop = 0;

    delete[] m_container;
    m_container = new_container;

}

template <typename T>
void QueueMax<T>::FindMax()
{
    m_max = m_container[m_pop + 1];

    size_t i = 0;

    for (i = m_pop + 1; i < m_push; ++i)
    {
        if (m_max < m_container[i])
        {
            m_max = m_container[i];
        }
    }
}
