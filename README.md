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


#### Rappels et Bootstrap
Pour bien commencer, vous devez faire le bootstrap. En effet vous allez apprendre que vous pouvez écrire autre chose que des charactères à l'intérieur des fichiers, comme des int voir même des structures.

(Petit rappel: un byte vaut 8bits. N'hésitez pas à aller chercher comment fonctionne le binaire si besoin.)

Ces différents types prennent évidemment différentes tailles dans la mémoire:

  - Un **unsigned char** peut contenir des valeurs entre 0 et 255. 255 = 1111 1111. C'est donc écrit sur 1byte.
    
  - Un **int** peut contenir des valeurs entre -2 147 483 648 et 2 147 483 647. Il est écrit sur 4bytes.

Pour connaître facilement combien de bytes vont être utilisés par le type, vous pouvez vous servir de "sizeof(TYPE)" qui vous renverra le nombre correspondant.


#### Réponses au sujet dans l'ordre de lecture
Pour faire simple je vais expliquer les différents termes du sujet au fur et à mesure.


  - Un **label**, c'est une sorte de repère dans le programme. On va dire qu'on créer un "repère" en mettant son nom au début d'une ligne suivie d'un LABEL_CHAR (ici '**:**'), et qu'on peut appeler ce repère dans certaines instructions en mettant le LABEL_CHAR en premier suivit de son nom. Par exemple dans un zork.cor:
```
.name "Zork"
.comment "Just a basic living program"

l2:     sti r1, %:live, %1
        ld %4, r4
        ld %200, r2

live:
        live %1
        zjmp %:live
```
  Ici l2 et live sont des labels. Quand on appelle live dans l'instruction sti, ce qu'il faut retenir c'est qu'on va compter le nombre de bytes à partir du début de l'instruction jusqu'au label et on va l'écrire à la place du ":live". De même pour l'appel de live dans zjmp, le chiffre sera d'ailleurs négatif parce que le label live est placé avant.
Mon conseil à ce sujet, est de pour l'instant ne pas y penser, on reviendra dessus plus tard quand vous aurez acquis d'autres connaissances.

Attention, live est une instruction ! Par contre s'il y a un LABEL_CHAR juste avant ou juste après un mot, cela veut dire que ce mot est un label.



  - Les **instructions**: ce sont les différentes "fonctions" que peut comprendre la VM. Leur nom ainsi que leur comportement est détaillé en page 8 du sujet, je vais quand même les détailler plus tard dans l'explication. Vous trouverez aussi dans le fichier op.c donné avec le sujet, un tableau de structure qui liste toutes les instructions avec les arguments qu'elles prennent et le type des arguments.



- Les **arguments** ou **paramètres d'instructions**: chaque argument peut être un des 3 types:
  - Un **registre**: représenté par un 'r' suivit d'un nombre entre 1 et 16. Il sera codé sur 1 byte. (Par exemple r2)
  - Un **direct**: représenté par un DIRECT_CHAR (ici '%') suivit d'un nombre ou d'un label. Il sera codé sur DIR_SIZE bytes (ici 4) sauf pour certaines instructions où il sera codé sur 2 bytes: {zjmp, ldi, sti, fork, lldi, lfork}. (Par exemple %666 ou %:live)
  - Un **indirect**: un nombre ou un label directement. Il sera codé sur IND_SIZE bytes (ici 2). (Par exemple 666 ou :ceci_est_un_label)
  

#### Organisation
Niveau code je vous conseille de procéder ainsi:
1) Lisez et stockez tout le fichier dans un list chaînée.
2) Vérifiez et stockez le nom et le commentaire dans la structure "header_t" donnée dans le op.h .
3) Créez 2 int*: un pour stocker le nombre que vous voulez écrire, et un second pour savoir sur combien de bytes vous allez l'écrire.  Pour l'instant, ne vous préoccupez pas des labels.
```
Prenons pour exemple:
live %666

to_write[0] = 01 (l'op code de live)      ->     stock[0] = 1 (nombre de bytes sur lequel on doit écrire number[0])
to_write[1] = 666 (premier argument)      ->     stock[1] = 4 (= DIR_SIZE bytes car c'est un direct)
```
4) Une fois que tout a été compté, passez une seconde fois à la recherche des labels. Il vous suffira juste d'additionner les nombres de bytes écrits dans votre int *"stock" jusqu'au label correspondant. (Il y aura des exemples par la suite.
5) Il vous suffit d'écrire chaque maillon de votre int *"to_write" à la taille écrite dans votre int *"stock" (write(fd, to_write\[i], stock\[i]);). Attention il vous faudra aussi penser à convertir le contenu de little endian vers big endian ! Pour cela vous pourrez utiliser cette "fonction":
```
#define SWAP_UINT32(x) ((x >> 24) & 0xff) | (( x << 8) & 0xff0000) | ((x >> 8) & 0xff00) | ((x << 24) & 0xff000000)
```

#### Codage des instruction
Chaque instruction est codée à travers 3 éléments:
  - Le code d'instruction: il est écrit en page 8 du pdf et est présent dans la structure op_tab.
  - Le **coding byte**: il permet la description des types des parèmetres. Il n'est pas présent pour ces instructions: {live, zjmp ,fork, lfork}. Il est codé sur 1byte.
```
Le but est de divisé en 4 le byte, ce qui donne 2bits par instruction.
01 pour un registre
10 pour un direct
11 pour un indirect

Exemple 1:
r2, 23, %34
01  11  10  00 = 01111000 = 78 en hexadécimal. (Pour les nombre représentés en hexa on va placer 0x devant, c'est une convention. Ici on aurait 0x78.)

Exemple 2:
23, 45, %34
11  11  10  00 = 11111000 = 0xF8.
```
  - Les **paramètres**: Il suffit d'écrire le nombre sur le bon nombre de bytes:
```
1 byte pour un registre
DIR_SIZE (4) bytes pour un direct (sauf exeptions qui en prennent 2) (rappel des exeptions: {zjmp, ldi, sti, fork, lldi, lfork})
IND_SIZE (2) bytes pour un indirect

Exemple 1:
r2,   23,       %34
0x02  0x00 0x17 0x00 0x00 0x00 0x22       ->    Ox17 en hexa = 23 en décimal       0x22 en hexa = 34 en décimal

Exemple 2:
23,       45,       %34
0x00 0x17 0x00 0x2d 0x00 0x00 0x00 0x22

Au passage il suffit juste d'écrire les nombres normalement, c'est la fonction hexdump qui va les convertir en hexa afin que ce soit plus lisibles. Mais ça vous avez dû le comprendre en faisant le BootStrap.
```


#### Un dernier exemple
```
cat zork.s:
.name "Zork"
.comment "Just a basic living program"

l2:     sti r1, %:live, %1
        ld %4, r4
        ld %200, r2

live:
        live %1
        zjmp %:live
        
        
hexdump -C zork.cor
00000000  00 ea 83 f3 5a 6f 72 6b  00 00 00 00 00 00 00 00  |....Zork........|
00000010  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
*
00000080  00 00 00 00 00 00 00 00  00 00 00 1d 4a 75 73 74  |............Just|
00000090  20 61 20 62 61 73 69 63  20 6c 69 76 69 6e 67 20  | a basic living |
000000a0  70 72 6f 67 72 61 6d 00  00 00 00 00 00 00 00 00  |program.........|
000000b0  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
*
00000890  0b 68 01 00 15 00 01 02  90 00 00 00 04 04 02 90  |.h..............|
000008a0  00 00 00 c8 02 01 00 00  00 01 09 ff fb           |.............|
000008ad


Bon décortiquons tout ça...
00 ea 83 f3       En lisant le op.h on se rend compte que c'est le MAGIC. Le MAGIC est présent au début de chaque fichier dans notre ordinateur. Il permet de déterminer l'extension du fichier. Eh oui l'extension ne dépend pas uniquement du nom du fichier !

```

## Auteur
* **Lucas GOIFFON** - [lucas-goiffon](https://github.com/lucas-goiffon)
