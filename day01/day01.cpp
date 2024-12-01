#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    FILE * f = fopen("day01/day01_data.txt", "r");

    int32_t num1, num2;
    vector<int32_t> v1, v2;
    while (fscanf(f, "%d %d\n", &num1, &num2) == 2) {
        v1.push_back(num1);
        v2.push_back(num2);
    }

    // Part 1
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    // sum of diffs
    uint64_t diff_sum = 0;
    for (int i = 0; i < v1.size(); i++) {
        diff_sum += abs(v1[i] - v2[i]);
    }
    printf("Diff sum: %lu\n", diff_sum);

    // Part 2
    uint64_t mult_sum = 0;
    for (int i = 0; i < v1.size(); i++) {
        uint64_t times = 0;
        for (int j = 0; j < v2.size(); j++) {
            if (v1[i] == v2[j])
                times++;
        }
        mult_sum += v1[i] * times;
    }
    printf("Mult sum: %lu\n", mult_sum);
}
