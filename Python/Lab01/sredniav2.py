from os import stat_result

suma = 0
ilosc = 0
srednia = 0
ocena = 1
print("Żeby skończyć dodawanie ocen wciśnij 0")
while ocena != 0:
    ocena = -1
    while ocena< 0 or ocena>7:
        ocena = int( input("Podaj ocenę: "))
        suma+= ocena
        ilosc+= 1
ilosc -= 1
if ilosc == 0:
    print("Brak ocen")
else:
    srednia = suma / ilosc
    print("Srednia wynosi: ", srednia)