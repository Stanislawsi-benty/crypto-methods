const char alphabet_a[153] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '�', '�',
'�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�',
'�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�',
'�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�',
'�', '�', '�', '�', '�', '�', '�', '�', '�', '�', ',', '.', '-', '*', '/', '+', '_', '=',
'(', ')', '&', '?', '!', '[', ']', '{', '}', '#', '@', '~', '<', '>', '%', '1', '2', '3',
'4', '5', '6', '7', '8', '9', '0', ' ', '$'
};

const char alphabet_key_one[153] = {'Q', 'W', 'E', 'R', 'T', 'Y', 'A', 'S', 'D', 'F', 'G', 'H', 'Z', 'X', 'C', 'V', 'B', 'N',
'U', 'I', 'O', 'P', 'J', 'K', 'L', 'M', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
',', '.', '-', '*', '/', '+', '_', '=', '(', ')', '&', '?', '!', '[', ']', 'q', 'w', 'e',
'r', 't', 'y', 'a', 's', 'd', 'f', 'g', 'h', 'z', 'x', 'c', 'v', 'b', 'n', 'u', 'i', 'o',
'p', 'j', 'k', 'l', 'm', '{', '}', '#', '@', '~', '<', '>', '%', '�', '�', '�', '�', '�',
'�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�',
'�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�',
'�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�',
'�', '�', '�', '�', '�', '�', '�', '$', ' '
};

const char alphabet_key_two[153] = {'m', '(', 'X', 'k', '�', '[', '�', 't', 'h', 'a', '�', '�', '�', '!', 'g', '�', '7',
'I', 'Q', '�', '+', '#', 'j', '�', '�', '{', 'c', 'q', '�', 'f', '�', 's', 'L', '�', 'u', '�', '~', 'v', 'H', '�',
'�', '4', '/', 'Z', '9', '�', '�', '$', 'p', ',', '�', '6', '�', '�', 'R', 'o', '@', ' ', '*', '�', '?', '}', '2', '�',
'J', 'Y', '�', '�', '=', '�', '8', '�', 'y', ']', '�', '�', '�', 'z', '�', '�', 'O', 'K', '&', 'n', '_', 'e', '�', '�',
'M', '�', '�', '�', 'E', 'A', 'N', 'd', '%', '�', 'C', '�', '�', '�', '-', 'T', '�', '�', '�', 'U', 'V', '�', '�', 'w',
'F', '>', '�', '�', '�', 'b', 'P', '�', '�', 'G', '<', '�', '5', ')', '�', '�', '�', '�', 'i', '�', 'l', '�', '�', 'S',
'�', 'B', '�', '�', '0', 'r', '.', '�', '�', 'D', '�', '�', '3', '1', 'W', '�', 'x'};

const char alphabet_key_three[153] = { 'A', 'k', 'U', '/', 'D', '�', '�', '8', '!', 'H', '$', 'J', '�', 'C', 'l', '�', 'O',
'o', '�', '_', 'S', '[', '�', '�', 'a', 'v', '#', 'L', '�', '�', '-', 'e', 'y', 'c', '�', '�', '�', 'R', '�', 'w', '~', '�',
'W', 'E', ',', '}', 'g', 't', '�', '�', '�', 'p', '�', 'N', 'Y', 'd', '�', '�', '�', '�', 'f', '?', '�', 'Z', '5', 'G', 'b',
'�', 'P', '9', 'X', '3', '�', '�', '�', '�', '�', '<', '%', 'j', '=', '�', '�', '*', '�', 'n', '2', '�', '�', '�', '�', '�',
'�', '�', 'F', '�', '�', '�', '�', '�', '�', 's', '�', 'V', '(', '.', '7', ')', 'M', '4', '�', '0', 'q', '�', '�', '�', '6',
'i', '�', '�', ']', '�', '�', '�', 'r', 'B', '�', '>', '�', '�', '�', 'x', '�', 'Q', '{', '@', '�', '�', 'm', ' ', '&', 'u',
'�', 'K', 'T', 'z', '+', '�', '�', '�', '1', 'I', 'h' };