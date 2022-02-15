package Main;

import javax.swing.*;
import java.awt.*;
import java.awt.image.BufferStrategy;

public class FenetreDessin {
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
        this.getFrame().setIgnoreRepaint(true);
    }

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
