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

long long sumMultiplesOfThreeOrFive(long long N) {
    N--;

    long long sumThree = (3 * (N / 3) * (N / 3 + 1)) / 2;
    long long sumFive = (5 * (N / 5) * (N / 5 + 1)) / 2;
    long long sumFifteen = (15 * (N / 15) * (N / 15 + 1)) / 2;

    return sumThree + sumFive - sumFifteen;
}

int main() {
    int T;
    cin >> T;
    
    while (T--){
        long long N;
        cin >> N;
        long long result = sumMultiplesOfThreeOrFive(N);
        cout<<result<<endl;
    }
    
    return 0;
}
