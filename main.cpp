#include <iostream>
#include <cstring> // Pour strcpy, strlen
using namespace std; // Ajout du namespace std

#include "Collection.h"
#include "Trajet.h"

// Classe concrète pour tester (implémentation minimale de Trajet)
class TrajetSimple : public Trajet {
private:
    char* depart;
    char* arrivee;

public:
    TrajetSimple(const char* dep, const char* arr) {
        depart = new char[strlen(dep) + 1];
        arrivee = new char[strlen(arr) + 1];
        strcpy(depart, dep);
        strcpy(arrivee, arr);
    }

    ~TrajetSimple() {
        delete[] depart;
        delete[] arrivee;
    }

    void Afficher(bool nl = true) const override {
        cout << "Trajet simple: " << depart << " -> " << arrivee;
        if (nl) cout << endl;
    }

    const char* RecupDepart() const override { return depart; }
    const char* RecupArrivee() const override { return arrivee; }

    Trajet* Clone() const override {
        return new TrajetSimple(depart, arrivee);
    }
};

// Fonction pour afficher une collection (simplifiée avec namespace std)
void AfficherCollection(const Collection& col) {
    cout << "Collection (" << col.Longueur() << " trajets):" << endl;
    for (unsigned int i = 0; i < col.Longueur(); ++i) {
        cout << "  ";
        col.Acceder(i)->Afficher();
    }
}

int main() {
    cout << "=== DEBUT DES TESTS ===" << endl << endl;

    // Test 1: Création d'une collection vide
    cout << "Test 1: Collection vide" << endl;
    Collection col1;
    cout << "Longueur: " << col1.Longueur() << " (attendu: 0)" << endl;
    cout << endl;

    // Test 2: Ajout de trajets (sans tri)
    cout << "Test 2: Ajout de trajets (ordre d'insertion)" << endl;
    Collection col2(false); // Pas de tri alphabétique
    col2.AjouterElement(new TrajetSimple("Paris", "Lyon"));
    col2.AjouterElement(new TrajetSimple("Marseille", "Nice"));
    col2.AjouterElement(new TrajetSimple("Bordeaux", "Toulouse"));
    AfficherCollection(col2);
    cout << endl;

    // Test 3: Ajout de trajets (avec tri alphabétique)
    cout << "Test 3: Ajout de trajets (tri alphabétique)" << endl;
    Collection col3(true); // Avec tri alphabétique
    col3.AjouterElement(new TrajetSimple("Paris", "Lyon"));
    col3.AjouterElement(new TrajetSimple("Marseille", "Nice"));
    col3.AjouterElement(new TrajetSimple("Bordeaux", "Toulouse"));
    col3.AjouterElement(new TrajetSimple("Lyon", "Paris"));
    AfficherCollection(col3);
    cout << endl;

    // Test 4: Accès aux éléments
    cout << "Test 4: Accès aux éléments" << endl;
    cout << "Premier trajet: ";
    col3.PremierTrajet()->Afficher();
    cout << "Dernier trajet: ";
    col3.DernierTrajet()->Afficher();
    cout << "Trajet à l'indice 1: ";
    col3.Acceder(1)->Afficher();
    cout << "Trajet à l'indice 10 (invalide): ";
    if (col3.Acceder(10) == nullptr) {
        cout << "OK (nullptr retourné)" << endl;
    } else {
        cout << "ERREUR" << endl;
    }
    cout << endl;

    // Test 5: Constructeur de copie
    cout << "Test 5: Constructeur de copie" << endl;
    Collection col4(col3);
    cout << "Collection originale:" << endl;
    AfficherCollection(col3);
    cout << "Collection copiée:" << endl;
    AfficherCollection(col4);
    cout << endl;

    // Test 6: Vérification de l'indépendance des collections
    cout << "Test 6: Indépendance des collections" << endl;
    col3.AjouterElement(new TrajetSimple("Nantes", "Rennes"));
    cout << "Longueur col3: " << col3.Longueur() << endl;
    cout << "Longueur col4: " << col4.Longueur() << " (doit rester inchangé)" << endl;
    cout << endl;

    // Test 7: Destruction automatique
    cout << "Test 7: Destruction des collections" << endl;
    cout << "Les collections vont être détruites automatiquement..." << endl;

    cout << endl << "=== FIN DES TESTS ===" << endl;
    return 0;
}
