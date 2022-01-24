#define _CRTDBG_MAP_ALLOC
#include "Vecteur2D.h"
#include "Triangle.h"
#include "Segment.h"
#include "Exception.h"
#include <crtdbg.h>


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	cout << "essai des vecteurs 2D \n";
	Vecteur2D u1(2, 3), u2(2, 3), v(5), w, v1(35, -63), u3(3, 4), u4(3, -4), v3;
	cout << " u1 = " << u1 << endl;
	cout << " u2 = " << u2 << endl;
	cout << " u1 - u2 = " << u1 - u2 << endl;
	cout << " 5*u1 = " << 5 * u1 << endl;

	v3.setX(3);

	cout << "essai Triangles \n";

	try
	{
		cout << "essai 1 \n";

		cout << " u1 = " << u1 << endl;
		cout << " v = " << v << endl;
		cout << " u3 = " << u3 << endl;
		Triangle a(u1, v, u3, "noir");

		cout << "essai 2 \n";
		a.affiche();

		Triangle b = a;

		b.affiche();
		Vecteur2D f(0, 0);

		Vecteur2D g(1, 1);

		Vecteur2D h(2, 2);

		Triangle c(f, g, h, "jaune");

		c.affiche();

		a.setP1(u2);

		cout << "essai 3 \n";

		Segment s(f, g, "jaune");

		s.affiche();

		Segment k(g, h, "bleu");

		k.affiche();

		k = s;

		k.affiche();

		k.setP1(g);


	}
	catch (Exception e)
	{
		cout << e << endl;
	}




	

}