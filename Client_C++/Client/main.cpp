#include "Vecteur2D.h"
#include "Triangle.h"
#include "Cercle.h"
#include "COR.h"
#include "Segment.h"
#include "Polygone.h"
#include "Groupe.h"
#include "Exception.h"
#include "SocketSingleton.h"
#include "VisiteurHomothetie.h"
#include "VisiteurRotation.h"
#include "Visiteur.h"
#include "VisiteurDessin.h"
#include "VisiteurTranslation.h"
#include "VisiteurTxt.h"


int main()
{
	string reponse;

	try
	{
		do
		{
			cout << "Voulez-vous afficher les details dans la console ?" << endl;
			cout << "[ y / n ]" << endl;
			cin >> reponse;
		}
		while (reponse != "y" && reponse != "n");
		if(reponse == "y")
		{
			cout << "					Debut des tests						" << endl << endl << endl;

			cout << "			-------------------------------------------------------" << endl;
			cout << "					Creation des Transformations				   " << endl;
			cout << "			-------------------------------------------------------" << endl << endl;


			Vecteur2D v(3, 5);
			cout << "Le vecteur utilise pour les transformations est le vecteur v = " << v << endl << endl;

			VisiteurTranslation translation(v);
			VisiteurRotation rotation(v, PI / 4);
			VisiteurHomothetie homothetie(v, 2);

			cout << "			-------------------------------------------------------" << endl;
			cout << "					Fin Transformations							   " << endl;
			cout << "			-------------------------------------------------------" << endl << endl << endl;

			system("pause");

			cout << "			-------------------------------------------------------" << endl;
			cout << "					Test des Vecteurs							   " << endl;
			cout << "			-------------------------------------------------------" << endl << endl;

			cout << "Affichage d'un vecteur : " << endl << endl;

			Vecteur2D v2(300, 400), v3(400, 450), v4(500, 600), v5(10, 15), v6(130, 90);
			v2.affiche();

			Vecteur2D vt = v2;
			Vecteur2D vh = v2;
			Vecteur2D vr = v2;

			cout << "Les 3 transformations utilisent le vecteur v : " << v << endl << endl;

			cout << "Translation de v2 avec le vecteur v." << endl << endl;
			cout << "Avant translation v2 = " << v2 << endl;
			vt.translation(v);
			cout << "Apres translation v2 = " << vt << endl << endl;

			cout << "Rotation de v2 avec un angle de PI/4 et le vecteur v." << endl << endl;
			cout << "Avant rotation v2 = " << v2 << endl;
			vr.rotation(v, PI / 4);
			cout << "Apres rotation v2 = " << vr << endl << endl;

			cout << "Homothetie de v2 avec un rapport de 2 et le vecteur v." << endl << endl;
			cout << "Avant homothetie v2 = " << v2 << endl;
			vh.homothetie(v, 2);
			cout << "Apres homothetie v2 = " << vh << endl << endl;

			cout << "			-------------------------------------------------------" << endl;
			cout << "					Fin Vecteurs								   " << endl;
			cout << "			-------------------------------------------------------" << endl << endl << endl;

			system("pause");

			cout << "			-------------------------------------------------------" << endl;
			cout << "					Test des Segments							   " << endl;
			cout << "			-------------------------------------------------------" << endl << endl;

			cout << "Affichage de 2 segments : " << endl << endl;

			Segment s(v3, v4), s2(v5, v6);

			s.affiche();
			s2.affiche();

			Segment st = s;
			Segment sr = s;
			Segment sh = s;

			cout << "Les 3 transformations utilisent le vecteur v : " << v << endl << endl;

			cout << "Translation de s avec le vecteur v." << endl << endl;
			cout << "Avant translation s = " << s << endl;
			st.accepte(translation);
			cout << "Apres translation s = " << st << endl << endl;

			cout << "Rotation de s avec un angle de PI/4 et le vecteur v." << endl << endl;
			cout << "Avant rotation s = " << s << endl;
			sr.accepte(rotation);
			cout << "Apres rotation s = " << sr << endl << endl;

			cout << "Homothetie de s avec un rapport de 2 et le vecteur v." << endl << endl;
			cout << "Avant homothetie s = " << s << endl;
			sh.accepte(homothetie);
			cout << "Apres homothetie s = " << sh << endl << endl;

			cout << "			-------------------------------------------------------" << endl;
			cout << "					Fin Segments								   " << endl;
			cout << "			-------------------------------------------------------" << endl << endl << endl;

			system("pause");

			cout << "			-------------------------------------------------------" << endl;
			cout << "					Test des Triangles							   " << endl;
			cout << "			-------------------------------------------------------" << endl << endl;

			cout << "Affichage de 2 triangles : " << endl << endl;

			Triangle t(v, v5, v3), t2(v4, v5, v6);

			t.affiche();
			t2.affiche();

			Triangle tt = t;
			Triangle tr = t;
			Triangle th = t;

			cout << "Les 3 transformations utilisent le vecteur v : " << v << endl << endl;

			cout << "Translation de t avec le vecteur v." << endl << endl;
			cout << "Avant translation t = " << t << endl;
			tt.accepte(translation);
			cout << "Apres translation t = " << tt << endl << endl;

			cout << "Rotation de t avec un angle de PI/4 et le vecteur v." << endl << endl;
			cout << "Avant rotation t = " << t << endl;
			tr.accepte(rotation);
			cout << "Apres rotation t = " << tr << endl << endl;

			cout << "Homothetie de t avec un rapport de 2 et le vecteur v." << endl << endl;
			cout << "Avant homothetie t = " << t << endl;
			th.accepte(homothetie);
			cout << "Apres homothetie t = " << th << endl << endl;

			cout << "			-------------------------------------------------------" << endl;
			cout << "					Fin Triangles								   " << endl;
			cout << "			-------------------------------------------------------" << endl << endl << endl;

			system("pause");

			cout << "			-------------------------------------------------------" << endl;
			cout << "					Test des Cercles							   " << endl;
			cout << "			-------------------------------------------------------" << endl << endl;

			cout << "Affichage de 2 cercles : " << endl << endl;

			Cercle c(v3, 100), c2(v6, 50);

			c.affiche();
			c2.affiche();

			Cercle ct = c;
			Cercle cr = c;
			Cercle ch = c;

			cout << "Les 3 transformations utilisent le vecteur v : " << v << endl << endl;

			cout << "Translation de c avec le vecteur v." << endl << endl;
			cout << "Avant translation c = " << c << endl;
			ct.accepte(translation);
			cout << "Apres translation c = " << ct << endl << endl;

			cout << "Rotation de c avec un angle de PI/4 et le vecteur v." << endl << endl;
			cout << "Avant rotation c = " << c << endl;
			cr.accepte(rotation);
			cout << "Apres rotation c = " << cr << endl << endl;

			cout << "Homothetie de c avec un rapport de 2 et le vecteur v." << endl << endl;
			cout << "Avant homothetie c = " << c << endl;
			ch.accepte(homothetie);
			cout << "Apres homothetie c = " << ch << endl << endl;

			cout << "			-------------------------------------------------------" << endl;
			cout << "					Fin Cercles									   " << endl;
			cout << "			-------------------------------------------------------" << endl << endl << endl;

			system("pause");

			cout << "			-------------------------------------------------------" << endl;
			cout << "					Test des Polygones							   " << endl;
			cout << "			-------------------------------------------------------" << endl << endl;

			cout << "Affichage de 2 polygones : " << endl << endl;

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

			cout << "Les 3 transformations utilisent le vecteur v : " << v << endl << endl;

			cout << "Translation de p avec le vecteur v." << endl << endl;
			cout << "Avant translation p = " << p << endl;
			pt.accepte(translation);
			cout << "Apres translation p = " << pt << endl << endl;

			cout << "Rotation de p avec un angle de PI/4 et le vecteur v." << endl << endl;
			cout << "Avant rotation p = " << p << endl;
			pr.accepte(rotation);
			cout << "Apres rotation p = " << pr << endl << endl;

			cout << "Homothetie de p avec un rapport de 2 et le vecteur v." << endl << endl;
			cout << "Avant homothetie p = " << p << endl;
			ph.accepte(homothetie);
			cout << "Apres homothetie p = " << ph << endl << endl;

			cout << "			-------------------------------------------------------" << endl;
			cout << "					Fin Polygones								   " << endl;
			cout << "			-------------------------------------------------------" << endl << endl << endl;

			system("pause");

			cout << "			-------------------------------------------------------" << endl;
			cout << "					Test des Groupes							   " << endl;
			cout << "			-------------------------------------------------------" << endl << endl;

			cout << "Affichage de 2 groupes : " << endl << endl;

			Groupe g, g2;

			g.ajouter(s);
			g.ajouter(t);
			g.ajouter(c);
			g.ajouter(p);



			g2.ajouter(s);
			g2.ajouter(t2);
			g2.ajouter(c2);

			g.affiche();
			g2.affiche();

			Groupe gt = g;
			Groupe gr = g;
			Groupe gh = g;

			cout << "Les 3 transformations utilisent le vecteur v : " << v << endl << endl;

			cout << "Translation de g avec le vecteur v." << endl << endl;
			cout << "Avant translation g = " << g << endl;
			gt.accepte(translation);
			cout << "Apres translation g = " << gt << endl << endl;

			cout << "Rotation de g avec un angle de PI/4 et le vecteur v." << endl << endl;
			cout << "Avant rotation g = " << g << endl;
			gr.accepte(rotation);
			cout << "Apres rotation g = " << gr << endl << endl;

			cout << "Homothetie de g avec un rapport de 2 et le vecteur v." << endl << endl;
			cout << "Avant homothetie g = " << g << endl;
			gh.accepte(homothetie);
			cout << "Apres homothetie g = " << gh << endl << endl;

			cout << "			-------------------------------------------------------" << endl;
			cout << "					Fin Groupes							   		   " << endl;
			cout << "			-------------------------------------------------------" << endl << endl << endl;

			do
			{
				cout << "Voulez-vous tester la sauvegarde dans un fichier .txt ?" << endl;
				cout << "[ y / n ]" << endl;
				cin >> reponse;
			} while (reponse != "y" && reponse != "n");
			if (reponse == "y")
			{
				cout << "			-------------------------------------------------------" << endl;
				cout << "					Test de la Sauvegarde						   " << endl;
				cout << "			-------------------------------------------------------" << endl << endl;

				cout << "Creation de la classe destinee a la sauvegarde." << endl << endl;

				VisiteurTxt sauvegarde;

				cout << "Les formes sauvegardees par defaut sont :" << endl;
				cout << s << endl;
				cout << t << endl;
				cout << c << endl;
				cout << p << endl;
				cout << g << endl;

				s.accepte(sauvegarde);
				t.accepte(sauvegarde);
				c.accepte(sauvegarde);
				p.accepte(sauvegarde);
				g.accepte(sauvegarde);

				cout << "Sauvegarde terminee." << endl << endl;

				system("pause");
			}

			do
			{
				cout << "Voulez-vous tester le chargement de formes depuis un fichier .txt ?" << endl;
				cout << "[ y / n ]" << endl;
				cin >> reponse;
			} while (reponse != "y" && reponse != "n");
			if (reponse == "y")
			{
				cout << "			-------------------------------------------------------" << endl;
				cout << "					Test du Chargement						   " << endl;
				cout << "			-------------------------------------------------------" << endl << endl;

				cout << "Il y a 5 formes qui sont engistrees dans le fichier, leurs id vont de 0 a 4. " << endl;

				COR* cor = COR::getInstance();
				Chargement* chargeurForme = cor->getChargeurForme();
				Forme* forme = NULL;
				string idForme;

				while (reponse == "y")
				{
					do {

						cout << "Donenz l'id de la forme: " << endl;
						cin >> idForme;

						forme = chargeurForme->resoudre(idForme);
						if (forme == NULL)
							cout << "L'identifiant n'existe pas." << endl;

					} while (forme == NULL);
					cout << "Affichage de la forme chargee depuis le fichier: " << endl;
					cout << (*forme) << endl << endl;
					forme = NULL;

					do
					{
						cout << "Voulez-vous tester une autre forme ? " << endl;
						cout << "[ y / n ]" << endl;
						cin >> reponse;
					} while (reponse != "y" && reponse != "n");
				}
			}
		}

		cout << endl;
		system("pause");
		cout << endl;

		do
		{
			cout << "Voulez-vous tester le dessin des formes geometriques ?" << endl;
			cout << "[ y / n ]" << endl;
			cin >> reponse;
		} while (reponse != "y" && reponse != "n");
		if (reponse == "y")
		{
			cout << "			-------------------------------------------------------" << endl;
			cout << "					Test des Dessins							   " << endl;
			cout << "			-------------------------------------------------------" << endl << endl;


			cout << "Pour chaque forme [ Segment, Triangle, Cercle, Polygone et Groupe(ensemble de formes) ] du sujet," << endl;
			cout << "est effectue :" << endl;
			cout << " 1. - Creation" << endl;
			cout << " 2. - Rotation suivie de Translation" << endl;
			cout << " 3. - Homothetie" << endl << endl;
			cout << "Apres chaque etape, la forme est ajoutee a un groupe." << endl << endl;

			cout << "Il y a donc 3 dessins pour chaque formes dans la fenetre." << endl << endl;

			cout << "Une nouvelle fenetre est ouverte pour chaque forme n'appartenant pas a un groupe." << endl << endl;


			VisiteurDessin dessin;
			Groupe groupe(RED);

			//--------------------------TRIANGLE----------------------------

			Triangle triangle(Vecteur2D(150, 100), Vecteur2D(100, 200), Vecteur2D(200, 200), BLACK);
			groupe.ajouter(triangle);
		
			VisiteurRotation rotaTriangle(triangle.getCentreGravite(), PI);
			triangle.accepte(rotaTriangle);

			VisiteurTranslation transTriangle(Vecteur2D(0, 150));
			triangle.accepte(transTriangle);

			groupe.ajouter(triangle);

			VisiteurHomothetie homoTriangle(triangle.getCentreGravite(), 2);
			triangle.accepte(homoTriangle);

			groupe.ajouter(triangle);

			//--------------------------CERCLE----------------------------

			Cercle cercle(Vecteur2D(390, 100), 50, GREEN);
			groupe.ajouter(cercle);

			VisiteurRotation rotaCercle(cercle.getCentre(), PI);
			cercle.accepte(rotaCercle);

			VisiteurTranslation transCercle(Vecteur2D(0, 200));
			cercle.accepte(transCercle);

			groupe.ajouter(cercle);

			VisiteurHomothetie homoCercle(cercle.getCentre(), 2);
			cercle.accepte(homoCercle);

			groupe.ajouter(cercle);

			//--------------------------SEGMENT----------------------------

			Segment segment(Vecteur2D(600, 100), Vecteur2D(600, 200), GREEN);
			groupe.ajouter(segment);

			VisiteurRotation rotaSegment(Vecteur2D(600, 150), PI / 2);
			segment.accepte(rotaSegment);

			groupe.ajouter(segment);

			VisiteurHomothetie homoSegment(Vecteur2D(600, 150), 2);
			segment.accepte(homoSegment);

			VisiteurTranslation transSegment(Vecteur2D(0, 150));
			segment.accepte(transSegment);

			groupe.ajouter(segment);

			//--------------------------POLYGONE----------------------------

			Polygone polygone(CYAN);

			polygone.ajouter(Vecteur2D(350, 550));
			polygone.ajouter(Vecteur2D(450, 550));
			polygone.ajouter(Vecteur2D(550, 650));
			polygone.ajouter(Vecteur2D(450, 750));
			polygone.ajouter(Vecteur2D(350, 750));

			groupe.ajouter(polygone);

			VisiteurRotation rotaPolygone(Vecteur2D(550, 650), PI);
			polygone.accepte(rotaPolygone);

			VisiteurTranslation transPolygone(Vecteur2D(50, 0));
			polygone.accepte(transPolygone);

			groupe.ajouter(polygone);

			VisiteurHomothetie homoPolygone(Vecteur2D(670, 650), 0.5);
			polygone.accepte(homoPolygone);

			groupe.ajouter(polygone);

			dessin.ouvrirFenetre();
			//On dessine le groupe
			groupe.accepte(dessin);

			//--------------------------GROUPE----------------------------

			cout << "\n				---------------- 2eme FENETRE : --------------" << endl << endl;
			cout << "Creation d'un nouveau groupe(ensemble de formes) contenant :" << endl;
			cout << " - le groupe construit et dessine precedemment" << endl;
			cout << " - un triangle de couleur bleu." << endl << endl;
			 
			cout << "Cette nouvelle forme n'appartient pas a un groupe, elle sera donc affichee sur une nouvelle fenetre." << endl << endl;
			cout << "Ouverture de la 2eme fenetre :" << endl;

			system("pause");


			Groupe groupe2;

			groupe2.ajouter(groupe);

			triangle.setCouleur(BLUE);
			groupe2.ajouter(triangle);


			dessin.ouvrirFenetre();
			groupe2.accepte(dessin);

			SocketSingleton::getInstance()->fermerConnexion();
			SocketSingleton::getInstance()->killInstance();
		}
	}

	catch (Exception e)
	{
		cout << e << endl;
	}
	

}
