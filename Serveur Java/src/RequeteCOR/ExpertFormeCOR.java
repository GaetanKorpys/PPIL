package RequeteCOR;

import Main.COR;
import Main.FenetreDessin;

import java.io.PrintStream;

/**
 * Expert pour traiter une requete du type forme.
 */
public class ExpertFormeCOR extends RequeteCOR{
    /**
     * Constructeur par defaut.
     */
    public ExpertFormeCOR() {}

    /**
     * Execute la requete grace a la classe COR (Singleton).
     * @param forme
     * @param op
     * @param fluxSortant
     */
    public void executerRequete(String forme, FenetreDessin op, PrintStream fluxSortant) {
        boolean dessinOK = COR.getInstance().getForme().resoudre(forme, op);
        if (!dessinOK) {
            System.out.println("La forme n'a pas été reconnue par le serveur");
            fluxSortant.print("0");
        } else {
            fluxSortant.print("1");
        }

    }

    /**
     * Type de la requete, ici c'est une forme : FORME
     * @return Sting
     */
    public String getType() {
        return "FORME";
    }

}
