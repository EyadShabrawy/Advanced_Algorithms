#include <iostream>
#include <pthread.h>

using namespace std;

struct matrix {
    int rows;
    int cols;
    int* data;
};

struct args {
    matrix* A;
    matrix* B;
    matrix* C;
    int row_index;
};

void* calculate_row(void* arg) {
    args *params = (args*)arg;
    for (int col = 0; col < params->B->cols; col++) {
        int sum = 0;
        for (int inner = 0; inner < params->A->cols; inner++) {
            sum += params->A->data[params->row_index * params->A->cols + inner] *
                   params->B->data[inner * params->B->cols + col];
        }
        params->C->data[params->row_index * params->C->cols + col] = sum;
    }

    pthread_exit(NULL);
}

int main() {
    int aRow = 3, aCol = 4, bRow = 4, bCol = 3; // Hard-coded rows and columns

    if (aCol != bRow) {
        cout << "Error: Invalid matrix dimensions for multiplication." << endl;
        return 1;
    }

    matrix A, B, C;
    A.rows = aRow;
    A.cols = aCol;
    A.data = new int[aRow * aCol];
    int aData[] = {1, 2, 3, 4, 5, 6,7,8,9,10,11,12};  // Hard-coded elements of matrix A
    for (int i = 0; i < aRow * aCol; ++i) {
        A.data[i] = aData[i];
    }

    B.rows = bRow;
    B.cols = bCol;
    B.data = new int[bRow * bCol];
    int bData[] = {16, 12, 8, 15, 11, 7, 14, 10, 6, 13, 9, 5};  // Hard-coded elements of matrix B
    for (int i = 0; i < bRow * bCol; ++i) {
        B.data[i] = bData[i];
    }

    C.rows = aRow;
    C.cols = bCol;
    C.data = new int[aRow * bCol];  // Resultant matrix

    int num_threads = min(aRow, 4);
    pthread_t threads[num_threads];
    args thread_args[num_threads];

    for (int i = 0; i < num_threads; i++) {
        thread_args[i].A = &A;
        thread_args[i].B = &B;
        thread_args[i].C = &C;
        thread_args[i].row_index = i;

        pthread_create(&threads[i], NULL, calculate_row, &thread_args[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    cout << "Resultant matrix:" << endl;
    for (int i = 0; i < aRow; i++) {
        for (int j = 0; j < bCol; j++) {
            cout << C.data[i * bCol + j] << " ";
        }
        cout << endl;
    }

    delete[] A.data;
    delete[] B.data;
    delete[] C.data;

    return 0;
}
