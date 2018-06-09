#include<iostream>

using namespace std;

const int N = 20;
static int count = 0;

void Qsort(int pivot, int end, int array[]) {
    count++;
    if(end != pivot) {
        int start = pivot + 1;
        if((end - start) == 0) {
            if(array[pivot] > array[start]) {
                swap(array[pivot], array[start]);
            }
        }
         else {
            int l = start;
            int r = end;
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
}

int main() {
    int pivot = 0, end = N - 1, arraynum[N] = {12,9,2,2,5,15,20,3,1,9,8,17,4,11,7,2,0,16,10,6};
    Qsort(pivot, end, arraynum);
    for(int i = 0; i < N; i++) {
        cout << arraynum[i] << endl;
    }
    cout << "My Count : " << count;
    return 0;
}
