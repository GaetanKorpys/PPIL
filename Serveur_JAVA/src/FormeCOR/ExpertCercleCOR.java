package FormeCOR;

import Main.COR;
import Main.FenetreDessin;

import java.awt.*;

/**
 * Expert pour traiter un cercle.
 */
public class ExpertCercleCOR extends FormeCOR{

    /**
     * Constructeur par defaut.
     */
    public ExpertCercleCOR() {
    }

    /**
     * Execute la requete grace a la classe COR (Singleton) : dessine un cercle dans la fenetre.
     * @param forme
     * @param op
     */
    public void dessiner(String forme, FenetreDessin op) {
        String couleurNonInterpretee = forme.split(";")[0];
        Color couleur = COR.getInstance().getCouleur().resoudre(couleurNonInterpretee);
        String[] attributsForme = forme.split(";");
        double rayonDouble = Double.parseDouble(attributsForme[1]);
        rayonDouble *= 2.0D;
        int rayon = (int)Math.round(rayonDouble);
        String centre = attributsForme[2].replace("(", "").replace(")", "");
        double xCentreDouble = Double.parseDouble(centre.split(",")[0]);
        xCentreDouble -= (double)(rayon / 2);
        double yCentreDouble = Double.parseDouble(centre.split(",")[1]);
        yCentreDouble -= (double)(rayon / 2);
        int xCentre = (int)Math.round(xCentreDouble);
        int yCentre = (int)Math.round(yCentreDouble);
        op.dessinerCercle(xCentre, yCentre, rayon, couleur);
    }

    /**
     * Type de la requete, ici c'est un cercle : Cercle
     * @return String
     */
    public String getType() {
        return "Cercle";
    }

}
