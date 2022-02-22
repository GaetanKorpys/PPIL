package CouleurCOR;

import java.awt.*;
/**
 * Expert pour traiter la couleur bleu.
 */
public class ExpertBleuCOR extends CouleurCOR {

    /**
     * Constructeur par defaut.
     */
    public ExpertBleuCOR(){}

    /**
     * Renvoie la couleur pour un affichage graphique.
     * @return Color
     */
    public Color getCouleur() {
        return Color.blue;
    }

    /**
     * Type de la requete, ici c'est la couleur : bleu.
     * @return String
     */
    public String getType() {
        return "bleu";
    }

}
