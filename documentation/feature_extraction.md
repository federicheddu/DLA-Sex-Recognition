# NORMALE

|          | AlexNet *(1GPU)*  | ResNet-18 *(2GPU)* | ResNet-50 *(1GPU)*  | VGG16 *(1GPU)* |
| -------  | --------------- | ---------------- | ----------------- | ------------ |
| Accuracy | 93.29%          | 92.71%           | 94.76%            | 93.37%       |
| Rateo    | 18623/19962     | 18507/19962      | 18916/19962       | 18638/19962  |
| Time     | 380.5152s       | 206.0166s        | 285.4249s         | 739.1441s    |

AlexNet confusion
|               | **T Female**          |  **T Male**           |
| ---           | ---                   | ---                   |
| **P Female**  |  93.8% <br> (11488)   |  7.5% <br> (580)      |
| **P Male**    |  6.2% <br> (759)      |  92.5% <br> (7135)    |

Resnet-18 confusion 
|               | **T Female**          |  **T Male**           |
| ---           | ---                   | ---                   |
| **P Female**  |  93.3% <br> (11426)   |  8.5% <br> (634)      |
| **P Male**    |  6.7% <br> (821)      |  91.6% <br> (7081)    |

Resnet-50 confusion 
|               | **T Female**          |  **T Male**           |
| ---           | ---                   | ---                   |
| **P Female**  |  95.3% <br> (11671)   |  6.1% <br> (470)      |
| **P Male**    |  4.7% <br> (576)      |  93.9% <br> (7245)    |

VGG16 confusion 
|               | **T Female**          |  **T Male**           |
| ---           | ---                   | ---                   |
| **P Female**  |  93.8% <br> (11488)   |  7.5% <br> (580)      |
| **P Male**    |  6.2% <br> (762)      |  97.7% <br> (7153)    |

<br>
<br>

# CONCATENAZIONE

|          | AlexNet *(1GPU)*  | ResNet-18 *(2GPU)* | ResNet-50 *(1GPU)*  | VGG16 *(1GPU)* |
| -------  | --------------- | ---------------- | ----------------- | ------------ |
| Accuracy | 96.36%          | 96.35%           | 96.91%            | 96.51%       |
| Rateo    | 19236/19962     | 19234/19962      | 19346/19962       | 19265/19962  |
| Time     | 369.4852s       | 177.8919s        | 283.0541s         | 552.8084s    |

AlexNet confusion
|               | **T Female**          |  **T Male**           |
| ---           | ---                   | ---                   |
| **P Female**  |  96.9% <br> (11862)   |  4.4% <br> (341)      |
| **P Male**    |  3.1% <br> (385)      |  95.6% <br> (7374)    |

Resnet-18 confusion 
|               | **T Female**          |  **T Male**           |
| ---           | ---                   | ---                   |
| **P Female**  |  96.8% <br> (11860)   |  4.4% <br> (341)      |
| **P Male**    |  3.2% <br> (387)      |  95.6% <br> (7374)    |

Resnet-50 confusion 
|               | **T Female**          |  **T Male**           |
| ---           | ---                   | ---                   |
| **P Female**  |  97.3% <br> (11920)   |  3.7% <br> (289)      |
| **P Male**    |  2.7% <br> (327)      |  96.3% <br> (7426)    |

VGG16 confusion 
|               | **T Female**          |  **T Male**           |
| ---           | ---                   | ---                   |
| **P Female**  |  96.9% <br> (11868)   |  4.1% <br> (318)      |
| **P Male**    |  3.1% <br> (379)      |  95.9% <br> (7397)    |

<br>
<br>

# CONCATENAZIONE & NORMALIZZAZIONE

|          | AlexNet *(1GPU)*  | ResNet-18 *(2GPU)* | ResNet-50 *(1GPU)*  | VGG16 *(1GPU)* |
| -------  | --------------- | ---------------- | ----------------- | ------------ |
| Accuracy | 96.37%          | 96.35%           | 96.97%            | 96.64%       |
| Rateo    | 19238/19962     | 19233/19962      | 19358/19962       | 19292/19962  |
| Time     | 383.4852s       | 191.9109s        | 282.0613s         | 710.436s     |

AlexNet confusion
|               | **T Female**          |  **T Male**           |
| ---           | ---                   | ---                   |
| **P Female**  |  96.8% <br> (11861)   |  4.4% <br> (338)      |
| **P Male**    |  3.2% <br> (386)      |  95.6% <br> (7377)    |

Resnet-18 confusion 
|               | **T Female**          |  **T Male**           |
| ---           | ---                   | ---                   |
| **P Female**  |  96.8% <br> (11850)   |  4.3% <br> (332)      |
| **P Male**    |  3.2% <br> (397)      |  95.7% <br> (7383)    |

Resnet-50 confusion 
|               | **T Female**          |  **T Male**           |
| ---           | ---                   | ---                   |
| **P Female**  |  97.3% <br> (11921)   |  3.6% <br> (278)      |
| **P Male**    |  2.7% <br> (326)      |  96.3% <br> (7437)    |

VGG16 confusion 
|               |  **T Female**         |  **T Male**           |
| ---           |  ---                  | ---                   |
| **P Female**  | 97.1% <br> (11888)    |  4.0% <br> (311)      |
| **P Male**    | 2.9% <br> (359)       |  96.0% <br> (7404)    |

<br>
<br>

# FINE TUNING ALEXNET
|               |                 |
| -----------   | --------------- |
| **Acc. Val**  | 97.43%          |
| **Acc. Test** | 96.59%          |
| **Rateo**     | 19281/19962     |  
| **Time**      | 28071.5158s     |  

Fine Tuned Alexnet confusion
|               | **T Female**          |  **T Male**           |
| ---           | ---                   | ---                   |
| **P Female**  |  96.8% <br> (11857)   |  3.8% <br> (291)      |
| **P Male**    |  3.2% <br> (390)      |  96.2% <br> (7424)    |