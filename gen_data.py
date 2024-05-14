import random
import sys
import uuid

N = 10000000
START = 501
END = 99950


def main():
    with open(sys.argv[1], "w") as f:
        for _ in range(N):
            f.write(f"{random.randint(START, END)}\n")


if __name__ == "__main__":
    main()
