import math

a = float(input("Podaj początek przedziału: "))
b = float(input("Podaj koniec przedziału: "))
n = int(input("Podaj na ile trapezów podzielić podany przedział, aby obliczyć pole funkcji: "))

h=(a+b)/n
suma = 0
x1 = 0
y1 = math.sin(x1)
x2 = h
y2 = math.sin(x2)

print("a=",a," b=",b," n=",n," h= ",h)
for i in range(n):
    p = ((y1 + y2) * h) / 2
    print("Wartość x1=", y1, " Wartość x2=", y2)
    print(i + 1, ". Pole = ", p)
    x1 = h
    y1 = math.sin(x1)
    x2= h + h
    y2 = math.sin(x2)
    h += h
    suma =+ p



print("Pole pod wykresem wynosi: ", suma)