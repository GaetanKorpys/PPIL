package FormeCOR;

import Main.FenetreDessin;

/**
 * Classe mere du DP COR pour la gestion de la forme.
 */
public abstract class Forme {

    /**
     * Constructeur par defaut.
     */
    public Forme(){}

    /**
     * Essaie de traiter la requete selon l'expert.
     * @param forme String
     * @param op FenetreDessin
     * @return boolean
     */
    public abstract boolean resoudre(String forme, FenetreDessin op);
}
