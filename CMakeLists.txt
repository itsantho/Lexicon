cmake_minimum_required(VERSION 3.27)
project(lexicon)

set(CMAKE_CXX_STANDARD 17)

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
)
