# Filler
> **Création en C, d'un joueur inteligent pour un jeux de strategie**

*Dans Filler, deux joueurs s’affrontent sur un plateau, et doivent placer, tour à tour, une pièce que le maître du jeu (sous la
forme d’un exécutable Ruby fourni) leur donne. Le joueur qui place le plus de pièce a gagné.*

![presentation du jeux](https://media.giphy.com/media/xT1R9X3UP647yiNPO0/giphy.gif)



## Mon joueur
Mon joueur a trois mode de fonctionnement:
* Tout d'abord il pose des pieces pour se rapprocher de l'adversaire le plus rapidement possible

  //gif rapprochement

* Une fois au contacte de l'adversaire, il pose les piece les plus en contactes avec lui pour l'entourer
 
  //gif entourer

* Une fois l'adversaire entouré, il complete le reste du plateau 
  
  //gif fin

## Mon visualisateur
> partie optionnelle du projet

J'ai réalisé un visualisateur graphique avec *Ncurses*.

// Sans visualisateur vs avec

Il permet viusaliser le jeux étape par étape, avec la possibilité de revenir en arrière et de changé la vitesse

## Instalation

