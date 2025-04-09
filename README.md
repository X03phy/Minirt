# Minirt
minirt

# todo
ajust size of object with window size
ambient light
camera

# Ce que j'ai change par rapport a samedi :
 - Les ombres :
    hit.c = fonction in_shadow
    multiple_sphere.c = ajout test pour savoir si le point d'intersection du rayon camera->objet est dans l'ombre d'un autre objet
    Acne sur certains objets : décrit dans le PDF page 114, de ce que j'ai compris : Du fait de l'imprécision de l'ordinateur, il se peut que le point d'intersection calculé soit proche de la bordure de l'objet mais un tout petit peu dans l'objet lui-même. Il faut décaler le point d'intersection un peu vers l'origine du rayon pour éviter que le rayon shadow ne rebondisse sur l'objet lui meme. ex : hit a 7.8923 -> decaler le hit a 7.88 ? 
    bug sur la scene piece.rt = jsp pourquoi l'ombre de la sphere n'est pas visible sur les deux murs
 - Lumiere :
    lighting.c = ajout de la fonction tuple_mult_tuple mais pas sur que ce soit utile
        la foinction lighting2 est la fonction qu'on avait samedi que j'ai garde au cas ou.
        J'ai essaye plein de combinaison dans le code avec des scenes du style sphere blanche et lumiere rouge pour melanger les couleurs mais jsp si le resultat est coherent.
        Donc a voir comment on ajuste la fonction ??
