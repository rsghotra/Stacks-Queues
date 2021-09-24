#ifndef STACK_H
#define STACK_H
#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
using namespace std;

class Stack {
  private:
    static bool isExpressionBalanced(string& exp);
    static string InfixToPostfixSimple(const string& exp);
    static bool isOperator(char ch);
    static int pre(char ch);
    static int outStackPre(char ch);
    static int inStackPre(char ch);
    static bool isOperatorComprehensive(char ch);
    static string InfixToPostfixComprehensive(const string& exp);
    static int EvaluatePostfix(const string& exp);
  public:
    static void isExpressionBalanced();
    static void InfixToPostfixSimple();
    static void InfixToPostfixComprehensive();
    static void EvaluatePostfix();
};


#endif