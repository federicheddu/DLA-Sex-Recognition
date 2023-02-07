# DLA-Sex-Recognition

>  Questo è un progetto svolto nell'ambito dell'esame **Deep Learning and Applications Mod.1** del **CdLM in Informatica** presso l'Università degli Studi di Cagliari

| **Studente**          | **Matricola** | **E-Mail**                        |
|-----------------------|---------------|-----------------------------------|
| Federico Meloni       | 60/73/65243   | <f.meloni62@studenti.unica.it>    |
| Luca Faccin           | 60/73/65236   | <l.faccin@studenti.unica.it>      |

Questo progetto univeristario si pone l'obiettivo di classificare immagini del volto di persone famose in base al loro sesso attraverso diversi esperimenti di Deep Learning. Il dataset di partenza è [CelebA](https://mmlab.ie.cuhk.edu.hk/projects/CelebA.html), in particolare la versione [Align & Cropped](https://drive.google.com/drive/folders/0B7EVK8r0v71pTUZsaXdaSnZBZzg?resourcekey=0-rJlzl934LzC-Xp28GeIBzQ) che contiene le immagini già pulite, con le facce allineate e centrata. Il dataset è stato scelto per la sua semplicità e per la sua dimensione, che permette di eseguire i test in tempi ragionevoli.

Sonos stati effettuati tre diversi esperimenti, ognuno con un approccio diverso:
- Feature Extraction con AlexNet, ResNet e VGG16 per poi utilizzare un classificatore SVM Lineare
- Fine Tuning di una rete pre-addestrata
- Creazione di una rete da zero

> Table of Contents
> 1. [Feature Extraction](#feature-extraction)
>    - [AlexNet](#alexnet)
>    - [ResNet](#resnet)
>    - [VGG16](#vgg16)
>    - [SVM](#svm)
>    - [Risultati](#fe-risultati)
> 1. [Fine Tuning](#fine-tuning)
> 1. [Creazione di una rete da zero](#creazione-di-una-rete-da-zero)
>

## Feature Extraction


### **AlexNet**
AlexNet è una rete neurale convolutiva utilizzata nella computer vision presentata nel 2012.
AlexNet consiste in 8 layer, 5 dei quali sono layer convolutivi, 2 sono layer fully connected e 1 è un layer di output.

![](img/alexnet_structure.png)

Nel primo strato si riceve l'immagine come input e la si ridimensiona per adattarsi alla rete neurale, successivamente i cinque strati convolutivi itilizzano filtri per estrarre le caratteristiche visive dall'immagine.  
Ogni strato convolutivo utilizza un insieme di filtri che scorrono sull'immagine eseguendo una combinazione lineare dei valori dei pixel e producendo una nuova immaigne chiamata "*feature map*".  
Gli strati fully connected sono due e hanno la funzione di classificare l'immagine in base alle caratteristiche estratte dai layer convolutivi.  
Il layer di output è un layer softmax che restituisce la probabilità che l'immagine appartenga ad una delle 2 classi.

### ResNet


### VGG16


### SVM


### Risultati


## Fine Tuning


## Creazione di una rete da zero