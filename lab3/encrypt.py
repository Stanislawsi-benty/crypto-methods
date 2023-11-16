from alphabet import alphabet_key_one, alphabet_key_two, alphabet_a, alphabet_key_three

message = input("Введите сообщение: ")


def encrypt():
    en_message = ""
    counter = 0

    for j in message:
        if 0 <= counter <= 3:
            for e in alphabet_a:
                if e == j:
                    ind = alphabet_a.index(e)
                    en_message += alphabet_key_one[ind]
                    counter += 1
                    if counter > 3:
                        counter = 4
                    break
        elif 4 <= counter <= 7:
            for e in alphabet_a:
                if e == j:
                    ind = alphabet_a.index(e)
                    en_message += alphabet_key_two[ind]
                    counter += 1
                    if counter > 7:
                        counter = 8
                    break
        elif 8 <= counter <= 11:
            for e in alphabet_a:
                if e == j:
                    ind = alphabet_a.index(e)
                    en_message += alphabet_key_three[ind]
                    counter += 1
                    if counter > 11:
                        counter = 0
                    break

    return en_message


def decrypt(crypt_message):
    standard_message = ""
    counter = 0

    for j in crypt_message:
        if 0 <= counter <= 3:
            for e in alphabet_key_one:
                if e == j:
                    ind = alphabet_key_one.index(e)
                    standard_message += alphabet_a[ind]
                    counter += 1
                    if counter > 3:
                        counter = 4
                    break
        elif 4 <= counter <= 7:
            for e in alphabet_key_two:
                if e == j:
                    ind = alphabet_key_two.index(e)
                    standard_message += alphabet_a[ind]
                    counter += 1
                    if counter > 7:
                        counter = 8
                    break
        elif 8 <= counter <= 11:
            for e in alphabet_key_three:
                if e == j:
                    ind = alphabet_key_three.index(e)
                    standard_message += alphabet_a[ind]
                    counter += 1
                    if counter > 11:
                        counter = 0
                    break

    return standard_message


if __name__ == '__main__':
    res = encrypt()
    print(res)
    choice = int(input("Хотите расшифровать? (1 - да / 2 - нет): "))
    if choice == 1:
        text = decrypt(res)
        print(text)
    else:
        print(f"Программа завершена")
