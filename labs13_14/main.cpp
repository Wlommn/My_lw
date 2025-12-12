#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void L13_First_Part_Handler() {
    const int SIZE = 5;
    int matrix[SIZE][SIZE];
    long int product = 1;
    bool found = false;
    
    srand(time(0));
    
    cout << "Generated matrix:" << endl;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matrix[i][j] = rand() % 101;
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (matrix[i][j] > 0 && matrix[i][j] % 5 != 0) {
                product *= matrix[i][j];
                found = true;
            }
        }
    }
    
    cout << "\nResult: ";
    if (found) {
        cout << product << endl;
    } else {
        cout << "0" << endl;
    }
}

void L13_Second_Part_Handler() {
    const int SIZE = 5;
    int matrix[SIZE][SIZE];
    
    srand(time(0));
    
    cout << "Matrix C:" << endl;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matrix[i][j] = rand() % 101 - 50;
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    
    int countNegative = 0;
    int sumNegative = 0;
    
    for (int i = 0; i < SIZE; i++) {
        int element = matrix[i][i];
        if (element < 0 && element % 3 != 0) {
            sumNegative += element;
            countNegative++;
        }
    }
    
    long long productPositive = 1;
    bool foundPositive = false;
    
    for (int i = 0; i < SIZE; i++) {
        int element = matrix[i][SIZE - 1 - i];
        if (element > 0 && element % 2 != 0) {
            productPositive *= element;
            foundPositive = true;
        }
    }
    
    cout << "\nResults:" << endl;
    
    if (countNegative > 0) {
        double average = static_cast<double>(sumNegative) / countNegative;
        cout << "1 - " << average << endl;
    } else {
        cout << "1 - 0" << endl;
    }
    
    if (foundPositive) {
        cout << "2 - " << productPositive << endl;
    } else {
        cout << "2 - 0" << endl;
    }
}

double Bisection(double (*F)(double), double a, double b, double EPS, int& steps) {
    double m = 0.0;
    steps = 0;
    while ((b - a) >= EPS) {
        m = (a + b) / 2;
        if (F(m) == 0.0) {
            break;
        } else if (F(m) * F(a) < 0) {
            b = m;
        } else {
            a = m;
        }
        steps++;
    }
    return (a + b) / 2;
}

double Newton(double (*F)(double), double (*F_d)(double), double x0, double EPS, int& steps) {
    double x1 = 0;
    steps = 0;
    do {
        x1 = x0 - F(x0) / F_d(x0);
        steps++;
        x0 = x1;
    } while (fabs(F(x1)) > EPS);
    return x1;
}

//  Functions

double F1(double x) {
    return cos(x) - tan(x);
}

double F2(double x) {
    return cos(x) - pow(x, 3);
}

double F3(double x) {
    return 1 - 5 * x + pow(x, 3);
}

double F4(double x) {
    return 1 - 5 * x + pow(x, 4);
}

double F5(double x) {
    return 1 - 3 * x + pow(x, 5);
}

//  Functions

//  Function derivative

double F1_d(double x) {
    return -sin(x) - 1/(cos(x) * cos(x));
}

double F2_d(double x) {
    return -sin(x) - 3 * x * x;
}

double F3_d(double x) {
    return 5 + 3 * x * x;
}

double F4_d(double x) {
    return 5 + 4 * pow(x, 3);
}

double F5_d(double x) {
    return 3 + 5 * pow(x, 4);
}

//  Function derivative

void L14_First_Part_Handler(double (*F)(double), double (*F_d)(double), double x0, double a, double b) {
    double EPS = 0.00000001, root = 0.0;
    int steps = 0;

    root = Bisection(F, a, b, EPS, steps);
    cout << "Bisection:" << endl;
    cout << fixed << setprecision(8) << "\tx = " << root << endl;
    cout << fixed << setprecision(8) << "\tF(x) = " << F(root) << endl;
    cout << "\tSteps = "<< steps << endl;

    root = Newton(F, F_d, x0, EPS, steps);
    cout << "Newton:" << endl;
    cout << fixed << setprecision(8) << "\tx = " << root << endl;
    cout << fixed << setprecision(8) << "\tF(x) = " << F(root) << endl;
    cout << "\tSteps = "<< steps << endl;
}

int main() {
    int end_code = 0;
    int lab = 0, part = 0;
    
    cout << "Choose lab (13 or 14): " << endl;
    cin >> lab;
    
    if (lab == 13) {
        cout << "Choose part (1 - 2): " << endl;
        cin >> part;
        switch (part) {
            case 1:
                L13_First_Part_Handler();
                break;
            case 2:
                L13_Second_Part_Handler();
                break;
            default:
                cout << "That part not found {" << part << "}" << endl;
                end_code = 1;
                break;
        }
    } else if (lab == 14) {
        L14_First_Part_Handler(F1, F1_d, 1, 0, M_PI / 2);
        L14_First_Part_Handler(F2, F2_d, 1, 0, M_PI / 2);
        L14_First_Part_Handler(F3, F3_d, 0.25, 0, 1);
        L14_First_Part_Handler(F4, F4_d, 0.25, 0, 1);
        L14_First_Part_Handler(F5, F5_d, 0.25, 1, 2);
    } else {
        cout << "That lab not found {" << lab << "}" << endl;
        end_code = 1;
    }
    
    return end_code;
}
