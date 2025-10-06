/*************************************************************************
                              Trajet  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $ANNEE$ par $AUTEUR$
    e-mail               : $EMAIL$
*************************************************************************/

//------- Interface de la classe <Trajet> (fichier Trajet.h) -------------
#if ! defined ( TRAJET_H )
#define TRAJET_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
// La classe Trajet représente un trajet orienté entre deux villes,
// le départ et l'arrivée, comprenant ou pas des étapes intermédiaires.
// C'est une classe abstraite qui sert à manipuler dans une collection
// hétérogène ses classes filles (TrajetSimple et TrajetCompose), sans
// distinction de leur nature
//------------------------------------------------------------------------

class Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual void Afficher ( bool nl = true ) const = 0;
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual const char* GetDepart ( ) const = 0;
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual const char* GetArrivee ( ) const = 0;
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual Trajet* Clone ( ) const = 0;
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Trajet ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Trajet ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
//----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de <Xxx>
#endif // TRAJET_H

