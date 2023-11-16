#include <iostream>
#include <string>
#include <Windows.h>
#include "alphabet.h"

using namespace std;


string encrypt() {
	string en_message;
	string message;
	int counter = 0;
	int counter_2 = 1;
	

	cout << "Введите сообщение для шифра: ";
	getline(cin, message);

	for (int i = 0; message[i] != '\0'; i++) {
		for (int j = 0; alphabet_a[j] != '\0'; j++) {
			if (message[i] == alphabet_a[j]) {
				counter = j;
				if (counter_2 % 2 == 0) {
					en_message += alphabet_key_two[counter];
				}
				else if (counter_2 % 3 == 0) {
					en_message += alphabet_key_three[counter];
				}
				else {
					en_message += alphabet_key_one[counter];
				}
				counter_2 += 1;
				if (counter_2 > 3) {
					counter_2 = 1;
				}
				break;
			}
		}
	}

	return en_message;
};

string decrypt(string result) {
	string message;
	int counter = 0;
	int counter_2 = 1;

	for (int i = 0; result[i] != '\0'; i++) {
		if (counter_2 % 2 == 0) {
			for (int j = 0; alphabet_key_two[j] != '\0'; j++) {
				if (alphabet_key_two[j] == result[i]) {
					counter = j;
					message += alphabet_a[counter];
					break;
				}
			}
		}
		else if (counter_2 % 3 == 0) {
			for (int j = 0; alphabet_key_three[j] != '\0'; j++) {
				if (alphabet_key_three[j] == result[i]) {
					counter = j;
					message += alphabet_a[counter];
					break;
				}
			}
		}
		else {
			for (int j = 0; alphabet_key_one[j] != '\0'; j++) {
				if (alphabet_key_one[j] == result[i]) {
					counter = j;
					message += alphabet_a[counter];
					break;
				}
			}
		}
		counter_2 += 1;
		if (counter_2 > 3) {
			counter_2 = 1;
		}

	}
	return message;
};


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	int choice;
	string unresult;
	string result = encrypt();

	cout << "Зашифрованное сообщение: " << result << endl;
	cout << "Хотите расшифровать сообщение? (1 - да / 2 - нет)" << endl;
	cin >> choice;

	if (choice == 1) {
		unresult = decrypt(result);
		cout << unresult;
	}
	else {
		cout << "Программа завершена";
	}



	return 1;
}