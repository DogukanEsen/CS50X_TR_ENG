from cs50 import get_string
from sys import argv


def main():
    if len(argv) == 2:
        yasakli = set()
        file = open(argv[1], "r")
        for line in file:
            yasakli.add(line.strip("\n"))
        file.close()
    else:
        print("Usage: python bleep.py dictionary")
        exit(1)
    text = get_string("What message would you like to censor?\n")
    print(sansurleme(text, yasakli))






def sansurleme(text, yasakli):
    sansurlu = ""
    harf = text.split(" ")
    for word in harf:
        if word.lower() in yasakli:
            sansurlu += ("*" * len(word)) + " "
        else:
            sansurlu += word + " "
    return sansurlu


if __name__ == "__main__":
    main()