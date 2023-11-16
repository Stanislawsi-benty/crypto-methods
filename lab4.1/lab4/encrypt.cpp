#include <iostream>
#include <string>
#include <Windows.h>
#include "alphabet.h"

using namespace std;

int* key(string key_word) {
    int counter = 0;

    int* digit_key = new int[key_word.length()];

    for (int i = 0; key_word[i] != '\0'; i++) {
        for (int j = 0; alphabet_a[j] != '\0'; j++) {
            if (key_word[i] == alphabet_a[j]) {
                digit_key[i] = j;
                break;
            }
        }
    }

    return digit_key;
};


string encrypt(int* digit_key, int len) {
    string en_message;
    string message;
    int j = 0;

    for (int i = 0; i < len; i++) {
        cout << digit_key[i] << " ";
    }
    cout << endl;

    cout << "Введите сообщение: ";
    getline(cin, message);

    for (int i = 0; message[i] != '\0'; i++) {
        for (int e = 0; alphabet_a[e] != '\0'; e++) {
            if (message[i] == alphabet_a[e]) {
                for (; j < len;) {
                    en_message += alphabet_key[digit_key[j]][e];
                    break;
                }
                break;  
            }
        }
        j++;
        if (j >= len) {
            j = 0;
        }
    }

    return en_message;
};

string decrypt(int* digit_key, int len, string result) {
    string standard_message;
    int j = 0;

    for (int i = 0; result[i] != '\0'; i++) {
        for (; j < len;) {
            for (int e = 0; alphabet_key[digit_key[j]][e] != '\0'; e++) {
                if (result[i] == alphabet_key[digit_key[j]][e]) {
                    standard_message += alphabet_a[e];
                    break;
                }
                
            }
            break;
        }
        j++;
        if (j >= len) {
            j = 0;
        }
    }

    return standard_message;
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    string res;
    string key_word;
    string text;
    int choice;

    cout << "Введите ключ для шифра: ";
    getline(cin, key_word);

    int* digit_key = key(key_word); 

    res = encrypt(digit_key, key_word.length()); 

    cout << "Зашифрованное сообщение: " << res << endl;
    cout << "Хотите расшифровать? (1 - да / 2 - нет): ";
    cin >> choice;

    if (choice == 1) {
        text = decrypt(digit_key, key_word.length(), res);
        cout << "Расшифрованное сообщение: " << text << endl;
    }
    else {
        cout << "Программа завершена!" << endl;
    }
    

    delete[] digit_key;
}
