#include "Vecteur2D.h"
#include "Triangle.h"
#include "Cercle.h"
#include "Segment.h"
#include "Polygone.h"
#include "Groupe.h"
#include "Exception.h"
#include "VisiteurHomothetie.h"
#include "VisiteurRotation.h"
#include "Visiteur.h"
#include "VisiteurTranslation.h"


int main()
{
	try
	{
		cout << "					D�but des tests						" << endl << endl << endl;

		cout << "-------------------------------------------------------" << endl;
		cout << "					Cr�ation des Transformations		" << endl;
		cout << "-------------------------------------------------------" << endl << endl;

		Vecteur2D v(3, 5);

		VisiteurTranslation translation(v);
		VisiteurRotation rotation(v, PI/4);
		VisiteurHomothetie homothetie(v, 2);

		cout << "-------------------------------------------------------" << endl;
		cout << "					Fin Transformations					" << endl;
		cout << "-------------------------------------------------------" << endl << endl << endl;

		cout << "-------------------------------------------------------" << endl;
		cout << "					Test des Vecteurs					" << endl;
		cout << "-------------------------------------------------------" << endl << endl;

		cout << "Cr�ation de 5 vecteurs : " << endl;

		Vecteur2D v2(2, 4), v3(3, 6), v4(9, 12), v5(5, 5), v6(20, 14);

		v2.affiche();
		v3.affiche();
		v4.affiche();
		v5.affiche();
		v6.affiche();

		Vecteur2D vt = v2;
		Vecteur2D vh = v2;
		Vecteur2D vr = v2;

		cout << "Les 3 transformations utilisent le vecteur v : " << v << endl;

		cout << "Translation de v2 avec le vecteur v." << endl;
		cout << "Avant translation v2 = " << v2 << endl;
		vt.translation(v);
		cout << "Apr�s translation v2 = " << vt << endl << endl;

		cout << "Rotation de v2 avec un angle de PI/4 et le vecteur v." << endl;
		cout << "Avant rotation v2 = " << v2 << endl;
		vr.rotation(v,PI/4);
		cout << "Apr�s rotation v2 = " << vr << endl << endl;

		cout << "Homoth�tie de v2 avec un rapport de 2 et le vecteur v."<< endl;
		cout << "Avant homoth�tie v2 = " << v2 << endl;
		vh.homothetie(v,2);
		cout << "Apr�s homoth�tie v2 = " << vh << endl << endl;

		cout << "-------------------------------------------------------" << endl;
		cout << "					Fin Vecteurs						" << endl;
		cout << "-------------------------------------------------------" << endl << endl << endl;


		cout << "-------------------------------------------------------" << endl;
		cout << "					Test des Segments					" << endl;
		cout << "-------------------------------------------------------" << endl << endl;

		cout << "Cr�ation de 2 segments : " << endl;

		Segment s(v3, v4), s2(v5, v6);

		s.affiche();
		s2.affiche();

		Segment st = s;
		Segment sr = s;
		Segment sh = s;

		cout << "Les 3 transformations utilisent le vecteur v : " << v << endl;

		cout << "Translation de s avec le vecteur v." << endl;
		cout << "Avant translation s = " << s << endl;
		st.accepte(translation);
		cout << "Apr�s translation s = " << st << endl << endl;

		cout << "Rotation de s avec un angle de PI/4 et le vecteur v." << endl;
		cout << "Avant rotation s = " << s << endl;
		sr.accepte(rotation);
		cout << "Apr�s rotation s = " << sr << endl << endl;

		cout << "Homoth�tie de s avec un rapport de 2 et le vecteur v." << endl;
		cout << "Avant homoth�tie s = " << s << endl;
		sh.accepte(homothetie);
		cout << "Apr�s homoth�tie s = " << sh << endl << endl;

		cout << "-------------------------------------------------------" << endl;
		cout << "					Fin Segments						" << endl;
		cout << "-------------------------------------------------------" << endl << endl << endl;

		cout << "-------------------------------------------------------" << endl;
		cout << "					Test des Triangles					" << endl;
		cout << "-------------------------------------------------------" << endl << endl;

		cout << "Cr�ation de 2 triangles : " << endl;

		Triangle t(v, v5, v3), t2(v4, v5, v6);

		t.affiche();
		t2.affiche();

		Triangle tt = t;
		Triangle tr = t;
		Triangle th = t;

		cout << "Les 3 transformations utilisent le vecteur v : " << v << endl;

		cout << "Translation de t avec le vecteur v." << endl;
		cout << "Avant translation t = " << t << endl;
		tt.accepte(translation);
		cout << "Apr�s translation t = " << tt << endl << endl;

		cout << "Rotation de t avec un angle de PI/4 et le vecteur v." << endl;
		cout << "Avant rotation t = " << t << endl;
		tr.accepte(rotation);
		cout << "Apr�s rotation t = " << tr << endl << endl;

		cout << "Homoth�tie de t avec un rapport de 2 et le vecteur v." << endl;
		cout << "Avant homoth�tie t = " << t << endl;
		th.accepte(homothetie);
		cout << "Apr�s homoth�tie t = " << th << endl << endl;

		cout << "-------------------------------------------------------" << endl;
		cout << "					Fin Triangles						" << endl;
		cout << "-------------------------------------------------------" << endl << endl << endl;

		cout << "-------------------------------------------------------" << endl;
		cout << "					Test des Cercles					" << endl;
		cout << "-------------------------------------------------------" << endl << endl;

		cout << "Cr�ation de 2 cercles : " << endl;

		Cercle c(v3, 5), c2(v6, 3);

		c.affiche();
		c2.affiche();

		Cercle ct = c;
		Cercle cr = c;
		Cercle ch = c;

		cout << "Les 3 transformations utilisent le vecteur v : " << v << endl;

		cout << "Translation de c avec le vecteur v." << endl;
		cout << "Avant translation c = " << c << endl;
		ct.accepte(translation);
		cout << "Apr�s translation c = " << ct << endl << endl;

		cout << "Rotation de c avec un angle de PI/4 et le vecteur v." << endl;
		cout << "Avant rotation c = " << c << endl;
		cr.accepte(rotation);
		cout << "Apr�s rotation c = " << cr << endl << endl;

		cout << "Homoth�tie de c avec un rapport de 2 et le vecteur v." << endl;
		cout << "Avant homoth�tie c = " << c << endl;
		ch.accepte(homothetie);
		cout << "Apr�s homoth�tie c = " << ch << endl << endl;

		cout << "-------------------------------------------------------" << endl;
		cout << "					Fin Cercles							" << endl;
		cout << "-------------------------------------------------------" << endl << endl << endl;


		cout << "-------------------------------------------------------" << endl;
		cout << "					Test des Polygones					" << endl;
		cout << "-------------------------------------------------------" << endl << endl;

		cout << "Cr�ation de 2 polygones : " << endl;

		Polygone p, p2;

		p.ajouter(v);
		p.ajouter(v2);
		p.ajouter(v3);
		p.ajouter(v4);
	


		p2.ajouter(v);
		p2.ajouter(v2);
		p2.ajouter(v3);
		p2.ajouter(v4);
		p2.ajouter(v5);
		p2.ajouter(v6);

		p.affiche();
		p2.affiche();

		Polygone pt = p;
		Polygone pr = p;
		Polygone ph = p;

		cout << "Les 3 transformations utilisent le vecteur v : " << v << endl;

		cout << "Translation de p avec le vecteur v." << endl;
		cout << "Avant translation p = " << p << endl;
		pt.accepte(translation);
		cout << "Apr�s translation p = " << pt << endl << endl;

		cout << "Rotation de p avec un angle de PI/4 et le vecteur v." << endl;
		cout << "Avant rotation p = " << p << endl;
		pr.accepte(rotation);
		cout << "Apr�s rotation p = " << pr << endl << endl;

		cout << "Homoth�tie de p avec un rapport de 2 et le vecteur v." << endl;
		cout << "Avant homoth�tie p = " << p << endl;
		ph.accepte(homothetie);
		cout << "Apr�s homoth�tie p = " << ph << endl << endl;

		cout << "-------------------------------------------------------" << endl;
		cout << "					Fin Polygones						" << endl;
		cout << "-------------------------------------------------------" << endl << endl << endl;


	}
	catch (Exception e)
	{
		cout << e << endl;
	}
	

}
