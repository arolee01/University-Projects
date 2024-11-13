'''
Podaj początek i koniec przedziału funkcji i eps (jaka dokładność ma być)
abs|~x0-x0|<eps
'''

import math

a = float(input("Podaj początek przedziału: "))
b = float(input("Podaj koniec przedziału: "))
eps = float(input("Podaj z jaką dokładnością ma być podane miejsce zerowe funkcji: "))


def miejsce_zerowe(a, b, eps, f):
    while (b - a) > eps:
        if(f(b) > 0 and f(a) < 0):
            b = b / 2
            print("Sprawdzam przedział <", a, ", ", b, ">")
        elif (f(a) > 0 and f(b) < 0):
            a = a * 2
            print("Sprawdzam przedział <", a, ", ", b, ">")
        else:
            print("Miejsce zerowe to: ", (a + b) / 2)

miejsce_zerowe(a, b, eps, math.sin)
print("Miejsce zerowe to: ",(a + b) / 2)

#print("Miejsce zerowe wynosi")

    #if((f(a)>0 and f(b)<0) or (f(b)>0 and f(a)<0)):


