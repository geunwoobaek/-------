#include <bits/stdc++.h>
using namespace std;
void Merge1(const vector<int>& vec, vector<int>& answer, int left, int right);
void mergeSort(vector<int>& arr, int l, int r);
void Merge1(const vector<int>& vec, vector<int>& answer, int left, int right);
int main()
{
    time_t start, end;
    double result;
    int i, j;
    int sum = 0;

    vector<int> vec;
    vector<int> vec2;
    vector<int> answer;
    for (int i = 0;i <= 100000;i++) vec.push_back(rand() % 200000000);

    start = clock(); //시간 측정 시작
    mergeSort(vec, 0, 100000);
    //Merge1(vec, answer, 0, 100000);
    end = clock(); //시간 측정 시작
    result = (double)(end - start);
    printf("%f\n", result); //결과 출력

    start = clock(); //시간 측정 시작
    sort(vec.begin(), vec.end());
    end = clock(); //시간 측정 시작
    result = (double)(end - start);
    printf("%f\n", result); //결과 출력

    cout << "end";

    return 0;
}
void merge(vector<int> &arr, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    vector<int> L(n1), R(n2);

    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r]

    // Initial index of first subarray
    int i = 0;

    // Initial index of second subarray
    int j = 0;

    // Initial index of merged subarray
    int k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of
    // L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of
    // R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// l is for left index and r is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(vector<int> &arr, int l, int r) {
    if (l >= r) {
        return;//returns recursively
    }
    int m = (l + r - 1) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}
void Merge1(const vector<int>& vec, vector<int>& answer, int left, int right)
{
    if (right == left)
    {
        answer.push_back(vec[left]);
        return;
    }
    vector<int> left_vec;
    vector<int> right_vec;
    int mid = (left + right)>>1;
    Merge1(vec, left_vec, left, mid);
    Merge1(vec, right_vec, mid + 1, right);
    for (int idx = left, left_idx = 0, right_idx = 0; idx <= right; idx++)
    {
        if (left_idx == left_vec.size()) answer.push_back(right_vec[right_idx++]); //왼쪽 다 탐색했을떄
        else if (right_idx == right_vec.size()) answer.push_back(left_vec[left_idx++]); //오른쪽 다 탐색했을때
        else if (left_vec[left_idx] > right_vec[right_idx]) answer.push_back(right_vec[right_idx++]); //비교해서 작은값넣기
        else answer.push_back(left_vec[left_idx++]);
    }
}
