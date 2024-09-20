/*
 * Project: server
 * Moudle:
 * File: ringlist.h
 * Created Date: 2024-05-10 17:23:23
 * Author: zhuzhu
 * Description: description
 * -----
 * todo: modified
 * -----
 * Copyright (c) 2024  Inc
 */
#ifndef RINGLIST_H
#define RINGLIST_H

#include <array>
namespace myweb::utils {

template <typename T>
class RingList {
  private:
    struct Node {
        T value;
        Node *next;
        Node *prev;
        explicit Node(const T &val) : value(val), next(nullptr), prev(nullptr) {}
    };

  public:
    RingList() : head(nullptr) {}

    ~RingList()
    {
        while (head != nullptr) {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push_back(const T &val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node *temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    Node *getHead() { return head; }

  private:
    Node *head;
};

template <typename T, std::size_t N>
class RingQueue {
  public:
    void push_back(T &&item)
    {
        if (!full()) [[likely]] {
            array_[tail_] = std::move(item);
            tail_ = (tail_ + 1) % N;
        }
    }

    [[nodiscard]] std::size_t size() const
    {
        if (tail_ >= head_) {
            return tail_ - head_;
        } else {
            return N - (head_ - tail_);
        }
    }

    [[nodiscard]] bool empty() const { return head_ == tail_; }

    [[nodiscard]] bool full() const { return ((tail_ + 1) % N) == head_; }

    // 没有判断array_[head]有效性
    T &front() { return array_[head_]; }

    const T &front() const { array_[head_]; }

    void pop_front() { head_ = (head_ + 1) % N; }

  private:
    std::array<T, N + 1> array_;
    typename std::array<T, N + 1>::size_type head_ = 0;
    typename std::array<T, N + 1>::size_type tail_ = 0;
    int count_ = 0;
};

} // namespace myweb::utils

#endif // RINGLIST_H