package FormeCOR;

import Main.FenetreDessin;

public abstract class FormeCOR extends Forme{
    private FormeCOR suivant;

    public FormeCOR(){}

    public void setSuivant(FormeCOR suivant) {
        this.suivant = suivant;
    }

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

    @Override
    public boolean resoudre(String forme, FenetreDessin op) {
        if (this.dessinable(forme, op)) {
            return true;
        } else {
            return this.suivant != null ? this.suivant.resoudre(forme, op) : false;
        }
    }

    public abstract String getType();

    public abstract void dessiner(String string, FenetreDessin op);
}
