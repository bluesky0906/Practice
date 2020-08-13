def binary_search(n, S, T):
    count = 0
    for t in T:
        left = 0
        right = n
        while left <= right:
            middle = (left + right)//2
            center = S[middle]
            if t == center:
                count += 1
                break
            elif t < center:
                right = middle - 1
            else:
                left = middle + 1
    return count


def main():
    n = int(input())
    S = list(map(int, input().split()))
    int(input())
    T = list(map(int, input().split()))

    print(binary_search(n, S, T))


if __name__ == "__main__":
    main()
