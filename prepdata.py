#!/usr/bin/env python
import numpy as np
cities = np.loadtxt("cities.csv", delimiter=",",skiprows=1, usecols=(1,2))

def primes(N):
    """Returns a list of primes up to N.
    
    Uses Eratosthenes' sieve method."""
    L = list(range(2,N+1))
    primes = []

    while L:
        i = L[0]
        primes.append(i)
        del L[0]

        # Remove all multiples of i in the remaining list
        k = 0
        while k < len(L): # don't use "for" here; len(L) may change during iterations.
            if L[k] % i == 0:
                del L[k]
            k += 1
    
    return primes

primeids = primes(len(cities)) # list of prime city ids.

with open("santa.h","w") as f:
    f.write( "#ifndef SANTA_H\n#define SANTA_H\n" )
    f.write( "#define nprimes "+str(len(primeids))+"\n" )
    f.write( "#define ncities "+str(len(cities))+"\n" )
    f.write( "extern double totaldistance(unsigned int tour[], int tourlen);\n");
    f.write( "extern float x[];\n")
    f.write( "extern float y[];\n")
    f.write( "extern unsigned int primeids[];\n")
    f.write( "#endif /* SANTA_H */\n")
        
with open("data.c","w") as f:
    f.write("unsigned int primeids[] = {")
    for p in primeids:
        f.write( str(p)+"," )
    f.write( "};\n" )
    
    f.write( "float x[]={"+str(cities[0,0]) )
    for x in cities[1:,0]:
        f.write( ","+str(x) )
    f.write( "};\n" )
    
    f.write( "float y[]={"+str(cities[0,1]) )
    for y in cities[1:,1]:
        f.write( ","+str(y) )
    f.write( "};\n" )