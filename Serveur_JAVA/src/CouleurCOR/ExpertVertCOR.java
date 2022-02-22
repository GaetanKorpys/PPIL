package CouleurCOR;

import java.awt.*;

/**
 * Expert pour traiter la couleur vert.
 */
public class ExpertVertCOR extends CouleurCOR{

    /**
     * Constructeur par defaut.
     */
    public ExpertVertCOR(){}

    /**
     * Renvoie la couleur pour un affichage graphique.
     * @return Color
     */
    public Color getCouleur() {
        return Color.green;
    }

    /**
     * Type de la requete, ici c'est la couleur : vert.
     * @return String
     */
    public String getType() {
        return "vert";
    }

}
