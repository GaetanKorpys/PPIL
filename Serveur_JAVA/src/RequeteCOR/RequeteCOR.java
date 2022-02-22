package RequeteCOR;

import Main.FenetreDessin;

import java.io.PrintStream;

public abstract class RequeteCOR extends Requete{

    private RequeteCOR suivant;

    public RequeteCOR() {}

    public boolean avoirTraiteRequete(String requete, FenetreDessin op, PrintStream fluxSortant) {
        String type = requete.split("&")[0];
        String donnees_requete = requete.split("&")[1];
        if (!type.equals(this.getType())) {
            return false;
        } else {
            this.executerRequete(donnees_requete, op, fluxSortant);
            return true;
        }
    }

    public void setSuivant(RequeteCOR suivant) {
        this.suivant = suivant;
    }

    @Override
    public boolean resoudre(String requete, FenetreDessin op, PrintStream fluxSortant) {
        if (this.avoirTraiteRequete(requete, op, fluxSortant)) {
            return true;
        } else {
            return this.suivant != null ? this.suivant.resoudre(requete, op, fluxSortant) : false;
        }
    }

    public abstract void executerRequete(String requete, FenetreDessin op, PrintStream fluxSortant);

    public abstract String getType();
}
