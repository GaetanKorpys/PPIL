package CouleurCOR;

import java.awt.*;

/**
 * Expert pour traiter la couleur rouge.
 */
public class ExpertRougeCOR extends CouleurCOR{

    /**
     * Constructeur par defaut.
     */
    public ExpertRougeCOR(){}

    /**
     * Renvoie la couleur pour un affichage graphique.
     * @return Color
     */
    public Color getCouleur() {
        return Color.red;
    }

    /**
     * Type de la requete, ici c'est la couleur : rouge.
     * @return String
     */
    public String getType() {
        return "rouge";
    }
}
