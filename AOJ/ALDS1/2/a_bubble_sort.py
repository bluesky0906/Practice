def show(A, n):
    for i in range(n):
        if i != n-1:
            print(A[i], end=' ')
        else:
            print(A[i])


def bubble_sort(A, n):
    flag = 1
    count = 0
    while flag:
        flag = 0
        for i in range(n-1):
            if A[i] > A[i+1]:
                A[i], A[i+1] = A[i+1], A[i]
                flag = 1
                count += 1
    show(A, n)
    print(count)


def main():
    n = int(input())
    A = list(map(int, input().split()))
    bubble_sort(A, n)


if __name__ == "__main__":
    main()
