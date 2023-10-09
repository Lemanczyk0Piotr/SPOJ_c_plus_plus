#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

// Funkcja sprawdzająca, czy liczba jest potęgą liczby 3
bool isPowerOfThree(int num) {
    if (num <= 0) return false;
    while (num % 3 == 0) {
        num /= 3;
    }
    return num == 1;
}

// Funkcja obliczająca silnię liczby
int factorial(int n) {
    if (n == 0) return 1;
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Funkcja obliczająca sumę silni cyfr liczby
int sumOfFactorialOfDigits(int num) {
    int sum = 0;
    while (num > 0) {
        int digit = num % 10;
        sum += factorial(digit);
        num /= 10;
    }
    return sum;
}

// Funkcja do obliczenia największego wspólnego dzielnika dwóch liczb
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    ifstream input("liczby.txt");
    ofstream output("wyniki4.txt");

    vector<int> numbers;
    int num;

    // Zadanie 4.1
    int powerOfThreeCount = 0;

    while (input >> num) {
        numbers.push_back(num);
        if (isPowerOfThree(num)) {
            powerOfThreeCount++;
        }
    }

    output << "Zadanie 4.1: " << powerOfThreeCount << endl;

    // Zadanie 4.2
    output << "Zadanie 4.2: ";

    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == sumOfFactorialOfDigits(numbers[i])) {
            output << numbers[i] << " ";
        }
    }

		output << endl;

    // Zadanie 4.3
    int maxDlugosc = 0;
    int miejsce = 0;
    int maxNwd = 1;

    for (int i = 0; i < numbers.size(); i++) {
        int currentNwd = numbers[i];
        for (int j = i + 1; j < numbers.size(); j++) {
            currentNwd = gcd(currentNwd, numbers[j]);
            if (currentNwd > 1 && j - i + 1 > maxDlugosc) {
                maxDlugosc = j - i + 1;
                miejsce = i;
                maxNwd = currentNwd;
            }
        }
    }

    output << "Zadanie 4.3: " << numbers[miejsce] << " " << maxDlugosc << " " << maxNwd << endl;

    return 0;
}
