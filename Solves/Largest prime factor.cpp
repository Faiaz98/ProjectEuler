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


long long largestPrimeFactor(long long N){
    long long largestFactor = -1;
    
    while (N % 2 == 0){
        largestFactor = 2;
        N /= 2;
    }
    
    for (long long i = 3; i * i <= N; i += 2){
        while (N % i == 0) {
            largestFactor = i;
            N /= i;
        }
    }
    
    if (N > 2){
        largestFactor = N;
    }
    
    return largestFactor;
}

int main (){
    int T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        long long result = largestPrimeFactor(N);
        cout<<result<<endl;
    }
    
    return 0;
}