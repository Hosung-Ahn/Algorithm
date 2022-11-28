s = input()
origin = []

for c in s :
    origin.append(c)
    if origin[-4:] == ['P','P','A','P'] :
        for _ in range(3) : origin.pop(-1)
        
if origin == ['P'] : print('PPAP')
else : print('NP')