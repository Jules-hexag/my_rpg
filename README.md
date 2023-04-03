# my_rpg

PENSER A REGLER LE PROBLEME : QUAND TU BOUGES ALORS QUE CLIQUÉ CA REPASSE EN HOVER ALORS QU'IL FAUT QUE CA RESTE CLIQUÉ !

Si on change un truc dans le tileset (taille &| nombre) :
    - Dans gen_map_tab.c -> retrieve_lines() :
      - il faut ajouter ou enlever des ternaires en fonction
    Et normalement tout le reste se fait tout seul si vous utilisez bien les macros