import math


def is_prime(a):
    sqrt_a = int(math.sqrt(a))
    for i in range(2, sqrt_a + 1):
        if a % i == 0:
            return False
    return True


def main():
    n = int(input())
    count = 0

    for i in range(n):
        a = int(input())
        if is_prime(a):
            count += 1

    print(count)


if __name__ == "__main__":
    main()
