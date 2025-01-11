#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// 퀵 정렬
void quickSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;
    int pivot = arr[left];
    int i = left + 1, j = right;
    while (i <= j) {
        while (i <= right && arr[i] <= pivot) i++;
        while (j >= left && arr[j] > pivot) j--;
        if (i < j) swap(arr[i], arr[j]);
    }
    swap(arr[left], arr[j]);
    quickSort(arr, left, j - 1);
    quickSort(arr, j + 1, right);
}

// 합병 정렬
void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    for (int t = 0; t < temp.size(); t++) {
        arr[left + t] = temp[t];
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

// 힙 정렬
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// 버블 정렬
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
        }
    }
}

// 선택 정렬
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) min_idx = j;
        }
        swap(arr[i], arr[min_idx]);
    }
}

// 쉘 정렬
void shellSort(vector<int>& arr) {
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}

// 배열 출력
void printArray(const vector<int>& arr) {
    for (int num : arr) cout << num << " ";
    cout << endl;
}

// 메뉴 기반 프로그램
int main() {
    srand(time(0));
    int n;

    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) arr[i] = rand() % 100; // 0 ~ 99 사이의 난수 생성

    cout << "Original Array: ";
    printArray(arr);

    int choice;
    do {
        cout << "\nChoose a sorting algorithm:\n";
        cout << "1. Quick Sort\n";
        cout << "2. Merge Sort\n";
        cout << "3. Heap Sort\n";
        cout << "4. Bubble Sort\n";
        cout << "5. Selection Sort\n";
        cout << "6. Shell Sort\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        vector<int> temp = arr; // 원본 배열 유지

        switch (choice) {
        case 1:
            quickSort(temp, 0, n - 1);
            cout << "Sorted Array (Quick Sort): ";
            printArray(temp);
            break;
        case 2:
            mergeSort(temp, 0, n - 1);
            cout << "Sorted Array (Merge Sort): ";
            printArray(temp);
            break;
        case 3:
            heapSort(temp);
            cout << "Sorted Array (Heap Sort): ";
            printArray(temp);
            break;
        case 4:
            bubbleSort(temp);
            cout << "Sorted Array (Bubble Sort): ";
            printArray(temp);
            break;
        case 5:
            selectionSort(temp);
            cout << "Sorted Array (Selection Sort): ";
            printArray(temp);
            break;
        case 6:
            shellSort(temp);
            cout << "Sorted Array (Shell Sort): ";
            printArray(temp);
            break;
        case 7:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 7);

    return 0;
}