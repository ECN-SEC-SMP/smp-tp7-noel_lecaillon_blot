# Rapport de TP7 : Programmation Orientée Objet et Polymorphisme en C++

---

## 1. Introduction

Ce travail pratique a pour objectif la mise en œuvre de concepts avancés de la programmation orientée objet (POO) en C++. Le sujet s'articule autour de la modélisation géométrique de formes planes. Les principaux axes de travail ont été la création de classes, l'utilisation de la surcharge d'opérateurs et l'exploitation du polymorphisme pour manipuler de manière générique des objets (Cercles, Rectangles, Carrés).

## 2. Modélisation et Conception

L'architecture du projet repose sur une hiérarchie de classes claire, séparant les entités de base, les abstractions et les implémentations concrètes.

### 2.1 La Classe Point : Brique Élémentaire
La première étape a consisté à développer une classe `Point` représentant une coordonnée dans le plan.
* **Encapsulation :** La classe gère deux attributs réels (x, y) accessibles via des accesseurs et mutateurs.
* **Forme Canonique :** Nous avons implémenté les constructeurs essentiels : par défaut (origine), paramétré (coordonnées spécifiques) et de recopie (`const Point &`).
* **Translation :** Une méthode `translater()` ainsi qu'une surcharge de l'opérateur `+` (ou `+=`) ont été définies pour permettre le déplacement intuitif des points.

### 2.2 Abstraction via la Classe Forme
La classe `Form` introduit le concept d'abstraction. Elle définit l'interface commune à toute entité géométrique fermée centrée sur un point.
* **Héritage :** Elle sert de classe mère. Elle contient un objet `Point` comme attribut principal (le centre ou coin de référence).
* **Méthodes Virtuelles :** Les méthodes `perimetre()` et `surface()` sont déclarées virtuelles. Cela oblige les classes dérivées à fournir leur propre formule de calcul, garantissant que chaque forme se comporte correctement selon sa nature géométrique.

### 2.3 Spécialisation des Formes
Trois classes concrètes ont été implémentées :
1.  **Cercle :** Caractérisé par un rayon `r`. Les calculs de surface et périmètre utilisent la constante `M_PI`.
2.  **Rectangle :** Caractérisé par une largeur `l` et une hauteur `h`.
3.  **Carré :** Un cas particulier défini par un côté `c`. Bien que pouvant hériter de Rectangle, il a été traité ici spécifiquement pour assurer une cohérence stricte de ses dimensions (côté unique).

---

## 3. Aspects Techniques Avancés

### 3.1 Surcharge d'Opérateurs
Pour améliorer la lisibilité du code et l'interaction avec les flux standards C++, nous avons systématiquement surchargé l'opérateur de flux `<<`.
* **Intérêt :** Cela permet d'écrire `cout << monCercle;` au lieu d'appeler une méthode dédiée type `monCercle.afficher()`.
* **Implémentation :** Chaque classe (Point, Form, Cercle, etc.) définit comment elle doit être représentée textuellement (ex: "Cercle(centre=..., r=...)").

### 3.2 Polymorphisme et Conteneurs STL
La partie la plus critique du TP concernait la gestion d'une liste de formes hétérogènes.
* **Vecteur de Pointeurs :** Nous avons utilisé la bibliothèque standard `std::vector` pour stocker des pointeurs de type `Form*` (`vector<Form*>`).
* **Liaison Dynamique :** En parcourant cette liste, l'appel à `liste[i]->surface()` invoque dynamiquement la méthode correspondant à l'objet réel (Cercle ou Rectangle) et non celle de la classe mère `Form`. C'est l'essence du polymorphisme qui permet de traiter uniformément des objets différents.
* **Fonctionnalités globales :** Cette structure permet de calculer aisément la surface totale de toutes les formes instanciées, quelle que soit leur nature.

---

## 4. Validation et Problèmes Rencontrés

### 4.1 Problème de Compilation (Linker)
Une difficulté technique a été rencontrée lors de la phase de construction du projet avec CMake.
* **Symptôme :** Erreur `undefined reference to Carre::Carre(...)` lors de l'édition des liens.
* **Analyse :** Le fichier source `carre.cpp` existait physiquement mais n'était pas déclaré dans le fichier `CMakeLists.txt`. Par conséquent, le compilateur générait le code objet pour les autres fichiers, mais l'éditeur de liens ne trouvait pas l'implémentation du Carré.
* **Résolution :** L'ajout de `src/carre.cpp` dans la commande `add_executable` du fichier CMake a résolu le problème.

### 4.2 Tests Unitaires
Le fichier `main.cpp` a servi de banc de test pour valider :
1.  L'instanciation correcte des points et des formes.
2.  La précision des calculs géométriques (Périmètre/Surface).
3.  Le bon fonctionnement des translations via les opérateurs surchargés.
4.  La libération correcte de la mémoire (suppression des pointeurs dans le vecteur).

## 5. Conclusion

Ce TP a permis de consolider notre maîtrise du cycle de vie des objets en C++ et de comprendre l'importance de l'héritage et des méthodes virtuelles pour concevoir des architectures logicielles modulaire. La manipulation des vecteurs a également illustré comment le C++ gère les collections d'objets.