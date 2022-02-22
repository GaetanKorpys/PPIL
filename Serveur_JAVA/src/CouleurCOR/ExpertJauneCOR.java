package CouleurCOR;

import java.awt.*;

/**
 * Expert pour traiter la couleur jaune.
 */
public class ExpertJauneCOR extends CouleurCOR{

    /**
     * Constructeur par defaut.
     */
    public ExpertJauneCOR(){}

    /**
     * Renvoie la couleur pour un affichage graphique.
     * @return Color
     */
    public Color getCouleur() {
        return Color.yellow;
    }

    /**
     * Type de la requete, ici c'est la couleur : jaune.
     * @return String
     */
    public String getType() {
        return "jaune";
    }

}
