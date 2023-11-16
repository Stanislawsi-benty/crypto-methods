#include <iostream>
#include <string>
#include <limits>
#include <Windows.h>

using namespace std;

string encrypt(string message, int len, int* key) {
    string en_message;
    int m = 0;
    bool flag = false;

    for (int i = 0; i < 4; i++) {
        cout << key[i];
    }

    cout << endl;

    for (int step = 0; step < len; step++) {
        bool flag = false;
        char** table = new char* [3];

        for (int i = 0; i < 3; i++) {
            table[i] = new char[4];
        }

        for (; message[m] != '\0';) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 4; j++) {
                    table[i][j] = message[m];
                    if (message[m] == '\0') {
                        table[i][j] = '~';
                    }
                    else if (i * j == 6) {
                        flag = true;
                        break;
                    }
                    else {
                        m++;
                    }
                }
                if (flag == true) {
                    break;
                }
            }
            if (flag == true) {
                break;
            }
        }

        m++;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 4; j++) {
                cout << table[i][j] << "\t";
            }
            cout << endl;
        }

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                if (table[j][key[i]] != '\0') {
                    en_message += table[j][key[i]];
                }
                else {
                    break;
                }
            }
        }

        for (int d = 0; d < 3; d++) {
            delete[] table[d];
        }

        delete[] table;
    }

    return en_message;
}


string decrypt(string en_message, int len, int* key) {
    string decrypted_message;
    int m = 0;
    bool flag = false;

    for (int step = 0; step < len; step++) {
        bool flag = false;
        char** table = new char* [3];

        for (int i = 0; i < 3; i++) {
            table[i] = new char[4];
        }

        for (; en_message[m] != '\0';) {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 3; j++) {
                    table[j][key[i]] = en_message[m];
                    if (j * i == 6) {
                        flag = true;
                        break;
                    }
                    else {
                        m++;
                    }
                }
                if (flag == true) {
                    break;
                }
            }
            if (flag == true) {
                break;
            }
        }

        m++;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 4; j++) {
                cout << table[i][j] << "\t";
            }
            cout << endl;
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 4; j++) {
                if (table[i][j] != '\0') {
                    decrypted_message += table[i][j];
                }
            }
        }

        for (int d = 0; d < 3; d++) {
            delete[] table[d];
        }

        delete[] table;
    }

    return decrypted_message;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    double length;
    int choice;
    string message;
    string result;
    string text;
    string en_message;
    string decrypted_message;

    cout << "Введите сообщение: ";
    getline(cin, message);

    length = ceil(static_cast<double>(message.length()) / 12);

    cout << length << endl;

    int key[4] = {};
    cout << "Введите ключ от 0 до 3 через enter: " << endl;

    for (int i = 0; i < 4; i++)
    {
        cin >> key[i]; 
    }

    result = encrypt(message, length, key);
    for (int i = 0; result[i] != '\0'; i++) {
        if (result[i] != '~') {
            en_message += result[i];
        }
    }

    cout << "Зашифрованное сообщение: " << en_message << endl;
    cout << "Хотите расшифровать сообщение? (1 - да / 2 - нет) ";
    cin >> choice;

    if (choice == 1) {
        text = decrypt(result, length, key);
        for (int i = 0; text[i] != '\0'; i++) {
            if (text[i] != '~') {
                decrypted_message += text[i];
            }
        }
        cout << "Исходное сообщение: " << decrypted_message << endl;
    }
    else {
        cout << "Программа завершена" << endl;
    }
    return 1;
}