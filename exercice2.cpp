
#include <iostream>
#include <string>
using namespace std;

class Produit {
private:
    string nom;
    float prixHT;
    static float tauxTVA; 

public:
 
    Produit(const string& n, float prix) : nom(n), prixHT(prix) {}

    float getPrixTTC() const {
        return prixHT * (1 + tauxTVA / 100);
    }

    void afficher() const {
        cout << nom << " : " << getPrixTTC() << " TTC" << endl;
    }

    static void modifierTVA(float nouveauTaux) {
        tauxTVA = nouveauTaux;
    }
};

float Produit::tauxTVA = 20.0f;


int main() {
    Produit p1("Stylo", 10.0);
    Produit p2("Cahier", 15.0);

    cout << "Prix TTC avant modification du taux :" << endl;
    p1.afficher();
    p2.afficher();

    Produit::modifierTVA(10.0);

    cout << "\nPrix TTC après modification du taux :" << endl;
    p1.afficher();
    p2.afficher();

    return 0;
}
