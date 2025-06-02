# 2113_DeElectronique_V3

Ce projet implémente une application pour microcontrôleur PIC32MM0064GPL020, développée avec MPLAB X et XC32.

## Sommaire

- [Présentation](#présentation)
- [Informations de génération](#informations-de-génération)
- [Compilation](#compilation)
- [Utilisation](#utilisation)
- [Documentation Doxygen](#documentation-doxygen)
- [Diagrammes](#diagrammes)
- [Ressources](#ressources)

## Présentation

Ce dépôt contient le code source et la configuration pour le projet électronique basé sur le PIC32MM.  
La documentation technique est générée avec Doxygen.

## Modifications apportées entre V2 et V3

- Modification de la fonction d'attente avec utilisation du timer (précision accrue et meilleure gestion du temps).
- Ajout de la possibilité de modifier le changement de la consigne PWM avec le CoreTimer (meilleure flexibilité et contrôle).
- Ajout du réglage d'intensité automatique avec les "rampes" (transition douce de l'intensité).
- Refactorisation et amélioration des commentaires pour une meilleure génération de documentation Doxygen.
- Refactorisation de la structure principale du main.

## Informations de générations

```
Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.75.1
Device            :  PIC32MM0064GPL020

Les drivers générés sont testés avec :
    Compiler      :  XC16 v1.35
    MPLAB         :  MPLAB X v5.05

La version 3 de cette application est conçue et testée avec :
    Compiler      :  XC32 v2.5 
    MPLAB         :  MPLAB X v5.50
```

## Compilation

1. crée un dossier "PROJ" sous" C:\microchip\harmony\v2_06\apps\"
2. Cloner ce dépôt à l'intérieur  le chemin devrais être : "C:\microchip\harmony\v2_06\apps\PROJ\PRJ_2113_D-sElectronique"
4. Ouvrez le projet dans MPLAB X.
5. Sélectionnez le compilateur XC32 v2.5.
6. Compilez le projet (`Build Project`).

## Utilisation

- Chargez le firmware sur la carte cible (2113E_DeElectronique) via MPLAB X (la carte doit être alimentée en +1,5V).
- Retirer la sonde de programation (snap/icd4) appuyer sur le switch environs 1s.
- secouer
- pour éteindre: retirer la pile 

## Etat actuel 
- Possibilité d'apparition de l'interruption sans que le microcontroleur ne soit totalement éteind/allumé à déterminer. 
- Après quelques rolls de dé puis laisser ~2h un roll était toujour possible aucun problème... (n'empêche pas le point précédent)
### Résultat des tirrages 
sur 130 tirrages: 
<img src="https://github.com/user-attachments/assets/80f78ce2-e4ff-41b6-9405-6ea307c8bbcf" alt="drawing" width="500"/>

Le N°1 sort le plus souvent


## Documentation Doxygen

La documentation complète du code est disponible dans le dossier [html/](html/).  
[Consulter la documentation Doxygen](https://docdees.neocities.org/)
(ouvrir dans un browser une fois le dépot en local) exemple du rendus : 

<img src="https://github.com/user-attachments/assets/8a3879f3-ec6a-4e69-901c-e0ea78a6e7db" alt="drawing" width="500"/>


<img src="https://github.com/user-attachments/assets/bda516ce-c087-4f1c-b8d6-f7e2d5f6061d" alt="drawing" width="500"/>



## Diagrammes

Précédente version (V2)

<img src="https://github.com/user-attachments/assets/d62e0037-c5a4-41ff-92a0-f798ec1ad384" alt="drawing" width="200"/>

Nouvelle version (V3) 


<img src="https://github.com/user-attachments/assets/66971962-94b2-4289-b230-344099b36478 " alt="drawing" width="700"/>

les autres diagrammes sont disponibles sous "C:\microchip\harmony\v2_06\apps\PROJ\PRJ_2113_D-sElectronique\soft\2113_DeElectronique_V3.X\code2flow"

## Ressources

- [Diagramme de flux (Code2Flow)](https://app.code2flow.com/)
- [VS Code](https://code.visualstudio.com/)
- [GitHub Copilot](https://github.com/features/copilot)
- [MPLAB X IDE](https://www.microchip.com/en-us/tools-resources/develop/mplab-x-ide)
- [Graphviz](https://graphviz.gitlab.io/)
- [Doxygen](https://www.doxygen.nl/index.html)
- [MCC Standalone (MPLAB Code Configurator)](https://www.microchip.com/en-us/tools-resources/configure/mplab-code-configurator)
- [Documentation Microchip PIC32MM](https://www.microchip.com/wwwproducts/en/PIC32MM0064GPL020)

---


