package Main;

import java.io.IOException;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;

public class ServeurDessin {

    public static void main(String[] args)
    {
        int portServeurDessin = 8091;
        int nbClient = 0;
        int portLocal;
        InetAddress IpLocale;

        try
        {
            ServerSocket serveurDessin = new ServerSocket(portServeurDessin);

            System.out.println("Serveur de dessin pret. \n Details : "+serveurDessin);
            portLocal = serveurDessin.getLocalPort();
            IpLocale = InetAddress.getLocalHost();
            System.out.println("L'IP du serveur est : " + IpLocale.getHostAddress());
            System.out.println("Le port du serveur est : " + portLocal);

            while (true)
            {
                Socket nouveauClient = serveurDessin.accept();
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
