#include <iostream>
#include <sstream>
#include <set>
#include <vector>
using namespace std;

// Set of C++ keywords
const set<string> keywords = {
    "auto", "break", "case", "char", "const", "continue", "default", "do", "double",
    "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register",
    "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef",
    "union", "unsigned", "void", "volatile", "while"
};

bool isKeyword(const string& str) {
    return keywords.find(str) != keywords.end();
}

bool isIdentifier(const string& str) {
    if (isdigit(str[0])) return false;
    for (char ch : str) {
        if (!isalnum(ch) && ch != '_') return false;
    }
    return true;
}

bool isConstant(const string& str) {
    for (char ch : str) {
        if (!isdigit(ch)) return false;
    }
    return true;
}

bool isArithmeticOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/'|| ch == '=';
}

bool isLogicalOperator(const string& str) {
    return str == ">" || str == ">=" || str == "<" || str == "<=" || str == "==" || str == "!=";
}

bool isParenthesis(char ch) {
    return ch == '(' || ch == ')' || ch == '{' || ch == '}' || ch == '[' || ch == ']';
}

bool isPunctuation(char ch) {
    return ch == ';' || ch == ',' || ch == ':' || ch == '.' || ch == '?' || ch == '!' || ch == '-' || ch == '/';
}

void analyze(const string& input) {
    vector<string> keywords, identifiers, constants, arithmeticOperators, logicalOperators, parenthesis, punctuation;
    stringstream ss(input);
    string token;

    while (ss >> token) {
        if (isKeyword(token)) {
            keywords.push_back(token);
        } else if (isConstant(token)) {
            constants.push_back(token);
        } else if (isIdentifier(token)) {
            identifiers.push_back(token);
        } else if (isLogicalOperator(token)) {
            logicalOperators.push_back(token);
        } else {
            for (char ch : token) {
                if (isArithmeticOperator(ch)) {
                    arithmeticOperators.push_back(string(1, ch));
                } else if (isParenthesis(ch)) {
                    parenthesis.push_back(string(1, ch));
                } else if (isPunctuation(ch)) {
                    punctuation.push_back(string(1, ch));
                }
            }
        }
    }

    auto printCategory = [](const string& category, const vector<string>& items) {
        if (!items.empty()) {
            cout << category << " (" << items.size() << "): ";
            for (size_t i = 0; i < items.size(); ++i) {
                cout << items[i];
                if (i < items.size() - 1) {
                    cout << ", ";
                }
            }
            cout << endl;
        }
    };

    printCategory("Keyword", keywords);
    printCategory("Identifier", identifiers);
    printCategory("Constant", constants);
    printCategory("Arithmetic Operator", arithmeticOperators);
    printCategory("Logical Operator", logicalOperators);
    printCategory("Parenthesis", parenthesis);
    printCategory("Punctuation", punctuation);
}

int main() {
    string input;
    cout << "Enter a line of code: ";
    getline(cin, input);
    analyze(input);
    return 0;
}

