package FormeCOR;

import Main.COR;
import Main.FenetreDessin;

import java.awt.*;

/**
 * Expert pour traiter un segment.
 */
public class ExpertSegmentCOR extends FormeCOR{

    /**
     * Constructeur par defaut.
     */
    public ExpertSegmentCOR() {
    }

    /**
     * Execute la requete grace a la classe COR (Singleton) : dessine un segment dans la fenetre.
     * @param forme
     * @param op
     */
    public void dessiner(String forme, FenetreDessin op) {
        String couleurNonInterpretee = forme.split(";")[0];
        Color couleur = COR.getInstance().getCouleur().resoudre(couleurNonInterpretee);
        String pointA = forme.split(";")[1].replace("(", "").replace(")", "");
        String pointB = forme.split(";")[2].replace("(", "").replace(")", "");
        double pointAxDouble = Double.parseDouble(pointA.split(",")[0]);
        double pointAyDouble = Double.parseDouble(pointA.split(",")[1]);
        double pointBxDouble = Double.parseDouble(pointB.split(",")[0]);
        double pointByDouble = Double.parseDouble(pointB.split(",")[1]);
        int pointAx = (int)Math.round(pointAxDouble);
        int pointAy = (int)Math.round(pointAyDouble);
        int pointBx = (int)Math.round(pointBxDouble);
        int pointBy = (int)Math.round(pointByDouble);
        op.dessinerSegment(pointAx, pointAy, pointBx, pointBy, couleur);
    }

    /**
     * Type de la requete, ici c'est un segment : Segment
     * @return String
     */
    public String getType() {
        return "Segment";
    }

}
