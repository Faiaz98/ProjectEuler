#include <iostream>
#include <vector>
#include <cmath>

bool isPrime(int num) {
    if (num <= 1)
        return false;
    if (num <= 3)
        return true;

    if (num % 2 == 0 || num % 3 == 0)
        return false;

    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0)
            return false;
    }

    return true;
}

bool isCircularPrime(int num) {
    std::string numStr = std::to_string(num);
    int numLength = numStr.length();

    for (int i = 0; i < numLength; i++) {
        int rotatedNum = std::stoi(numStr.substr(i) + numStr.substr(0, i));
        
        if (!isPrime(rotatedNum))
            return false;
    }

    return true;
}

int sumCircularPrimesBelowN(int N) {
    int sum = 0;
    for (int num = 2; num < N; num++) {
        if (isCircularPrime(num))
            sum += num;
    }
    return sum;
}

int main() {
    int N;
    std::cin >> N;
    int result = sumCircularPrimesBelowN(N);
    std::cout << result << std::endl;
    return 0;
}
