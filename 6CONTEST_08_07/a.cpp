#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void findMaxXor(const vector<int>& nums, int n, int k, int index, int current_k, int current_xor, int& max_xor) {
    if (current_k == k) {
        if (current_xor > max_xor) {
            max_xor = current_xor;
        }
        return;
    }

    if (index >= n) {
        return;
    }

    findMaxXor(nums, n, k, index + 1, current_k + 1, current_xor ^ nums[index], max_xor);
    findMaxXor(nums, n, k, index + 1, current_k, current_xor, max_xor);
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int max_xor = -1;
    findMaxXor(nums, n, k, 0, 0, 0, max_xor);

    cout << max_xor << endl;

    return 0;
}
