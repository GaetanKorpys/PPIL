/**
* \file Constante.h
* \brief Ce fichier contient la d�finition de l'ensemble des constantes utilis�es dans le programme.
*/
#pragma once
#include <string>

const double PI = 3.1415926535897932; ///< PI pour les calcules math�matiques.

const std::string SAUVGARDE = "../Sauvgarde.txt"; ///< Le chemin pour sauvgarder/charger une forme.


/**
 * \brief D�finitions de plusieurs constantes pour les s�parateurs lors de l'envoi d'une requ�te.
 */
const std::string SEPARATEUR_TYPE_REQUETE = "&"; ///< Pour savoir si la requ�te demande le dessin d'une forme ou l'ouverture d'une fen�tre.
const std::string SEPARATEUR_TYPE_DONNEE = ":"; ///< Pour connaitre le type de la forme.
const std::string SEPARATEUR_DONNEE = ";"; ///< Pour s�parer les donn�es classiques.

/**
 * \brief 2 constantes pour les dimensions de la fen�tre du serveur.
 */
const int LARGEUR = 1024;
const int HAUTEUR = 768;


/**
 * \brief D�finitions de plusieurs constantes pour les couleurs.
 */
const std::string BLACK = "noir"; 
const std::string BLUE = "bleu"; 
const std::string RED = "rouge";
const std::string GREEN = "vert"; 
const std::string YELLOW = "jaune";
const std::string CYAN = "cyan"; 
