# Filler
> **Création en C, d'un joueur inteligent pour un jeux de strategie**

*Dans Filler, deux joueurs s’affrontent sur un plateau et doivent placer, tour à tour, une pièce donnée par un exécutable fourni dans l'énoncé. Le joueur qui place le plus de pièce a gagné.*

![presentation du jeux](https://media.giphy.com/media/3oFzlUjKcjowSmvqgg/giphy.gif)


## Mon joueur
> *ici en bleu*

Mon joueur a trois modes de fonctionnement:
* Tout d'abord il se rapproche le plus rapidement possible de l'adversaire
  
  ![phase 1: rapprochement](https://media.giphy.com/media/3ohc195jHIcP3tscqQ/giphy.gif)

* Une fois en contact avec lui, il tente de l'entourer
 
  ![phase 2: entourer](https://media.giphy.com/media/3ohc1gOOSV7SZfGoYo/giphy.gif)

* Puis il complète le reste du plateau 
  
  ![phase 3: remplir](https://media.giphy.com/media/l49JF6J2NKslCvHTW/giphy.gif)

## Mon visualisateur
> **partie optionnelle du projet**

J'ai réalisé un visualisateur graphique avec *Ncurses*.
Il permet de viusaliser le jeu étape par étape, avec la possibilité de revenir en arrière et de changer la vitesse.

![avec visualisateur](https://media.giphy.com/media/l0HU04tvzqyMXx92U/giphy.gif)

*Sans visualisateur:*

![sans visualisateur](https://media.giphy.com/media/xULW8gUuoy1cSizoAw/giphy.gif)

## Instalation

Installez le projet avec cette commande:

```shell
git clone https://github.com/FlorianMuller/filler.git FillerFmuller && cd FillerFmuller && make
```


Lancez une partie **avec** le visualisateur:
```shell
./backToTheFiller -f [map] -p1 ./[first player] -p2 ./[second player]
```
*par exemple:*
```shell
./backToTheFiller -f maps/map01 -p1 ./players/grati.filler -p2 ./fmuller.filler
```


Lancez une partie **sans** le visualisateur:
```shell
./filler_vm -f [map] -p1 ./[first player] -p2 ./[second player]
```
