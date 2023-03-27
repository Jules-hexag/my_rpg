# my_rpg

ENLEVER LE STRNCMP DANS LES INPUT_ERRORS, METTRE UN MY_STRNCMP

Si on change un truc dans le tileset (taille &| nombre) :
    - Dans gen_map_tab.c -> retrieve_lines() :
      - il faut ajouter ou enlever des ternaires en fonction
    Et normalement tout le reste se fait tout seul si vous utilisez bien les macros