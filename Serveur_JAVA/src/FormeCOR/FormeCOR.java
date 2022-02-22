package FormeCOR;

import Main.FenetreDessin;

public abstract class FormeCOR extends Forme{

    //Le maillon suivant dans la chaine de responsabilite.
    private FormeCOR suivant;

    /**
     * Constructeur par defaut.
     */
    public FormeCOR(){}


    /**
     * Setter du suivant, relie les maillons de la chaine de responsabilite.
     * @param suivant
     */
    public void setSuivant(FormeCOR suivant) {
        this.suivant = suivant;
    }

    /**
     * Verifie si l'expert peut traiter la requete, si oui alors il l'a traite et renvoie true, sinon renvoi false.
     * @param forme String
     * @param op FenetreDessin
     * @return boolean
     */
    public boolean dessinable(String forme, FenetreDessin op) {
        String typeForme = forme.split(":")[0];
        if (!typeForme.equals(this.getType())) {
            return false;
        } else {
            String infosForme = forme.split(":")[1];
            this.dessiner(infosForme, op);
            return true;
        }
    }

    /**
     * Essaie de d'interpreter la requete, sinon demande au suivant de faire de meme.
     * @param forme String
     * @param op FenetreDessin
     * @return boolean
     */
    @Override
    public boolean resoudre(String forme, FenetreDessin op) {
        if (this.dessinable(forme, op)) {
            return true;
        } else {
            return this.suivant != null ? this.suivant.resoudre(forme, op) : false;
        }
    }

    /**
     * Getter du type de la forme.
     * @return String Une partie de la requete definissant le type de la forme.
     */
    public abstract String getType();

    /**
     * Traitement de la requete par l'expert.
     * @param string String
     * @param op FenetreDessin
     */
    public abstract void dessiner(String string, FenetreDessin op);
}
