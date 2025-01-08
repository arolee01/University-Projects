def nieparz( li ):
    kop= list( li )
    for x in kop:
        if x% 2== 1:
            yield x

def nieparz( li ):
    kop= list()
    for x in li:
        if x% 2== 1:
            kop.append( x )
    for x in kop:
        yield x

qq= (2,5,8,3,7,12,6,8,5)
for x in nieparz( qq ):
    print( x )


class NieparzIterator:
    def __init__(self, li):
        self.li= li
        self.i= 0

    def __iter__(self):
        return self

    def __next__(self):
        if self.i>= len(self.li):
            raise StopIteration
        while self.li[ self.i ]% 2!= 1:
            self.i+= 1
            if self.i== len( self.li ):
                raise StopIteration
        self.i+= 1
        return self.li[ self.i- 1 ]

for x in NieparzIterator( qq ):
    print( x )