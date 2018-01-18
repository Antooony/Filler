# Filler
Filler est un jeu algorithmique qui consiste à remplir une grille d’une taille connue à l’avance avec des pièces de taille et de formes aléatoires, sans que les pièces ne se superposent de plus d’une seule case et sans qu’elles ne depassent de la grille. Si l’une de ces conditions n’est pas remplie, la partie s’arrête.

Chaque pièce posée avec succès rapporte un certain nombre de points, et a un seul joueur, le but du jeu pourrait être d’obtenir le meilleur score possible. Cepedant, c’est avec deux joueurs que le filler prend tout son intérêt. Chaque joueur a pour but de poser un maximum de pièces tout en tentant d’empêcher son adversaire de le faire. A la fin de la partie, celui avec le plus de point remporte le match...

L'objectif de ce projet est de concevoir un programme capable de jouer (et gagner) au jeu du Filler.
Voici un exemple d'execution: 
![Alt Text](http://g.recordit.co/XloTQ0HwI2.gif)

## Usage
le match se deroule sous le controle de la vm fournie en ressources, voici la ligne de commande permettant l'execution de celle ci:
```
./filler_vm -f maps/mapXX -p1 players/XX.filler -p2 player/XX.filler
```
le compilation du champion s'effectue via le makefile, ```make```

un exemple concret d'execution :
```
./resources/filler_vm -f resources/maps/map01 -p1 resources/players/hcao.filler -p2 resources/players/adenis.filler
```
