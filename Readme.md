# RihenNatural - Framework Graphique et Simulation de Feu

![C++](https://img.shields.io/badge/C++-17/20/23-blue.svg)
![SDL3](https://img.shields.io/badge/SDL3-3.0.0-green.svg)
![License](https://img.shields.io/badge/License-MIT-yellow.svg)

RihenNatural est un framework graphique léger écrit en C++ moderne, utilisant SDL3 pour le rendu. Il inclut plusieurs démonstrations dont une simulation de particules de feu avec des effets réalistes et personnalisables, ainsi qu'une démo basée sur "The Nature of Code" de Daniel Shiffman.

##  Fonctionnalités

- **Moteur graphique 2D** avec transformations matricielles
- **Système de particules** performant pour effets visuels
- **Simulation de feu** réaliste avec paramètres configurables
- **Marche aléatoire** (Random Walk) selon Nature of Code
- **Système de logging** avancé avec couleurs et timestamps
- **Gestion d'événements** (souris, clavier)
- **Mathématiques 2D** (vecteurs, matrices, transformations)
- **Build system cross-platform** (Windows et Linux)
- **Système de configuration** pour choisir les démos sans recompilation

##  Structure du Projet

```
RihenNatural/
├── Build/                 # Fichiers de compilation
├── Sources/
│   ├── Core/             # Cœur du framework
│   │   ├── Events/       # Gestion événements
│   │   ├── Math/         # Mathématiques 2D
│   │   └── Application.h # Classe principale
│   ├── Demos/            # Démonstrations
│   └── Graphics/         # Graphismes et couleurs
├── Tools/Commands/       # Scripts de build
├── nken.*               # Scripts principaux de gestion
├── app.config           # Configuration de l'application
└── demos.config         # Configuration des démos
```

##  Installation et Utilisation

### Prérequis

- **Compiler C++** : Clang++ (recommandé) ou GCC/G++
- **SDL3** : Bibliothèque graphique
- **Système** : Windows (MSYS2) ou Linux

### Installation sur Windows (MSYS2)

1. Installer MSYS2 depuis https://www.msys2.org/
2. Ouvrir MSYS2 UCRT64 et installer les dépendances :
```bash
pacman -S mingw-w64-ucrt-x86_64-clang mingw-w64-ucrt-x86_64-SDL3
```

### Installation sur Linux (Ubuntu/Debian)

```bash
sudo apt install clang libsdl3-dev
```

### Compilation et Exécution

Utilisez le script `nken` pour gérer le projet :

```bash
# Compiler le projet
./nken build

# Exécuter avec la démo par défaut
./nken run

# Exécuter une démo spécifique
./nken run --demo particles
./nken run --demo randomwalk

# Nettoyer les fichiers de compilation
./nken clean

# Afficher l'aide
./nken help
```

Sous Windows, utilisez les fichiers `.bat` correspondants.

## 🔧 Configuration des Démonstrations

Le système de configuration permet de choisir quelle démo exécuter sans recompiler.

### Fichier de configuration `app.config`

```ini
# Configuration principale de l'application
windowTitle=RihenNatural Demo
windowWidth=1024
windowHeight=768
fullscreen=false
resizable=true
vsync=true
targetFPS=60
defaultDemo=randomwalk
```

### Fichier de configuration `demos.config`

```ini
# Configuration des démonstrations disponibles
[particles]
enabled=true
name=Fire Particles Simulation
description=Simulation réaliste de particules de feu avec paramètres configurables

[randomwalk]
enabled=true
name=Random Walker Demo
description=Marche aléatoire basée sur Nature of Code Chapter 0

# Ajouter de nouvelles démos ici
[newdemo]
enabled=false
name=New Demo
description=Une nouvelle démonstration
```

### Arguments en ligne de commande

```bash
# Spécifier une démo particulière
./nken run --demo particles
./nken run --demo randomwalk

# Options de fenêtre
./nken run --width 1280 --height 720 --fullscreen

# Options spécifiques aux démos
./nken run --demo particles --fire-config custom_fire.config
```

##  Démonstrations Disponibles

### 1. Simulation de Feu (particles)

Une simulation réaliste de particules de feu avec paramètres configurables :

```bash
# Lancer avec configuration personnalisée
./nken run --demo particles --fire-config fire.config

# Options spécifiques au feu
./nken run --demo particles --particle-count 1000 --fire-intensity 2.0
```

### 2. Marche Aléatoire (randomwalk)

Implémentation du chapitre 0 de "Nature of Code" avec plusieurs types de marcheurs :

```bash
# Lancer la démo de marche aléatoire
./nken run --demo randomwalk

# Options spécifiques
./nken run --demo randomwalk --walker-type gaussian --step-size 5
```

##  Créer une Nouvelle Démonstration

Pour ajouter une nouvelle démo, suivez ces étapes :

1. Créez une nouvelle classe dans `Sources/Demos/`
2. Implémentez les méthodes Setup(), Update(), Draw()
3. Ajoutez la configuration dans `demos.config`
4. Enregistrez-la dans `Main.cpp`

### Exemple de nouvelle démo

```cpp
// Sources/Demos/NewDemo.h
#pragma once
#include "Core/Application.h"

namespace nkentseu {
    class NewDemo : public Application {
    public:
        NewDemo(const ApplicationProperties& props);
        
    protected:
        void Setup() override;
        void Update(float deltaTime) override;
        void Draw() override;
        
    private:
        // Membres spécifiques à la démo
    };
}
```

##  Simulation de Feu - Paramètres

La simulation de feu peut être configurée via :

- **Arguments en ligne de commande**
- **Fichier de configuration** (`fire.config`)
- **Valeurs par défaut** programmables

### Options de Configuration du Feu

```ini
# Exemple de fire.config
fireStartColor=#FF6400
fireMidColor=#FF3200
fireEndColor=#FF0000
particleCount=800
spawnRate=0.03
minSize=2.0
maxSize=6.0
minLife=0.8
maxLife=2.2
upwardForce=90.0
horizontalSpread=25.0
turbulence=20.0
enableSmoke=true
enableWind=true
windStrength=8.0
```

##  Marche Aléatoire - Fonctionnalités

La démo Random Walk implémente les concepts du chapitre 0 de "Nature of Code" :

- **Walker traditionnel** (4 directions)
- **Walker avec probabilités variables**
- **Distribution gaussienne**
- **Mouvement Perlin noise**
- **Visualisation des distributions**

### Types de marcheurs disponibles

```bash
# Différents types de marcheurs
./nken run --demo randomwalk --walker-type traditional
./nken run --demo randomwalk --walker-type rightbiased
./nken run --demo randomwalk --walker-type gaussian
./nken run --demo randomwalk --walker-type perlin
```

##  Build System

Le projet utilise un système de build personnalisé avec :

- **Compilation incrémentale**
- **Support multi-plateforme**
- **Gestion des dépendances**
- **Nettoyage automatique**

Les scripts de build détectent automatiquement les fichiers sources et les recompilent si nécessaire.

##  TODO/Améliorations Futures

- [ ] Support OpenGL pour l'accélération matérielle
- [ ] Système de textes et polices
- [ ] Chargement d'images (PNG, JPG)
- [ ] Animations et sprites
- [ ] Interface utilisateur simple
- [ ] Support audio
- [ ] Plus de démos Nature of Code

## Licence

Ce projet est sous licence MIT. Voir le fichier LICENSE pour plus de détails.

##  Contribution

Les contributions sont les bienvenues ! N'hésitez pas à :
1. Fork le projet
2. Créer une branche pour votre fonctionnalité
3. Committer vos changements
4. Push vers la branche
5. Ouvrir une Pull Request

## Support

Pour toute question ou problème, veuillez ouvrir une issue sur le repository du projet.

---

**RihenNatural** - *Rendu Naturel et Performant*
