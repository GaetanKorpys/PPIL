package Main;

import javax.swing.*;
import java.awt.*;
import java.awt.image.BufferStrategy;

/**
 * Classe de dessin graphique.
 */
public class FenetreDessin {
    private JFrame frame;
    private BufferStrategy strategie;
    private Graphics graphic;

    /**
     * Constructeur par defaut.
     */
    public FenetreDessin() {}

    /**
     * Getter de graphic.
     * @return Graphics
     */
    public Graphics getGraphique() {
        return this.graphic;
    }

    /**
     * Setter de grapic
     * @param graph Graphics
     */
    public void setGraphique(Graphics graph) {
        this.graphic = graph;
    }

    /**
     * Getter de frame
     * @return JFrame
     */
    public JFrame getFrame() {
        return this.frame;
    }

    /**
     * Setter de frame
     * @param f JFrame
     */
    public void setFrame(JFrame f) {
        this.frame = f;
    }

    /**
     * Getter de strategie
     * @return BufferStrategy
     */
    public BufferStrategy getStrategie() {
        return this.strategie;
    }

    /**
     * Setter de strategie
     * @param strat BufferStrategy
     */
    public void setStrategie(BufferStrategy strat) {
        this.strategie = strat;
    }

    /**
     * Creation de la fenetre de dessin
     * @param titre String Le titre de la fentre
     * @param largeur int La largeur de la fenetre
     * @param hauteur int La hauteur de la fenetre
     */
    public void creerFenetre(String titre, int largeur, int hauteur) {
        this.setFrame(new JFrame(titre));
        this.getFrame().setSize(largeur, hauteur);
        this.getFrame().setLocationRelativeTo((Component)null);
        this.getFrame().setResizable(false);
        this.getFrame().setVisible(true);
        this.getFrame().setIgnoreRepaint(true);
    }

    /**
     * Affichage gaphique du cercle dans la fentre de dessin.
     * @param x int
     * @param y int
     * @param rayon int
     * @param color Color
     */
    public void dessinerCercle(int x, int y, int rayon, Color color) {
        try {
            int numBuffers = 2;
            this.getFrame().createBufferStrategy(numBuffers);
            this.setStrategie(this.getFrame().getBufferStrategy());
            this.setGraphique(this.getStrategie().getDrawGraphics());
            Thread.sleep(150);
            this.getGraphique().setColor(color);
            this.getGraphique().drawOval(x, y, rayon, rayon);
            this.getStrategie().dispose();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

    }

    /**
     * Affichage graphique d'un polygone dans la fentre de dessin.
     * @param x int[]
     * @param y int[]
     * @param taille int Nombre de points
     * @param color Color
     */
    public void dessinerPolygone(int[] x, int[] y, int taille, Color color) {
        try {
            int numBuffers = 2;
            this.getFrame().createBufferStrategy(numBuffers);
            this.setStrategie(this.getFrame().getBufferStrategy());
            this.setGraphique(this.getStrategie().getDrawGraphics());
            Thread.sleep(50);
            this.getGraphique().setColor(color);
            this.getGraphique().drawPolygon(x, y, taille);
            this.getStrategie().dispose();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

    }

    /**
     * Affichage graphique d'un segment dans le fentre de dessin.
     * @param x1 int
     * @param y1 int
     * @param x2 int
     * @param y2 int
     * @param color Color
     */
    public void dessinerSegment(int x1, int y1, int x2, int y2, Color color) {
        try {
            int numBuffers = 1;
            this.getFrame().createBufferStrategy(numBuffers);
            this.setStrategie(this.getFrame().getBufferStrategy());
            this.setGraphique(this.getStrategie().getDrawGraphics());
            Thread.sleep(50);
            this.getGraphique().setColor(color);
            this.getGraphique().drawLine(x1, y1, x2, y2);
            this.getStrategie().dispose();
        } catch (InterruptedException var7) {
            var7.printStackTrace();
        }

    }

    /**
     * Affichage graphique d'un triangle dans la fentre de dessin.
     * @param x int[]
     * @param y int[]
     * @param color Color
     */
    public void dessinerTriangle(int[] x, int[] y, Color color) {
        try {
            int numBuffers = 2;
            this.getFrame().createBufferStrategy(numBuffers);
            this.setStrategie(this.getFrame().getBufferStrategy());
            this.setGraphique(this.getStrategie().getDrawGraphics());
            Thread.sleep(50);
            this.getGraphique().setColor(color);
            this.getGraphique().drawPolygon(x, y, 3);
            this.getStrategie().dispose();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
