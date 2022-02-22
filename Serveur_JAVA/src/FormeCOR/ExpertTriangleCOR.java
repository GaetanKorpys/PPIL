package FormeCOR;

import Main.COR;
import Main.FenetreDessin;

import java.awt.*;

public class ExpertTriangleCOR extends FormeCOR{

    public ExpertTriangleCOR() {
    }

    public void dessiner(String forme, FenetreDessin op) {
        String[] donneesTriangle = forme.split(";");
        String couleurNonInterpretee = donneesTriangle[0];
        Color couleur = COR.getInstance().getCouleur().resoudre(couleurNonInterpretee);
        int[] x = new int[3];
        int[] y = new int[3];

        for(int i = 1; i < donneesTriangle.length; ++i) {
            double xTemp = Double.parseDouble(donneesTriangle[i].replace("(", "").replace(")", "").split(",")[0]);
            double yTemp = Double.parseDouble(donneesTriangle[i].replace("(", "").replace(")", "").split(",")[1]);
            x[i - 1] = (int)Math.round(xTemp);
            y[i - 1] = (int)Math.round(yTemp);
        }

        op.dessinerTriangle(x, y, couleur);
    }

    public String getType() {
        return "Triangle";
    }

}
