#ifndef TASK3_H
#define TASK3_H
#include "Task1.h"

template <typename T>
class GapOrderedList : public OrderedList<T> {
public:
    using OrderedList<T>::Size;
    using OrderedList<T>::comparisons;
    using OrderedList<T>::moves;
    using OrderedList<T>::capacity;
    using OrderedList<T>::items;
    using OrderedList<T>::count;

    GapOrderedList(int cap = 20) : OrderedList<T>(cap) {}

    void AddItem(const T& item) override {
        if (this->IsFull()) throw ListError("List is full.");

        int pos = 0;
        while (pos < this->capacity && this->items[pos] != nullptr && *this->items[pos] < item) {
            this->comparisons++;
            pos++;
        }
        if (pos < this->capacity && this->items[pos] == nullptr) {
            this->items[pos] = new T(item);
        } 
        else {
            int i = this->capacity - 1;
            while (i > pos && this->items[i] == nullptr) i--;
            if (i == this->capacity - 1 && this->items[i] != nullptr) throw ListError("No room to insert with gaps.");
            for (int j = i+1; j > pos; j--) { this->items[j] = this->items[j-1]; this->moves++; }
            this->items[pos] = new T(item);
        }

        this->count++;
    }

    void RemoveItem(const T& item) override 
    {
        bool found = false;
        for (int i = 0; i < this->capacity; i++) {
            if (this->items[i] != nullptr && *this->items[i] == item) {
                delete this->items[i];
                this->items[i] = nullptr;
                this->count--;
                found = true;
                break;
            }
        }
        if (!found) throw ListError("Item not found.");
    }

    void PrintContentsWithGaps() const 
    {
        for (int i = 0; i < this->capacity; i++)
            if (this->items[i] != nullptr)
                std::cout << *this->items[i] << " ";
            else
                std::cout << "_ ";
        std::cout << std::endl;
    }
};
#endif
