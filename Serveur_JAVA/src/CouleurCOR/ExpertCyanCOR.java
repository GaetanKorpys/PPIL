package CouleurCOR;

import java.awt.*;

/**
 * Expert pour traiter la couleur cyan.
 */
public class ExpertCyanCOR extends CouleurCOR{

    /**
     * Constructeur par defaut.
     */
    public ExpertCyanCOR(){}

    /**
     * Renvoie la couleur pour un affichage graphique.
     * @return Color
     */
    public Color getCouleur() {
        return Color.cyan;
    }

    /**
     * Type de la requete, ici c'est la couleur : cyan.
     * @return String
     */
    public String getType() {
        return "cyan";
    }

}
