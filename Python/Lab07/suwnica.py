'''
    Program do obsługiwania działania suwnicy

    Funkcje:
        - sprawdza, ile kontenerów jest na danym miejscu np. pole [3][4] 3 kontenery
        - max 9 kontenerów na sobie, czyli suwnica ma wysokość 10 pięter
        - ma przesuwać się do przodu/tyłu, prawo/lewo, w górę/dół
        - złapać kontener 10 cm nad jego powierzchnią
        - ma 2 lasery, które sprawdzają czy na ich drodze stoi już jakiś kontener (czy można przejechać w lini prostej)
        - jedź, złap, puść, podnieś, opuść
'''
def ile( x, y ):
    pass

def droga_wolna( x1, y1, x2, y2, h ):
    pass

class Suwnica:
    MAKSYMALNA_ILOŚĆ_KONTENERÓW= 9
    MAKSYMALNA_WYSOKOŚĆ= MAKSYMALNA_ILOŚĆ_KONTENERÓW+ 1

    def __init__(self, dł, sz ):
        self.x= 0
        self.y= 0
        self.h= Suwnica.MAKSYMALNA_WYSOKOŚĆ
        self.złapany= False
        self.X= dł
        self.Y= sz

    def podnieś(self, o_ile ):
        if o_ile< 0:
            return False
        if self.h+ o_ile> Suwnica.MAKSYMALNA_WYSOKOŚĆ:
            return False
        self.h+= o_ile
        return True

    def opuść(self, o_ile ):
        if o_ile< 0:
            return False
        dół= self.h
        if self.złapany:
            dół-= 1
        if dół- o_ile< ile( self.x, self.y ):
            return False
        self.h-= o_ile
        return True

    def złap(self):
        if self.złapany:
            return False
        if self.h== 0:
            return False
        if self.h!= ile( self.x, self.y ):
            return False
        self.złapany= True
        return True

    def puść(self):
        if not self.złapany:
            return False
        if self.h== Suwnica.MAKSYMALNA_WYSOKOŚĆ:
            return False
        if self.h- 1!= ile( self.x, self.y ):
            return False
        self.złapany= False
        return True

    def jedź(self, x, y):
        if x< 0 or x>= self.X:
            return False
        if y< 0 or y>= self.Y:
            return False
        dół= self.h
        if self.złapany:
            dół-= 1
        h_pom= dół
        while not droga_wolna( self.x, self.y, x, self.y, h_pom ):
            h_pom+= 1
        while not droga_wolna( x, self.y, x, y, h_pom ):
            h_pom+= 1
        self.podnieś( h_pom- dół )
        self.x= x
        self.y= y
        return True

    def __str__(self):
        w= 'telewizor jest w'
        return w

    __repr__= __str__

