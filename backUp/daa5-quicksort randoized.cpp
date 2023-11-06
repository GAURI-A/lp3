#include <bits/stdc++.h>
using namespace std;

// Function to partition the array for the deterministic variant
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Deterministic Quick Sort
void quickSortDeterministic(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);

        quickSortDeterministic(arr, low, pivot - 1);
        quickSortDeterministic(arr, pivot + 1, high);
    }
}

// Randomized Quick Sort
int partitionRandom(vector<int>& arr, int low, int high) {
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(low, high);

    int random = dist(mt);
    swap(arr[random], arr[high]);

    return partition(arr, low, high);
}

void quickSortRandomized(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = partitionRandom(arr, low, high);

        quickSortRandomized(arr, low, pivot - 1);
        quickSortRandomized(arr, pivot + 1, high);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);

    // Initialize array with random values
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(1, 10000);

    for (int i = 0; i < n; i++) {
        arr[i] = dist(mt);
    }

    // Perform deterministic quick sort and measure execution time
    vector<int> deterministicArr(arr);
    auto startTime = chrono::high_resolution_clock::now();
    quickSortDeterministic(deterministicArr, 0, n - 1);
    auto endTime = chrono::high_resolution_clock::now();
    chrono::duration<double> deterministicTime = endTime - startTime;

    // Perform randomized quick sort and measure execution time
    vector<int> randomizedArr(arr);
    startTime = chrono::high_resolution_clock::now();
    quickSortRandomized(randomizedArr, 0, n - 1);
    endTime = chrono::high_resolution_clock::now();
    chrono::duration<double> randomizedTime = endTime - startTime;

    // Verify that both variants produce the same result
    if (deterministicArr != randomizedArr) {
        cout << "Sorting algorithms produced different results!" << endl;
    } else {
        cout << "Sorting algorithms produced identical results." << endl;
    }

    cout << "Deterministic Quick Sort took " << deterministicTime.count() << " seconds." << endl;
    cout << "Randomized Quick Sort took " << randomizedTime.count() << " seconds." << endl;

    return 0;
}
