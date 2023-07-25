#include <iostream>
#include <vector>
using namespace std;

const vector<string> ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
const vector<string> teens = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
const vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
const vector<string> thousands = {"", "Thousand", "Million", "Billion"};

string numberToWordsHelper(int num); // Forward declaration

string numberToWords(int num) {
    if (num == 0) return "Zero";
    string words;
    int i = 0;

    while (num > 0) {
        if (num % 1000 != 0) {
            words = numberToWordsHelper(num % 1000) + thousands[i] + " " + words;
        }
        num /= 1000;
        i++;
    }

    // Remove any leading/trailing spaces
    size_t start = words.find_first_not_of(' ');
    size_t end = words.find_last_not_of(' ');
    words = words.substr(start, end - start + 1);

    return words;
}

string numberToWordsHelper(int num) {
    if (num == 0) return "";
    else if (num < 10) return ones[num] + " ";
    else if (num < 20) return teens[num - 10] + " ";
    else if (num < 100) return tens[num / 10] + " " + numberToWordsHelper(num % 10);
    else return ones[num / 100] + " Hundred " + numberToWordsHelper(num % 100);
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        string result = numberToWords(N);
        cout << result << endl;
    }

    return 0;
}
