package Main;

import java.io.IOException;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;
import java.util.regex.Pattern;

/**
 * Serveur de dessin, classe ecouteur en attente d'une connexion d'un client.
 * Lorsqu'un client se connect, on cree alors une nouvelle instance de SessionDessin (Interlocuteur).
 */
public class ServeurDessin {

    private static final Pattern PATTERN = Pattern.compile("^(([01]?\\d\\d?|2[0-4]\\d|25[0-5])\\.){3}([01]?\\d\\d?|2[0-4]\\d|25[0-5])$");

    public static boolean validate(final String ip) {
        return PATTERN.matcher(ip).matches();
    }

    public static void main(String[] args)
    {
        int portServeurDessin = 8091; //Port de connexion
        int nbClient = 0; //Nombre de client
        int portLocal;
        InetAddress Ip;
        String reponse;


        try
        {
            //Saisie claver
            Scanner scanner = new Scanner(System.in);
            do
            {
                System.out.println("Voulez-vous tester le programme en locale (ou sur 2 machines) ?");
                System.out.println("[ y / n ]");
                reponse = scanner.nextLine();
                System.out.println(reponse);
            } while (!reponse.equals("y") && !reponse.equals("n"));

            if (reponse.equals("y"))
            {
                Ip = InetAddress.getByName("127.0.0.1");
            }
            else
            {
                do
                {
                    System.out.println("Veuillez saisir l'adresse IP de votre machine : ");
                    reponse = scanner.nextLine();
                } while (!validate(reponse));

                //Ip valide car testé précédement avec un regex
                Ip = InetAddress.getByName(reponse);
            }

            //Création du ServeurSocket : port 8091 et IP variable (locale ou saisie clavier)
            ServerSocket serveurDessin = new ServerSocket(portServeurDessin, 5, Ip );

            System.out.println("Serveur de dessin pret. \n Details : "+serveurDessin);
            portLocal = serveurDessin.getLocalPort();
            System.out.println("L'IP du serveur est : " + Ip);
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
