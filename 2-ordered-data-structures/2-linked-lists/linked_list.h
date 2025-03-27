#pragma once

#include <iostream>
#include "list_node.h"

template <typename T>
class LinkedList
{
public:
    LinkedList();
    ~LinkedList();

    void push_front(T *data);
    void push_back(T *data);
    void insert_at(unsigned index, T *data);
    T *remove_at(unsigned index);
    T *pop_front();
    T *pop_back();

    bool is_empty() const;
    size_t size() const;

    T *front() const;
    T *back() const;
    T *operator[](unsigned index);

    bool contains(T *data) const;
    void remove(T *data);
    void clear();
    void print() const;

private:
    ListNode<T> *head_;
    ListNode<T> *tail_;
    size_t size_;
};

template <typename T>
LinkedList<T>::LinkedList() : size_(0), head_(nullptr), tail_(nullptr) {}
template <typename T>
LinkedList<T>::~LinkedList() { clear(); }

template <typename T>
void LinkedList<T>::push_front(T *data)
{
    // Create new node
    ListNode<T> *new_node = new ListNode<T>(data);
    size_++;

    // If head_ is null, it means that this is the first node
    if (!head_)
    {
        head_ = tail_ = new_node;
        return;
    }

    // Otherwise, insert at front and update head
    new_node->next_ = head_;
    head_ = new_node;
}

template <typename T>
void LinkedList<T>::push_back(T *data)
{
    // Create new node
    ListNode<T> *new_node = new ListNode<T>(data);
    size_++;

    // If head_ is null, it means that this is the first node
    if (!head_)
    {
        head_ = tail_ = new_node;
        return;
    }

    // Otherwise, insert at end and update tail
    tail_->next_ = new_node;
    tail_ = tail_->next_;
}

template <typename T>
T *LinkedList<T>::pop_front()
{
    if (is_empty())
        throw std::runtime_error("Cannot pop from an empty list");

    ListNode<T> *to_delete = head_;
    T *data = to_delete->data_;

    // Update head
    if (size_ == 1)
        head_ = tail_ = nullptr;
    else
        head_ = head_->next_;

    // Decrement size and delete node
    size_--;
    delete to_delete;
    return data;
}

template <typename T>
T *LinkedList<T>::pop_back()
{
    if (is_empty())
        throw std::runtime_error("Cannot pop from an empty list");

    ListNode<T> *to_delete = tail_;
    T *data = to_delete->data_;

    // Update tail
    if (size_ == 1)
        head_ = tail_ = nullptr;
    else
    {
        // Move curr to the last but one node
        ListNode<T> *curr = head_;
        while (curr->next_->next_)
            curr = curr->next_;

        tail_ = curr;
        tail_->next_ = nullptr;
    }

    // Decrement size and delete node
    size_--;
    delete to_delete;
    return data;
}

template <typename T>
void LinkedList<T>::insert_at(unsigned index, T *data)
{
    if (index > size_)
        throw std::runtime_error("Invalid index");

    if (index == 0)
    {
        push_front(data);
        return;
    }

    if (index == size_)
    {
        push_back(data);
        return;
    }

    // At this point size is atleast 2, as one of the above cases
    // would have been applicable for sizes 0, 1

    // Move curr to the node after which the new node has to be inserted
    ListNode<T> *curr = head_;
    for (size_t i = 0; i < index - 1; i++)
        curr = curr->next_;

    // Insert after curr
    // Create new node
    ListNode<T> *new_node = new ListNode<T>(data);
    size_++;
    new_node->next_ = curr->next_;
    curr->next_ = new_node;
}

template <typename T>
T *LinkedList<T>::remove_at(unsigned index)
{
    if (index >= size_)
        throw std::runtime_error("Invalid index");

    if (index == 0)
        return pop_front();

    // there won't be any overflows here because
    // size is atleast 2 as size 1 would be handled by above case
    if (index == size_ - 1)
        return pop_back();

    // At this point size is atleast 3, as one of the above cases
    // would have been applicable for sizes 0, 1, 2

    // Move curr to the element at index - 1
    // and delete the next element
    ListNode<T> *curr = head_;
    for (size_t i = 0; i < index - 1; i++)
        curr = curr->next_;

    // Delete node after curr
    // There would be atleast one node after the one we want to delete
    // as edge cases were handled already
    size_--;
    ListNode<T> *to_delete = curr->next_;
    T *data = to_delete->data_;
    curr->next_ = curr->next_->next_;
    delete to_delete;
    return data;
}

template <typename T>
T *LinkedList<T>::front() const
{
    if (is_empty())
        throw std::runtime_error("Cannot get data from an empty list");

    return head_->data_;
}

template <typename T>
T *LinkedList<T>::back() const
{
    if (is_empty())
        throw std::runtime_error("Cannot get data from an empty list");

    return tail_->data_;
}

template <typename T>
T *LinkedList<T>::operator[](unsigned index)
{
    if (index >= size_)
        throw std::runtime_error("Invalid index");

    // Move curr index number of times to get curr to the correct index
    ListNode<T> *curr = head_;
    for (int i = 0; i < index; i++)
    {
        curr = curr->next_;
    }

    return curr->data_;
}
template <typename T>
bool LinkedList<T>::is_empty() const { return size_ == 0; }

template <typename T>
size_t LinkedList<T>::size() const { return size_; }

template <typename T>
void LinkedList<T>::clear()
{
    ListNode<T> *curr = head_;
    while (curr)
    {
        ListNode<T> *next = curr->next_;
        delete curr;
        curr = next;
    }
    head_ = nullptr;
    tail_ = nullptr;
    size_ = 0;
}

template <typename T>
void LinkedList<T>::remove(T *data)
{
    if (is_empty())
        return;

    if (*(head_->data_) == *data)
    {
        pop_front();
        return;
    }

    if (*(tail_->data_) == *data)
    {
        pop_back();
        return;
    }

    size_--;
    ListNode<T> *prev = nullptr;
    ListNode<T> *curr = head_;
    while (curr)
    {
        if (*(curr->data_) == *data)
        {
            prev->next_ = curr->next_;
            delete curr;
            return;
        }
        prev = curr;
        curr = curr->next_;
    }
}

template <typename T>
bool LinkedList<T>::contains(T *data) const
{
    if (is_empty())
        return false;

    ListNode<T> *curr = head_;
    while (curr)
    {
        if (*(curr->data_) == *data)
            return true;
        curr = curr->next_;
    }

    return false;
}

template <typename T>
void LinkedList<T>::print() const
{
    ListNode<T> *curr = head_;
    while (curr)
    {
        std::cout << *(curr->data_) << " -> ";
        curr = curr->next_;
    }
    std::cout << std::endl;
}