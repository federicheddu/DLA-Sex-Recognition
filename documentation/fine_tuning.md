# Finetuning di una rete pre-addestrata
In questo esperimento abbiamo preso AlexNet e abbiamo fatto un finetuning, cioé un riaddestramento degli ultimi livelli della rete per adattarla al nostro problema, lasciando invariati i primi livelli della rete.

## **Flag e impostazioni**
All'inizio del file è possibile impostare alcune variabili che influenzano il comportamento del programma. Queste sono tre variabili che regolano la stampa di alcune informazioni durante l'esecuzione del programma, in maniera simile a quello fatto negli altri esperimenti.

```MATLAB
% === VARIABILI SI STAMPA === %
printTrainingSet = 1;
printTestSet = 1;
printConfMatrix = 1;
```

## **Caricamento dei dati**
Per caricare i dati abbiamo utilizzato il metodo `imageDatastore` che permette di caricare le immagini e le label associate. In questo caso abbiamo caricato le immagini di training, validation e test set, ognuno dei quali corrisponde ad una cartella nella cartella del dataset.  
Per ogni immagine è stata associata una label che indica il sesso dell'utente rappresentato e questa è stata recuperata dal nome della sottocartella in cui è contenuta l'immagine.

```MATLAB
% caricamento dei dati
imdsTrain = imageDatastore ('dataset/TrainSet/', 'IncludeSubfolders', true, 'LabelSource', 'foldernames');
imsValidation = imageDatastore ('dataset/ValSet', 'IncludeSubfolders', true, 'Labelsource', 'foldernames');
imdsTest = imageDatastore ('dataset/TestSet/', 'IncludeSubfolders', true, 'LabelSource', 'foldernames');
%numero di dati caricati
numTrainImages = numel (imdsTrain.Labels);
numValImages = numel(imsValidation.Labels);
numTestImages = numel(imdsTest.Labels);
```

## **Caricamento della rete e ridimensionamento**
È stata caricata alexnet e dopodiché sono state ridimensionate le immagini in modo da essere compatibili con la rete scelta.

```MATLAB
% caricamento della rete
net = alexnet;
% ridimensionamento delle immagini
inputSize = net.Layers(1). InputSize;
augimdsTrain = augmentedImageDatastore(inputSize(1:2), imdsTrain);
augimdsValidation = augmentedImageDatastore(inputSize(1:2), imdsValidation);
augimdsTest = augmentedImageDatastore (inputSize(1:2), imdsTest);
```

## **Fine-tuning**
Per effettuare il fine-tuning è sono stati bloccati tutti i layer della rete tranne gli ultimi tre, quindi ne sono stati aggiunti altrettanti e sono stati riaddestrati.  
I layer aggiunti sono un fully connected layer con 2 neuroni, una funzione di softmax layer e un layer di classificazione.

```MATLAB
freezedLayers = net. Layers (1:end-3);
layers = [
    freezedLayers
    fullyConnectedLayer (numClasses, ...
        'WeightLearnRateFactor', 20, ...
        'BiasLearnRateFactor', 20)
    softmaxLayer
    classificationLayer];
```

Dopo aver definito i layer è stato definito un oggetto `trainingOptions` che contiene le impostazioni per l'addestramento della rete e infine è stato avviato l'addestramento.

```MATLAB
options = trainingOptions ('sgdm',...
    'MiniBatchSize', 256, ...
    'MaxEpochs', 6, ...
    'InitialLearnRate', 1e-4, ...
    'Shuffle', 'every-epoch'
    'ValidationData', augimsValidation, ...
    'ValidationFrequency'3, ...
    'Verbose', false, ...
    'Plots', 'training-progress',...
    'ExecutionEnvironment', 'gpu');

net = trainNetwork(augimdsTrain, layers, options);
```

Dato che si tratta di un fine-tuning abbiamo scelto un numero di epoche basso pari a 6.

![](../img/results/finetuning_alexnet.png)

## **Risultati**
Dopo aver addestrato la rete è stato calcolato l'errore sul test set e la matrice di confusione ottenendo i seguenti risulati:

|               |                 |
| -----------   | --------------- |
| **Acc. Val**  | 97.43%          |
| **Acc. Test** | 96.59%          |
| **Rateo**     | 19281/19962     |  
| **Time**      | 28071.5158s     |  

**Fine Tuned Alexnet confusion**
|               | **T Female**          |  **T Male**           |
| ---           | ---                   | ---                   |
| **P Female**  |  96.8% <br> (11857)   |  3.8% <br> (291)      |
| **P Male**    |  3.2% <br> (390)      |  96.2% <br> (7424)    |

Di seguito possiamo osservare alcune immagini di test e la loro classificazione effettuata dalla rete, con una gradcam per evidenziare le parti dell'immagine che hanno contribuito maggiormente alla classificazione.
![](../img/results/fineALEX_pred.png) ![](../img/results/fineALEX_grad.png)

Come possiamo notare il modello si concentra di più sul collo, dove è presente o meno il pomo d'adamo, e sul viso, nella zona inferiore, dove può essere presente o meno la barba e dove sono ben distinguibili i tratti maschili da quelli femminili con zigomi e mento più pronunciati.

## **Conclusioni**
Il modello ha ottenuto un'accuratezza di circa il 97.4% sul validation set e circa il 96.6% sul test set, con un tempo di addestramento di circa 7 ore e 45 minuti.
Se lo mettiamo a confronto con l'esperimento di feature extraction con classificazione SVM analogo, cioé con l'estrazione delle features con AlexNet, abbiamo ottenuto un delta positivo del 3.3% in accuracy sul test set. Se andiamo a considerare nel confronto anche l'esperimento con l'utilizzo dei metadati su questo abbiamo ottenuto un delta positivo dello 0.22/0.23% in accuracy sul test set.

|              | **AlexNet FT** | **AlexNet FE** | **AlexNet FE w/ metadata** | **AlexNet w/ metadata & norm** |
| -----------  | -------------  | -------------- | -------------------------- | ------------------------------ |
| **Accuracy** | 96.59          | 93.29%         | 96.36%                     | 96.37%                         |
| **Delta**    | /              | -3.3%          | -0.23%                     | -0.22%                         |

Se prendiamo in considerazione tutti gli altri esperimenti effettuati in precedenza possiamo notare che il fine-tuning raggiunge un accuracy superiore della maggior parte degli esperimenti, a parte qualche eccezione, sempre ascrivibile agli esperimenti con l'utilizzo dei metadati.

|              | **AlexNet FT** | **ResNet-50 FE w/ metadata** | **ResNet-50 w/ metadata & norm** | **VGG16 w/ metadata & norm** |
| -----------  | -------------  | ---------------------------- | -------------------------------- | ---------------------------- |
| **Accuracy** | 96.59          | 96.91%                       | 96.97%                           | 96.64%                       |
| **Delta**    | /              | +0.32%                       | +0.38%                           | +0.05%                       |

Il miglior risultato di feature extraction e classificazione SVM ottenuto senza l'utilizzo dei metadati è stato quello ottenuto con ResNet-50, con un accuracy del 94.76% sul test set, il che lo pone l'1.83% sotto il risultato ottenuto con il fine-tuning di AlexNet.

Preso atto dei risultati ottenuti e tenendo conto che il fine-tuning di AlexNet ha richiesto circa 7 ore e 45 minuti, mentre tutti gli esperimenti di feature extraction con classificazione SVM con ResNet-50 hanno richiesto meno di 5 minuti, possiamo concludere che il fine-tuning di AlexNet non è il metodo migliore per questo problema, sia in un caso generale con l'utilizzo delle sole immagini in quanto lo scarto in termini di accuracy è basso e c'è un abisso per quanto riguarda le tempistiche di addestramento, sia nel caso specifico di questo dataset in cui si hanno a disposizione dei metadati che combinati alle feature estratte dalle reti permettono di raggiungere risultati migliori in circa un 1/100º del tempo.