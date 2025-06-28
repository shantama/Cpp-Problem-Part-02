#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <map>
#include <sstream>
using namespace std;

bool isKeyword(const string& str) {
    vector<string> keywords = {"if", "else", "int"};
    for (const string& keyword : keywords) {
        if (str == keyword) return true;
    }
    return false;
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
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

bool isLogicalOperator(const string& str) {
    vector<string> logicalOperators = {">", ">=", "<", "<=", "==", "!="};
    for (const string& op : logicalOperators) {
        if (str == op) return true;
    }
    return false;
}

bool isParenthesis(char ch) {
    return ch == '(' || ch == ')' || ch == '{' || ch == '}' || ch == '[' || ch == ']';
}

bool isPunctuation(char ch) {
    return ch == ';' || ch == ',' || ch == ':';
}

void analyze(const string& input) {
    map<string, vector<string>> tokens;
    stringstream ss(input);
    string word;

    while (ss >> word) {
        if (isKeyword(word)) {
            tokens["Keyword"].push_back(word);
        } else if (isConstant(word)) {
            tokens["Constant"].push_back(word);
        } else if (isIdentifier(word)) {
            tokens["Identifier"].push_back(word);
        } else if (word.length() == 1 && isArithmeticOperator(word[0])) {
            tokens["Arithmetic Operator"].push_back(word);
        } else if (isLogicalOperator(word)) {
            tokens["Logical Operator"].push_back(word);
        } else if (word.length() == 1 && isParenthesis(word[0])) {
            tokens["Parenthesis"].push_back(word);
        } else if (word.length() == 1 && isPunctuation(word[0])) {
            tokens["Punctuation"].push_back(word);
        }
    }

    cout << "Sample output:\n";
    for (const auto& token : tokens) {
        cout << token.first << " (" << token.second.size() << "): ";
        for (const auto& value : token.second) {
            cout << value << ", ";
        }
        cout << endl;
    }
}

int main() {
    string input;
    cout << "Enter a line of code: ";
    getline(cin, input);
    analyze(input);
    return 0;
}

