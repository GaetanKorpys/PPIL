package Main;

import javax.swing.*;
import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.image.BufferStrategy;

public class FenetreDessin extends Frame{
    private JFrame frame;
    private BufferStrategy strategie;
    private Graphics graphic;

    public FenetreDessin() {}

    public Graphics getGraphique() {
        return this.graphic;
    }

    public void setGraphique(Graphics graph) {
        this.graphic = graph;
    }

    public JFrame getFrame() {
        return this.frame;
    }

    public void setFrame(JFrame f) {
        this.frame = f;
    }

    public BufferStrategy getStrategie() {
        return this.strategie;
    }

    public void setStrategie(BufferStrategy strat) {
        this.strategie = strat;
    }

    public void creerFenetre(String titre, int largeur, int hauteur) {
        this.setFrame(new JFrame(titre));
        this.getFrame().setSize(largeur, hauteur);
        this.getFrame().setLocationRelativeTo((Component)null);
        this.getFrame().setResizable(false);
        this.getFrame().setVisible(true);
        this.frame.createBufferStrategy(2);
        try {
            Thread.sleep(150);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        this.strategie = this.frame.getBufferStrategy();
        this.graphic = this.strategie.getDrawGraphics();
        this.getFrame().setIgnoreRepaint(true);
    }

    public void dessinerCercle(int x, int y, int rayon, Color color) {
        this.getGraphique().setColor(color);
        this.getGraphique().drawOval(x, y, rayon, rayon);
    }

    public void dessinerPolygone(int[] x, int[] y, int taille, Color color) {
        this.getGraphique().setColor(color);
        this.getGraphique().drawPolygon(x, y, taille);
    }

    public void dessinerSegment(int x1, int y1, int x2, int y2, Color color) {
        this.getGraphique().setColor(color);
        this.getGraphique().drawLine(x1, y1, x2, y2);

    }

    public void dessinerTriangle(int[] x, int[] y, Color color) {
        this.getGraphique().setColor(color);
        this.getGraphique().drawPolygon(x, y, 3);
    }
}
