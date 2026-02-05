#include <iostream>
#include <vector>

#include "point.h"
#include "form.h"
#include "carre.h"
#include "cercle.h"
#include "rectangle.h" 

using namespace std;

int main()
{

    cout << "=== TEST POINT ===" << endl;
    
    Point p1;            
    Point p2(10, 20);     
    Point p3(p2);         

    cout << "p1 (defaut) : " << endl << p1;
    cout << "p2 (10,20) : " << endl << p2;


    p1.translater(5, 5);
    cout << "p1 apres translater(5,5) : " << endl << p1;

    p1 += p2;
    cout << "p1 apres += p2 : " << endl << p1;



    cout << "\n=== TEST FORMES (STATIQUE) ===" << endl;


    Cercle c(Point(0, 0), 10);
    cout << "--- Cercle ---" << endl;
    cout << c << endl;
    cout << "Perimetre (2*PI*r) : " << c.perimeter() << endl;
    cout << "Surface (PI*r^2)   : " << c.surface() << endl;


    Rect r(Point(2, 2), 10, 5);
    cout << "\n--- Rectangle ---" << endl;
    cout << r << endl; 
    cout << "Perimetre (2*(l+h)) : " << r.perimeter() << endl;
    cout << "Surface (l*h)       : " << r.surface() << endl;

   
    Carre sq(Point(5, 5), 4);
    cout << "\n--- Carre ---" << endl;
    cout << sq << endl; 
    cout << "Perimetre (4*c) : " << sq.perimeter() << endl;
    cout << "Surface (c*c)   : " << sq.surface() << endl;



    cout << "\n=== TEST POLYMORPHISME (Vecteur) ===" << endl;

    vector<Form*> liste;
    
    // Ajout des formes
    liste.push_back(new Cercle(Point(0,0), 5));
    liste.push_back(new Rect(Point(10,10), 4, 2));
    liste.push_back(new Carre(Point(1,1), 3));

    int surfaceTotale = 0;

    for(size_t i = 0; i < liste.size(); ++i)
    {
        cout << "Forme #" << i << " : ";
        cout << "Surface = " << liste[i]->surface();
        cout << ", Perimetre = " << liste[i]->perimeter() << endl;

        surfaceTotale += liste[i]->surface();

        Form deplacement(Point(1, 1));
        *(liste[i]) += deplacement; 
    }

    cout << "\nSurface totale de la liste : " << surfaceTotale << endl;
    cout << "Verification translation (Form #0 doit etre en 1,1) : " << endl;
    cout << liste[0]->getPoint(); 

    for(size_t i = 0; i < liste.size(); ++i) {
        delete liste[i];
    }

    return 0;
}