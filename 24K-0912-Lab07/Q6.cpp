#include <iostream>
#include <vector>
using namespace std;

struct Employee {
    string name;
    int id;
    double salary;
};

void merge(vector<Employee>& e, int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid;
    vector<Employee> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = e[left + i];
    for (int j = 0; j < n2; j++) R[j] = e[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].salary >= R[j].salary) e[k++] = L[i++];
        else e[k++] = R[j++];
    }
    while (i < n1) e[k++] = L[i++];
    while (j < n2) e[k++] = R[j++];
}

void mergeSort(vector<Employee>& e, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(e, left, mid);
        mergeSort(e, mid + 1, right);
        merge(e, left, mid, right);
    }
}

int main() {
    vector<Employee> e = {
        {"Alice", 101, 45000}, {"Bob", 102, 55000}, {"Charlie", 103, 39000},
        {"David", 104, 62000}, {"Eve", 105, 47000}, {"Frank", 106, 72000},
        {"Grace", 107, 51000}, {"Hannah", 108, 68000}, {"Ian", 109, 43000},
        {"Jack", 110, 59000}, {"Karen", 111, 49000}, {"Leo", 112, 80000}
    };

    mergeSort(e, 0, e.size() - 1);

    cout << "Top 3 Highest Paid Employees:\n";
    for (int i = 0; i < 3; i++) {
        cout << e[i].name << " (ID: " << e[i].id << ") - $" << e[i].salary << endl;
    }
}
