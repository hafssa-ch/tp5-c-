
#include <iostream>
#include <string>
using namespace std;

class Utilisateur {
private:
    string nom;
    string role;
    static int nbUtilisateursConnectes; 

public:
    
    Utilisateur(const string& n, const string& r) : nom(n), role(r) {
        nbUtilisateursConnectes++;
    }

    ~Utilisateur() {
        nbUtilisateursConnectes--;
    }

    static int getNbUtilisateursConnectes() {
        return nbUtilisateursConnectes;
    }

    void afficher() const {
        cout << "Utilisateur : " << nom << ", Rôle : " << role << endl;
    }
};

int Utilisateur::nbUtilisateursConnectes = 0;


int main() {
    cout << "Nombre d'utilisateurs connectés : " 
         << Utilisateur::getNbUtilisateursConnectes() << endl;

    Utilisateur u1("Alice", "admin");
    cout << "Après connexion de Alice : " 
         << Utilisateur::getNbUtilisateursConnectes() << endl;

    Utilisateur u2("Bob", "visiteur");
    cout << "Après connexion de Bob : " 
         << Utilisateur::getNbUtilisateursConnectes() << endl;

    {
        Utilisateur u3("Charlie", "moderateur");
        cout << "Après connexion de Charlie : " 
             << Utilisateur::getNbUtilisateursConnectes() << endl;
    }

    cout << "Après déconnexion de Charlie : " 
         << Utilisateur::getNbUtilisateursConnectes() << endl;

    return 0;
}
