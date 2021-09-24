#ifndef STACKADT_H
#define STACKADT_H
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class ArrayStack {
  private:
    //  ___
    // |size|
    // |top |   _ _ _ _ _ _ _
    // |_S__|->|_|_|_|_|_|_|_|
    int size;
    int top;
    int* S;
  public:
    ArrayStack(int size) {
      this->size = size;
      this->top = -1;
      this->S = new int[this->size];
    }
    virtual bool isEmpty() {
      if(this->top == -1) return true;
      return false;
    }

    virtual bool isFull() {
      if(this->top == this->size-1) return true;
      return false;
    }

    virtual void push(int num) {
      if(!isFull()) {
        this->top++;
        this->S[this->top] = num;
      } else {
        cout << "Stack is full" << endl;
      }
    }

    virtual int pop() {
      int x = -1;
      if(!isEmpty()) {
        x =this->S[this->top];
        this->top--;
      }
      return x;
    }

    virtual int peek(int pos) {
      if(this->top - pos + 1 < 0) {
        cout << "Invalid index is given" << endl;
        return -1;
      }
      return this->S[this->top - pos + 1];
    }
};

class ListNode {
  public:
    ListNode* next;
    int data;
};

class LLStack {
  private:
    ListNode* top;
  public:
    LLStack() {
      this->top = nullptr;
    }

    bool isEmpty() {
      if(this->top == 0){
        cout << "Stack is Empty" << endl;
        return true;
      }
      return false;
    }

    bool isFull() {
      ListNode* node = new ListNode();
      if(node == 0) {
        cout << "Stack is full because Computer's heap is full" << endl;
        return true;
      }
      return false;
    }

    void push(int num) {
      if(!isFull()) {
        ListNode* node = new ListNode();
        node->data = num;
        node->next = top;
        top = node;
      }
    }

    int pop() {
      int x = -1;
      if(!isEmpty()) {
        ListNode* ptr = this->top;
        x = ptr->data;
        top = top->next;
        delete ptr;
        ptr = 0;
      }
      return x;
    }

    int stackTop() {
      int x = -1;
      if(this->top) {
        x = this->top->data;
      }
      return x;
    }

    int peek(int pos) {
      int x = -1;
      ListNode* ptr = this->top;
      for(int i = 0; i < pos - 1 && ptr != 0; i++) {
        ptr = ptr->next;
      }
      if(ptr != 0) {
        x = ptr->data;
      }
      return x;
    }
};



int driver() {
  ArrayStack stk(5);
  stk.push(2);
  stk.push(4);
  stk.push(5);
  stk.push(7);
  stk.push(10);
  stk.push(12);
  cout << stk.pop() << endl;
  cout << stk.peek(3) << endl;
  //Stack using LL
  int A[] = {1, 3, 5, 7, 9};
 
  LLStack lStk;

  // Populate stack
  for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
      lStk.push(A[i]);
  }

  cout << "Stack peek at 3rd: " << lStk.peek(3) << endl;
  cout << "Stack peek at 10th: " << lStk.peek(10) << endl;
  cout << "Stack top: " << lStk.stackTop() << endl;
  cout << "Stack full: " << lStk.isFull() << endl;
  cout << "Stack empty: " << lStk.isEmpty() << endl;

  // Pop out elements from stack
  cout << "Popped: " << flush;
  for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
      cout << lStk.pop() << ", " << flush;
  }
  cout << endl;

  // Underflow
  cout << lStk.pop() << endl;

  return 0;
}
#endif