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


long long sumEvenFibonacci(long long N) {
    long long a = 1, b = 2, sum = 0;
    
    while (b <= N){
        if (b % 2 == 0){
            sum += b;
        }
        
        long long nextTerm = a + b;
        a = b;
        b = nextTerm;
    }
    
    return sum;
}

int main (){
    int T;
    cin >> T;
    
    while (T--) {
        long long N;
        cin >> N;
        long long result = sumEvenFibonacci(N);
        cout << result << endl;
    }
    return 0;
}
