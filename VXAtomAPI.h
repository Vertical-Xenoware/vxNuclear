#include <stdio.h>
#include <stdlib.h>

#ifndef ATOM
#define ATOM

typedef long double (*method)();




/*opaque*/ typedef struct myAtom Atom; 
/*methods*/ typedef struct myAtomMethods {
    method massDefect;
    method bindingEnergy;
    method displayMassDefect;
    method displayEnergy;
} AtomMethods;



/*public*/ Atom* Atom_atom(long double *p, long double *n, long double *nucleus, AtomMethods *methods);

long double *Atom_displayMassDefect(Atom* arg);
long double *Atom_displayEnergy(Atom* arg);


#endif
