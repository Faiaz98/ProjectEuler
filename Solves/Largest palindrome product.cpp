#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(int num) {
    string strNum = to_string(num);
    int left = 0;
    int right = strNum.length() - 1;
    while (left < right) {
        if (strNum[left] != strNum[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}
int findLargestPalindrome(int N) {
    for (int num = N - 1; num >= 10000; num--) {
        if (isPalindrome(num)) {
            for (int i = 100; i <= 999; i++) {
                if (num % i == 0) {
                    int factor = num / i;
                    if (factor >= 100 && factor <= 999) {
                        return num;
                    }
                }
            }
        }
    }
    return 0;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        int result = findLargestPalindrome(N);
        cout << result << endl;
    }

    return 0;
}
