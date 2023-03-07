# DLA-Sex-Recognition

>  Questo è un progetto svolto nell'ambito dell'esame **Deep Learning and Applications Mod.1** del **CdLM in Informatica** presso l'Università degli Studi di Cagliari

| **Studente**          | **Matricola** | **E-Mail**                        |
|-----------------------|---------------|-----------------------------------|
| Federico Meloni       | 60/73/65243   | <f.meloni62@studenti.unica.it>    |
| Luca Faccin           | 60/73/65236   | <l.faccin@studenti.unica.it>      |

Questo progetto univeristario si pone l'obiettivo di classificare immagini del volto di persone famose in base al loro sesso attraverso diversi esperimenti di Deep Learning. Il dataset di partenza è [CelebA](https://mmlab.ie.cuhk.edu.hk/projects/CelebA.html), in particolare la versione [Align & Cropped](https://drive.google.com/drive/folders/0B7EVK8r0v71pTUZsaXdaSnZBZzg?resourcekey=0-rJlzl934LzC-Xp28GeIBzQ) che contiene le immagini già pulite, con le facce allineate e centrata. Il dataset è stato scelto per la sua semplicità e per la sua dimensione, che permette di eseguire i test in tempi ragionevoli.

Sonos stati effettuati diversi esperimenti, ognuno con un approccio diverso:
- Feature Extraction con AlexNet, ResNet e VGG16 per poi utilizzare un classificatore SVM Lineare
- Integrazione dei metadati disponibili all'interno dell'esperimento precedente
- Fine Tuning di una rete pre-addestrata
- Creazione di una rete da zero

<br>

Di seguito i link alla documentazione completa del progetto:
> ### **Documentazione**
> - [teoria] [Stato dell'arte](documentation/networks.md)
> - [esperimento] [Feature Extraction & SVM](documentation/feature_extraction.md)
> - [esperimento] [Integrazione dei metadati](documentation/metadata_concatenation.md)
> - [esperimento] [Fine Tuning di AlexNet](documentation/fine_tuning.md)
> - [esperimento] [Creazione di una rete da zero](documentation/new_network.md)

<br>

---

<br><br>

> ### **README - Table of content**
> 1. [Utilizzo](#utilizzo-del-progetto)
>    - [Requisiti](#requisiti-di-matlab)
>    - [Inserimento del dataset](#inserimento-del-dataset)
>    - [Settare le variabili dei file](#settare-le-variabili-dei-file)

<br><br>

---

## **Utilizzo del progetto**
Di seguito le istruzioni per l'utilizzo dei file MATLAB

### **Requisiti di MATLAB**

1. Installare su MATLAB il Statistic and Machine Learning Toolbox  
`Add On: Home > Add-On > Statistic and Machine Learning Toolbox`

2. Installare su MATLAB il Deep Learning Toolbox  
`Add On: Home > Add-On > Deep Learning Toolbox`

3. Installare su MATLAB il Deep Learning Toolbox Model for AlexNet Network  
`Add On: Home > Add-On > Deep Learning Toolbox Model for AlexNet Network`

4. Installare su MATLAB il Deep Learning Toolbox Model for ResNet-18 Network  
`Add On: Home > Add-On > Deep Learning Toolbox Model for ResNet-18 Network`

5. Installare su MATLAB il Deep Learning Toolbox Model for ResNet-50 Network  
`Add On: Home > Add-On > Deep Learning Toolbox Model for ResNet-50 Network`

6. Installare su MATLAB il Deep Learning Toolbox Model for VGG-16 Network  
`Add On: Home > Add-On > Deep Learning Toolbox Model for VGG-16 Network`

7. Installare su MATLAB il Plot Confusion Matrix  
`Add On: Home > Add-On > Plot Confusion Matrix by Vane Tshitoyan`

8. Installare su MATLAB il Parallel Computing Toolbox  
`Add On: Home > Add-On > Parallel Computing Toolbox`  
*facoltativo se si vuole usare la GPU ma vivamente consigliato*

--- 

DA RIVEDERE DOPO QUESTA SEZIONE

1. Clonare la repository  
`git clone https://github.com/federicheddu/DLA-Sex-Recognition.git`

2. Aprire uno dei file (ogni file corrisponde ad un task specifico):  
    1. `alex_res_vgg.mlx`: il file utilizza dei network pre-trainati per fare la feature extraction e la classificazione usando SVM
    1. ```finetuning.mlx```: il file che esegue il fine tuning
    1. ```new_network.mlx```: il file con la rete creata da zero

### **Inserimento del dataset**
Scaricare il dataset dal link [CelebA](https://mmlab.ie.cuhk.edu.hk/projects/CelebA.html), in particolare la versione [Align & Cropped](https://drive.google.com/drive/folders/0B7EVK8r0v71pTUZsaXdaSnZBZzg?resourcekey=0-rJlzl934LzC-Xp28GeIBzQ)

<br>TI LASCIO L'ONORE DI SCRIVERE LE SEZIONI PER LO SCRIPT DEL DATASET E DELLE FEATURES 

### **Settare le variabili dei file**
Ogni file ha delle variabili all'inizio una sezione per poter decidere alcune variazioni all'esecuzione come il network o delle stampe.

### **Eseguire lo script**
se si sono eseguiti a dovere i passi precedenti tutti i file dovrebbero essere eseguibili senza problemi (per alcuni è richiesta una più che buona capacità delle RAM).
