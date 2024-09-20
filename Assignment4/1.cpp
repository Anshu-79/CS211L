#include <iostream>
#include <map>
#include <algorithm>

using namespace std;


char operators[6] = {'+', '-', '/', '*', '('};

int compute(int n1, int n2, char op) {
    if (op == '+') return n1 + n2;
    if (op == '-') return n1 - n2;
    if (op == '*') return n1 * n2;
    if (op == '/') return n1 / n2;
}

bool isOperator(char op) {
    
    for (int i = 0; i < sizeof(operators); i++) {
        if (operators[i] == op) {
            return true;
        }
    }

    return false;
}

bool operatorsPresent(string expr) {
    for (int i = 0; i < sizeof(operators); i++) {
        for (int j = 0; j < expr.length(); j++) {
            if (operators[i] == expr[j]) return true;
        }
    }

    return false;
}

int findHighestOperator(string expr) {
    std::map<char, int> precedenceMap;

    precedenceMap['('] = 5;
    precedenceMap['/'] = 4;
    precedenceMap['*'] = 3;
    precedenceMap['+'] = 2;
    precedenceMap['-'] = 1;

    int highestOpIndex = 0, opPriority = 0;

    for (int i = 0; i < expr.length(); i++) {
        if (isOperator(expr[i]) && opPriority < precedenceMap[expr[i]]) {
            highestOpIndex = i;
            opPriority = precedenceMap[expr[i]];
        }
    }

    return highestOpIndex;

}

string solve (string expr) {
    while (operatorsPresent(expr)) {
        int idx = findHighestOperator(expr);

        if (expr[idx] == '(') {
            int end;

            for (int i = expr.length()-1; i > idx; i--) {
                if (expr[i] == ')') {
                    end = i;
                    break;
                }
            }
            
            string newExpr = expr.substr(idx+1, end-idx-1);
            cout << newExpr << endl;

            expr.erase(idx, end - idx+1);
            expr.insert(idx, solve(newExpr));

        }

        else {
            // Stops execution if expr is a -ve number. eg: expr = -15
            if (idx == 0 && expr[idx] == '-') {
                string subExpr = expr.substr(idx+1, expr.length()-1);
                if (operatorsPresent(subExpr)) {
                    int opIdx = findHighestOperator(subExpr);

                    string p1 = subExpr.substr(idx, opIdx);
                    string p2 = subExpr.substr(opIdx, subExpr.length()-opIdx);
                    cout << "Nums: " << p1 << " " << p2 << endl;

                    if (operatorsPresent(p2)) p2 = solve(p2);
                    
                    int n1 = p1.length() == 0 ? 0 : std::stoi(p1);
                    int n2 = std::stoi(p2);

                    int ans = compute(-1*n1, n2, '+');

                    return to_string(ans);
                }
                else {
                    return expr;
                }
            }

            int popStart, popEnd;
            string p1 = "", p2 = "";
            
            // Run loop until an operator is encountered
            // Continue running the loop if '-' operator is encountered just after idx
            // since it might represent a negative number rather than an operation
            for (int i = idx + 1; (!isOperator(expr[i]) && i < expr.length()) || (i - idx == 1 && expr[i] == '-'); i++) {
                p2 += expr[i];
                popEnd = i;
            }


            for (int i = idx - 1; !isOperator(expr[i]) && i >= 0; i--) {
                p1 += expr[i];
                popStart = i;
            }

            reverse(p1.begin(), p1.end());

            cout << "Pops: " << popStart << " " << popEnd << endl;

            cout << "Nums: " << p1 << " " << p2 << endl;


            int n1 = p1.length() == 0 ? 0 : std::stoi(p1);
            int n2 = std::stoi(p2);

            // Stops execution if expr compels division by zero 
            if (n2 == 0 && expr[idx] == '/') {
                return "Division by zero error";
            }

            int ans = compute(n1, n2, expr[idx]);

            cout << "Ans: " << ans << endl;   

            expr.erase(popStart, popEnd - popStart + 1);

            expr.insert(popStart, to_string(ans));

            cout << "Expr: " << expr << endl;  

            solve(expr);
        }
    }

    return expr;
}

int main() {

    string expr;
    cout << "Enter expression: ";
    cin >> expr;

    expr = solve(expr);

    cout << "Answer: " << expr << endl;

}
