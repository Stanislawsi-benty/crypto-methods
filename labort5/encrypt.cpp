#include <iostream>
#include <string>
#include <limits>
#include <Windows.h>

using namespace std;

string encrypt(string message, int rows, int cols, int* key) {
    string en_message;

    char** table = new char* [rows];

    for (int i = 0; i < 5; i++) {
        cout << key[i];
    }

    cout << endl;

    for (int i = 0; i < rows; i++) {
        table[i] = new char[cols];
    }


    for (int m = 0; message[m] != '\0';) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                table[i][j] = message[m];
                if (message[m] == '\0') {
                    table[i][j] = '~';
                }
                else {
                    m++;
                }
            }
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << table[i][j] << "\t";
        }
        cout << endl;
    }


    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            if (table[j][key[i]] != '\0') {
                en_message += table[j][key[i]];
            }
            else {
                break;
            }
        }
    }

    for (int d = 0; d < rows; d++) {
        delete[] table[d];
    }

    delete[] table;

    return en_message;
    
}

string decrypt(string en_message, int rows, int cols, int* key) {
    string decrypted_message;
    char** table = new char* [rows];

    for (int i = 0; i < rows; i++) {
        table[i] = new char[cols];
    }

    int index = 0;
    for (int i = 0; i < cols; i++) {
        int col = key[i];
        for (int j = 0; j < rows; j++) {
            table[j][col] = en_message[index++];
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << table[i][j] << "\t";
        }
        cout << endl;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            decrypted_message += table[i][j];
        }
    }

    for (int d = 0; d < rows; d++) {
        delete[] table[d];
    }
    delete[] table;

    return decrypted_message;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    int m;
    int n;
    int choice;
    int count;
    string message;
    string result;
    string text;
    string en_message;
    string decrypted_message;
    
    cout << "Требуется ввести размерность таблицы подстановки MxN" << endl;
    cout << "Введите M(количество строк): ";
    cin >> m;
    cout << "Введите N(количество столбцов): ";
    cin >> n;
    cout << "Вы можете зашифровать сообщение не более " << m * n << " символов!" << endl;

    while ((getchar()) != '\n');

    cout << "Введите сообщение: ";
    getline(cin, message);
    
    int* key = new int[n];

    for (int i = 0; i < n; i++) {
        cout << "Введите ключ через enter от 0 до " << n - 1 << ": ";
        cin >> key[i];
        cout << "Value of " << i << " element is " << key[i] << endl;
    }

    result = encrypt(message, m, n, key);
    for (int i = 0; result[i] != '\0'; i++) {
        if (result[i] != '~') {
            en_message += result[i];
        }
    }

    cout << "Зашифрованное сообщение: " << en_message << endl;
    cout << "Хотите расшифровать сообщение? (1 - да / 2 - нет) ";
    cin >> choice;

    if (choice == 1) {
        text = decrypt(result, m, n, key);
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