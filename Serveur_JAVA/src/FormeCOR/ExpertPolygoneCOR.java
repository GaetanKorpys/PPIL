package FormeCOR;

import Main.COR;
import Main.FenetreDessin;

import java.awt.*;

public class ExpertPolygoneCOR extends FormeCOR{

    public ExpertPolygoneCOR() {
    }

    public void dessiner(String forme, FenetreDessin op) {
        String[] donneesPolygone = forme.split(";");
        String couleurNonInterpretee = donneesPolygone[0];
        Color couleur = COR.getInstance().getCouleur().resoudre(couleurNonInterpretee);
        int taille = donneesPolygone.length - 1;
        int[] x = new int[taille];
        int[] y = new int[taille];

        for(int i = 1; i < donneesPolygone.length; ++i) {
            double xTemp = Double.parseDouble(donneesPolygone[i].replace("(", "").replace(")", "").split(",")[0]);
            double yTemp = Double.parseDouble(donneesPolygone[i].replace("(", "").replace(")", "").split(",")[1]);
            x[i - 1] = (int)Math.round(xTemp);
            y[i - 1] = (int)Math.round(yTemp);
        }

        op.dessinerPolygone(x, y, taille, couleur);
    }

    public String getType() {
        return "Polygone";
    }

}
