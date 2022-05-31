def isprime(a):
    for i in range(2, a):
        if a % i == 0:
            return False
    else:
        return True


primelist = [] #将所有的素数放到一个列表里, 防止多次计算浪费时间
for i in range(2, 100):
    if isprime(i):
        primelist.append(i)

for i in range(2, 400, 2):
    sign = 0
    for numb1 in primelist:
        for numb2 in primelist: # 两层循环, 将 numb1 和 numb2 取出来
            if numb1 + numb2 == i: # 如果 numb1+numb2 就是 i 就将 sign 改为 1
                print(numb1,numb2,numb1+numb2)
                sign = 1
                break

        if sign == 1: # 用来退出 numb1 的取值的循环
            break
        
        