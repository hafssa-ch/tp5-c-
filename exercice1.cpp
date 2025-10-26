
#include <iostream>
using namespace std;

class Boite {
private:
    double longueur;
    double largeur;
    double hauteur;
    static int nbBoites; 

public:
    
    Boite(double l, double L, double h) 
        : longueur(l), largeur(L), hauteur(h) {
        nbBoites++;
    }

    ~Boite() {
        nbBoites--;
    }

    static int getNombreBoites() {
        return nbBoites;
    }

    void afficher() const {
        cout << "Boite (" << longueur << " x " << largeur << " x " 
             << hauteur << ")" << endl;
    }
};

int Boite::nbBoites = 0;


int main() {
    Boite b1(2.0, 3.0, 4.0);
    Boite b2(1.5, 2.5, 3.5);

    cout << "Nombre total de boîtes créées : " << Boite::getNombreBoites() << endl;

    {
        Boite b3(5.0, 5.0, 5.0);
        cout << "Nombre total de boîtes après création de b3 : " 
             << Boite::getNombreBoites() << endl;
    }

    cout << "Nombre total de boîtes après destruction de b3 : " 
         << Boite::getNombreBoites() << endl;

    return 0;
}
