Bienvenue dans le Monde de Tron,
Ceci est un jeu multi-joueurs dans l'univers de TRON le film.
Il s'agit ici de piloter des motos ultra-rapides, un seul but survivre pour gagner la manche.

INSTALLATION:
	Veuillez avoir installé les librairies suivantes : SDL, SDL_ttf;
	La librairie FMOD pour le son est déjà dans l'archive.
	Pour bien faire fonctionner la libFmod et utiliser l'executable "jeu" créer par le make, il faut rajouter une ligne au .bashrc
	
	#
 export LD_LIBRARY_PATH="$LD_LIBRARY_PATH:/home/antoine/Projet/tron-lif7/lib/FMOD/lib"
	
	
JOUER:
	Le plus simple pour jouer est d'avoir codeBlocks afin de pouvoir modifier les constantes du jeu. Dans le fichier Constantes.h
	Le nombre de joueur est le nombre de joueurs total (IA comprises)
	Le nombre de mannettes est le nombre de PAD qui vous avez branché à votre ordinateur.
	(Attention le jeu ne gère que 8 joueurs au total, un assert vous empèchera d'en mettre plus)
	Il existe aussi un makefile pour compiler.
	
	Vous pouvez définir le nombre de manche pour gagner dans la constante score de victoire.
	Nous vous conseillons de ne pas toucher au autres constantes du jeu.
	
	Les couleurs et les touchent sont pour l'instant arbitraire, veuillez noter que,
	ORANGE joueur 1
	BLEU joueur 2
	ROUGE joueur 3
	VERT joueur 4
	VIOLET joueur 5
	BLEUF joueur 6
	JAUNE joueur 7
	BLANC joueur 8
	
	Pour les affectation des touches, notez que le jeu affecte en priorité les joueur au clavier(4 joueurs au clavier maximum)
		  HAUT BAS GAUCHE DROITE BONUS	
	Joueur 1  Z    Q   S 	  D      A
	Joueur 2  O    K   L      M      I
	Joueur 3  T    F   G      H      R
	Joueur 4  ↑    ↓     ←       →        END(Fin)
	
	Pour les manettes, on vous conseille les Pad Xbox360, linux ne gérant pas l'affichage des numéro de manettes, celle-ci sont numérotés dans l'ordre des allumages.
		HAUT BAS GAUCHE DROITE BONUS
		Y    A   X      B      Rb
	Les Ia prendront les joueurs restant.

GAMEPLAY:
	Chaque Moto avance sans pouvoir s'arreter, laissant derrière elle la trace infranchissable de son passage.
	Le but etant d'éviter les murs et motos des autres, tout en évitant de rentrer dansles frontères de la GRID.
	Heureusement leurs murs disparaissent au fil du temps.
	Les motos ne cessent d'accèlerer et plus leur vitesse est grande, plus elles laissent de murs derrières elles.
	
	LES BONUS:(Les carrés qui aparraisent de façon aléatoire)
	- Le bonus Blanc est un bonus de nettoyage de la grille, il efface tout et remet l'écrant comme au départ.
	- Le bonus Bleu est un boost, activable lorsque l'on veut dans la manche, il dure quelques secondes. Mefiez vous de cette vitesse.
	  Il est activanle avec la touche bonus.
	  
	L'affichage à droite indique les dernières informations importantes du jeu et l'affichage de la progression du score pour chaque joueur. Le premier joueur a remplir sa jauge gagne en cas d'égalité, il y aura une manche suplémentaire.
	
	Fin de manche, la fin de manche se défini lorsqu'il ne reste plus qu'un joueur en course.
	A ce moment la vous avez trois options:
	- quitter le jeu, avec ECHAP
	- lancer la manche suivante avec F1
	- reintialiser les scores avec TAB
	
	A la fin de la partie:
	- quitter le jeu, avec ECHAP
	- relancer une partie avec les mêmes paramètre avec F1
	
Bon jeu!


				
		
		
