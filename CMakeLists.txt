cmake_minimum_required(VERSION 3.23.2)
project(lexicon)

set(CMAKE_CXX_STANDARD 20)

add_executable(lexicon lexicon.cpp
        jeu.h
        jeu.cpp
        constante.h
        Conteneur/piles.h
        Conteneur/piles.cpp
        Conteneur/ListCarte.cpp
        Conteneur/ListCarte.h
        Conteneur/ListMots.cpp
        Conteneur/ListMots.h
        Joueurs.cpp
        Joueurs.h
)
