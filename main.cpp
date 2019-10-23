#include <iostream>
#include <cstdlib>
#include "ArbreBI.h"

using namespace std;

int main(){
    int monTableau [17]={51, 77, 22, 5, 16, 33, 65, 53, 15, 101, 84, 3, 4, 71, 88, 81,23};
    Arbre arbre;

    for (int i= 0; i<17; i++){
        arbre.AjouterNoeud(monTableau[i]);
    }

    arbre.AfficherArbre();


    cout << endl;
    //***********************************
    int racine;
    racine = arbre.GetCleRoot();
    cout << "La cle de la racine est : " << racine << endl;

    cout<< "La plus petite cle dans l'arbre est: " << arbre.TrouverPlusPetiteCle()<< endl;

     arbre.AfficherInverse();
    arbre.DeleteNoeud(16);
    arbre.AfficherArbre();

    return 0;
}
