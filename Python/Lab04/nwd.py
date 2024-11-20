def nwd(a, b):
    d = 2
    nwd = 1
    while(d <= a or d <= b):
        if (a % d == 0 and b % d == 0):
            a = a / d
            b = b / d
            nwd *= d
        else:
            d = d + 1
    print("NWD = ", nwd)

a = int( input("Podaj pierwszą liczbę: "))
b = int( input("Podaj drugą liczbę: "))
nwd(a, b)