package Main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.Socket;
import java.net.SocketException;

public class SessionDessin extends Thread{

    int nbConnexion;
    Socket socket;
    BufferedReader fluxEntrant;
    PrintStream fluxSortant;

    public SessionDessin(Socket socket, int nbConnexion) throws IOException {
        this.socket = socket;
        this.nbConnexion = nbConnexion;
        this.fluxEntrant = new BufferedReader(new InputStreamReader(this.socket.getInputStream()));
        this.fluxSortant = new PrintStream(this.socket.getOutputStream());
    }

    public void run()
    {
        String requete;
        FenetreDessin objetAwt = new FenetreDessin();
        try
        {
            while(true)
            {

                requete = this.fluxEntrant.readLine();

                if(requete != null)
                {
                    System.out.println("Le client numero " + this.nbConnexion + " a envoye la requete : " + requete);

                    requete = requete.trim();

                    boolean interpreteOk = COR.getInstance().getRequete().resoudre(requete, objetAwt, this.fluxSortant);
                    if (interpreteOk) {
                        objetAwt.getStrategie().show();
                    }
                    else
                    {
                        System.out.println("Requete non interpretee");
                    }
                }
            }

        } catch (SocketException e){
            System.out.println("Erreur : Socket Exception");
            e.printStackTrace();
        } catch (IOException e) {
            System.out.println("Erreur : Impossible de lire sur le socket provenant du client.");
        }
    }
}
