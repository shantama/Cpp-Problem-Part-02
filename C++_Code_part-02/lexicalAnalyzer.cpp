#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <set>
using namespace std;

// Set of C++ keywords
const set<string> keywords = {
    "auto", "break", "case", "char", "const", "continue", "default", "do", "double",
    "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register",
    "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef",
    "union", "unsigned", "void", "volatile", "while"
};

// Check if a string is a keyword
bool isKeyword(const string& str) {
    return keywords.find(str) != keywords.end();
}

// Check if a string is a valid identifier
bool isIdentifier(const string& str) {
    if (isdigit(str[0])) return false;
    for (char ch : str) {
        if (!isalnum(ch) && ch != '_') return false;
    }
    return true;
}

// Check if a string is a constant (numeric value)
bool isConstant(const string& str) {
    for (char ch : str) {
        if (!isdigit(ch)) return false;
    }
    return true;
}

// Check if a character is an arithmetic operator
bool isArithmeticOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

// Check if a string is a logical operator
bool isLogicalOperator(const string& str) {
    return str == ">" || str == ">=" || str == "<" || str == "<=" || str == "==" || str == "!=";
}

// Check if a character is a parenthesis
bool isParenthesis(char ch) {
    return ch == '(' || ch == ')' || ch == '{' || ch == '}' || ch == '[' || ch == ']';
}

// Check if a character is a punctuation mark
bool isPunctuation(char ch) {
    return ch == ';' || ch == ',' || ch == ':' || ch == '.';
}

// Function to analyze a line of code
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

    cout << "Sample output:\n";
    cout << "Keyword (" << keywords.size() << "): ";
    for (const string& kw : keywords) cout << kw << " ";
    cout << endl;

    cout << "Identifier (" << identifiers.size() << "): ";
    for (const string& id : identifiers) cout << id << " ";
    cout << endl;

    cout << "Constant (" << constants.size() << "): ";
    for (const string& cnst : constants) cout << cnst << " ";
    cout << endl;

    cout << "Arithmetic Operator (" << arithmeticOperators.size() << "): ";
    for (const string& op : arithmeticOperators) cout << op << " ";
    cout << endl;

    cout << "Logical Operator (" << logicalOperators.size() << "): ";
    for (const string& op : logicalOperators) cout << op << " ";
    cout << endl;

    cout << "Parenthesis (" << parenthesis.size() << "): ";
    for (const string& par : parenthesis) cout << par << " ";
    cout << endl;

    cout << "Punctuation (" << punctuation.size() << "): ";
    for (const string& punct : punctuation) cout << punct << " ";
    cout << endl;
}

int main() {
    string input;
    cout << "Enter a line of code: ";
    getline(cin, input);
    analyze(input);
    return 0;
}
