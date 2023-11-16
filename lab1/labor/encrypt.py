from alphabet import alphabet_a, alphabet_key

message = str(input("Введи сообщение: "))


def encrypt():
    enc_mess = ''

    for i in message:
        for j in alphabet_a:
            if i == j:
                ind = alphabet_a.index(j)
                enc_mess += alphabet_key[ind]
    return enc_mess


def decrypt(result):
    standard_mess = ''

    for i in result:
        for j in alphabet_key:
            if i == j:
                ind = alphabet_key.index(j)
                standard_mess += alphabet_a[ind]
    return standard_mess


if __name__ == '__main__':
    res = encrypt()
    print(f"Зашифрованный текст: {res}")
    request = input("Хотите расшифровать сообщение? 1 - да, 2 - нет: ")
    if request == '1':
        ret = decrypt(res)
        print(f"Изначальный текст: {ret}")
    else:
        print("Программа завершена")
