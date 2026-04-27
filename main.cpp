#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isOpening(char ch) {
    return ch == '(' || ch == '{' || ch == '[';
}

bool isClosing(char ch) {
    return ch == ')' || ch == '}' || ch == ']';
}

bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool hasMatchingGroupingSymbols(const string& expression) {
    // Think of this like checking brackets by hand: last opener must close first.
    stack<char> symbols;

    for (char ch : expression) {
        if (isOpening(ch)) {
            symbols.push(ch);
        } else if (isClosing(ch)) {
            // If there is nothing to match, or the pair is wrong, the expression fails.
            if (symbols.empty() || !isMatchingPair(symbols.top(), ch)) {
                return false;
            }
            symbols.pop();
        }
    }

    // Valid only when every opener found a matching closer.
    return symbols.empty();
}

int main() {
    string expression;

    cout << "Enter an arithmetic expression: ";
    getline(cin, expression);

    if (hasMatchingGroupingSymbols(expression)) {
        cout << "The expression contains matching grouping symbols." << endl;
    } else {
        cout << "The expression does not contain matching grouping symbols." << endl;
    }

    return 0;
}
