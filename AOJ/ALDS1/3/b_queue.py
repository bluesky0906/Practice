from collections import deque


def main():
    n, q = [int(i) for i in input().split()]
    P = [input().split() for i in range(n)]
    process = deque()
    process.extend([
        {'name': p[0], 'time': int(p[1])}
        for p in P
    ])
    sum_time = 0
    while len(process):
        p = process.popleft()
        if p['time'] <= q:
            sum_time += p['time']
            print(p['name'], sum_time)
        else:
            sum_time += q
            p['time'] -= q
            process.append(p)


if __name__ == "__main__":
    main()
