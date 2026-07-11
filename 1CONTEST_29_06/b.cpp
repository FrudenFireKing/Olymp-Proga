#include <iostream>

using namespace std;


int main() {
    int count;

    cin >> count;
    int nums[7];

    for (int i = 0; i < count; i++) {

        int sum = 0;
        int max_val = -100;
        for (int j = 0; j < 7; j++) {
            cin >> nums[j];
            sum += nums[j];
            if (max_val < nums[j]) {
                max_val = nums[j];
            } 
        }

        int answer = 2 * max_val - sum;
        cout << answer << "\n";
    }
    return 0;
}