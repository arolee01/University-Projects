import math

a = float(input("Podaj współczynnik a: "))
b = float(input("Podaj współczynnik b: "))
c = float(input("Podaj współczynnik c: "))

x = float
x1 = float
x2 = float

while(a == 0 or b == 0):
    print("Podaj wartości inne od 0:")
    a = float(input("Podaj współczynnik a: "))
    b = float(input("Podaj współczynnik b: "))
    if (a != 0 and b != 0):
        break

delta=(b * b) - 4 * a * c
print("Delta wynosi: ", delta)

if (delta > 0):
        print("Równanie ma dwa rozwiązania: ")
        x1= ((-b) + math.sqrt(delta)) / (2 * a)
        x2= ((-b) - math.sqrt(delta)) / (2 * a)
        print("x1=", x1)
        print("x2=", x2)
elif (delta == 0):
    print("Równanie ma jedno rozwiązanie: ")
    x=(-b) / 2 * a
    print("x=", x)
else: #delta jest równa 0
    print("Równanie nie ma rozwiązań rzeczywistych")
