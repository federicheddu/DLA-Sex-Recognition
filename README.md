# DLA-Sex-Recognition

>  Questo è un progetto svolto nell'ambito dell'esame **Deep Learning and Applications Mod.1** del **CdLM in Informatica** presso l'Università degli Studi di Cagliari

| **Studente**          | **Matricola** | **E-Mail**                        |
|-----------------------|---------------|-----------------------------------|
| Federico Meloni       | 60/73/65243   | <f.meloni62@studenti.unica.it>    |
| Luca Faccin           | 60/73/65236   | <l.faccin@studenti.unica.it>      |

<br>

---

<br>

> ### **Table of Content**
> 1. [Introduzione al progetto](#introduzione-al-progetto)
> 1. [Il dataset](#il-dataset)
> 1. [Esperimenti e documentazione](#esperimenti-e-documentazione)
>    - [Documentazione](#documentazione)
> 1. [Utilizzo del progetto](#utilizzo-del-progetto)
>    - [Clonare la repository](#clone-la-repository)
>    - [Requisiti di MATLAB](#requisiti-di-matlab)
>    - [Inserimento del dataset](#inserimento-del-dataset)
>    - [Esecuzione degli esperimenti](#esecuzione-degli-esperimenti)
> 1. [Hardware e limitazioni](#hardware-e-limitazioni)


```
STRUTTURA DELLA REPOSITORY
·
│
│ FILE ESPERIMENTI
├── alex_res_vgg.mlx
├── finetuning.mlx
├── custom_network.mlx
│
│
│ FILE C
├── split.c
├── features.c
│
│
│ FUNZIONI SVM
├── libsvmread.mexw64/.mexa64
├── libsvmwrite.mexw64/.mexa64
├── train.mexw64/.mexa64
├── libsvm-master
│   └── ···
│
│
│ DATASET
├── dataset
│   ├── TrainSet_features.txt
│   ├── TestSet_features.txt
│   └── ValSet_features.txt
├── metadata
│   ├── list_attr_celeba.txt
│   └── list_eval_partition.txt
│
│
│ MARKDOWN & DOCUMENTAZIONE
├── README.md
├── documentation
│   ├── networks.md
│   ├── features_extraction.md
│   ├── metadata_concatenation.md
│   ├── fine_tuning.md
│   └── custom_network.md
├── img
│   └── ···
│
│ OTHER
├── .gitignore
└── LICENSE
```

<br>

---

<br>

## **Introduzione al progetto**

Questo progetto univeristario si pone l'obiettivo di classificare immagini del volto di persone famose in base al loro sesso attraverso diversi esperimenti e tecniche di Deep Learning.  

Il dataset di partenza è [CelebA](https://mmlab.ie.cuhk.edu.hk/projects/CelebA.html). Questo dataset è stato scelto per la sua semplicità e per la sua dimensione, che permette di eseguire i test in tempi ragionevoli.

Il progetto è stato sviluppato in MATLAB, utilizzando il Deep Learning Toolbox e alcuni add-on collegati per i vari modelli scelti. È stato fatto utilizzo anche del Parallel Computing Toolbox per l'utilizzo della GPU.

Per preparare il dataset agli esperimenti sono stati scritti alcuni script in C che permettono di eseguire la divisione del dataset in training, validation e test set, di creare le cartelle necessarie per il caricamento delle immagini e di fare il parsing dei metadati disponibili in modo da caricarli con facilità in MATLAB.

<br>

## **Il dataset**

CelebFaces Attributes Dataset, abbreviato CelebA, è un dataset di immagini del viso di celebrità con relativi attributi.  
Contiene 202.599 immagini di volti in cinque posizioni di riferimento, con 40 annotazioni binarie degli attributi per ogni immagine. Attualmente include dati relativi a oltre 10.000 celebrità.

CelebA include molte immagini diverse che coprono varie pose e variazioni di sfondo. Fornisce annotazioni dettagliate per le immagini utili per la formazione di modelli di apprendimento automatico e di visione artificiale.

Nel nostro caso è stata utilizzata la versione [Align & Cropped](https://drive.google.com/drive/folders/0B7EVK8r0v71pTUZsaXdaSnZBZzg?resourcekey=0-rJlzl934LzC-Xp28GeIBzQ) che contiene le immagini già pulite, con le facce allineate e centrata.

Per la preparazione e l'utilizzo del dataset rimandiamo alle istruzioni conenute nei paragrafo [[Utilizzo del progetto](#utilizzo-del-progetto)].

<br>

## **Esperimenti e documentazione**
Sonos stati effettuati diversi esperimenti, ognuno con un approccio diverso:
- Feature Extraction con AlexNet, ResNet e VGG16 per poi utilizzare un classificatore SVM Lineare
- Integrazione dei metadati disponibili all'interno dell'esperimento precedente
- Fine Tuning di una rete pre-addestrata
- Creazione di una rete da zero



Di seguito i link alla documentazione completa del progetto:
> ### **Documentazione**
> - [teoria] [Stato dell'arte](documentation/networks.md)
> - [esperimento] [Feature Extraction & SVM](documentation/feature_extraction.md)
> - [esperimento] [Integrazione dei metadati](documentation/metadata_concatenation.md)
> - [esperimento] [Fine Tuning di AlexNet](documentation/fine_tuning.md)
> - [esperimento] [Creazione di una rete da zero](documentation/new_network.md)
>
> *[Link alla cartella con tutta la documentazione](documentation/)*

<br>

## **Utilizzo del progetto**
Di seguito le istruzioni per l'utilizzo dei file contenenti gli esperimenti e poterli replicare, per preparare il dataset (*non contenuto in questa repository per problemi di spazio*) e il materiale aggiuntivo.



### **Clonare la repository**
Clonare la repository con GitHub Desktop o con il comando:
```bash
git clone https://github.com/federicheddu/DLA-Sex-Recognition.git
```



### **Requisiti di MATLAB**
Per poter replicare ed utilizzare il progetto è necessario avere installato su MATLAB i seguenti add-on:

- Installare su MATLAB il Statistic and Machine Learning Toolbox  
`Add On: Home > Add-On > Statistic and Machine Learning Toolbox`

- Installare su MATLAB il Deep Learning Toolbox  
`Add On: Home > Add-On > Deep Learning Toolbox`

- Installare su MATLAB il Deep Learning Toolbox Model for AlexNet Network  
`Add On: Home > Add-On > Deep Learning Toolbox Model for AlexNet Network`

- Installare su MATLAB il Deep Learning Toolbox Model for ResNet-18 Network  
`Add On: Home > Add-On > Deep Learning Toolbox Model for ResNet-18 Network`

- Installare su MATLAB il Deep Learning Toolbox Model for ResNet-50 Network  
`Add On: Home > Add-On > Deep Learning Toolbox Model for ResNet-50 Network`

- Installare su MATLAB il Deep Learning Toolbox Model for VGG-16 Network  
`Add On: Home > Add-On > Deep Learning Toolbox Model for VGG-16 Network`

- Installare su MATLAB il Plot Confusion Matrix  
`Add On: Home > Add-On > Plot Confusion Matrix by Vane Tshitoyan`

- Installare su MATLAB il Parallel Computing Toolbox  
`Add On: Home > Add-On > Parallel Computing Toolbox`  
*facoltativo se si vuole usare la GPU ma vivamente consigliato*

Il classificatore SVM è stato implementato utilizzando il [libsvm](https://www.csie.ntu.edu.tw/~cjlin/libsvm/). Questa repository contiene una copia della libreria nella cartella `liblinear-master` e le funzioni già compilate per MATLAB nella home della demo sia per Windows che per Linux.
Quindi in caso di utilizzo di MATLAB su Windows o Linux non è necessario compilare le funzioni o effettuare altre operazioni.  
In caso di incompatibilità col proprio sistema operativo si possono compilare le funzioni necessarie nella cartella [`liblinear-master/matlab`](liblinear-master/matlab) utilizzando il comando `make` da terminale come suggerito nella [guida](liblinear-master/matlab/README) contenuta nella stessa cartella (in inglese).



### **Inserimento del dataset**
È necessario scaricare il dataset CelebA nella sua versione [Align & Cropped](https://drive.google.com/drive/folders/0B7EVK8r0v71pTUZsaXdaSnZBZzg?resourcekey=0-rJlzl934LzC-Xp28GeIBzQ)

[`https://drive.google.com/drive/folders/0B7EVK8r0v71pTUZsaXdaSnZBZzg?resourcekey=0-rJlzl934LzC-Xp28GeIBzQ`](https://drive.google.com/drive/folders/0B7EVK8r0v71pTUZsaXdaSnZBZzg?resourcekey=0-rJlzl934LzC-Xp28GeIBzQ)

Dopodiché è necessario estrarre l'archivio inserendo le immagini nella cartella [`dataset`](dataset).

Una volta inserite le immagini è necessario compilare ed eseguire il file C denominato [`split.c`](split.c) che, andando a pescare le informazioni dai file [`list_attr_celeba.txt`](metadata/list_attr_celeba.txt) e [`list_eval_partition.txt`](metadata/list_eval_partition.txt) presente nella cartella [`metadata`](metadata), crea tutte le cartelle e sottocartelle necessarie per il caricamento su MATLAB.
> **NOTA**: il file `split.c` è stato scritto per essere eseguito su Linux, in caso di utilizzo di Windows è necessario compilare ed eseguire il file `split.c` utilizzando un terminale bash.

Non è necessario eseguire invece il file `features.c` che è stato utilizzato per creare i file [`TrainSet_features.txt`](dataset/TrainSet_features.txt), [`TestSet_features.txt`](dataset/TestSet_features.txt) e [`ValSet_features.txt`](dataset/ValSet_features.txt), contenenti i metadati messi a disposizione dal dataset divisi e parsati nel modo corretto per essere letti da MATLAB, in quanto questi file sono già messi a disposizione in questa repository all'interno della cartella [`dataset`](dataset).



### **Esecuzione degli esperimenti**
Una volta eseguiti tutti i passaggi preliminari è possibile eseguire gli esperimenti.

Gli esperimenti sono stati suddivisi in 3 file MATLAB Live Script:
- [`alex_res_vgg.mlx`](alex_res_vgg.mlx): esperimento con delle reti pre-addestrate per fare la feature extraction e la classificazione usando SVM
- [`finetuning.mlx`](finetuning.mlx): esperimento che esegue il fine tuning di una rete pre-trainata
- [`custom_network.mlx`](custom_network.mlx): esperimento con la rete creata da zero

Per eseguire gli esperimenti è necessario aprire i file MATLAB Live Script e cliccare su `Run` per eseguire il codice.

Per maggiori dettagli sui singoli file si rimanda alla documentazione dei singoli esperimenti in cui vengono descritti step-by-step i vari file. Si possono trovare i link nella sezione [[Documentazione](#documentazione)].

<br>

## **Hardware e limitazioni**
Gli esperimenti sono stati eseguiti su un computer con le seguenti caratteristiche:
- OS: Ubuntu 18.04.5 LTS
- CPU: Intel i9-7920X
- GPU: NVIDIA GeForce GTX 2080 Ti x2
- RAM: 128GB

È possibile che alcuni esperimenti non siano eseguibili o risultino molto lenti su computer con meno risorse in quanto si tratta di un dataset di grosse dimensioni.