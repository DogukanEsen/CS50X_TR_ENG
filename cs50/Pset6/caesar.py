  
from cs50 import get_string
from sys import argv


def main():
    key = get_key()
    plaintext = get_plaintext("plaintext: ")
    print("ciphertext:", encipher_text(plaintext, key))


def get_key():
    if len(argv) == 2:
        return int(argv[1])
    else:
        print("Usage: python caesar.py key")
        exit(1)


def get_plaintext(prompt):
    return get_string(prompt)


def encipher_text(text, key):
    str = ""
    for char in text:
        if not char.isalpha():
            str += char
        if char.isupper():
            str += chr(((ord(char) - 65) + key) % 26 + 65)
        if char.islower():
            str += chr(((ord(char) - 97) + key) % 26 + 97)
    return str


if __name__ == "__main__":
    main()
                

