/*************************************************************************
Xxx  -  description
                             -------------------
    début                : 2025
    copyright            : (C) 3IFA par $AUTEUR$
    e-mail               : $EMAIL$
*************************************************************************/

//------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ---------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Trajet.h"

//------------------------------------------------------------- Constantes
//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques
// type Xxx::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

//-------------------------------------------- Constructeurs - destructeur
Trajet::Trajet ( )
{
#ifdef MAP
    cout << "Appel au constructeur de <Trajet>" << endl;
#endif
} //----- Fin de Trajet


Trajet::~Trajet ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Trajet>" << endl;
#endif
} //----- Fin de ~Trajet

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées