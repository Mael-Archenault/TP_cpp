#include <iostream>

#include <vector>
#include <string>
#include <fstream>
#include <sstream>




std::vector<std::vector<std::string>> lireCSV(const std::string& nomFichier) {
    std::ifstream fichier(nomFichier); // Ouvre le fichier
    if (!fichier.is_open()) { // Vérifie si le fichier est bien ouvert
        std::cerr << "Impossible d'ouvrir le fichier : " << nomFichier << std::endl;
        return std::vector<std::vector<std::string>>();
    }


    std::vector<std::vector<std::string>> csv;
    std::string ligne;

    while (std::getline(fichier, ligne)) { // Lit le fichier ligne par ligne
        std::stringstream ss(ligne); // Utilise un flux pour diviser la ligne
        std::string cellule;
        std::vector<std::string> donneesLigne;

        // Divise la ligne en cellules séparées par des virgules
        while (std::getline(ss, cellule, ',')) {
            donneesLigne.push_back(cellule); // Ajoute chaque cellule au vecteur
        }

        csv.push_back(donneesLigne);
    }
    fichier.close(); // Ferme le fichier

    return csv;



}
