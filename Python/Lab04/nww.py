def nww(a, b):
    d = 2
    nww = 1
    while(d <= a or d <= b):
        if (a % d == 0 and b % d == 0):
            a = a / d
            b = b / d
            nww *= d
            #print("a=", a, " b=", b, " d=", d, " nww=", nww)
        elif (a % d == 0 or b % d == 0):
            if(a%d==0):
                a=a / d
                nww *= d
                #print("a=", a, " b=", b, " d=", d, " nww=", nww)
            if(b % d == 0):
                b = b / d
                nww *= d
                #print("a=", a, " b=", b, " d=", d, " nww=", nww)
        else:
            #print("Ani ", a, ", ani ", b, " nie dzieli się przez ", d)
            d = d + 1

    print("NWW = ", nww)

a = int(input("Podaj pierwszą liczbę: "))
b = int(input("Podaj drugą liczbę: "))
nww(a, b)