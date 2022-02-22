package RequeteCOR;

import Main.FenetreDessin;

import java.io.PrintStream;

public abstract class Requete {

    public Requete(){}

    public abstract boolean resoudre(String requete, FenetreDessin op, PrintStream fluxSortant);

}
