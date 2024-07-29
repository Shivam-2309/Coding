#include <bits/stdc++.h>
#include <vector>

// Function to count the number of set bits in n
int countSetBits(int n) {
    int count = 0;
    while (n > 0) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

// Function to generate patterns of set bits
void generatePatterns(int setBitsCount, std::vector<int> &patterns) {
    int maxPattern = (1 << setBitsCount) - 1; // Generate 2^setBitsCount - 1
    for (int i = 0; i <= maxPattern; ++i) {
        patterns.push_back(i);
    }
}

// Function to apply a pattern to the original number
int applyPattern(int n, int pattern) {
    int result = n;
    int patternBitIndex = 0;

    for (int i = 0; i < 32; ++i) {
        if (n & (1 << i)) { // If the ith bit in n is set
            if (pattern & (1 << patternBitIndex)) {
                result |= (1 << i); // Set the bit in result
            } else {
                result &= ~(1 << i); // Unset the bit in result
            }
            patternBitIndex++;
        }
    }
    return result;
}

int main() {
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;

    int setBitsCount = countSetBits(n);
    std::vector<int> patterns;

    generatePatterns(setBitsCount, patterns);

    std::cout << "Original number: " << n << " (Binary: " << std::bitset<32>(n) << ")\n";
    std::cout << "Patterns of set bits:\n";
    for (int pattern : patterns) {
        int modifiedNumber = applyPattern(n, pattern);
        std::cout << modifiedNumber << " (Binary: " << std::bitset<32>(modifiedNumber) << ")\n";
    }

    return 0;
}
