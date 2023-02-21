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

<br>

> ### **Table of Contents**
> 1. [Stato dell'arte](#stato-arte)
>    - [AlexNet](#alexnet)
>    - [ResNet](#resnet)
>    - [VGG16](#vgg16)
>    - [SVM](#svm)
> 1. [Feature Extraction](#feature-extraction)
>    - [Caricamento dei dati](#fe-dataset)
>    - [Caricamento delle reti](#fe-reti)
>    - [Risultati](#fe-risultati)
> 1. [Fine Tuning](#fine-tuning)
>    - [Caricamento dei dati](#ft-dataset)
>    - [Caricamento delle rete](#ft-reti)
>    - [Fine Tuning](#ft-finetuning)
>    - [Risultati](#ft-risultati)
> 1. [Creazione di una rete da zero](#nuova-rete)
> 

<br><br>

---

<br>

<a name="stato-arte"></a>

## **Stato dell'arte**

<br>

<a name="alexnet"></a>

### **AlexNet**


<br>

<a name="resnet"></a>

### **ResNet**



<br>

<a name="vgg16"></a>

### **VGG16**
VGG16 è un modello di rete neurale convoluzionale presentato nel 2014 dall'Università di Oxford.
VGG16 prende in input immagini RGB di dimensione 224x224.

![](img/vgg_structure.png)

La rete è composta, come suggerisci il nome, da 16 layer, 13 dei quali sono layer convolutivi, 2 sono layer fully connected e 1 è un layer di output.

<br><br>
Tutte le rete presentate precedentemente sono state applicate grazie al seguente codice: 
```
if network == "alexnet"
    net = alexnet;
    layer = 'fc7';
elseif network == "resnet"
    net = resnet18;
    layer = 'pool5'
else
    net = vgg16;
    layer = 'fc7';
end
```
Il quale a seconda della variabile "network" selezionata dall'utente all'inizio del file direttamente da codice può selezionare il network che più preferisce.
```
featuresTrain = activations(net,augimdsTrain,layer,'OutputAs','rows');
```
Nel codice di sopra si vede come i parametri di scelta del network vengono poi applicati; ovvero durante l'estrazione della features.
<br>

<a name="svm"></a>

### **SVM Lineare**
Le Support Vector Machine, o SVM, sono modelli di classificazione che mirano a trovare una linea di separazione delle classi che massimizzi il margine tra le classi stesse. 
Questo obiettivo viene raggiunto utilizzando una parte minima del set di dati di addestramento, i cosiddetti vettori di supporto (da cui il nome della famiglia di modelli).

![](img/svm_structure.png)

La figura mostra qual è la linea di demarcazione che massimizza il margine tra  due classi di dati. La stella visibile e i due triangoli  sono i vettori di supporto, che sono gli unici esempi nel set di dati che si trovano sul bordo. Una volta trovati, tutti gli altri esempi nel dataset sono irrilevanti per la classificazione, in quanto definiscono la linea di demarcazione e il margine. 
I vettori di supporto rappresentano i valori di una classe più vicini alla linea di demarcazione e i valori più vicini all'altra classe. Fondamentalmente, questi sono i valori più difficili da essere classificati.
Maggiore è il margine, migliore è la generalizzazione. Il motivo è  semplice: maggiore è il margine, maggiore è la distanza tra le classi, e quindi il potenziale di  confusione.
<br><br>
Per fara la classificazione abbiamo usato la libreria "liblinear", e applicata tramite il seguente codice: 
```
YTrain = double(YTrain(:,1));
YTest = double(YTest(:,1));
```
Prima trasfomando le etichette da categoriche a variabili double in modo tale da poter essere usate più avanti.
```
featuresTrain = sparse(double(featuresTrain));
featuresTest = sparse(double(featuresTest));
```
Successivamente abbiamo reso la matrice contente le features sparsa in modo da renderla più leggera e il processo di addestramento più snello.
```
model = train(YTrain, featuresTrain, options, '-s 2');
YPred = predict(YTest, featuresTest, model);
```
Infine eseguito l'addestramento (passando tutte i paramentri e variabili necessari) e la predizione sul Test set per poter valutare il modello.
<br><br>

---

<br>

<a name="feature-extraction"></a>

## **Feature Extraction**
Il primo esperimento consiste nell'utilizzare una rete neurale pre-addestrata per estrarre le caratteristiche visive dalle immagini e poi utilizzare un classificatore SVM Lineare per classificare le immagini in base al sesso.

Per fare ciò è stato utilizzato il dataset di partenza, che è stato suddiviso in due parti: una per il training e una per il testing.

Il modus operandi è il seguente:
1. Caricamento del dataset di training e di testing
2. Caricamento della rete neurale pre-addestrata e ridimensionamento delle immagini
3. Estrazione delle features dalle immagini estrapolando i dati dal penultimo layer della rete neurale
4. Training del classificatore SVM Lineare
5. Test del classificatore SVM Lineare

<br>

<a name="fe-risultati"></a>

### **Risultati**

```
AlexNet

init f 1.628e+05 |g| 1.985e+07
iter  1 f 6.720e+04 |g| 3.317e+06 CG   3 step_size 1.00e+00 
iter  2 f 4.669e+04 |g| 1.320e+06 CG   8 step_size 1.00e+00 
iter  3 f 3.950e+04 |g| 5.743e+05 CG   9 step_size 1.00e+00 
iter  4 f 3.420e+04 |g| 5.140e+05 CG  17 step_size 1.00e+00 
iter  5 f 3.365e+04 |g| 3.133e+05 CG   9 step_size 1.00e+00 
iter  6 f 3.322e+04 |g| 5.421e+05 CG   9 step_size 1.00e+00 
iter  7 f 3.284e+04 |g| 2.521e+05 CG   9 step_size 1.00e+00 
iter  8 f 3.065e+04 |g| 1.420e+05 CG  16 step_size 1.00e+00 
iter  9 f 3.052e+04 |g| 2.343e+05 CG   9 step_size 1.00e+00 
iter 10 f 3.043e+04 |g| 4.875e+04 CG   9 step_size 1.00e+00 

Accuracy = 93.3874% (18642/19962)
```
```
Resnet
init f 1.628e+005 |g| 1.453e+006
iter  1 f 5.028e+004 |g| 2.083e+005 CG   3 step_size 1.00e+000 
iter  2 f 4.099e+004 |g| 7.206e+004 CG   5 step_size 1.00e+000 
iter  3 f 3.673e+004 |g| 2.755e+004 CG   9 step_size 1.00e+000 
iter  4 f 3.538e+004 |g| 1.181e+004 CG   9 step_size 1.00e+000 
iter  5 f 3.500e+004 |g| 8.823e+003 CG   9 step_size 1.00e+000 
iter  6 f 3.484e+004 |g| 5.836e+003 CG   9 step_size 1.00e+000 

Accuracy: 92.68% - Time Elapsed: 184.1821 s - True Positive vs Total: 18500/19962
```
<br><br>

---

<br>

<a name="fine-tuning"></a>

## **Fine Tuning**

<br><br>

---

<br>

<a name="nuova-rete"></a>


## **Creazione di una rete da zero**



Il network che abbiamo creato ha la seguente struttura: 

![](img/new_network_map.png)

Rappresenta cinque volte una ripetizione degli strati:<br>
![](img/Layers_cycle.png)
<br>
concludendo infine con gli strati fully connected, di dropout, softmax e infine di classificazione e output.
Sfortunatamente la struttura era troppo complessa quindi la struttura è stata ridotta nella seguente:<br>
![](img/map2.png)
<br>
Rimuovendo uno delle cinque ripetizioni evidenziate prima, abbassando il numero di fitri negli strati convoluzionari, togliendo uno dei fullyconnected layers e
abbassandone anche il numero di output.<br><br>

## **Utilizzo della feature del dataset**
<br>
In origine nel dataset assieme alle classi erano presenti anche svariate altre features poste come booleane a simboleggiare se sono presenti o no, (per esempio borse sotto gli occhi, doppio mento, labbra carnose, occhiali etc.). Da principio non ci era richiesto di utilizzarle direttamente, ma abbiamo deciso di fare un quarto file "feat_concat_network" per poterne farne uso. Per realizzarla siamo parti dal file che utilizzava le reti pretrainate e aggiungerle alle feature estratte nella sezione del codice SVM.

```
featuresTrain = [featuresTrain, featTrainMatrix];
featuresTest = [featuresTest, featTestMatrix];
```

In questa sezione concateniamo le features estratte dalle funzione activations() e quelle lette dal file con tutte le features.

```
featuresTrain = sparse(double(featuresTrain));
featuresTest = sparse(double(featuresTest));

model = train(YTrain, featuresTrain, '-s 2');
YPred = predict(YTest, featuresTest, model);
```

Questa sezione è invece come il file d'origine, il probelma sorge alla conversione della matrice delle feature in una matrice sparsa di tipo double, in quanto diventando più pesante ha saturato la memoria di uno dei pc che stavamo utilizzando (16 gb), e abbiamo dovuto fare ricorso ad un server per poter concludere i calcoli.

```
featTrainMatrix = normalize(featTrainMatrix, 'range') * 2 - 1;
featTestMatrix = normalize(featTestMatrix, 'range') * 2 - 1;
```

È stato anche provato a normalizzare le features dato che quelle estratte dal modello oscillavano tra -25 e 25 mentre quelle del dataset tra -1 e 1; quindi con il codice di sopra si mettono anche le features estratte dal modello nello stesso intorno delle altre; questa modifica però non ha portato dei miglioramenti, anzi ha abbassato l'accuratezza di un 0,1%, quindi questa modifica è stata scartata.
