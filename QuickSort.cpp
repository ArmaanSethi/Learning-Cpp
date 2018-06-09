#include<iostream>
#include<fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <H:\My Documents\ComputerScience\Headers\MyClass.h>

using namespace std;

const int N = 100;

/*void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}*/

/*void Qsort(int pivot, int end, int array[]) {
    int start = pivot + 1;
    int l = start;
    int r = end;
    if(end != pivot) {
        if((end - start) == 0) {
            if(array[pivot] > array[start]) {
                swap(array[pivot], array[start]);
            }
        } else {
            while(l < r) {
                l = start;
                r = end;
                while(array[l] <= array[pivot] && (l != end)) l++;
                while(array[r] > array[pivot] && (r != start)) r--;
                if(l < r) swap(array[l], array[r]);
            }
            if(l == end) {
                if(array[l] < array[pivot])  swap(array[l], array[pivot]);
                Qsort(0, r-1, array);
            } else if(r == start) {
                if(array[r] < array[pivot])  swap(array[r], array[pivot]);
                Qsort(l, end, array);
            } else {
                swap(array[pivot], array[r]);
                Qsort(0, r-1, array);
                Qsort(l, end, array);
            }
        }
    }
}*/

int main() {
    int pivot = 0, end = N - 1, array[N];
    srand(time(0));
    for(int i = 0; i < N; i++) {
        array[i] = rand() % 1001 + 0;
        cout << array[i] << endl;
    }
    cout << endl << "SORT TIME!!!" << endl << endl;
    Qsort(pivot, end, array);
    for(int i = 0; i < N; i++) {
        cout << array[i] << endl;
    }
}
