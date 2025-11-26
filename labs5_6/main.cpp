#include <iostream>
#include <cmath>

using namespace std;

int Euclid_Alg(int a, int b) {
    while(a != b){
        if(a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }
    return a;
}

void L5_First_Part_Handler() {
    int a = 0, b = 0, n;
    cout << "Enter a and b" << endl;
    cin >> a >> b;
    n = Euclid_Alg(a, b);
    cout << "Result: " << a / n << "/" << b / n << endl;
}

void L5_Second_Part_Handler() {
    int a = 0, b = 0, c = 0;
    cout << "Enter a, b and c" << endl;
    cin >> a >> b >> c;
    cout << "Result: " << Euclid_Alg(Euclid_Alg(a, b), c) << endl;
}

int Get_Fibonachi(int n) {
    if (n <= 1) {
        return n;
    }
    int a = 0, b = 1, t = 0;
    for (size_t i = 2; i <= n; i++) {
        t = a + b;
        a = b;
        b = t;
    }
    return b;
    
}

void L5_Third_Part_Handler() {
    int n = 0;
    cout << "Enter n" << endl;
    cin >> n;
    if (n < 0 || n >= 20) {
        cout << "NOt correct n. Enter n from 0 to 19" << endl;
        return;
    }

    cout << "Result: " << Get_Fibonachi(n) << endl;
}

void L5_Fourth_Part_Handler() {
    do {
        int n = 0, f = 0;
        cout << "Enter n" << endl;
        cin >> n;
        if (n < 0 || n >= 20) {
            cout << "Not correct n. Enter n from 0 to 1000" << endl;
            continue;
        }
        for (size_t i = 0; i < 17; i++) {
            if (n == Get_Fibonachi(i)) {
                cout << "Result: true, it is Fibonachi number from " << i << endl;
                return;
            }
        }
        cout << "Result: false, it is not Fibonachi number" << endl;
        return;
    } while (true);
}

void L6_First_Part_Handler() {
    float x = 1.25f, res = 0.0f;
    for (float i = 0; i <= 10; i += 0.5) {
        res += sin(x / (sqrtf(i + x)));
    }
    cout << "Result: " << res << endl;
}

float ch(float x) {
    return (exp(x) + exp(-x)) / 2;
}

float sh(float x) {
    return (exp(x) - exp(-x)) / 2;
}

void L6_Second_Part_Handler() {
    float res = 1.0f, s = 0.0f;
    for (float x = 1.0f; x <= 10.0f; x++) {
        for (float n = -1.0f; n >= -10.0f; n--) {
            s += ((sqrt(abs(n)) + x * ch(x)) * exp(x + n)) / ((pow(sin(x), 3) + log10(abs(n))) * sh(x));
        }
        res *= s;
    }
    cout << "Result: " << res << endl;
}

void L6_Third_Part_Handler() {
    int n = 0, count = 0;
    cout << "Enter n" << endl;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            cout << i << " ";
            if (i % 2 == 0) {
                count++;
            }
        }
    }
    cout << "\nEven: " << count << endl;
}

int main() {
    int end_code = 0;
    int lab = 0, part = 0;
    cout << "Choose lab (5 or 6): " << endl;
    cin >> lab;
    if (lab == 5) {
        cout << "Choose part (1 - 4): " << endl;
        cin >> part;
        switch (part) {
            case 1:
                L5_First_Part_Handler();
                break;
            case 2:
                L5_Second_Part_Handler();
                break;
            case 3:
                L5_Third_Part_Handler();
                break;
            case 4:
                L5_Fourth_Part_Handler();
                break;
            default:
                cout << "That part not found {" << part << "}" << endl;
                end_code = 1;
                break;
        }
    } else if (lab == 6) {
        cout << "Choose part (1 - 3): " << endl;
        cin >> part;
        switch (part) {
            case 1:
                L6_First_Part_Handler();
                break;
            case 2:
                L6_Second_Part_Handler();
                break;
            case 3:
                L6_Third_Part_Handler();
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
    return 0;
}
