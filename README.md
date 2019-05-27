# Corewar Project (Realised 20.05.19)
###### {EPITECH First Year Project}
Last Project of the year ! Currently the best project of the 2018 SchoolYear at Marseille !

# CE REPO EST EN CRÉATION !

Bon cette fois-ci le projet va être présenté en Français parce que je vais essayer de l'expliquer entièrement afin qu'il soit plus compréhensible pour les prochains élèves qui le feront. Alors n'hésitez pas à descendre un peu plus bas afin de voir toute l'explication !

## Visuel
![Game Screenshot](/bonus/screenshots/game.png?raw=true "Game Screenshot")


## Instructions
Pour tester ce projet, il suffit de make dans le répertoire. Vous aurez ensuite l'assembleur dans le dossier "asm" ainsi que la machine virtuelle dans le dossier "corewar". Vous trouverez aussi dans le dossier bonus un **Désassembleur** et une VM permettant de jouer avec un fond sonore ET en **multi-joueurs** !
```
make
```


## Utilisation
Pour l'assembleur il suffira juste de mettre en argument le fichier à compiler.
```
./asm [fichier_à_compiler.s]
```
Pour la machine virtuelle voici les arguments possibles (pour la machine virtuelle avec seulement le bonus graphique):
![Usage Screenshot](/bonus/screenshots/usage.png?raw=true "Usage Screenshot")


## No memory leaks
![Valgrind Asm Screenshot](/bonus/screenshots/valgrind_asm.png?raw=true "Valgrind Asm Screenshot")
![Valgrind VM Screenshot](/bonus/screenshots/valgrind_vm.png?raw=true "Valgrind VM Screenshot")


# Explications
Bon il est temps de passer aux explications de ce super projet !

## L'Assembleur
C'est la partie avec laquelle je vous conseille de commencer, sans avoir compris l'assembleur vous ne pourrez pas faire la VM alors que le contraire est possible.


L'assembleur sert à transformer les champions, écrits dans un langage basé sur l'assembleur, en exécutables lisibles par la Machine Virtuelle.


Pour bien commencer, vous devez faire le bootstrap. En effet vous allez apprendre que vous pouvez écrire autre chose que des charactères à l'intérieur des fichiers, comme des int voir même des structures.

(Petit rappel: un byte vaut 8bits. N'hésitez pas à aller chercher comment fonctionne le binaire si besoin.)

Ces différents types prennent évidemment différentes tailles dans la mémoire:

    - Un **unsigned char** peut contenir des valeurs entre 0 et 255. 255 = 1111 1111. C'est donc écrit sur 1byte.
    
    - Un **int** peut contenir des valeurs entre -2 147 483 648 et 2 147 483 647. Il est écrit sur 4bytes.

Pour connaître facilement combien de bytes vont être utilisés par le type, vous pouvez vous servir de "sizeof(TYPE)" qui vous renverra le nombre correspondant.




## Author
* **Lucas GOIFFON** - [lucas-goiffon](https://github.com/lucas-goiffon)
