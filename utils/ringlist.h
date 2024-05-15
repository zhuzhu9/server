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

} // namespace myweb::utils

#endif // RINGLIST_H