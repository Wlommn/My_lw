#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

void Fill_Vector(vector<double> &V, int min, int max) {
    srand(static_cast<unsigned>(time(NULL)));
    for (size_t i = 0; i < V.size(); ++i) {
        V[i] = rand() % (max - min + 1) + min;
    }
}

void Print_Vector(vector<double> V, string name) {
    cout << name << ": ";
    for (size_t i = 0; i < V.size(); ++i) {
        cout << V[i] << " ";
    }
    cout << endl;
}

void L9_First_Part_Handler() {
    vector<double> T(15), A(12);
    double mul = 1.0;
    Fill_Vector(T, 1, 10);
    Fill_Vector(A, 1, 10);

    Print_Vector(T, "T");
    for (size_t i = 0; i < T.size(); ++i) {
        mul *= T[i];
    }
    cout << pow(mul, 1.0/T.size()) << endl;

    mul = 1.0;
    Print_Vector(A, "A");
    for (size_t i = 0; i < A.size(); ++i) {
        mul *= A[i];
    }
    cout << pow(mul, 1.0/A.size()) << endl;
}

void L9_Second_Part_Handler() {
    vector<double> B(12), C(10);
    double mean = 0.0;
    Fill_Vector(B, -10, 10);
    Fill_Vector(C, -10, 10);

    Print_Vector(B, "B");
    for (size_t i = 0; i < B.size(); ++i) {
        if ((i + 1) % 2 == 0 && B[i] < 0) {
            mean += B[i];
        }
    }
    cout << "Result for B: " << mean / B.size() << endl;

    mean = 0.0;
    Print_Vector(C, "C");
    for (size_t i = 0; i < C.size(); ++i) {
        if ((i + 1) % 2 == 0 && C[i] < 0) {
            mean += C[i];
        }
    }
    cout << "Result for C: " << mean / C.size() << endl;
}

void L10_First_Part_Handler() {
    string result, input;
    cout << "Enter your text: ";
    getline(cin, input);

    for (char ch : input) {
        if (ch != '*') {
            result += ch;
            result += ch;
        }
    }

    cout << "Result: " << result << endl;
}

void L10_Second_Part_Handler() {
    string input;
    cout << "Enter your text: ";
    getline(cin, input);
    
    int total = input.length(), lower = 0, upper = 0;
    
    for (char ch : input) {
        if (ch >= 'a' && ch <= 'z') lower++;
        else if (ch >= 'A' && ch <= 'Z') upper++;
    }
    cout << "Result: " << endl;
    cout << "Lowercase: " << (lower * 100.0 / total) << endl;
    cout << "Uppercase: " << (upper * 100.0 / total) << endl;
}

int main() {
    int end_code = 0;
    int lab = 0, part = 0;
    
    cout << "Choose lab (9 or 10): " << endl;
    cin >> lab;
    
    if (lab == 9) {
        cout << "Choose part (1 - 2): " << endl;
        cin >> part;
        switch (part) {
            case 1:
                L9_First_Part_Handler();
                break;
            case 2:
                L9_Second_Part_Handler();
                break;
            default:
                cout << "That part not found {" << part << "}" << endl;
                end_code = 1;
                break;
        }
    } else if (lab == 10) {
        cout << "Choose part (1 - 2): " << endl;
        cin >> part;
        switch (part) {
            case 1:
                L10_First_Part_Handler();
                break;
            case 2:
                L10_Second_Part_Handler();
                break;
            default:
                cout << "That part not found {" << part << "}" << endl;
                end_code = 1;
                break;
        }
    } else {
        cout << "That lab not found {" << lab << "}" << endl;
        end_code = 1;
    }
    
    return end_code;
}
