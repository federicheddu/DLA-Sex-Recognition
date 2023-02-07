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
Il primo esperimento consiste nell'utilizzare una rete neurale pre-addestrata per estrarre le caratteristiche visive dalle immagini e poi utilizzare un classificatore SVM Lineare per classificare le immagini in base al sesso.

Per fare ciò è stato utilizzato il dataset di partenza, che è stato suddiviso in due parti: una per il training e una per il testing.

Il modus operandi è il seguente:
1. Caricamento del dataset di training e di testing
2. Caricamento della rete neurale pre-addestrata e ridimensionamento delle immagini
3. Estrazione delle features dalle immagini estrapolando i dati dal penultimo layer della rete neurale
4. Training del classificatore SVM Lineare
5. Test del classificatore SVM Lineare

### **AlexNet**
AlexNet è una rete neurale convolutiva utilizzata nella computer vision presentata nel 2012.
AlexNet consiste in 8 layer, 5 dei quali sono layer convolutivi, 2 sono layer fully connected e 1 è un layer di output.

![](img/alexnet_structure.png)

Nel primo strato si riceve l'immagine come input e la si ridimensiona per adattarsi alla rete neurale, successivamente i cinque strati convolutivi itilizzano filtri per estrarre le caratteristiche visive dall'immagine.  
Ogni strato convolutivo utilizza un insieme di filtri che scorrono sull'immagine eseguendo una combinazione lineare dei valori dei pixel e producendo una nuova immaigne chiamata "*feature map*".  
Gli strati fully connected sono due e hanno la funzione di classificare l'immagine in base alle caratteristiche estratte dai layer convolutivi.  
Il layer di output è un layer softmax che restituisce la probabilità che l'immagine appartenga ad una delle 2 classi.

### **ResNet**

ResNet è una rete neurale convolutiva presentata nel 2015 da Microsoft Research Asia. Con i suoi 152 livelli, la versione completa di ResNet è un’architettura piuttosto complessa, quindi abbiamo optato per utilizzare la versione ResNet18.  
Per allenare un così alto numero di livelli utilizza un metodo detto "skip connection". Il quale prende i dati trasferiti al livello successivo e lo aggiungono anche al output di quelli precedenti come mostrato nella figura sottostante:

![](img/resnet_structure.png)

ResNet è organizzata in **blocchi residuali** *(residual block)*. 

Durante la **back propagation** e il **calcolo del metodo di ottimizzazione** (es. gradiente stocastico discendente) se il numero di livelli è troppo grande, il gradiente può diventare:
- molto grande (**exploding gradient**): causa problemi d’instabilità e genera parametri (weights) che superano quelli gestibili dal computer
- estremamente piccolo (**vanishing gradient**): determina un aggiornamento minimo dei pesi e causa un rallentamento del processo di training.

Grazie alla sua struttura, ResNet invece di aspettare che il gradiente si propaghi indietro (back propagation) un livello alla volta, il percorso di skip connection gli consente di raggiungere i nodi iniziali efficacemente saltando quelli intermedi.

### **VGG16**
VGG16 è un modello di rete neurale convoluzionale presentato nel 2014 dall'Università di Oxford.
VGG16 prende in input immagini RGB di dimensione 224x224.

![](img/vgg_structure.png)

La rete è composta, come suggerisci il nome, da 16 layer, 13 dei quali sono layer convolutivi, 2 sono layer fully connected e 1 è un layer di output.

### **SVM Lineare**


### Risultati


## Fine Tuning


## Creazione di una rete da zero