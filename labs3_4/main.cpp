#include <iostream>
#include <cmath>

using namespace std;

#define SUM(A, B) ((A) + (B));
#define MUL(A, B) ((A) * (B));
#define DIV(A, B) ((A) / (B));

void L3_First_Part_Handler() {
    int x = 0, y = 0;
    cout << "Enter x and y" << endl;
    cin >> x >> y;
    if (x != 0 && y != 0) {
        if (x * y > 0) {
            if (x > 0) {
                cout << "I" << endl;    
            } else {
                cout << "III" << endl;
            }
        } else {
            if (x < 0) {
                cout << "II" << endl;
            } else {
                cout << "VI" << endl;
            }
        }
    }
}

void L3_Second_Part_Handler() {
    int a = 0, b = 0, c = 0;
    cout << "Enter 3 numbers: " << endl;
    cin >> a >> b >> c;
    if (a > b && b < c) {
        cout << "Answer: " << b << endl;
    }
    if (b > a && a < c) {
        cout << "Answer: " << a << endl;
    }
    if (a > c && c < b) {
        cout << "Answer: " << c << endl;
    }
}

void L3_Third_Part_Handler() {
    int m = 0;
    cout << "Enter number of month" << endl;
    cin >> m;
    switch (m) {
    case 1:
    case 2:
    case 12:
        cout << "It is winter" << endl;
        break;
    case 3:
    case 4:
    case 5:
        cout << "It is spring" << endl;
        break;
    case 6:
    case 7:
    case 8:
        cout << "It is summer" << endl;
        break;
    case 9:
    case 10:
    case 11:
        cout << "It is fall" << endl;
        break;
    default:
        cout << "Not correct number of month: " << m << endl; 
        break;
    }
}

int L3_Fourth_Part_Handler() {
    int op = 0, a = 0, b = 0;
    cout << "Choose operations: 1) a + b\n 2) a - b\n 3) a * b\n 4) a / b\n";
    cout << "5) a^b\n 6) x^1/y\n 7) (x + y) / 2\n 8) (x * y)^1/2\n9) max(x, y)\n10) min(x, y)" << endl;
    cin >> op;
    if (op < 1 || op > 10) {
        cout << "Not correct operation number, {" << op << "}" << endl;
        return 2;
    }

    cout << "Enter first number: ";
    cin >> a;
    cout << "Enter second number: ";
    cin >> b;
    
    switch (op) {
    case 1:
        cout << "Result: " << SUM(a, b);
        break;
    case 2:
        cout << "Result: " << SUM(a, -b);
        break;
    case 3:
        cout << "Result: " << MUL(a, b);
        break;
    case 4:
        if (b == 0) {
            cout << "Not correct opperand " << a << "/" << b << endl;
            return 3;
        } 
        cout << "Result: " << DIV(a, b);
        break;
    case 5:
        cout << "Result: " << pow(a, b);
        break;
    case 6:
        if (a < 0) {
            cout << "Not correct opperand " << a << "^1/" << b << endl;
            return 3;
        } 
        cout << "Result: " << pow(a, 1/b);
        break;
    case 7:
        cout << "Result: " << (a + b) / 2;
        break;
    case 8:
        if (a * b < 0) {
            cout << "Not correct opperand (" << a << " * " << b  << ")^1/2"<< endl;
            return 3;
        } 
        cout << "Result: " << pow(a * b, 1/2);
        break;
    case 9:
        cout << "Result: " << max(a, b);
        break;
    case 10:
        cout << "Result: " << min(a, b);
        break;
    default:
        break;
    }
    return 0;
}

void L4_First_Part_Handler() {
    float x = 0.0f, y_20 = 0.0f, y_22 = 0.0f;
    cout << "Enter x:" << endl;
    cin >> x;
    if (x < 0.0f) {
        y_20 = pow(1.0 / tanf(3 * x - 1), 2);
        y_22 = (2 * x + 1) / pow(x, 5);
    } else if (x > 1.0f) {
        y_20 = 2 + x * exp(-x);
        y_22 = exp(x + 1) + cos(x);
    } else {
        y_20 = pow(sin(x * x), 3);
        y_22 = 3 * log(pow(sin(x) + x * x, 1/5));
    }
    cout << "Result: Y_20 = " << y_20 << " ; Y_22 = " << y_22 << endl; 
}

void L4_Second_Part_Handler() {
    float x = 0.0f, y = 0.0f;
    cout << "Enter x:" << endl;
    cin >> x;
    if (x == 3.0f) {
        y = 1;
    } else if (x >= 1.0f && x < 3.0f) {
        y = (1.0 / tanf(pow(x, 3) + 3) * exp(x - 3)) / sqrt(abs(x - 3));
    } else {
        y = pow(1.0 / tanf(x * x + 2) * exp(2) * log(x + 2), 1/3);
    }
    cout << "Result: Y = " << y << endl; 
}

void L4_Third_Part_Handler() {
    float a = 0.0f, b = 0.0f;
    cout << "Enter a:" << endl;
    cin >> a;
    cout << "Enter b:" << endl;
    cin >> b;

    float result_min = (a + b) / 2;
    float result_max = 2 * a * b;

    if (a < b) {
        a = result_min;
        b = result_max;
    } else if (b < a) {
        a = result_min;
        b = result_max;
    }
    cout << "Result: a = " << a << " ; b = " << b << endl;
}

int main() {
    int end_code = 0;
    int lab = 0, part = 0;
    cout << "Choose lab (3 or 4): " << endl;
    cin >> lab;
    if (lab == 3) {
        cout << "Choose part (1 - 4): " << endl;
        cin >> part;
        switch (part) {
            case 1:
                L3_First_Part_Handler();
                break;
            case 2:
                L3_Second_Part_Handler();
                break;
            case 3:
                L3_Third_Part_Handler();
                break;
            case 4:
                end_code = L3_Fourth_Part_Handler();
                break;
            default:
                cout << "That part not found {" << part << "}" << endl;
                end_code = 1;
                break;
        }
    } else if (lab == 4) {
        cout << "Choose part (1 - 4): " << endl;
        cin >> part;
        switch (part) {
            case 1:
                L4_First_Part_Handler();
                break;
            case 2:
                L4_Second_Part_Handler();
                break;
            case 3:
                L4_Third_Part_Handler();
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
