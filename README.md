# 🧱 Cub3D

## 🎯 Description

**Cub3D** est un projet graphique inspiré de *Wolfenstein 3D*. Il consiste à créer un **moteur de rendu 3D** basé sur la technique du **raycasting**, à partir d'une carte 2D, tout en gérant l'affichage, les textures et les interactions utilisateur. Ce projet introduit la **programmation graphique**, la **gestion d’événements temps réel** et les notions fondamentales d’un moteur 3D.

Le **bonus** permet d’ajouter des éléments interactifs et visuels supplémentaires : une mini-carte, des textures animées, un rendu plus réaliste… mais **sans la gestion des portes**, comme demandé ici.

---

## 🕹️ Objectifs

- Afficher une scène 3D depuis une carte 2D avec le **raycasting**.
- Gérer les déplacements du joueur (déplacements, strafe, rotation).
- Utiliser la **MiniLibX** pour créer une fenêtre, capturer les événements clavier et afficher des images.
- Lire un fichier `.cub` avec les informations de la carte et des textures.
- Gérer les **textures murales**, les couleurs du sol et du plafond.
- **(Bonus)** Ajouter une mini-carte, des effets graphiques et des mouvements plus fluides.

---

## 📁 Format du fichier `.cub`

Un fichier `.cub` contient :

- Les chemins vers les textures pour les quatre directions (`NO`, `SO`, `WE`, `EA`)
- Les couleurs du sol (`F`) et du plafond (`C`) au format `R,G,B`
- La carte 2D du monde (murs = `1`, vide = `0`, joueur = `N`, `S`, `E`, `W`)

### Exemple :
```
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
F 150,100,50
C 100,100,255

111111111
100000001
1000N0001
100000001
111111111
```

---

## 🧠 Concepts techniques

- **Raycasting** pour déterminer la distance de chaque mur et son affichage.
- Utilisation de **DDA (Digital Differential Analysis)** pour trouver les intersections de rayons avec la carte.
- **Textures** selon l’orientation des murs.
- Précision temporelle pour la gestion fluide des mouvements.
- Détection de collision contre les murs.

---

## 🧩 Bonus inclus (hors portes)

- ✅ **Mini-carte** affichée en temps réel (vue du dessus)
- ✅ **Textures de sol et plafond "faux 3D"** (floor casting simplifié ou effets visuels)
- ✅ **Système de déplacement fluide** (mouvement continu)
- ✅ **Gestion de la souris pour tourner la vue** *(optionnel selon norme)*
- ✅ **Animation de textures ou effets spéciaux** (par ex. sprite animé sur les murs)
- ✅ **Affichage d’un curseur ou arme à l’écran**
- ✅ **Optimisations de performance**

---

## 🔨 Compilation

Le projet se compile via Makefile :

```bash
make
```

Pour le bonus :

```bash
make bonus
```

---

## 🚀 Lancement

Exécution standard :

```bash
./cub3D maps/map.cub
```

---

## ⌨️ Contrôles clavier

| Touche       | Action                         |
|--------------|--------------------------------|
| W / ↑        | Avancer                        |
| S / ↓        | Reculer                        |
| A            | Aller à gauche (strafe)        |
| D            | Aller à droite (strafe)        |
| ← / →        | Tourner la vue                 |
| ESC          | Quitter                        |

---

## 🔎 Gestion des erreurs

Le programme gère et affiche les erreurs suivantes :

- Nombre incorrect d’arguments
- Fichier `.cub` invalide ou manquant
- Textures introuvables ou corrompues
- Mauvais format de couleur (`R,G,B`)
- Carte non fermée ou plusieurs points de départ
- Fuites mémoire (valgrind-clean exigé)

---

## 🧪 Exemple de rendu

- Scène 3D immersive avec textures directionnelles
- Mini-carte en haut à gauche
- Déplacements fluides avec gestion des collisions
- Sol coloré, plafond coloré ou texturés selon les options bonus

---

## 📚 Librairies utilisées

- [`MiniLibX`](https://harm-smits.github.io/42docs/libs/minilibx)
- `math.h`, `stdlib.h`, `fcntl.h`, `unistd.h`, `stdio.h` etc.
- Aucun framework externe ou moteur 3D autorisé

---

## 📌 Remarques

- Le programme doit être fluide et réactif.
- Le fichier `.cub` doit être **strictement conforme au format attendu**.
- Aucun comportement indéfini ne doit être toléré.
- Toutes les ressources doivent être libérées correctement à la fermeture du programme ou en cas d’erreur.
- Le rendu doit être propre et sans glitch visuel.

---

##
