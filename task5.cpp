#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

struct Node {
    string value;
    Node* left;
    Node* right;

    Node(string val) : value(val), left(nullptr), right(nullptr) {}
};

int evaluate(Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return stoi(root->value);
    int left_val = evaluate(root->left);
    int right_val = evaluate(root->right);

    if (root->value == "+") return left_val + right_val;
    if (root->value == "-") return left_val - right_val;
    if (root->value == "*") return left_val * right_val;
    if (root->value == "/") return left_val / right_val;
    return 0;
}

void printTree(Node* root) {
    if (!root) return;
    printTree(root->left);
    cout << root->value << " ";
    printTree(root->right);
}

Node* expressionToTree(const string& exp) {
    stack<Node*> operands;
    stack<char> operators;

    for (int i = 0; i < exp.length(); i++) {
        if (exp[i] == ' ') continue;

        if (isdigit(exp[i])) {
            string num;
            while (i < exp.length() && isdigit(exp[i])) {
                num += exp[i++];
            }
            i--;
            operands.push(new Node(num));
        } else if (exp[i] == '(') {
            operators.push(exp[i]);
        } else if (exp[i] == ')') {
            while (!operators.empty() && operators.top() != '(') {
                Node* opNode = new Node(string(1, operators.top()));
                operators.pop();

                opNode->right = operands.top();
                operands.pop();
                opNode->left = operands.top();
                operands.pop();
                operands.push(opNode);
            }
            operators.pop();
        } else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
            operators.push(exp[i]);
        }
    }

    return operands.top();
}

int main() {
    string expression = "((3+1)*(4-2))";
    Node* root = expressionToTree(expression);
    printTree(root);
    cout << "\nValue at root: " << evaluate(root) << endl;
    return 0;
}

