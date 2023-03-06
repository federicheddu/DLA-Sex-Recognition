# Sviluppo della nuova rete 
In questa sezione descriveremo il procedimento di creazione e le caratteristiche della rete che abbiamo creato da zero per poter risolvere il problema di identificazione 
del genere a partire dal dataset di volti.

## **Flag e impostazioni**
All'inizio del file è possibile impostare alcune variabili che influenzano il comportamento del programma. Le prime tre sono variabili che regolano la stampa di alcune 
informazioni durante l'esecuzione del programma, in maniera simile a quello fatto negli altri esperimenti; mentre l'ultima determina se utilizzare le feature del dataset 
durante l'addestramento

```MATLAB
% === VARIABILI SI STAMPA === %
printTrainingSet = 1;
printTestSet = 1;
printConfMatrix = 1;

doubleInput = 0;
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

