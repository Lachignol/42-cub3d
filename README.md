# 🧱 Cub3D

## 🎯 Description

![screenshot1](https://github.com/user-attachments/assets/7c1e6b9f-6f53-4d28-8886-95dcbaed6795)

**Cub3D** est un projet graphique inspiré de *Wolfenstein 3D*. Il consiste à développer un **moteur de rendu 3D** basé sur la technique du **raycasting**, à partir d'une carte 2D. Ce projet vous initie à la programmation graphique, à la gestion d’événements en temps réel et à la création d’un mini moteur de jeu.

Dans sa version bonus, le projet ajoute une mini-carte, un affichage plus riche, des interactions via la souris, et des effets visuels supplémentaires.

---

## 🕹️ Objectifs

- Afficher une scène pseudo-3D à partir d’une carte 2D grâce au **raycasting**.
- Lire et interpréter un fichier `.cub` contenant la configuration du jeu (textures, carte, couleurs).
- Gérer les mouvements du joueur, la rotation de la vue, et les collisions avec les murs.
- Utiliser **MiniLibX** pour créer une fenêtre, afficher le rendu, et capturer les entrées clavier et souris.
- Bonus : ajouter des éléments interactifs et visuels pour enrichir l’expérience utilisateur.

---

## 📁 Format du fichier `.cub`

Un fichier `.cub` contient :

- Les chemins vers les textures des murs :
  - `NO`, `SO`, `WE`, `EA` pour Nord, Sud, Ouest, Est
- Les couleurs du sol (`F`) et du plafond (`C`) au format `R,G,B`
- Une carte 2D utilisant :
  - `1` pour les murs
  - `0` pour les espaces vides
  - `N`, `S`, `E`, `W` pour la position de départ du joueur et son orientation

### Exemple :
```
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
F 220,100,0
C 225,30,0

111111
100001
1000N1
100001
111111
```

---

## 🧠 Concepts techniques

- **Raycasting** : projection d’un rayon par colonne de l’écran pour déterminer la distance au mur et calculer la hauteur des murs affichés.
- **DDA (Digital Differential Analysis)** : méthode utilisée pour détecter les collisions entre les rayons et les murs de la carte.
- **Textures directionnelles** : chaque face du mur utilise une texture différente selon la direction d’impact du rayon.
- **Gestion des événements** : interaction clavier et souris via MiniLibX.
- **Détection de collisions** : le joueur ne peut pas traverser les murs.

---

## 🧩 Bonus inclus

- ✅ **Mini-carte** : affichée en haut à gauche, représentant la carte 2D en direct.
- ✅ **Textures de sol et plafond** ou effets visuels pour améliorer l’immersion.
- ✅ **Mouvements fluides** : appui long pour un mouvement continu.
- ✅ **Utilisation de la souris** pour faire pivoter la vue.
- ✅ **Animation ou effets spéciaux** sur certains éléments graphiques.
- ✅ **Arme affichée à l’écran** avec indicateurs interactifs.
- ✅ **Système de tir** avec clic gauche (sans effet réel sur l’environnement).

---

## 🔨 Compilation

Pour compiler le projet :

```bash
make
```

Pour compiler avec les fonctionnalités bonus :

```bash
make bonus
```

---

## 🚀 Lancement

Exécutez le programme avec un fichier `.cub` :

```bash
./cub3D maps/map.cub
```

---

## ⌨️🖱️ Contrôles clavier / souris

| Contrôle clavier / souris   | Action en jeu                                                                 |
|-----------------------------|-------------------------------------------------------------------------------|
| `W` / `↑`                   | Avancer                                                                      |
| `S` / `↓`                   | Reculer                                                                      |
| `A`                         | Se déplacer latéralement vers la gauche (strafe)                             |
| `D`                         | Se déplacer latéralement vers la droite (strafe)                             |
| `←` / `→`                   | Tourner la vue vers la gauche / la droite                                   |
| **Souris (mouvement)**      | Tourner la vue dans la direction du mouvement                               |
| **Clic gauche**             | Tirer (si le point gauche de l’arme indique qu’un mur est suffisamment proche) |
| **Clic droit**              | Sélectionner une couleur (modifie la couleur du point droit de l’arme)       |
| `ESC`                       | Fermer proprement le jeu                                                     |

---

## 🔎 Gestion des erreurs

Le programme gère et affiche les erreurs suivantes :

- Nombre d’arguments invalide
- Fichier `.cub` manquant ou mal formaté
- Carte non fermée ou invalide (trous, double spawn, etc.)
- Texture ou fichier `.xpm` manquant ou incorrect
- Format de couleur incorrect
- Fuites mémoire (testé sous Valgrind)
- Erreurs liées à l’utilisation de MiniLibX ou à l’allocation mémoire

---

## 🧪 Exemple de rendu

![screenshot2](https://github.com/user-attachments/assets/9ac36d4e-dc68-4eaf-b983-f46dbe28445c)
![screenshot3](https://github.com/user-attachments/assets/bab21e81-d194-424c-b4f6-578d57de838e)


- Vue 3D immersive avec textures directionnelles
- Mini-carte active affichée en bas à gauche
- Curseur dynamique et arme à l’écran
- Sol et plafond colorés ou texturés
- Effets d’interaction (tir, changement de couleur)
- Déplacements et rotation fluides

---

## 📚 Librairies utilisées

- [`MiniLibX`](https://harm-smits.github.io/42docs/libs/minilibx) – bibliothèque graphique utilisée pour l’affichage et la gestion d’événements
- `math.h` – fonctions trigonométriques
- `stdlib.h`, `fcntl.h`, `unistd.h`, `stdio.h`, `string.h` – pour la gestion de fichiers, de chaînes, et l’interface système

---

## 📌 Remarques

- Le projet **doit fonctionner exclusivement avec MiniLibX** (pas de SDL, OpenGL, SFML…).
- Aucun comportement indéfini ne doit être toléré, même en cas de fichier malformé.
- Toutes les ressources (textures, mémoire, fenêtre) doivent être libérées à la fermeture.
- Le rendu doit être propre, fluide, et sans artefacts visuels.

---

## Authors
- Arthur Oger | 42: aoger | GitHub: ![arthoge](https://github.com/arthoge)
- Alexandre Scordilis | 42: ascordil | GitHub: lachignol
