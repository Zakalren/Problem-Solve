import sys

T = int(input())
for _ in range(T):
    P = input()
    N = int(input())
    arr = list(sys.stdin.readline().replace('[', '').replace(']', '').split(','))
    for c in P:
        if c == 'R':
            arr.reverse()
        else:
            if arr:
                arr.pop(0)
            else:
                print('error')
                break

    print('[', end='')
    for a in arr:
        print(a, end='')
        if a != arr[-1]:
            print(',', end='')
    print(']')
