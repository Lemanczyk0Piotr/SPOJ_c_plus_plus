#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Funkcja zliczająca liczbę zer i jedynek w zapisie binarnym
pair<int, int> countZerosAndOnes(const string& binaryNumber) {
    int zeros = 0;
    int ones = 0;

    for (char c : binaryNumber) {
        if (c == '0') {
            zeros++;
        } else if (c == '1') {
            ones++;
        }
    }

    return make_pair(zeros, ones);
}

// Funkcja sprawdzająca czy liczba jest podzielna przez 2
bool isDivisibleBy2(const string& binaryNumber) {
    int lastDigit = binaryNumber.back() - '0';
    return lastDigit % 2 == 0;
}

// Funkcja sprawdzająca czy liczba jest podzielna przez 8
bool isDivisibleBy8(const string& binaryNumber) {
    int length = binaryNumber.length();
    if (length < 3) {
        return false;  // Liczba o długości mniejszej niż 3 nie może być podzielna przez 8
    }

    int lastThreeDigits = stoi(binaryNumber.substr(length - 3, 3), nullptr, 2);
    return lastThreeDigits % 8 == 0;
}

int main() {
    ifstream inputFile("liczby.txt");
    ofstream outputFile("wynik4.txt");

    if (!inputFile) {
        cout << "Błąd przy otwieraniu pliku liczby.txt." << endl;
        return 1;
    }

    if (!outputFile) {
        cout << "Błąd przy otwieraniu pliku wynik4.txt." << endl;
        return 1;
    }

    int lineNumber = 0;
    int moreZerosCount = 0;
    int divisibleBy2Count = 0;
    int divisibleBy8Count = 0;
    string line;
    string smallestNumber;
    string largestNumber;
    int smallestLineNumber = -1;
    int largestLineNumber = -1;

    while (getline(inputFile, line)) {
        lineNumber++;

        pair<int, int> zerosAndOnes = countZerosAndOnes(line);
        int zeros = zerosAndOnes.first;
        int ones = zerosAndOnes.second;

        if (zeros > ones) {
            moreZerosCount++;
        }

        if (isDivisibleBy2(line)) {
            divisibleBy2Count++;
        }

        if (isDivisibleBy8(line)) {
            divisibleBy8Count++;
        }

        if (smallestLineNumber == -1 || line < smallestNumber) {
            smallestNumber = line;
            smallestLineNumber = lineNumber;
        }

        if (largestLineNumber == -1 || line > largestNumber) {
            largestNumber = line;
            largestLineNumber = lineNumber;
        }
    }

    inputFile.close();

    outputFile << "Zadanie 4.1: " << moreZerosCount << endl;
    outputFile << "Zadanie 4.2: Podzielne przez 2: " << divisibleBy2Count << ", podzielne przez 8: " << divisibleBy8Count << endl;
    outputFile << "Zadanie 4.3: Najmniejsza liczba (wiersz): " << smallestLineNumber << ", największa liczba (wiersz): " << largestLineNumber << endl;

    outputFile.close();

    cout << "Program zakończył działanie." << endl;

    return 0;
}
