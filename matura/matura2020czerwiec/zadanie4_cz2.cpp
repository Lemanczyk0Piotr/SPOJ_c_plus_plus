#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool isPrime(int num) {
		if (num <= 1) return false;
		for (int i = 2; i * i <= num; i++) {
				if (num % i == 0) return false;
		}
		return true;
}

pair<int, int> findPrimePair(int evenNumber) {
		for (int i = 2; i < evenNumber; i++) {
				if (isPrime(i) && isPrime(evenNumber - i)) {
						return make_pair(i, evenNumber - i);
				}
		}
		return make_pair(2, evenNumber - 2);
}

int main() {
		ifstream inputFile("pary.txt");
		ofstream outputFile("wyniki4.txt");

		int number;
		string word;
		while (inputFile >> number >> word) {
				if (number % 2 == 0 && number > 4) {
						pair<int, int> primePair = findPrimePair(number);
						outputFile << number << " " << primePair.first << " " << primePair.second << endl;
				}
		}

		inputFile.close();
		outputFile.close();

		return 0;
}
