#include <bits/stdc++.h>

using namespace std;

void merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> left(arr.begin() + low, arr.begin() + mid + 1);
    vector<int> right(arr.begin() + mid + 1, arr.begin() + high + 1);
    int i = 0, j = 0, k = low;
    while (i < left.size() && j < right.size()) {
        arr[k++] = (left[i] < right[j]) ? left[i++] : right[j++];
    }
    while (i < left.size()) arr[k++] = left[i++];
    while (j < right.size()) arr[k++] = right[j++];
}

void mergeSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high], i = low - 1;
    for (int j = low; j < high; j++)
        if (arr[j] < pivot) swap(arr[++i], arr[j]);
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int randomPartition(vector<int>& arr, int low, int high) {
    int randIdx = low + rand() % (high - low + 1);
    swap(arr[high], arr[randIdx]);
    return partition(arr, low, high);
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void randomizedQuickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = randomPartition(arr, low, high);
        randomizedQuickSort(arr, low, pi - 1);
        randomizedQuickSort(arr, pi + 1, high);
    }
}



void heapSort(vector<int>& arr) {
    //heap sort using priority queue
    priority_queue<int, vector<int>, greater<int>> minHeap(arr.begin(), arr.end());
    for (size_t i = 0; i < arr.size(); i++) {
        arr[i] = minHeap.top();
        minHeap.pop();
    }
    
}

void bubbleSort(vector<int>& arr) {
    for (size_t i = arr.size()-1; i >= 0; i--)
        for (size_t j = 0; j <= i - 1; j++)
            if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
}

void selectionSort(vector<int>& arr) {
    for (size_t i = 0; i < arr.size() - 1; i++) {
        size_t minIdx = i;
        for (size_t j = i + 1; j < arr.size(); j++)
            if (arr[j] < arr[minIdx]) minIdx = j;
        swap(arr[i], arr[minIdx]);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2 || argc > 3) {
        cerr << "Usage: ./sort_test <number_of_elements> [seed]" << endl;
        return 1;
    }

    int n = atoi(argv[1]);
    int seed = (argc == 3) ? atoi(argv[2]) : time(NULL);
    srand(seed);

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) arr[i] = rand() % 100000;

    string algo =
    #ifdef MERGE
        "merge";
    #elif defined(QUICK)
        "quick";
    #elif defined(RNDQUICK)
        "rndquick";
    #elif defined(HEAP)
        "heap";
    #elif defined(BUBBLE)
        "bubble";
    #elif defined(SELECTION)
        "selection";
    #else
        "none";
    #endif

    if (algo == "merge") mergeSort(arr, 0, n - 1);
    else if (algo == "quick") quickSort(arr, 0, n - 1);
    else if (algo == "rndquick") randomizedQuickSort(arr, 0, n - 1);
    else if (algo == "heap") heapSort(arr);
    else if (algo == "bubble") bubbleSort(arr);
    else if (algo == "selection") selectionSort(arr);
    else cerr << "Invalid algorithm!" << endl;

    return 0;
}
