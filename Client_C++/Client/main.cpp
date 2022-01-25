//#define _CRTDBG_MAP_ALLOC
#include "Vecteur2D.h"
#include "Triangle.h"
#include "Cercle.h"
#include "Segment.h"
#include "Polygone.h"
#include "Groupe.h"
#include "Exception.h"



int main()
{
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	try
	{
		cout << "Début des tests." << endl << endl; 

		cout << "Création des Vecteurs." << endl << endl;

		Vecteur2D a, b(3, 6), c(9, 12), d(5, 5), e(20, 14);

		cout << "Affichage des vecteurs." << endl << endl;

		a.affiche();
		b.affiche();
		c.affiche();
		d.affiche();
		e.affiche();

		cout << endl << "Création des segments." << endl << endl;

		Segment f(a, b), g(a, b, RED), h(c, d, GREEN);

		cout << "Affichage des segments." << endl << endl;

		f.affiche();
		g.affiche();
		h.affiche();

		cout << endl << "Création des triangles." << endl << endl;

		Triangle i(a, b, c), j(e, d, b, YELLOW);

		cout << "Affichage des triangles." << endl << endl;

		i.affiche();
		j.affiche();

		cout << "Création des cercles." << endl << endl;

		double rayon = 3;

		Cercle k(b, rayon), l(e, rayon + 2, RED);

		cout << "Affichage des cercles." << endl << endl;

		k.affiche();
		l.affiche();

		cout << "Création d'un polygone." << endl << endl;

		Polygone m;
		m.ajouter(a);
		m.ajouter(b);
		m.ajouter(c);
		m.ajouter(d);
		m.ajouter(e);

		cout << "Affichage du polygone." << endl << endl;

		m.affiche();

		cout << "Création d'un groupe." << endl << endl;

		Groupe n;
		n.ajouter(f);
		n.ajouter(i);
		n.ajouter(k);
		n.ajouter(m);

		cout << "Affichage du groupe." << endl << endl;

		n.affiche();

	}
	catch (Exception e)
	{
		cout << e << endl << endl;
	}




	

}