def profit(R, n):
    max_profit = R[1] - R[0]
    min_n = R[0]
    for i in range(1, n-1):
        if min_n > R[i]:
            min_n = R[i]
        if max_profit < R[i+1] - min_n:
            max_profit = R[i+1] - min_n
    return max_profit


def main():
    n = int(input())
    R = [int(input()) for i in range(n)]

    print(profit(R, n))


if __name__ == "__main__":
    main()
