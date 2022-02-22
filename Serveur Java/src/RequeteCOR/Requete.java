package RequeteCOR;

import Main.FenetreDessin;

import java.io.PrintStream;

/**
 * Classe mere du DP COR pour la gestion de la requete (ouverture d'une fentre ou dessin d'une forme).
 */
public abstract class Requete {
    /**
     * Constructeur par defaut.
     */
    public Requete(){}

    /**
     * Essaie de traiter la requete selon l'expert.
     * @param requete String
     * @param op FenetreDessin
     * @param fluxSortant PrintStream
     * @return boolean
     */
    public abstract boolean resoudre(String requete, FenetreDessin op, PrintStream fluxSortant);

}
