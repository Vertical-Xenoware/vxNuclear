#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "VXAtomAPI.h"

const long double PROTON_AMU = 1.0072;
const long double NEUTRON_AMU = 1.0087;
const long double AMU_TO_KG = 1.661E-27;
const long double JOULES_TO_MEV = 6.242E+12;
const long double LIGHT_SPEED = 3E+8;



typedef struct myAtom {
	long double protons;
	long double neutrons;
	long double massNucleus;
	long double massNucleons;
	long double deltaMass;
	long double energy;
} Atom;

static long double Atom_MassDefect(Atom* arg);
static long double Atom_bindingEnergy(Atom* arg);

AtomMethods *initAtomMethods() {
	AtomMethods *methods = malloc(sizeof(AtomMethods));
	methods->displayEnergy = Atom_displayEnergy;
	methods->displayMassDefect = Atom_displayMassDefect;
	methods->bindingEnergy = Atom_bindingEnergy;
	methods->massDefect = Atom_MassDefect;
	return methods;
}

Atom* Atom_atom(long double *p, long double *n, long double *nucleus, AtomMethods *methods) {
	Atom* object = malloc(sizeof(Atom));
	(object->protons) = *p;
	(object->neutrons) = *n;
	//(object->massNucleus) = 235.04392;
  	object->massNucleus = *nucleus;

	double protonMass = (object->protons) * PROTON_AMU;
	double neutronMass = (object->neutrons) * NEUTRON_AMU;
	(object->massNucleons) = (protonMass + neutronMass);
	
	methods = initAtomMethods();
	
	object->deltaMass = methods->massDefect(object);
	object->energy = methods->bindingEnergy(object);

	

	return object;
}





long double Atom_MassDefect(Atom* arg) {
	long double massDefect;
	massDefect = (arg->massNucleus) - (arg->massNucleons);
	return massDefect * AMU_TO_KG;

}

long double Atom_bindingEnergy(Atom* arg) {
	long double bindingEnergy = (arg->deltaMass) * (pow(LIGHT_SPEED, 2));
	bindingEnergy = bindingEnergy * JOULES_TO_MEV;
	return bindingEnergy;
}

long double *Atom_displayMassDefect(Atom* arg) {
	return &arg->deltaMass;
}

long double *Atom_displayEnergy(Atom* arg) {
	return &arg->energy;
}
