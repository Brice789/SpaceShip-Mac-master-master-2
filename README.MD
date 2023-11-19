<p align="center">
  <img src="https://gitlab.com/Brice789/cpp-rs-group-1-space-ship/-/blob/main/projet/projetUnix/Images-ReadMe/Capture%20d%E2%80%99%C3%A9cran%202023-11-19%20%C3%A0%2019.48.15.png?ref_type=heads" alt="Logo de Spaceship">
</p>

# Spaceship - Le Jeu Spatial Ultime 🚀

<p align="center">
  <b>A l'attention de M.Seheux</b>
</p>

<p align="center">
  <b>Les fonctionnalités du Jeu</b>
</p>

- **Initialisation :** Le project Compile Bien, Les classes sont bien toutes présentes, et hérité de FlyingObject
- **Mise à Jour :** À chaque appel de `majData`, le score est mis à jour en fonction du temps écoulé depuis le début (utilisation de `difftime`).
- **Affichage :** Le Modele MVC est Présent, et fonctionnelle.

<p align="center">
  <b>Attention : Pour SonarQube!</b>
</p>

- J'ai pu vous envoyer un mail concernant les régles de SonarQube.
- Etant donné que j'ai réussi à faire sonarQube, et ayant travailler prodondement dessus,  j'espere sincerement que vous pourrez avoir l'occasion de le valoriser.
- Je vous invite à faire une analyse : J'ai normallenet très peu de beug et j'ai une analyse aprofondie du code : Les seules erreurs de vulnérabilités que vous trouverez ne dependent pas de moi.
- En effet, elles sont inhérentes à la classe Framework ou la fonction Random (mais ici aucune gene de part le jeu : La vulnérabilités serait importante dans le cas ou il faudrait generer des mots de passe mais la fonction Random suffit amplement pour generer des asteroids, et meme répeter,
- C'est sans risque) Par contre, j'ai compris qu'elle n'est pas à utliser pour certaines choses car elle se répete beaucoup.
- Vous trouvez donc ci joint l'avant et après de mes projets : 
- 90bug vs 1 avec la versin actuelle

<p align="center">
  <img src="https://gitlab.com/Brice789/cpp-rs-group-1-space-ship/-/blob/main/projet/projetUnix/Images-ReadMe/Capture%20d%E2%80%99%C3%A9cran%202023-11-19%20%C3%A0%2019.48.15.png?ref_type=heads" alt="Logo de Spaceship">
</p>

- 

<p align="center">
  <b>Utilisation du Score pour la Victoire</b>
</p>

- Le score sert à déterminer si le joueur a maintenu un bouclier >= 0.5 pendant 3 minutes.
- Si le score est inférieur ou égal à 180 secondes et que le bouclier est >= 0.5, le joueur gagne.


<p align="center">
  <b> Si vous souhaitez mes Commits</b>
</p>

- Vous trouvez bon nombres de mes commits directement sur mon Gihub car c'est plus pratique pour moi, etant plus habitué je centralise tout ici.
- Mon GitHub est brice789 


<p align="center">
  <b>Installation</b>
</p>

1.  Pour le Project, il vous faudrat installer CMake et le disposer sur votre ordinateur
2.  Dans le cas ou il est différent de Windows, Veuillez installer les libraiires SDL adapté à Windows present dans project windows
3.  Il est tout à faire possible de copier toutes les librairies (Attention à la spécificé du main) dans un nouveau project



<p align="center">
  Je ne dirrais qu'une chose, préparez-vous pour une aventure spatiale palpitante avec Spaceship ! 🌌🛸
</p>
