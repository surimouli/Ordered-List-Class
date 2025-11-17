#ifndef TASK2_H
#define TASK2_H

#include "Task1.h"

template <typename T>
class EndOrderedList : public OrderedList<T> {
public:
    using OrderedList<T>::Size;
    using OrderedList<T>::comparisons;
    using OrderedList<T>::moves;

    EndOrderedList(int cap = 20) : OrderedList<T>(cap) {

    }

    void AddItem(const T& item) override {
        if (this->IsFull()) throw ListError("List is full.");

        int i = this->count - 1;
        while (i >= 0 && *this->items[i] > item) { this->comparisons++; i--; }
        for (int j = this->count; j > i+1; j--) { this->items[j] = this->items[j-1]; this->moves++; }
        this->items[i+1] = new T(item);
        this->count++;
    }
};
#endif