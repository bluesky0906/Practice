
def show(A, n):
    for i in range(n):
        if i != n-1:
            print(A[i], end=' ')
        else:
            print(A[i])


def insertionSort(A, n):
    for i in range(1, n):
        v = A[i]
        j = i - 1
        while j >= 0 and A[j] > v:
            A[j+1] = A[j]
            j -= 1
        A[j+1] = v
        show(A, n)


def main():
    n = int(input())
    A = list(map(int, input().split()))

    insertionSort(A, n)


if __name__ == "__main__":
    main()