#include <iostream>
#include <vector>
using namespace std;

int getMax(vector<int>& arr) {
    int m = arr[0];
    for (int x : arr) if (x > m) m = x;
    return m;
}

void countSort(vector<int>& arr, int exp) {
    vector<int> output(arr.size());
    int count[10] = {0};
    for (int x : arr) count[(x / exp) % 10]++;
    for (int i = 1; i < 10; i++) count[i] += count[i - 1];
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    arr = output;
}

void radixSort(vector<int>& arr) {
    int m = getMax(arr);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, exp);
}

int main() {
    vector<int> scores = {45, 78, 12, 99, 56, 84, 33, 67, 71, 89, 90, 64, 22, 44, 55,
                          37, 83, 47, 95, 16, 20, 27, 39, 50, 42, 31, 25, 68, 59, 76,
                          91, 73, 80, 66, 29, 11, 94, 88, 79, 18, 24, 34, 53, 61, 72,
                          87, 99, 60, 82, 35};
    radixSort(scores);
    cout << "Sorted Scores with Rank:\n";
    for (int i = 0; i < scores.size(); i++)
        cout << "Rank " << i + 1 << ": " << scores[i] << endl;
}
