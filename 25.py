fib = []
fib[0] = 1
fib[1] = 1
i = 2
while True:
    fib[i] = fib[i-1] + fib[i-2]
    if len(fib[i] >= 1000):
        print(i+1)
    i+=1