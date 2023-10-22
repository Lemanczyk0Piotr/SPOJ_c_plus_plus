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


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
		ifstream input("pary.txt"); // Otwórz plik do odczytu
		ofstream output("wyniki4.txt"); // Otwórz plik do zapisu wyników


		string word;
		int liczba;
		while (input >> liczba >> word) {
				int max_length = 0; // Długość najdłuższego spójnego fragmentu
				char current_char = '\0'; // Aktualna litera
				char max_char = '\0'; // Litera z najdłuższego fragmentu
				int current_length = 0; // Długość aktualnego fragmentu

				for (char c : word) {
						if (c == current_char) {
								current_length++;
						} else {
								current_char = c;
								current_length = 1;
						}

						if (current_length > max_length) {
								max_length = current_length;
								max_char = current_char;
						}
				}

				output << max_char << " " << max_length << endl;
		}

		input.close(); // Zamknij plik wejściowy
		output.close(); // Zamknij plik wyjściowy
		return 0;
}

