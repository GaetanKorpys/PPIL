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


public class COR {

    private static COR instance = null;
    private Requete requete;
    private Forme forme;
    private Couleur couleur;

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

    public static COR getInstance()
    {
        if(instance == null)
            instance = new COR();
        return instance;
    }

    public Couleur getCouleur() {
        return this.couleur;
    }

    public Requete getRequete() {
        return this.requete;
    }

    public Forme getForme() {
        return this.forme;
    }
}
