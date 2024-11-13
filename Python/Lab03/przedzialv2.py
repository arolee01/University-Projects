import math

a = float(input("Podaj początek przedziału: "))
b = float(input("Podaj koniec przedziału: "))
n = int(input("Podaj na ile trapezów podzielić podany przedział, aby obliczyć pole funkcji: "))

for i in range(n):
    h=(a+b)/n
    x1 = math.sin(math.radians(a))
