#include <iostream>
#include <vector>
using namespace std;

const int NUM_DIGITS = 10;

vector<int> stringToDigits(string str) {
    vector<int> digits;
    for (char ch : str) {
        digits.push_back(ch - '0');
    }
    return digits;
}

string digitsToString(vector<int>& digits) {
    string str;
    for (int digit : digits) {
        str += to_string(digit);
    }
    return str;
}

string firstTenDigitsSum(vector<string>& numbers) {
    vector<int> sum(NUM_DIGITS + 5, 0); // Increase size to handle carry

    for (string num : numbers) {
        vector<int> digits = stringToDigits(num);
        int carry = 0;

        for (int i = NUM_DIGITS + 4; i >= 0; i--) { // Start from larger index for more accurate carry handling
            int tempSum = sum[i] + (i >= 5 ? digits[i - 5] : 0) + carry; // Use i >= 5 to handle the offset due to larger size
            sum[i] = tempSum % 10;
            carry = tempSum / 10;
        }
    }

    string result = digitsToString(sum);
    size_t firstNonZero = result.find_first_not_of('0');
    if (firstNonZero != string::npos) {
        return result.substr(firstNonZero, NUM_DIGITS);
    }
    return "0";
}

int main() {
    int N;
    cin >> N;

    vector<string> numbers(N);
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }

    string result = firstTenDigitsSum(numbers);
    cout << result << endl;

    return 0;
}
