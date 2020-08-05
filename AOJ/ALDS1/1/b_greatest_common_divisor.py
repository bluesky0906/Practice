def gcd(a, b):
    if a < b:
        a, b = b, a
    while a % b != 0:
        c = a % b
        a = b
        b = c
    return b


def main():
    a, b = list(map(int, input().split()))

    print(gcd(a, b))


if __name__ == "__main__":
    main()