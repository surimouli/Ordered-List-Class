#ifndef TASK1_H
#define TASK1_H
#include <iostream>
#include <stdexcept>

class ListError : public std::exception {
private:
    std::string message;
public:
    ListError(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override { return message.c_str(); }
};

template <typename T>
class OrderedList {
protected:
    T** items;
    int capacity;
    int count;
public:
    int comparisons;
    int moves;

    OrderedList(int cap = 20) : capacity(cap), count(0), comparisons(0), moves(0) 
    {
        items = new T*[capacity];
        for (int i = 0; i < capacity; ++i) items[i] = nullptr;
    }
    virtual ~OrderedList() {
        for (int i = 0; i < count; ++i)
            delete items[i];
        delete[] items;
    }


    bool IsEmpty() const { return count == 0; }
    bool IsFull() const { return count == capacity; }
    void MakeEmpty() {
        for (int i = 0; i < count; ++i) {
            delete items[i];
            items[i] = nullptr;
        }
        count = 0;
        comparisons = moves = 0;

    }

    virtual void AddItem(const T& item) {
        if (IsFull()) throw ListError("List is full.");

        int i = 0;
        while (i < count && *items[i] < item) { comparisons++; i++; }
        for (int j = count; j > i; j--) { items[j] = items[j-1]; moves++; }
        items[i] = new T(item);
        count++;
    }

    virtual void RemoveItem(const T& item) {
        if (IsEmpty()) throw ListError("List is empty.");

        int i = 0;
        while (i < count && *items[i] != item) { comparisons++; i++; }
        if (i == count) throw ListError("Item not found.");

        delete items[i];
        for (int j = i; j < count-1; j++) { items[j] = items[j+1]; moves++; }

        items[count-1] = nullptr;
        count--;
    }

    void PrintContents() const
    {
        for (int i = 0; i < count; i++) std::cout << *items[i] << " ";
        std::cout << std::endl;
    }

    int Size() const { return count; }
};

#endif