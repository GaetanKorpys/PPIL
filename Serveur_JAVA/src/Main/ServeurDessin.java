package Main;

import java.io.IOException;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;

/**
 * Serveur de dessin, classe ecouteur en attente d'une connexion d'un client.
 * Lorsqu'un client se connect, on cree alors une nouvelle instance de SessionDessin (Interlocuteur).
 */
public class ServeurDessin {

    public static void main(String[] args)
    {
        int portServeurDessin = 8091; //Port de connexion
        int nbClient = 0; //Nombre de client
        int portLocal;
        InetAddress IpLocale;

        try
        {
            //Creation d'un socket
            ServerSocket serveurDessin = new ServerSocket(portServeurDessin);

            System.out.println("Serveur de dessin pret. \n Details : "+serveurDessin);
            portLocal = serveurDessin.getLocalPort();
            IpLocale = InetAddress.getLocalHost();
            System.out.println("L'IP du serveur est : " + IpLocale.getHostAddress());
            System.out.println("Le port du serveur est : " + portLocal);

            //Classe ecouteur en attente d'un client, donc constament a l'ecoute.
            while (true)
            {
                //Instanciation d'un nouveau interlocteur (Thread).
                Socket nouveauClient = serveurDessin.accept();

                //Incrementation du nombre de client
                ++nbClient;

                System.out.println("Connexion reussie n° : " + nbClient);
                SessionDessin nouveauClientThread = new SessionDessin(nouveauClient, nbClient);
                nouveauClientThread.start();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
