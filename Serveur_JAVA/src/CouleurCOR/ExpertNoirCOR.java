package CouleurCOR;

import java.awt.*;

/**
 * Expert pour traiter la couleur noir.
 */
public class ExpertNoirCOR extends CouleurCOR{
    /**
     * Constructeur par defaut.
     */
    public ExpertNoirCOR(){}

    /**
     * Renvoie la couleur pour un affichage graphique.
     * @return Color
     */
    public Color getCouleur() {
        return Color.black;
    }

    /**
     * Type de la requete, ici c'est la couleur : noir.
     * @return String
     */
    public String getType() {
        return "noir";
    }
}
