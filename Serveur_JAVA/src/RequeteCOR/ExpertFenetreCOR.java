package RequeteCOR;

import Main.FenetreDessin;

import java.io.PrintStream;

public class ExpertFenetreCOR extends RequeteCOR{

    public ExpertFenetreCOR() {}

    public void executerRequete(String fenetre, FenetreDessin op, PrintStream fluxSortant) {
        String[] donneesFenetre = fenetre.split(";");
        op.creerFenetre(donneesFenetre[0], Integer.parseInt(donneesFenetre[1]), Integer.parseInt(donneesFenetre[2]));
        fluxSortant.print("1");
    }

    public String getType() {
        return "FENETRE";
    }

}
