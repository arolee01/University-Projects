class Mikser:

    def __init__(self):
        self.włączony = False
        self.klapaOtwarta = True
        self.grzybekBezpieczenstwa = False

    def włącz(self):
        if self.grzybekBezpieczenstwa:
            return None
        if self.klapaOtwarta:
            return None
        self.włączony = True

    def wyłącz(self):
        if not self.włączony:
            return None
        self.włączony = False

    def otworzKlape(self):
        if self.włączony:
            return None
        else:
            self.klapaOtwarta = True

    def zamknijKlape(self):
        if not self.klapaOtwarta:
            return None
        self.klapaOtwarta = False

    def wciśnijGrzybekBezpieczenstwa(self):
        self.grzybekBezpieczenstwa = True
        self.włączony = False

    def zresetujGrzybekBezpieczenstwa(self):
        self.grzybekBezpieczenstwa = False

    def __str__(self):
        s= 'mikser jest w'
        if not self.włączony:
            s+= 'y'
        s+= 'łączony, klapa jest '
        if not self.klapaOtwarta:
            s+= 'zamknięta, '
        else:
            s+='otwarta, '
        s+= 'grzybek bezpieczeństwa jest'
        if not self.grzybekBezpieczenstwa:
            s+= ' wyłączony'
        else:
            s+=' wciśnięty '
        return s
x = Mikser()

print(x)

x.włącz()
print(x)
x.zamknijKlape()
print(x)
x.włącz()
print(x)
x.wciśnijGrzybekBezpieczenstwa()
print(x)
x.włącz()
print(x)
x.zresetujGrzybekBezpieczenstwa()
print(x)
x.włącz()
print(x)
x.wciśnijGrzybekBezpieczenstwa()
print(x)
x.otworzKlape()
print(x)
x.włącz()
print(x)
x.zresetujGrzybekBezpieczenstwa()
print(x)
x.zamknijKlape()
print(x)
x.włącz()
print(x)


