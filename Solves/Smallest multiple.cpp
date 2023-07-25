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


long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long lcm(long long a, long long b) {
    return (a * b) / gcd(a, b);
}

long long smallestMultiple(int N){
    long long result = 1;
    for (int i = 2; i <= N; i++){
        result = lcm(result, i);
    }
    return result;
}

int main (){
    int T;
    cin >> T;
    
    while (T--){
        int N;
        cin >> N;
        long long result = smallestMultiple(N);
        cout << result << endl;
    }
    return 0;
}
