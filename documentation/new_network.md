# Creazione di una nuova archietettura
Come ultimo esperimento abbiamo deciso di creare una nuova architettura da zero e di addestrarla per confrontare risultati con quelli ottenuti con le reti pre-addestrate.

## **Opzioni e caricamento dei dati**
In maniera analoga agli altri esperimenti sono stati messi a disposizione dei flag di stampa per decidere se visualizzare o meno alcune immagini di training e test set con relative predizioni e la matrice di confusione.

```MATLAB
% === VARIABILI DI STAMPA === %
printTrainingSet = 1;
printTestSet = 1;
printConfMatrix = 1;
```

Per il caricamento dei dati si è utilizzato un `imageDatastore` come descritto negli altri esperimenti.

```MATLAB
% caricamento dei dati
imdsTrain = imageDatastore ('dataset/TrainSet/', 'IncludeSubfolders', true, 'LabelSource', 'foldernames');
imdsTest = imageDatastore ('dataset/TestSet/', 'IncludeSubfolders', true, 'LabelSource', 'foldernames');
%numero di dati caricati
numTrainImages = numel (imdsTrain.Labels);
numTestImages = numel(imdsTest.Labels);
```

## **Creazione della nuova architettura**
Come primo test abbiamo creato un architettura realtivamente piccola composta da 9 livelli, di cui:

```MATLAB
layers = [
    imageInputLayer(imageInputSize, Normalization="zscore")
    convolution2dLayer(filterSize, numFilters)
    batchNormalizationLayer
    reluLayer
    fullyConnectedLayer(50)
    flattenLayer
    fullyConnectedLayer(numClasses)
    softmaxLayer
    classificationLayer];

lgraph = layerGraph(layers);
```

![](../img/custom_network/first_net.png)

Nel livello di input abbiamo utilizzato una normalizzazione `zscore` per ottenere una media nulla e una varianza unitaria. Successivamente abbiamo utilizzato un `convolution2dLayer` con 130 filtri di dimensione 40x40, un `batchNormalizationLayer` e una `reluLayer`. Questi tre livelli sono stati utilizzati per ottenere una maggiore robustezza del modello.  
Dopodiché abbiamo utilizzato un `fullyConnectedLayer` con 50 neuroni e un `flattenLayer` per ottenere un vettore di features. Infine abbiamo utilizzato un `fullyConnectedLayer` con 2 neuroni per la classificazione e un `softmaxLayer` per ottenere le probabilità di appartenenza ad una delle due classi.

<br>

## **Addestramento della nuova architettura**

Una volta definita l'architettura della rete abbiamo ed effettuato il ridimensionamento delle immagini di training e test set, si è potuto procedere all'addestramento della rete definendo alcune opzioni di training.

```MATLAB
options = trainingOptions("sgdm", ...
    MaxEpochs=10, ...
    InitialLearnRate=0.0001, ...
    Plots="training-progress", ...
    MiniBatchSize=128, ...
    Verbose=1, ...
    ExecutionEnvironment="multi-gpu");

net = trainNetwork(augimdsTrain, lgraph, options);
```

![](../img/custom_network/first_net_train.png)

Come si può notare dall'immagine sopra, l'addestramento è stato effettuato in 10 epoche, con un learning rate iniziale di 0.0001 e un mini-batch size di 128.

<br>

## **Risultati della nuova architettura**
Dopo aver addestrato la rete è stato calcolato l'errore sul test set e la matrice di confusione ottenendo i seguenti risulati:

|               |                 |
| -----------   | --------------- |
| **Accuracy**  | 96.09%          |
| **Rateo**     | 19182/19962     |  
| **Time**      | 5178.625s       |  

**Fine Tuned Alexnet confusion**
|               | **T Female**          |  **T Male**           |
| ---           | ---                   | ---                   |
| **P Female**  |  97.03% <br> (11916)  |  5.8% <br> (449)      |
| **P Male**    |  2.7% <br> (331)      |  94.2% <br> (7266)    |

Di seguito possiamo osservare alcune immagini di test e la loro classificazione effettuata dalla rete:

![](../img/custom_network/first_net_pred.png)