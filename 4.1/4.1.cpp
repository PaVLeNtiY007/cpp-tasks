#include <iostream>
#include <stack>
#include <unordered_map>
#include <string>
#include <vector>

bool isValid(const std::string& s) {
    std::stack<char> stack;
    std::unordered_map<char, char> brackets = { {')', '('}, {'}', '{'}, {']', '['} };

    for (char c : s) {
        if (brackets.count(c)) {
            if (stack.empty() || stack.top() != brackets[c]) {
                return false;
            }
            stack.pop();
        }
        else {
            stack.push(c);
        }
    }

    return stack.empty();
}



struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

std::vector<int> inorderTraversal(TreeNode* root) {
    std::vector<int> result;
    std::stack<TreeNode*> stack;
    TreeNode* current = root;

    while (current || !stack.empty()) {
        while (current) {
            stack.push(current);
            current = current->left;
        }

        current = stack.top();
        stack.pop();
        result.push_back(current->val);
        current = current->right;
    }

    return result;
}

class MinStack {
private:
    std::stack<int> mainStack;
    std::stack<int> minStack;

public:
    MinStack() {
        minStack.push(INT_MAX);
    }

    void push(int val) {
        mainStack.push(val);
        minStack.push(std::min(val, minStack.top()));
    }

    void pop() {
        mainStack.pop();
        minStack.pop();
    }

    int top() {
        return mainStack.top();
    }

    int getMin() {
        return minStack.top();
    }
};



class MyQueue {
private:
    std::stack<int> stack1, stack2;

    void transfer() {
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }

public:
    void push(int x) {
        stack1.push(x);
    }

    int pop() {
        if (stack2.empty()) {
            transfer();
        }
        int result = stack2.top();
        stack2.pop();
        return result;
    }

    int peek() {
        if (stack2.empty()) {
            transfer();
        }
        return stack2.top();
    }

    bool empty() {
        return stack1.empty() && stack2.empty();
    }
};



std::string decodeString(const std::string& s) {
    std::stack<std::string> strStack;
    std::stack<int> numStack;
    std::string currentStr;
    int k = 0;

    for (char c : s) {
        if (isdigit(c)) {
            k = k * 10 + (c - '0');
        }
        else if (c == '[') {
            numStack.push(k);
            strStack.push(currentStr);
            currentStr = "";
            k = 0;
        }
        else if (c == ']') {
            std::string decoded = strStack.top();
            strStack.pop();
            int repeat = numStack.top();
            numStack.pop();

            for (int i = 0; i < repeat; ++i) {
                decoded += currentStr;
            }
            currentStr = decoded;
        }
        else {
            currentStr += c;
        }
    }

    return currentStr;
}



int evalRPN(const std::vector<std::string>& tokens) {
    std::stack<int> stack;

    for (const std::string& token : tokens) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int b = stack.top();
            stack.pop();
            int a = stack.top();
            stack.pop();

            if (token == "+") stack.push(a + b);
            else if (token == "-") stack.push(a - b);
            else if (token == "*") stack.push(a * b);
            else stack.push(a / b);
        }
        else {
            stack.push(std::stoi(token));
        }
    }

    return stack.top();
}



int longestValidParentheses(const std::string& s) {
    std::stack<int> stack;
    stack.push(-1);
    int maxLength = 0;

    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '(') {
            stack.push(i);
        }
        else {
            stack.pop();
            if (stack.empty()) {
                stack.push(i);
            }
            else {
                maxLength = std::max(maxLength, i - stack.top());
            }
        }
    }

    return maxLength;
}

int main()
{
    return 0;
}