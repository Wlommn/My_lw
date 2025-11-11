#include <iostream>
#include <locale.h>
#include <string>
#include <cmath>

using namespace std;

void First_Quest() {
    const string text = "\tВася\n\t\tпошёл\n\t\t\tгулять";
    cout << text << endl;
}

void Second_Quest() {
    cout << "   Ж   \n  ЖЖЖ  \n ЖЖЖЖЖ \nЖЖЖЖЖЖЖ" << endl;
    cout << " НН НН \n ZZZZZ " << endl;
}

void Trird_Quest() {
    for (int i = 1; i < 10; ++i) {
        string line = "";
        for (int j = 1; j < 10; ++j) {
            if (i * j < 10) {
                line += " ";
            }
            line += to_string(i * j);
            if (j != 9) {
                line += " ";
            }
        }
        cout << line << endl;
    }
}

float Discriminant(float a, float b, float c) {
    return b * b - 4 * a * c;
}

void F_1(float x) {
    cout << "1)a = " << cos(x) << endl;
    cout << "  z = " << sqrt(abs(sin(x)/pow(x,2))) + abs(sin(cos(x))) << endl;
}

void F_2(float x) {
    cout << "2)y = " << sin(x) + pow(abs(pow(x, 2)+1), 5) - sqrt(abs(pow(x, 2) / (pow(x, 3) + 5))) << endl;
}

void F_3(float x) {
    cout << "3)z = " << sqrt(pow(sin(x), 4)) << endl;
    cout << "  y = " << pow(abs(pow(x, 4) + 1),7) + sin(x * x) + 5 * sqrt(pow(sin(x), 4)) << endl;
}

void F_4(float x) {
    cout << "4)z = " << cos(x)/(pow(sin(x), 2) + 5) - exp(x*x) + 4.48f << endl;
}

void F_5(float x) {
    cout << "5)z = " << sqrt(abs(cos(x))) + exp(sin(x)) - 0.36f << endl;
}

void F_6(float x) {
    cout << "6)y = " << exp(x * x) + cos(2 * x + 5) + sqrt(x * x + 5) << endl;
}

void F_7(float x) {
    cout << "7)y = " << exp(pow(x, 4)) + sin(x)/(pow(cos(x + 2), 4) + 10) + log(x*x + 5) << endl;
}

void F_8(float x) {
    cout << "8)y = " << exp(pow(abs(x*x-5), 3)) + pow(cos(x), 2) + sqrt(x*x + 1)<< endl;
}

void F_9(float x) {
    cout << "9)z = " << pow(abs(cos(x)), 5) + sin(x)/(pow(x*x+1, 3)) + 10 * log(abs(x + 1)) << endl;
}

void F_10(float x) {
    cout << "10)z = " << sin(x)/(pow(sin(x + 2), 2) + 0.5f) - 0.0012f << endl;
}

void F_11(float x) {
    cout << "11)y = " << pow(sin(x), 2) + exp(pow(x*x+1, 5)) - log(x*x + 1) << endl;
}

void F_12(float x) {
    cout << "12)y = " << exp(x*x) + pow(sin(x), 2) + cos(x)/(pow(sin(x), 2) + 1) - 0.14f << endl;
}

void F_13(float x) {
    cout << "13)y = " << log(abs(pow(x, 4) + 1)) + 0.5 * pow(abs(x*x + 10), 1/5) + 1.64f << endl;
}

void F_14(float x) {
    cout << "14)y = " << 3 * sin(x) + sqrt(x * x + 5) + x * x - 0.5f * pow(10, -2)<< endl;
}

void F_15(float x) {
    cout << "15)y = " << sqrt(pow(x, 4) + 1) + cos(x*x + M_PI/4) - log(x*x + 4) << endl;
}

int main() {
    float x = 0.0f;
    cout << "Enter x: " << endl;
    cin >> x;

    F_1(x);
    F_2(x);
    F_3(x);
    F_4(x);
    F_5(x);
    F_6(x);
    F_7(x);
    F_8(x);
    F_9(x);
    F_10(x);
    F_11(x);
    F_12(x);
    F_13(x);
    F_14(x);
    F_15(x);

    return 0;
    // setlocale(LC_ALL, "ru_RU.UTF-16");
    // First_Quest();
    // cout << "\n";
    // Second_Quest();
    // cout << "\n";
    // Trird_Quest();
    // cout << "\n";

    // float a, b, c = 0.0f;
    
    // cout << "Enter a:" << endl;
    // cin >> a;
    // cout << "Enter b:" << endl;
    // cin >> b;
    // cout << "Enter c:" << endl;
    // cin >> c;

    // cout << Discriminant(a, b, c) << endl;  
}
