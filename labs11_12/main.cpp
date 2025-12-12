#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void L11_First_Part_Handler() {
    const int SIZE = 3;
    int matrix1[SIZE][SIZE];
    int matrix2[SIZE][SIZE];
    int sum[SIZE][SIZE];
    int diff[SIZE][SIZE];
    
    cout << "Enter elements of the first 3x3 matrix:" << endl;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cin >> matrix1[i][j];
        }
    }
    
    cout << "Enter elements of the second 3x3 matrix:" << endl;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cin >> matrix2[i][j];
        }
    }
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
            diff[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    
    cout << "Sum of matrices:" << endl;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << "Difference of matrices:" << endl;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << diff[i][j] << " ";
        }
        cout << endl;
    }
}

void L11_Second_Part_Handler() {
    const int SIZE = 3;
    int matrix[SIZE][SIZE];
    int mainDiagonalSum = 0;
    int secondaryDiagonalSum = 0;
    
    cout << "Enter elements of a 3x3 matrix:" << endl;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cin >> matrix[i][j];
        }
    }
    
    for (int i = 0; i < SIZE; i++) {
        mainDiagonalSum += matrix[i][i];
        secondaryDiagonalSum += matrix[i][SIZE - 1 - i];
    }
    
    cout << "\nMatrix:" << endl;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << "\nSum of main diagonal: " << mainDiagonalSum << endl;
    cout << "Sum of secondary diagonal: " << secondaryDiagonalSum << endl;
    
    if (mainDiagonalSum == secondaryDiagonalSum) {
        cout << "\nResult: The sums are EQUAL." << endl;
    } else {
        cout << "\nResult: The sums are NOT equal." << endl;
    }
}

void L11_Third_Part_Handler() {
    const int SIZE = 3;
    int matrix[SIZE][SIZE];
    int transposed[SIZE][SIZE];

    cout << "Enter elements of a 3x3 matrix:" << endl;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }

    cout << "\nOriginal matrix:" << endl;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nTransposed matrix:" << endl;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << transposed[i][j] << " ";
        }
        cout << endl;
    }
}

void L11_Fourth_Part_Handler() {
    const int ROWS = 6;
    const int COLS = 4;
    int matrix[ROWS][COLS];
    int swapped[ROWS][COLS];
    
    srand(time(0));
    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = rand() % 101;
            swapped[i][j] = matrix[i][j];
        }
    }
    
    for (int i = 0; i < ROWS; i += 2) {
        if (i + 1 < ROWS) {
            for (int j = 0; j < COLS; j++) {
                int temp = swapped[i][j];
                swapped[i][j] = swapped[i + 1][j];
                swapped[i + 1][j] = temp;
            }
        }
    }
    
    cout << "Original matrix:" << endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    
    cout << "\nMatrix after swapping even and odd rows:" << endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << swapped[i][j] << "\t";
        }
        cout << endl;
    }
}

void L12_First_Part_Handler() {
    const int ROWS = 3;
    const int COLS = 4;
    int A[ROWS][COLS] = {
        {5, 1, -7, 2},
        {3, 4, 0, -4},
        {8, 5, 1, -1}
    };
    
    cout << "Original matrix:" << endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }
    
    int minVal = A[0][0];
    int minRow = 0;
    int minCol = 0;
    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (A[i][j] < minVal) {
                minVal = A[i][j];
                minRow = i;
                minCol = j;
            }
        }
    }
    
    int result[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == minRow || j == minCol) {
                result[i][j] = 0;
            } else {
                result[i][j] = A[i][j];
            }
        }
    }
    
    cout << "\nMatrix after zeroing row " << minRow << " and column " << minCol << ":" << endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << result[i][j] << "\t";
        }
        cout << endl;
    }
}

void L12_Second_Part_Handler() {
    const int ROWS = 3;
    const int COLS = 5;
    int B[ROWS][COLS] = {
        {8, 1, 8, 3, 13},
        {6, 7, 9, 14, 7},
        {2, 6, 3, 1, 1}
    };
    
    cout << "Matrix B:" << endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << B[i][j] << "\t";
        }
        cout << endl;
    }
    
    int maxVal = B[0][0];
    int minVal = B[0][0];
    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (B[i][j] > maxVal) {
                maxVal = B[i][j];
            }
            if (B[i][j] < minVal) {
                minVal = B[i][j];
            }
        }
    }
    
    cout << "\nMaximum element: " << maxVal << endl;
    cout << "Minimum element: " << minVal << endl;
    cout << "Result: " << maxVal * minVal << endl;
}

int main() {
    int end_code = 0;
    int lab = 0, part = 0;
    
    cout << "Choose lab (11 or 12): " << endl;
    cin >> lab;
    
    if (lab == 11) {
        cout << "Choose part (1 - 4): " << endl;
        cin >> part;
        switch (part) {
            case 1:
                L11_First_Part_Handler();
                break;
            case 2:
                L11_Second_Part_Handler();
                break;
            case 3:
                L11_Third_Part_Handler();
                break;
            case 4:
                L11_Fourth_Part_Handler();
                break;
            default:
                cout << "That part not found {" << part << "}" << endl;
                end_code = 1;
                break;
        }
    } else if (lab == 12) {
        cout << "Choose part (1 - 2): " << endl;
        cin >> part;
        switch (part) {
            case 1:
                L12_First_Part_Handler();
                break;
            case 2:
                L12_Second_Part_Handler();
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
