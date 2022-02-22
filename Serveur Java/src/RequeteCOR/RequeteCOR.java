package RequeteCOR;

import Main.FenetreDessin;

import java.io.PrintStream;

public abstract class RequeteCOR extends Requete{

    //Le maillon suivant dans la chaine de responsabilite.
    private RequeteCOR suivant;

    /**
     * Constructeur par defaut.
     */
    public RequeteCOR() {}

    /**
     * Verifie si l'expert peut traiter la requete, si oui alors il l'a traite et renvoie true, sinon renvoi false.
     * @param requete
     * @param op
     * @param fluxSortant
     * @return boolean
     */
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

    /**
     * Setter du suivant, relie les maillons de la chaine de responsabilite.
     * @param suivant
     */
    public void setSuivant(RequeteCOR suivant) {
        this.suivant = suivant;
    }

    /**
     * Essaie de d'interpreter la requete, sinon demande au suivant de faire de meme.
     * @param requete String
     * @param op FenetreDessin
     * @param fluxSortant PrintStream
     * @return
     */
    @Override
    public boolean resoudre(String requete, FenetreDessin op, PrintStream fluxSortant) {
        if (this.avoirTraiteRequete(requete, op, fluxSortant)) {
            return true;
        } else {
            return this.suivant != null ? this.suivant.resoudre(requete, op, fluxSortant) : false;
        }
    }

    /**
     * Traitement de la requete par l'expert.
     * @param requete
     * @param op
     * @param fluxSortant
     */
    public abstract void executerRequete(String requete, FenetreDessin op, PrintStream fluxSortant);

    /**
     * Getter du type de la requete (ouverture fenetre ou dessin forme).
     * @return string Une partie de la requete definissant son type.
     */
    public abstract String getType();
}
