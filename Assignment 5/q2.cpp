#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int calculateMinimumCost(vector<int> lengths) {
    int totalCost = 0;
    priority_queue<int, vector<int>, greater<int> > minHeap;

    for (size_t i = 0; i < lengths.size(); ++i) {
        minHeap.push(lengths[i]);
    }

    while (minHeap.size() > 1) {
        int firstLength = minHeap.top();
        minHeap.pop();
        int secondLength = minHeap.top();
        minHeap.pop();

        int combinedLength = firstLength + secondLength;
        minHeap.push(combinedLength);
        totalCost += combinedLength;
    }

    return totalCost;
}

int main() {
    int arr[] = {4, 3, 2, 6};
    vector<int> ropeLengths(arr, arr + sizeof(arr) / sizeof(arr[0]));
    cout << calculateMinimumCost(ropeLengths);
    return 0;
}