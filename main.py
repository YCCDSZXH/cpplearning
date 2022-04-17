def isprime(a):
    for i in range(2, a):
        if a % i == 0:
            return False
    else:
        return True


x = []
for n in range(2, i):
    if isprime(n):
        x.append(n)

c = 0
for i in range(4, 100, 2):

    if i % 10 == i:
        print(i, '=', sep='', end='\t')
    else:
        print(i, '=', sep='', end='')

    for a in range(len(x)): # 这操作......
        for b in range(len(x)):
            if i == x[a]+x[b]:
                if x[a] % 10 == x[a]:
                    print(' ', x[a], '+', sep='', end='')
                else:
                    print(x[a], '+', sep='', end='')
                if x[b] % 10 == b:
                    print(' ', x[b], sep='', end='')
                else:
                    print(x[b], sep='', end='\t')
                c += 1
                if c % 5 == 0:
                    print()
                break
