# Cub3D - Projet 42

![CUB3D](https://cdn.discordapp.com/attachments/904103885570981919/1204939150164230164/image.png?ex=65d68e08&is=65c41908&hm=629cc6b3ba7dbbff06e03e2377813433b491ec84308b30b66696cf1430337c76&)

## Description

Cub3D est un projet de l'école 42 qui vise à créer un moteur graphique basé sur le concept du jeu Wolfenstein 3D. Le projet est réalisé en utilisant la bibliothèque graphique miniLibX.

## Fonctionnalités

- Rendu graphique d'un labyrinthe en 3D
- Déplacement dans le labyrinthe
- Gestion des textures et des couleurs
- Système de gestion des événements (clavier)
- Système de collisions

## Installation

1. Clonez ce dépôt
2. Exécutez `make` pour compiler le projet
3. Lancez le programme avec `./cub3D path/to/map.cub`

## Utilisation

- Les touches WASD permettent de se déplacer
- Utilisez les flèches gauche/droite pour tourner

## Configuration de la carte (map.cub)

La carte est configurée dans un fichier au format `.cub`. Exemple de configuration :

```plaintext
R 1920 1080
NO ./textures/north_texture.xpm
SO ./textures/south_texture.xpm
WE ./textures/west_texture.xpm
EA ./textures/east_texture.xpm
S ./textures/sprite_texture.xpm
F 220,100,0
C 0,128,255
1111111111111111111
1000000000110000001
1011000001110000001
1001000000000000011
1111111111111111111
```

## Auteurs 

- lduthill
- sfroidev

  For 42 School ;)
