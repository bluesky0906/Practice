def main():
    formula = input().split()
    stack = []
    for f in formula:
        if f == '+':
            stack.append(stack.pop() + stack.pop())
        elif f == '-':
            a = stack.pop()
            b = stack.pop()
            stack.append(b - a)
        elif f == '*':
            stack.append(stack.pop() * stack.pop())
        else:
            stack.append(int(f))
    print(stack.pop())


if __name__ == "__main__":
    main()
