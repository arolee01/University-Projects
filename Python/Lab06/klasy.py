class Telewizor:

    def __init__(self, il_kan=32, maks_gł=100 ):
        self.włączony= False
        self.głośność= 1
        self.kanał= 0
        self.ILOŚĆ_KANAŁÓW= il_kan
        self.MAKS_GŁOŚNOŚĆ= maks_gł

    def włącz( self ):
        if self.włączony:
            return False
        self.włączony= True
        return True

    def wyłącz( self ):
        if not self.włączony:
            return False
        self.włączony= False
        return True

    def podgłośnij(self):
        if not self.włączony:
            return None
        if self.głośność!= self.MAKS_GŁOŚNOŚĆ:
            self.głośność+= 1
        return self.głośność

    def ścisz(self):
        if not self.włączony:
            return None
        if self.głośność!= 0:
            self.głośność-= 1
        return self.głośność

    def kanał_nast(self):
        if not self.włączony:
            return None
        self.kanał+= 1
        self.kanał%= self.ILOŚĆ_KANAŁÓW
        return self.kanał

    def kanał_pop(self):
        if not self.włączony:
            return None
        self.kanał-= 1
        self.kanał%= self.ILOŚĆ_KANAŁÓW
        return self.kanał

    def zmień_kanał(self, nr):
        if not self.włączony:
            return None
        if nr>= self.ILOŚĆ_KANAŁÓW or nr< 0:
            return None
        self.kanał= nr
        return self.kanał

    def __str__(self):
        s= 'telewizor jest w'
        if not self.włączony:
            s+= 'y'
        s+= 'łączony, ustawiony na kanał '
        s+= str( self.kanał )+ '/'
        s+= str( self.ILOŚĆ_KANAŁÓW )
        s+= ' i głośność '+ str( self.głośność )
        s+= '/'+ str( self.MAKS_GŁOŚNOŚĆ )
        return s

x= Telewizor( 64, 50 )
y= Telewizor()
z= Telewizor( maks_gł=200 )
x.włącz()
print(x.kanał_pop())
print( x )
print( y )
print( z )