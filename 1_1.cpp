/*Даны два массива целых чисел одинаковой длины A[0..n-1] и B[0..n-1].Необходимо найти
первую пару индексов i0 и j0, , такую что A[i0] + B[j0] = max {A[i] + B[j], где 0 <= i
< n, 0 <= j < n, i <= j}. Время работы - O(n). n ≤ 100000.
*/
#include <iostream>
#include <vector>
#include <utility>
using std::cin;
using std::pair;
using std::vector;
using std::cout;
using std::istream;

pair<int, int> maxSum(int n, const vector<int>& arr1,
    const vector<int>& arr2) {
    int i0 = 0;
    int j0 = 0;
    int i_max = 0;
    for (int i = 1, j = 1; j < n; j++, i++) {
        if (arr1[i] > arr1[i_max]) {
            i_max = i;
        }
        if (arr2[j] + arr1[i_max] > arr1[i0] + arr2[j0]) {
            j0 = j;
            i0 = i_max;
        }
    }
    return std::make_pair(i0, j0);
}

void fill_array(vector<int>& arr, const size_t& n, istream& stream) {
    for (size_t i = 0; i < n; i++) {
        int elem;
        stream >> elem;
        arr.push_back(elem);
    }
}
