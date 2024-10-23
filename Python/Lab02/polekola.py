import math
def pole_kola(r):
    if r>0:
        p=(math.pi)*r*r
        return round(p, 2)
    return "Nie możesz podać takiej wartości"

r= float(input("Podaj promień koła: "))
print(pole_kola(r))
