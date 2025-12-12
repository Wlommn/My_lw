#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

void L7_First_Part_Handler() {
    vector<float> sample = {2.6f, 8.5f, 9.1f, -1.5f, 4.0f, 6.0f, 7.0f, 4.0f, 2.0f, -5.6f};
    float m = 0.0f;

    for (size_t i = 0; i < sample.size(); i++) {
        m += sample[i];
    }

    m /= static_cast<float>(sample.size());
    float sumsq = 0.0f;

    for (size_t i = 0; i < sample.size(); i++) {
        float diff = sample[i] - m;
        sumsq += diff * diff;
    }
    
    float d = sumsq / static_cast<float>(sample.size());
    cout << "m = " << m << endl;
    cout << "d = " << d << endl;
}

void L7_Second_Part_Handler() {
    vector<int> A = {6, 7, 4, 5, 2, 0, 3, 3, 1, 9, 4};
    float prod = 1.0f;
    int n = 0;

    for (size_t i = 0; i < A.size(); i++) {
        if (A[i] > 4) {
            prod *= static_cast<float>(A[i]);
            n++;
        }
    }

    if (n == 0) {
        cout << "No elements greater than 4." << endl;
        return;
    }
    float f = powf(prod, 1.0f / static_cast<float>(n));
    cout << "f = " << f << endl;
}

void L7_Third_Part_Handler() {
    srand(static_cast<unsigned>(time(NULL)));
    vector<int> arr(20);

    for (size_t i = 0; i < arr.size(); i++) {
        arr[i] = rand() % 201 - 100;
    }

    sort(arr.begin(), arr.begin() + 10);
    sort(arr.begin() + 10, arr.end(), greater<int>());
    cout << "Results: " << endl;

    for (size_t i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void L8_First_Part_Handler() {
    vector<int> A(10);
    vector<int> B(15);
    
    cout << "Enter 10 integers for array A:" << endl;
    for (int i = 0; i < 10; i++) {
        cin >> A[i];
    }
    
    cout << "Enter 15 integers for array B:" << endl;
    for (int i = 0; i < 15; i++) {
        cin >> B[i];
    }
    
    int idxMaxA = static_cast<int>(max_element(A.begin(), A.end()) - A.begin());
    int idxMinB = static_cast<int>(min_element(B.begin(), B.end()) - B.begin());
    float result = static_cast<float>(idxMaxA) / static_cast<float>(idxMinB);
    
    cout << "Number of max in A = " << idxMaxA + 1 << endl;
    cout << "Number of min in B = " << idxMinB + 1 << endl;
    cout << "Result (Max A / Min B) = " << result << endl;
}

void L8_Second_Part_Handler() {
    vector<int> C(10);
    cout << "Enter 10 integers for array C:" << endl;
    for (int i = 0; i < 10; i++) {
        cin >> C[i];
    }
    
    int idx_min_mult_3 = -1;
    for (int i = 0; i < 10; i++) {
        if (C[i] % 3 == 0) {
            if (idx_min_mult_3 == -1 || C[i] < C[idx_min_mult_3]) {
                idx_min_mult_3 = i;
            }
        }
    }
    
    if (idx_min_mult_3 == -1) {
        cout << "No elements in C are divisible by 3" << endl;
        return;
    }
    
    cout << "Array C before swap:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << C[i] << " ";
    }
    cout << endl;

    swap(C[1], C[idx_min_mult_3]);
    
    cout << "Array C after swap:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << C[i] << " ";
    }
    cout << endl;
}

int main() {
    int end_code = 0;
    int lab = 0, part = 0;
    
    cout << "Choose lab (7 or 8): " << endl;
    cin >> lab;
    
    if (lab == 7) {
        cout << "Choose part (1 - 3): " << endl;
        cin >> part;
        switch (part) {
            case 1:
                L7_First_Part_Handler();
                break;
            case 2:
                L7_Second_Part_Handler();
                break;
            case 3:
                L7_Third_Part_Handler();
                break;
            default:
                cout << "That part not found {" << part << "}" << endl;
                end_code = 1;
                break;
        }
    } else if (lab == 8) {
        cout << "Choose part (1 - 2): " << endl;
        cin >> part;
        switch (part) {
            case 1:
                L8_First_Part_Handler();
                break;
            case 2:
                L8_Second_Part_Handler();
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
