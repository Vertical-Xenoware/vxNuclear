#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "VXAtomAPI.h"

int main() {
	long double protonIO, neutronIO, nucleusIO;
  long double *mDefect, *bEnergy;
  
	printf("Binding Energy Finder\n\nLiscenced by GPL v3.0\nDeveloped by Vertical-Xenoware\nPowered by VXNChem ver 0.8\n\n");
	printf("Please enter the number of protons, neutrons, and the atomic mass respectively.\n");

	scanf("%Lf", &protonIO);
	scanf("%Lf", &neutronIO);
	scanf("%Lf", &nucleusIO);

	AtomMethods *methods;
	Atom *element = Atom_atom(&protonIO, &neutronIO, &nucleusIO, methods);

	mDefect = Atom_displayMassDefect(element);
	bEnergy = Atom_displayEnergy(element);

	printf("The mass defect is %Lf MeV/c^2 \nThe binding energy is approximately %Lf MeV\n", *mDefect, *bEnergy);



	return 0;
}