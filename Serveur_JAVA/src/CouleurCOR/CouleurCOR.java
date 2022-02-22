package CouleurCOR;

import java.awt.*;

public abstract class CouleurCOR extends Couleur {

    private CouleurCOR suivant;

    public CouleurCOR() {}

    public void setSuivant(CouleurCOR suivant) {
        this.suivant = suivant;
    }

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

    public abstract String getType();

}
