#include <iostream>
#include <cstdlib>
#include "ArbreBI.h"

using namespace std;

Arbre::Arbre(){
    root = NULL;
}

Arbre::Noeud* Arbre::CreerFeuille(int cle){
    Noeud* n = new Noeud;
    n->cle = cle;
    n->gauche = NULL;
    n->droite = NULL;

    return n;
}

void   Arbre::AjouterNoeud (int cle){
    AjouterNoeudPrivee(cle, root);
}
void    Arbre::AjouterNoeudPrivee(int cle, Noeud* Ptr){
        if (root == NULL){
            root = CreerFeuille(cle);
        }
        else if(cle < Ptr->cle){
                if(Ptr->gauche !=NULL){
                    AjouterNoeudPrivee(cle, Ptr->gauche);
                }
                else{  // inserer mon noeud
                    Ptr->gauche = CreerFeuille(cle);
                }
        }
        else if(cle > Ptr->cle){
                if(Ptr->droite !=NULL){
                    AjouterNoeudPrivee(cle, Ptr->droite);
                }
                else{  // inserer mon noeud
                    Ptr->droite = CreerFeuille(cle);
                }
        }
        else{
            cout << "cet element existe deja !!!   \n" ;
        }
}

void    Arbre::AfficherArbre(){
   AfficherArbrePrivee(root);
}

 void    Arbre::AfficherArbrePrivee(Noeud* Ptr){
  if (root !=NULL){
        if (Ptr->gauche !=NULL){
            AfficherArbrePrivee(Ptr->gauche);
        }
        cout << Ptr->cle << " ** ";

        if (Ptr->droite !=NULL){
            AfficherArbrePrivee(Ptr->droite);
        }
    }
    else{
        cout << " arbre n existe  pas !!! \n";
    }
 }

 Arbre::Noeud* Arbre::GetNoeud(int cle){
    return GetNoeudPrivee(cle, root);
}

Arbre::Noeud* Arbre::GetNoeudPrivee(int cle, Noeud* Ptr){
    if (Ptr !=NULL){
        if(Ptr->cle == cle){
            return Ptr;
        }
        else {
            if (cle < Ptr->cle){
                 return GetNoeudPrivee(cle, Ptr->gauche);
            }
            else {
                return GetNoeudPrivee(cle, Ptr->droite);
            }
        }
    }
    else {
        return NULL;
    }
}

int Arbre::GetCleRoot(){
    if (root !=NULL){
        return root->cle;
    }
    else return -999;
}

void Arbre::AfficherEnfants(int cle){
    Noeud* Ptr = GetNoeud(cle);
    cout << "Ptr->cle: " << Ptr->cle;
    if (Ptr != NULL){
       cout<<"Le Noeud Parent est = "<< Ptr->cle << endl;
       Ptr->gauche == NULL ?
       cout << "Il n y a pas de fils a gauche \n" :
       cout << "Le fils gauche est = " << Ptr->gauche->cle <<endl;

       Ptr->droite == NULL ?
       cout << "Il n y a pas de fils a droite \n" :
       cout << "Le fils a droite est = "<< Ptr->droite->cle <<endl;
    }
    else{
        cout << "La cle est " << cle << " n existe pas \n";
    }
}

int Arbre::TrouverPlusPetiteCle(){
   return TrouverPlusPetiteClePrivee(root);
}

int Arbre::TrouverPlusPetiteClePrivee(Noeud* Ptr){
    if (root == NULL){
        cout << "l arbre est vide.... \n" ;
        return -999;
    }
    else {
        if(Ptr->gauche !=NULL){
            return TrouverPlusPetiteClePrivee(Ptr->gauche);
        }
        else {
            return Ptr->cle;
        }
    }
}

void Arbre::DeleteNoeudPriveeV1(int cle, Noeud * Ptr, Noeud * Pere)
{
    if (root -> cle==cle && root->gauche==NULL && root -> droite == NULL){
            root = NULL;
        }
        else if(cle < Ptr->cle){
                if(Ptr->gauche !=NULL){
                    DeleteNoeudPriveeV1(cle, Ptr->gauche,Ptr);
                }
                else{  // inserer mon noeud
                    cout << "Element n'existe pas";
                }
        }
        else if(cle > Ptr->cle){
                if(Ptr->droite !=NULL){
                    DeleteNoeudPriveeV1(cle, Ptr->droite,Ptr);
                }
                else{  // inserer mon noeud
                    cout << "Element n'existe pas";
                }
        }
        else
        {
            Noeud *filsGauche = Ptr -> gauche ;
            if (Pere != NULL)
                Pere -> gauche = Ptr ->droite;
            Ptr = Ptr -> droite;
            while(Ptr ->gauche !=NULL)
                Ptr = Ptr -> gauche;
            Ptr -> gauche = filsGauche;
        }
}

void  Arbre::DeleteNoeudPriveeV2(int cle, Noeud * Ptr)
{
    return DeleteNoeudPriveeV1(cle,Ptr,NULL);
}
void  Arbre::DeleteNoeud(int cle)
{
    return DeleteNoeudPriveeV2(cle,root);
}

void Arbre::AfficherInversePrivee(Noeud* Ptr)
{
if (root !=NULL){
        if (Ptr->droite !=NULL){
           AfficherInversePrivee(Ptr->droite);
        }
        cout << Ptr->cle << " ** ";

        if (Ptr->gauche !=NULL){
            AfficherInversePrivee(Ptr->gauche);
        }
    }
    else{
        cout << " arbre n existe  pas !!! \n";
    }

}
void   Arbre::AfficherInverse(){
 return AfficherInversePrivee(root);
}
