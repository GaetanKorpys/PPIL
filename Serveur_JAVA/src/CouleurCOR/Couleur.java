package CouleurCOR;

import java.awt.*;

/**
 * Classe mere du DP COR pour la gestion de la couleur.
 */
public abstract class Couleur {

    /**
     * Constructeur par defaut.
     */
    public Couleur(){}

    /**
     * Essaie de traiter la requete selon l'expert.
     * @param couleur String
     * @return Color
     */
    public abstract Color resoudre(String couleur);

}
