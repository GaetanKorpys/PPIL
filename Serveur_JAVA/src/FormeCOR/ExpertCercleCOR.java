package FormeCOR;

import Main.COR;
import Main.FenetreDessin;

import java.awt.*;

public class ExpertCercleCOR extends FormeCOR{

    public ExpertCercleCOR() {
    }

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

    public String getType() {
        return "Cercle";
    }

}
