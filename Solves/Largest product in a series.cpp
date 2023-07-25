#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


long long int greatestProduct(int N, int K, string num) {
    long long int maxProduct = 0;

    for (int i = 0; i <= N - K; i++) {
        long long int product = 1;
        for (int j = 0; j < K; j++) {
            product *= (num[i + j] - '0');
        }
        maxProduct = max(maxProduct, product);
    }

    return maxProduct;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;
        string num;
        cin >> num;
        long long int result = greatestProduct(N, K, num);
        cout << result << endl;
    }

    return 0;
}
