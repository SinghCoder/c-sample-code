# almost no python shortuts so that this can be implimented in C
# ** operator -> pow()

x = 1

while x<=500:
    if x<10:
        d1 = x
        print(x)
    elif x<100:
        d1 = int(x/10)
        d2 = x%(d1*10)
        if (d1**2 + d2**2) == x:
            print(x)
    else:
        d1 = int(x/100)
        d2 = int((x%(d1*100))/10)
        d3 = int(x%(d1*100 + d2*10))
        if (d1**3 + d2**3 + d3**3) == x:
            print(x)
    x += 1

print("done!")
