package Main;

import CouleurCOR.Couleur;
import CouleurCOR.CouleurCOR;
import FormeCOR.Forme;
import FormeCOR.FormeCOR;
import RequeteCOR.Requete;
import RequeteCOR.RequeteCOR;
import RequeteCOR.ExpertFormeCOR;
import RequeteCOR.ExpertFenetreCOR;
import FormeCOR.ExpertCercleCOR;
import FormeCOR.ExpertSegmentCOR;
import FormeCOR.ExpertTriangleCOR;
import FormeCOR.ExpertPolygoneCOR;
import CouleurCOR.ExpertNoirCOR;
import CouleurCOR.ExpertBleuCOR;
import CouleurCOR.ExpertRougeCOR;
import CouleurCOR.ExpertVertCOR;
import CouleurCOR.ExpertJauneCOR;
import CouleurCOR.ExpertCyanCOR;

/**
 * Classe COR qui construit et instancie les 3 chaines de responsabilites.
 * Utilisation du DP Singleton pour obtenir une classe unique.
 *
 */
public class COR {

    private static COR instance = null;
    private Requete requete;
    private Forme forme;
    private Couleur couleur;


    /**
     * Constructeur par defaut prive car la classe est un Singleton.
     * Creation des chaines de responsabilite :
     * - COR Requete (la requete est le dessin d'une forme ou l'ouverture d'une fenetre)
     * - COR Forme (la forme reçu a dessine)
     * - COR Couleur (la couleur a utilise pour le dessin)
     */
    private COR()
    {
        RequeteCOR forme = new ExpertFormeCOR();
        RequeteCOR fenetre = new ExpertFenetreCOR();
        forme.setSuivant(fenetre);
        this.requete = forme;

        FormeCOR dessinateurCercle = new ExpertCercleCOR();
        FormeCOR dessinateurSegment = new ExpertSegmentCOR();
        FormeCOR dessinateurTriangle = new ExpertTriangleCOR();
        FormeCOR dessinateurPolygone = new ExpertPolygoneCOR();
        dessinateurCercle.setSuivant(dessinateurPolygone);
        dessinateurSegment.setSuivant(dessinateurCercle);
        dessinateurTriangle.setSuivant(dessinateurSegment);
        this.forme = dessinateurTriangle;

        CouleurCOR black = new ExpertNoirCOR();
        CouleurCOR blue = new ExpertBleuCOR();
        CouleurCOR cyan = new ExpertCyanCOR();
        CouleurCOR green = new ExpertVertCOR();
        CouleurCOR red = new ExpertRougeCOR();
        CouleurCOR yellow = new ExpertJauneCOR();
        blue.setSuivant(black);
        cyan.setSuivant(blue);
        green.setSuivant(cyan);
        red.setSuivant(green);
        yellow.setSuivant(red);
        this.couleur = yellow;

    }

    /**
     * Getter de l'unique instance de la classe COR.
     * @return COR L'instance en cours ou une nouvelle si elle n'a pas ete instanciee.
     */
    public static COR getInstance()
    {
        if(instance == null)
            instance = new COR();
        return instance;
    }

    /**
     * Getter de COR Couleur.
     * @return Couleur Classe mere du DP COR des couleurs.
     */
    public Couleur getCouleur() {
        return this.couleur;
    }

    /**
     * Getter de COR Requete.
     * @return Requete Classe mere du DP COR des requetes.
     */
    public Requete getRequete() {
        return this.requete;
    }

    /**
     * Getter de COR Forme.
     * @return Forme Classe mere du DP COR des formes.
     */
    public Forme getForme() {
        return this.forme;
    }
}
