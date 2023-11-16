def encrypt(user_message, user_key):
    encrypted_message, j = '', 0

    for i, letter_m in enumerate(user_message):
        encrypted_message += chr((ord(letter_m) + ord(user_key[j])) % 127)
        j = j + 1 if j < len(user_key) - 1 else 0

    return encrypted_message


def decrypt(encrypted_message, user_key):
    decrypted_message, j = '', 0

    for i, letter_m in enumerate(encrypted_message):
        decrypted_message += chr((ord(letter_m) - ord(user_key[j])) % 127)
        j = j + 1 if j < len(user_key) - 1 else 0

    return decrypted_message


if __name__ == '__main__':
    message, key = input("Введите сообщение: "), input("Введите гамму(ключ): ")
    result = encrypt(message, key)
    print(result)
    choice = int(input("Хотите расшифровать сообщение? (1 - да/2 - нет): "))
    if choice == 1:
        text = decrypt(result, key)
        print(text)
    else:
        print('Программа завершена!')
