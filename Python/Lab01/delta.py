import math

a = float(input("Podaj współczynnik a: "))
b = float(input("Podaj współczynnik b: "))
c = float(input("Podaj współczynnik c: "))

x = float
x1 = float
x2 = float

delta = (b * b) - 4 * a * c
print("Delta wynosi: ", delta)

if (delta > 0):
    if(a == 0):
        if(c == 0): #bx=0
            if(b == 0):
                print("Równanie nie ma rozwiązań")
            else:
                print("Równanie ma jedno rozwiązanie\nx=0")
        else: #bx+c=0
            print("Równanie ma jedno rozwiązanie (funkcja liniowa): ")
            x = (-b) / c
            print("x=", x)
    else:
        print("Równanie ma dwa rozwiązania: ")
        x1 = ((-b) + math.sqrt(delta)) / (2 * a)
        x2 = ((-b) - math.sqrt(delta)) / (2 * a)
        print("x1=", x1)
        print("x2=", x2)
elif (delta==0):
    print("Równanie ma jedno rozwiązanie: ")
    x=(-b) / 2 * a
    print("x=", x)
    '''
    Taki komentarz długi no i w sumie śmiesznie to wygląda
    komentarz pisać nad fragmentem kodu !!!
    '''
else: #delta jest równa 0
    print("Równanie nie ma rozwiązań rzeczywistych")
