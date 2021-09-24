#include "Stack.h"


bool Stack::isExpressionBalanced(string& exp) {
  stack<char> stk;
  unordered_map<char, char> mappings;
  mappings.insert({')', '('});
  mappings.insert({'}', '{'});
  mappings.insert({']', '['});
  for(int i = 0; i < exp.size(); i++) {
    if(!isdigit(exp[i])) {
      if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
        stk.push(exp[i]);
      } else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
          if(stk.empty() || mappings[exp[i]] != stk.top()) {
            return false;
          }
          stk.pop();
      }
    }
  }
  if(stk.empty()) return true;
  return false;
}

void Stack::isExpressionBalanced() {
    string A = "{([a+b]*[c-d])/e}";
    cout << isExpressionBalanced(A) << endl;
 
    string B = "{([a+b]}*[c-d])/e}";
    cout << isExpressionBalanced(B) << endl;
 
    string C = "{([{a+b]*[c-d])/e}";
    cout << isExpressionBalanced(C) << endl;
}

bool Stack::isOperator(char ch) {
  if(ch == '+' || ch == '-' || ch == '*' || ch == '/') {
    return true;
  }
  return false;
}

int Stack::pre(char ch) {
  if(ch == '+' || ch == '-') {
    return 1;
  }
  if(ch == '*' || ch == '/') {
    return 2;
  }
  return 0; //this will cover when stack is empty;
}


string Stack::InfixToPostfixSimple(const string& infix) {
  string postfix;
  stack<char> stk;
  int i = 0;

  while(i < infix.size()) {
    if(isOperator(infix[i])) {
      if(stk.empty() || pre(infix[i]) > pre(stk.top())) {
        stk.push(infix[i]);
        i++;
      } else {
        postfix += stk.top();
        stk.pop(); //not incrementing i
      }
    } else {
      postfix += infix[i];
      i++;
    }
  }
  while(stk.empty() == false) {
    postfix += stk.top();
    stk.pop();
  }
  return postfix;
}

void Stack::InfixToPostfixSimple() {
  string postfix = InfixToPostfixSimple("a+b*c-d/e");
  cout << "Postfixed Express: " << postfix << endl;
}

/*
Comprehensive Infix to Post fix

+,-| 1 | 2 | L-R
*,/| 3 | 4 | L-R
^  | 6 | 5 | R-L
(  | 7 | 0 | L-R
)  | 0 | ? | L-R

*/

bool Stack::isOperatorComprehensive(char ch) {
  if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '(' || ch == ')') {
    return true;
  }
  return false;
}

int Stack::outStackPre(char ch) {
  if(ch == '+' || ch == '-') return 1;
  if(ch == '*' || ch == '/') return 3;
  if(ch == '^') return 6;
  if(ch == '(') return 7;
  if(ch == ')') return 0;
  return -1;
}

int Stack::inStackPre(char ch) {
  if(ch == '+' || ch == '-') {
    return 2;
  }
  if(ch == '*' || ch == '/') {
    return 4;
  }
  if(ch == '^') {
    return 5;
  }
  if(ch == '(') {
    return 0;
  }
  return -1;
}

string Stack::InfixToPostfixComprehensive(const string& exp) {
  string postfix;
  stack<char> stk;
  int i = 0;
  while(i < exp.size()) {
    if(isOperatorComprehensive(exp[i])) {
      if(stk.empty() || outStackPre(exp[i]) > inStackPre(stk.top())) {
        stk.push(exp[i]);
        i++;
      } else if(outStackPre(exp[i]) < inStackPre(stk.top())) {
        postfix += stk.top();
        stk.pop();
      } else if(outStackPre(exp[i]) == inStackPre(stk.top())) {
        stk.pop();
        i++;
      }
    } else {
      postfix += exp[i];
      i++;
    }
  }
  while(stk.empty() == false) {
    postfix += stk.top();
    stk.pop();
  }
  return postfix;
}


void Stack::InfixToPostfixComprehensive() {
  string postfix = InfixToPostfixComprehensive("((a+b)*c)-d^e^f");
  cout << "Postfix Expression Comprehensive: " << postfix << endl;
}

/*
Evaluate Postfix Expression
*/

int Stack::EvaluatePostfix(const string& exp) {
  stack<int> stk;

  for(int i=0; i < exp.size(); i++) {
    if(isOperatorComprehensive(exp[i])) {
      int x2 = stk.top(); stk.pop();
      int x1 = stk.top(); stk.pop();
      switch(exp[i]) {
        case '+':
          stk.push(x1 + x2);
          break;
        case '-':
          stk.push(x1 - x2);
          break;
        case '/':
          stk.push(x1/x2);
          break;
        case '*':
          stk.push(x1*x2);
          break;
      }
    } else {
      //operand push onto stack
      stk.push(exp[i] - '0');
    }
  }
  return stk.top();
}

void Stack::EvaluatePostfix() {
  int postfix = EvaluatePostfix("234*+82/-");
  cout << "Postfix evaluated to: " << postfix << endl;
}

