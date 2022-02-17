/**
* \file Constante.h
* \brief Ce fichier contient la définition de l'ensemble des constantes utilisées dans le programme.
*/
#pragma once
#include <string>

const double PI = 3.1415926535897932; ///< PI pour les calcules mathématiques.

const std::string SAUVGARDE = "../Sauvgarde.txt"; ///< Le chemin pour sauvgarder/charger une forme.


/**
 * \brief Définitions de plusieurs constantes pour les séparateurs lors de l'envoi d'une requête.
 */
const std::string SEPARATEUR_TYPE_REQUETE = "&"; ///< Pour savoir si la requête demande le dessin d'une forme ou l'ouverture d'une fenêtre.
const std::string SEPARATEUR_TYPE_DONNEE = ":"; ///< Pour connaitre le type de la forme.
const std::string SEPARATEUR_DONNEE = ";"; ///< Pour séparer les données classiques.

/**
 * \brief 2 constantes pour les dimensions de la fenêtre du serveur.
 */
const int LARGEUR = 1024;
const int HAUTEUR = 768;


/**
 * \brief Définitions de plusieurs constantes pour les couleurs.
 */
const std::string BLACK = "noir"; 
const std::string BLUE = "bleu"; 
const std::string RED = "rouge";
const std::string GREEN = "vert"; 
const std::string YELLOW = "jaune";
const std::string CYAN = "cyan"; 
