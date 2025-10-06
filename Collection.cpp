/*************************************************************************
                           Collection  -  description
                             -------------------
    début                : 2025
    copyright            : (C) 3IFA par $AUTEUR$
    e-mail               : $EMAIL$
*************************************************************************/

//-- Réalisation de la classe <Collection> (fichier Collection.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Collection.h"
#include "Trajet.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Collection::AjouterElement ( const Trajet* t )
// Algorithme :
// Allocation mémoire d'une nouvelle cellule et copie en profondeur de t
// Insertion par tri alphabétique, ou insertion en fin de liste
{
    //Allocation mémoire
    Cellule *cellule = new Cellule;
    cellule->suivante = 0;
    cellule->trajet = t->Clone();
    //Insertion en début si la liste est vide
    if(racine == 0)
    {
        racine = cellule;
    }
    //Insertion par tri alphabétique
    else if(triInsertion)
    {
        Cellule *courante = racine;
        //Cas particulier : insertion en début de liste
        if(!compare(racine->trajet, cellule->trajet))
        {
            cellule->suivante = racine;
            racine = cellule;
        }
        //Cas particulier : la liste n'a qu'un seul élément
        else if(racine->suivante == 0)
        {
            racine->suivante = cellule;
        }
        //Cas général : insertion en milieu ou en fin de liste
        else
        {
            const Trajet* t1 = courante->suivante->trajet;
            const Trajet* t2 = cellule->trajet;
            while(courante->suivante && compare(t1, t2))
            {
                courante = courante->suivante;
                if(courante->suivante)
                {
                    t1 = courante->suivante->trajet;
                }
            }
            cellule->suivante = courante->suivante;
            courante->suivante = cellule;
        }
    }
    //Insertion en fin de liste
    else
    {
        Cellule *courante = racine;
        while(courante->suivante)
        {
            courante = courante->suivante;
        }
        courante->suivante = cellule;
    }
    ++longueur;
} //----- Fin de AjouterElement
    
const Trajet* Collection::PremierTrajet ( ) const
{
    return racine->trajet;
} //----- Fin de PremierTrajet
    
const Trajet* Collection::DernierTrajet ( ) const
{
    return Acceder(longueur - 1);
} //----- Fin de DernierTrajet
    
const Trajet* Collection::Acceder ( unsigned int indice ) const
// Algorithme :
// Parcours de la liste chainée jusqu'à atteindre l'élément recherché
{
    if(indice >= longueur)
    {
        return 0;
    }
    Cellule *courante = racine;
    for(unsigned int i=0; i<indice; ++i)
    {
        courante = courante->suivante;
    }
    return courante->trajet;
} //----- Fin de Acceder

unsigned int Collection::Longueur ( ) const
{
    return longueur;
} //----- Fin de Longueur

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Collection::Collection ( const Collection & uneCollection )
 : racine(0), triInsertion(uneCollection.triInsertion), longueur(0)
// Algorithme :
// Ajout par copie en profondeur de tous les éléments de uneCollection
{
#ifdef MAP
    cout << "Appel au constructeur de <Collection>" << endl;
#endif
    for(unsigned int i=0; i<uneCollection.Longueur(); ++i)
    {
        AjouterElement(uneCollection.Acceder(i));
    }
} //----- Fin de Collection

Collection::Collection ( bool triAlpha )
 : racine(0), triInsertion(triAlpha), longueur(0)
{
#ifdef MAP
    cout << "Appel au constructeur de <Collection>" << endl;
#endif
} //----- Fin de Collection


Collection::~Collection ( )
// Algorithme :
// Parcours de la liste chainée en libérant la mémoire au fur et à mesure
{
#ifdef MAP
    cout << "Appel au destructeur de <Collection>" << endl;
#endif
    Cellule* courante = racine;
    while(courante)
    {
        delete courante->trajet;
        Cellule* suivante = courante->suivante;
        delete courante;
        courante = suivante;
    }
} //----- Fin de ~Collection


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
bool Collection::compare ( const Trajet* t1, const Trajet* t2 ) const
// Algorithme :
// Comparaison par ordre alphabérique des villes de départ puis d'arrivée
{
    int cmpDep = strcmp(t1->RecupDepart(), t2->RecupDepart());
    int cmpArr = strcmp(t1->RecupArrivee(), t2->RecupArrivee());
    return cmpDep < 0 || (cmpDep == 0 && cmpArr < 0);
} // ----- Fin de compare

