## Combinazione metadati e feature
Dato che il dataset CelebA a nostra disposizione, oltre che le immagini, metteva a disposizione una serie di metadati per ogni immagine, abbiamo deciso di provare a combinare queste informazioni con le feature estratte dalle reti neurali utilizzate nell'esperimento di feature extraction.

In questa sezione andremo a descrivere le integrazioni fatte all'[esperimento di feature extraction](../alex_res_vgg.mlx), per informazioni sul resto del codice rifarsi a quella sezione.

Questi metadati consistono in feature binarie ad alto livello quali:
- 5_o_Clock_Shadow
- Arched_Eyebrows
- Attractive
- Bags_Under_Eyes
- Bald
- Bangs 
- Big_Lips 
- Big_Nose 
- Black_Hair 
- Blond_Hair 
- Blurry 
- Brown_Hair 
- Bushy_Eyebrows 
- Chubby 
- Double_Chin 
- Eyeglasses 
- Goatee 
- Gray_Hair 
- Heavy_Makeup 
- High_Cheekbones 
- Mouth_Slightly_Open
- Mustache
- Narrow_Eyes
- No_Beard 
- Oval_Face 
- Pale_Skin 
- Pointy_Nose 
- Receding_Hairline 
- Rosy_Cheeks 
- Sideburns 
- Smiling 
- Straight_Hair 
- Wavy_Hair 
- Wearing_Earrings 
- Wearing_Hat 
- Wearing_Lipstick 
- Wearing_Necklace 
- Wearing_Necktie 
- Young

Oltre a queste 39 feature ad alto livello in questo file era presente anche la feature *Male* che indica se l'immagine rappresenta un uomo o una donna e che è stata utilizzata come label in tutti gli esperimenti.

<br>

## **Attivare la combinazione dei metadati**
La combinazione dei metadati è stata implementata come opzionale nel file [`alex_res_vgg.mlx`](../alex_res_vgg.mlx) e può essere attivata settando le variabilie `concatenationMetadata` a 1.  
È inoltre presente il flag `normalizationMetadata` che se impostato ad 1 effettua la normalizzazione delle feature dopo la concatenazione.

```MATLAB
% === CONCATENAZIONE === %
concatenationMetadata = 1;
normalizationMetadata = 1;
```

<br>

## **Estrazione e caricamento dei metadati**
I metadati sono stati estratti dal file originale fornito da CelebA [`list_attr_celeba.txt`](../metadata/list_attr_celeba.txt), che è un file con una riga per ogni immagine. Ogni riga contiene il nome dell'immagine e le informazioni relative ai metadati.  

Per l'estrazione è stato scritto lo script in C [`feature.c`](../feature.c) che legge i file [`list_eval_partition.txt`](../metadata/list_eval_partition.txt) (contenente la ripartizione delle immagini tra train, validation e test set) e [`list_attr_celeba.txt`](../metadata/list_attr_celeba.txt) (contenente le feature di alto livello) e scrive nel file un file contente le feature per ogni ripartizione, mettendo prima tutte le feature delle immagini di classe 0 (*Female*) e poi quelle delle immagini di classe 1 (*Male*).

I file sono stati organizzati in questo modo in maniera tale da poter caricare singolarmente le feature per ogni ripartizione del dataset e l'ordinamento interno è stato scelto per avere una corrispondeza tra le feature e il caricamento che effettua MATLAB delle immagini.

Questi dati vengono poi caricati in MATLAB:

```MATLAB
featTrainMatrix = readmatrix ('dataset/TrainSet_features.txt','Delimiter', ' ');
featTestMatrix = readmatrix('dataset/TestSet_features.txt','Delimitert', ' ');
```

<br>

## **Concatenazione delle feature**
Le feature una volta caricate vengono concatenate con le feature estratte dalle reti neurali riga per riga.

```MATLAB
featuresTrain1 = [featuresTrain1, featTrainMatrix];
featuresTest1 = [featuresTest1, featTestMatrix];
```

<br>

## **Normalizzazione delle feature**
Se il flag `normalizationMetadata` è impostato a 1, le feature vengono normalizzate secondo centro e deviazione standard, utilizzando la funzione `normalize` di MATLAB.

```MATLAB
[featuresTrain1, C, S] = normalize(featuresTrain1);
featuresTest1 = normalize(featuresTest1, 'center', C, 'scale', S);
```

<br>

## **Risultati - senza normalizzazione**
Dai risultati possiamo norare come la combinazione dei metadati abbia portato ad un aumento sostanziale dell'accuracy per tutte le reti neurali utilizzate del 3% circa per ogni rete, passando da un aumento del 3.71% per ResNet-18 ad un aumento del 2.15% di ResNet-50, quest'ultima che raggiunge però un accuracy del 96.91% che è il massimo raggiunto da tutte le reti neurali utilizzate.

|          | AlexNet *(1GPU)*  | ResNet-18 *(2GPU)* | ResNet-50 *(1GPU)*  | VGG16 *(1GPU)* |
| -------  | --------------- | ---------------- | ----------------- | ------------ |
| Accuracy | 96.36%          | 96.35%           | 96.91%            | 96.51%       |
| Rateo    | 19236/19962     | 19234/19962      | 19346/19962       | 19265/19962  |
| Time     | 369.4852s       | 177.8919s        | 283.0541s         | 552.8084s    |

Di seguito possiamo analizzare i risultati ottenuti per ogni rete andando a vedere la matrice di confusione e qualche esempio di classificazione.

<br>

<table>

<tr><td>

**AlexNet conf w/o norm**
|               | **T Female**          |  **T Male**           |
| ---           | ---                   | ---                   |
| **P Female**  |  96.9% <br> (11862)   |  4.4% <br> (341)      |
| **P Male**    |  3.1% <br> (385)      |  95.6% <br> (7374)    |

</td><td>

**Resnet-18 conf w/o norm**
|               | **T Female**          |  **T Male**           |
| ---           | ---                   | ---                   |
| **P Female**  |  96.8% <br> (11860)   |  4.4% <br> (341)      |
| **P Male**    |  3.2% <br> (387)      |  95.6% <br> (7374)    |

</td></tr>
<tr><td>

**Resnet-50 conf w/o norm**
|               | **T Female**          |  **T Male**           |
| ---           | ---                   | ---                   |
| **P Female**  |  97.3% <br> (11920)   |  3.7% <br> (289)      |
| **P Male**    |  2.7% <br> (327)      |  96.3% <br> (7426)    |

</td><td>

**VGG16 conf w/o norm**
|               | **T Female**          |  **T Male**           |
| ---           | ---                   | ---                   |
| **P Female**  |  96.9% <br> (11868)   |  4.1% <br> (318)      |
| **P Male**    |  3.1% <br> (379)      |  95.9% <br> (7397)    |

</td></tr>

</table>

<br>

## **Risultati - con normalizzazione**
Dai risultati di quest'ultimo esperimento possiamo notare come la normalizzazione delle feature non abbia portato grande beneficio rispetto alla semplice concatenazione dei metadati.  
L'accuracy massima rimane quella di ResNet-50 che raggiunge il 96.97% mentre la rete che ha avuto il miglioramento più significativo è stata VGG16 che ha raggiunto un accuracy del 96.64%.

|          | AlexNet *(1GPU)*  | ResNet-18 *(2GPU)* | ResNet-50 *(1GPU)*  | VGG16 *(1GPU)* |
| -------  | --------------- | ---------------- | ----------------- | ------------ |
| Accuracy | 96.37%          | 96.35%           | 96.97%            | 96.64%       |
| Rateo    | 19238/19962     | 19233/19962      | 19358/19962       | 19292/19962  |
| Time     | 383.4852s       | 191.9109s        | 282.0613s         | 710.436s     |

Di seguito possiamo analizzare i risultati ottenuti per ogni rete andando a vedere la matrice di confusione:

<br>

<table>

<tr><td>

**AlexNet conf w/ norm**
|               | **T Female**          |  **T Male**           |
| ---           | ---                   | ---                   |
| **P Female**  |  96.8% <br> (11861)   |  4.4% <br> (338)      |
| **P Male**    |  3.2% <br> (386)      |  95.6% <br> (7377)    |

</td><td>

**Resnet-18 conf w/ norm**
|               | **T Female**          |  **T Male**           |
| ---           | ---                   | ---                   |
| **P Female**  |  96.8% <br> (11850)   |  4.3% <br> (332)      |
| **P Male**    |  3.2% <br> (397)      |  95.7% <br> (7383)    |

</td></tr>
<tr><td>

**Resnet-50 conf w/ norm**
|               | **T Female**          |  **T Male**           |
| ---           | ---                   | ---                   |
| **P Female**  |  97.3% <br> (11921)   |  3.6% <br> (278)      |
| **P Male**    |  2.7% <br> (326)      |  96.3% <br> (7437)    |

</td><td>

**VGG16 conf w/ norm**
|               |  **T Female**         |  **T Male**           |
| ---           |  ---                  | ---                   |
| **P Female**  | 97.1% <br> (11888)    |  4.0% <br> (311)      |
| **P Male**    | 2.9% <br> (359)       |  96.0% <br> (7404)    |

</td></tr>

</table>

<br>

## **Conclusioni**
Per trarre le conclusioni finali riassumiamo i risultati ottenuti per ogni rete confrontando gli esperimenti con e senza metadati e/o normalizzazione:

|              | **AlexNet FE** | **AlexNet FE w/ metadata** | **AlexNet w/ metadata & norm** |
| -----------  | -------------- | -------------------------- | ------------------------------ |
| **Accuracy** | 93.29%         | 96.36%                     | 96.37%                         |
| **Delta**    | /              | +3.07%                     | +3.08%                         |

|              | **ResNet-18 FE** | **ResNet-18 FE w/ metadata** | **ResNet-18 w/ metadata & norm** |
| -----------  | ---------------- | ---------------------------- | -------------------------------- |
| **Accuracy** | 92.71%           | 96.35%                       | 96.35%                           |
| **Delta**    | /                | +3.64%                       | +3.64%                           |

|              | **ResNet-50 FE** | **ResNet-50 FE w/ metadata** | **ResNet-50 w/ metadata & norm** |
| -----------  | ---------------- | ---------------------------- | -------------------------------- |
| **Accuracy** | 94.76%           | 96.91%                       | 96.97%                           |
| **Delta**    | /                | +2.15%                       | +2.21%                           |

|              | **VGG16 FE** | **VGG16 FE w/ metadata** | **VGG16 w/ metadata & norm** |
| -----------  | ------------ | ------------------------ | ---------------------------- |
| **Accuracy** | 93.37%       | 96.51%                   | 96.64%                       |
| **Delta**    | /            | +3.14%                   | +3.27%                       |

La concatenazione dei metadati ha portato un miglioramento dell'accuracy per tutte le reti, con un aumento medio di circa il 3%, il che è un ottimo risultato, inoltre la normalizzazione delle feature non ha portato grandi miglioramenti aggiuntivi.  
Considerando che la concatenazione dei metadati non è un operazione pesante e che la normalizzazione delle feature anchessa non è un operazione esigente, possiamo concludere che la concatenazione dei metadati è un'operazione che può essere utilizzata per migliorare le prestazioni gratis (dove questi dati sono presenti) di una rete neurale e che la normalizzazione, sebbene non sia indispensabile, può portare un ulteriore miglioramento dell'accuracy con un limitato costo computazionale.
