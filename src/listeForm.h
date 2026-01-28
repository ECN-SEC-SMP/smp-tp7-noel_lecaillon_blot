#ifndef LISTEFORM_H
#define LISTEFORM_H


#include <vector>
#include "form.h"
#include "rectangle.h"

class ListeFormes
{
private:
    std::vector<Form*> formes;  // stockage polymorphique
public:
    ListeFormes() = default;
    ~ListeFormes();

    // Ajout d'une forme
    void add(Form* f);

    // Consultation
    const std::vector<Form*>& getFormes() const;

    // Calcul de la surface totale
    int surfaceTotale() const;

    // Boîte englobante (retourne un Rect)
    Rect boundingBox() const;
};


#endif