package CouleurCOR;

import java.awt.*;

public abstract class CouleurCOR extends Couleur {

    //Le maillon suivant dans la chaine de responsabilite.
    private CouleurCOR suivant;

    /**
     * Constructeur par defaut.
     */
    public CouleurCOR() {}

    /**
     * Setter du suivant, relie les maillons de la chaine de responsabilite.
     * @param suivant
     */
    public void setSuivant(CouleurCOR suivant) {
        this.suivant = suivant;
    }

    /**
     * Essaie de d'interpreter la requete et renvoie le resultat, sinon demande au suivant de faire de meme.
     * @param couleur String
     * @return Color
     */
    public Color resoudre(String couleur) {
        Color c = null;
        if (couleur.equals(this.getType())) {
            c = this.getCouleur();
        }

        if (c != null) {
            return c;
        } else {
            return this.suivant != null ? this.suivant.resoudre(couleur) : null;
        }
    }

    public abstract Color getCouleur();

    /**
     * Getter de la couleur.
     * @return String Une partie de la requete definissant la couleur de la forme.
     */
    public abstract String getType();

}
