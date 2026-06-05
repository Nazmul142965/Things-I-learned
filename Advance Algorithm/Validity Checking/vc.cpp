#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isValid(string exp) {
    stack<char> s;
    for (char ch : exp) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty()) return false;
            char top = s.top();
            if ((ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '[')) {
                s.pop();
            } else return false;
        }
    }
    return s.empty();
}

int main() {
    string exp = "d + [ (a - b) * { m / (n + p) } ]";
    if (isValid(exp)) cout << "VALID" << endl;
    else cout << "INVALID" << endl;
    return 0;
}