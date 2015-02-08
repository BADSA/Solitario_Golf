#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;
static void Assert(bool val, std::string s) {
   if (!val) { // Assertion failed -- close the program
       std::cout << "Assertion Failed: " << s << std::endl;
        exit(-1);
    }
}
static int irand(int min, int max) {
    return ((double)rand() / ((double)RAND_MAX + 1.0)) * (max - min + 1) + min;
}

template <typename E> class List { // List ADT
    private:
    void operator =(const List&) {}
    // Protect assignment
    List(const List&) {}
    // Protect copy constructor
    public:
    List() {}
    // Default constructor
    virtual ~List() {} // Base destructor
    // Clear contents from the list, to make it empty.
    virtual void clear() = 0;
    // Insert an element at the current location.
    // item: The element to be inserted
    virtual void insert(const E& item) = 0;
    // Append an element at the end of the list.
    // item: The element to be appended.
    virtual void append(const E& item) = 0;
    // Remove and return the current element.
    // Return: the element that was removed.
    virtual E remove() = 0;
    // Set the current position to the start of the list
    virtual void moveToStart() = 0;
    // Set the current position to the end of the list
    virtual void moveToEnd() = 0;
    // Move the current position one step left. No change
    // if already at beginning.
    virtual void prev() = 0;
    // Move the current position one step right. No change
    // if already at end.
    virtual void next() = 0;
    // Return: The number of elements in the list.
    virtual int length() const = 0;
    // Return: The position of the current element.
    virtual int currPos() const = 0;
    // Set current position.
    // pos: The position to make current.
    virtual void moveToPos(int pos) = 0;
    // Return: The current element.
    virtual const E& getValue() const = 0;
    virtual void print()=0;
    virtual void shuffle()=0;
    };

template <typename E> // Array-based list implementation
class AList : public List<E> {
    private:
    int maxSize; // Maximum size of list
    int listSize;// Number of list items now
    int curr; // Position of current element
    E* listArray;// Array holding list elements
    public:
    AList(int size) { // Constructor
        maxSize = size;
        listSize = curr = 0;
        listArray = new E[maxSize];
    }
    ~AList() { delete [] listArray; } // Destructor
        void clear() {
        delete [] listArray;
        listSize = curr = 0;
        listArray = new E[maxSize];
    }
    void insert(const E& it) {
        Assert(listSize < maxSize, "List capacity exceeded");
        for(int i=listSize; i>curr; i--) // Shift elements up
        listArray[i] = listArray[i-1]; //to make room
        listArray[curr] = it;
        listSize++;// Increment list size

    }
    void append(const E& it) { // Append "it"
        Assert(listSize < maxSize, "List capacity exceeded");
        listArray[listSize++] = it;
    }

    E remove() {// Remove and return the current element.
        Assert((curr>=0) && (curr < listSize), "No element");
        E it = listArray[curr];// Copy the element
        for(int i=curr; i<listSize-1; i++) // Shift them down
        listArray[i] = listArray[i+1];
        listSize--; // Decrement size
        return it;
    }
    void moveToStart() { curr = 0; } // Reset position
    void moveToEnd() { curr = listSize-1; } // Set at end
    void prev() { if (curr != 0) curr--; } // Back up
    void next() { if (curr < listSize) curr++; } // Next
    int length() const { return listSize; } // Return list size
    int currPos() const { return curr; } // Return current position
    void moveToPos(int pos) { // Set current list position to "pos"
    Assert ((pos>=0)&&(pos<=listSize), "Pos out of range");
        curr = pos;
    }
    const E& getValue() const { // Return current element
        Assert((curr>=0)&&(curr<listSize),"No current element");
        return listArray[curr];
    }
    void print(){
        for (curr=0;curr<listSize;curr++){
            std::cout<<listArray[curr]<<std::endl;
        }
    }
    void shuffle(){
        srand(time(0));
        for (int i=0;i<500;i++){
            int temp=irand(0,maxSize-1);
           // cout<<temp<<" ";
            int temp2=irand(0,maxSize-1);
           // cout<<temp2<<" ";
            E it=listArray[temp2];
            listArray[temp2]=listArray[temp];
            listArray[temp]=it;
        }
    }
};

    template <typename E> class Stack {
    private:
    void operator =(const Stack&) {}
    // Protect assignment
    Stack(const Stack&) {}
    // Protect copy constructor
    public:
    Stack() {}// Default constructor
    virtual ~Stack() {}// Base destructor
    virtual void clear() = 0;    // Push an element onto the top of the stack.
    virtual void push(const E& it) = 0;// it: The element being pushed onto the stack.
    virtual E pop() = 0; // Remove the element at the top of the stack. Return: The element at the top of the stack.
    virtual const E& topValue() const = 0; // Return: A copy of the top element.
    virtual int length() const = 0; // Return: The number of elements in the stack.

};
    template <typename E> class AStack: public Stack<E> {// Array-based stack implementation
    private:
    int maxSize; // Maximum size of stack
    int top; // Index for top element
    E *listArray; // Array holding stack elements
    public:
    AStack(int size) // Constructor
    { maxSize = size; top = 0; listArray = new E[size]; }
    ~AStack() { delete [] listArray; } // Destructor
    void clear() { top = 0; } // Reinitialize
    void push(const E& it) { // Put "it" on stack
       Assert(top != maxSize, "Stack is full");
    listArray[top++] = it;
    }
    E pop() {  // Pop top element
    Assert(top != 0, "Stack is empty");
    return listArray[--top];
    }
    const E& topValue() const { // Return top element
    Assert(top != 0, "Stack is empty");
    return listArray[top-1];
    }
    int length() const { return top; }
};
#endif // ESTRUCTURAS_H
