package RequeteCOR;

import Main.FenetreDessin;

import java.io.PrintStream;

/**
 * Expert pour traiter une requete du type fenetre.
 */
public class ExpertFenetreCOR extends RequeteCOR{

    /**
     * Constructeur par defaut.
     */
    public ExpertFenetreCOR() {}

    /**
     * Execute la requete en utilisant la methode creerFenetre(x,y,taille) de la classe FenetreDessin.
     * @param fenetre
     * @param op
     * @param fluxSortant
     */
    public void executerRequete(String fenetre, FenetreDessin op, PrintStream fluxSortant) {
        String[] donneesFenetre = fenetre.split(";");
        op.creerFenetre(donneesFenetre[0], Integer.parseInt(donneesFenetre[1]), Integer.parseInt(donneesFenetre[2]));
        fluxSortant.print("1");
    }

    /**
     * Type de la requete, ici c'est l'ouverture d'une fentre : FENETRE.
     * @return String
     */
    public String getType() {
        return "FENETRE";
    }

}
