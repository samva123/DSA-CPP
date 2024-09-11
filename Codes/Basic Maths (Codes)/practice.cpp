#include <iostream>

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int countPrimesInRange( int end) {
    int count = 0;
    for (int i = 2; i <= end; ++i) {
        if (isPrime(i)) {
            ++count;
        }
    }
    return count;
}

int main() {
    int start, end;

    // Input the range from the user
    
    std::cout << "Enter the end of the range: ";
    std::cin >> end;

    // Count and display the number of prime numbers in the range
    int primeCount = countPrimesInRange(end);
    std::cout << "Number of prime numbers between "  << end<< ": " << primeCount << std::endl;

    return 0;
}
