package RequeteCOR;

import Main.COR;
import Main.FenetreDessin;

import java.io.PrintStream;

public class ExpertFormeCOR extends RequeteCOR{

    public ExpertFormeCOR() {}

    public void executerRequete(String forme, FenetreDessin op, PrintStream fluxSortant) {
        boolean dessinOK = COR.getInstance().getForme().resoudre(forme, op);
        if (!dessinOK) {
            System.out.println("La forme n'a pas été reconnue par le serveur");
            fluxSortant.print("0");
        } else {
            fluxSortant.print("1");
        }

    }

    public String getType() {
        return "FORME";
    }

}
