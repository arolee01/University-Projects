#Program obliczający średnią podanych ocen

o1 = float(input("Podaj pierwszą ocenę: "))
o2 = float(input("Podaj drugą ocenę b: "))
o3 = float(input("Podaj drugą ocenę c: "))

if ((o1 - int(o1) != 0) or (o2 - int(o2) != 0) or (o3 - int(o3) != 0)):
    print("Prosze podać wartości całkowite")
    o1 = float(input("Podaj pierwszą ocenę: "))
    o2 = float(input("Podaj drugą ocenę: "))
    o3 = float(input("Podaj drugą ocenę: "))
    srednia = (o1+o2+o3)/3
    print("Średnia tych ocen wynosi: ", srednia)
else:
    srednia = (o1 + o2 + o3) / 3
    print("Średnia tych ocen wynosi: ", srednia)
