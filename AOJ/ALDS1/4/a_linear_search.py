def main():
    int(input())
    S = [int(i) for i in input().split()]
    int(input())
    T = [int(i) for i in input().split()]

    count = 0
    for t in T:
        if t in S:
            count += 1

    print(count)


if __name__ == "__main__":
    main()
