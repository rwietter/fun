AVL


Balance factor = heightOfLeftSubtree – heightOfRightSubtree 

Um nó N: 
  - com BalanceFactor (N) <0 é chamado "pesado à esquerda" 
  - com BalanceFactor (N)> 0 é chamado de "pesado à direita" 
  - com BalanceFactor (N) = 0 às vezes é simplesmente chamado de "equilibrado"

________________________________________________________________________
________________________________________________________________________
________________________________________________________________________


ROTAÇÃO AVL:

LL =
{
Rotação esquerda única (rotação LL) 
Na rotação LL, cada nó move uma posição para a esquerda a partir da posição atual:

1
 \
  2
   \
    3 

   2
 /  \
1    3

},


________________________________________________________________________
________________________________________________________________________
________________________________________________________________________


RR =
{
Rotação Direita Única (Rotação RR) 
Na rotação RR, cada nó move uma posição para a direita a partir da posição atual:

    3
   /
  2
 /
1

   2
 /  \
1    3

},


________________________________________________________________________
________________________________________________________________________
________________________________________________________________________


LR = 
{
Rotação Esquerda Direita (Rotação LR) A rotação LR é uma combinação de rotação única esquerda,
seguida por uma única rotação direita.  Na rotação LR, primeiro, cada nó move uma posição para
a esquerda e depois uma posição para a direita a partir da posição atual:

 3
/
1
\
 2

LL:
    3
   /
  2
 /
1

RR:
   2
  / \
 1   3

},


________________________________________________________________________
________________________________________________________________________
________________________________________________________________________


RL = 
{
Rotação direita esquerda (rotação RL). A rotação RL é uma combinação de rotação única à direita seguida por uma única rotação à esquerda.  Na rotação RL, primeiro, cada nó move uma posição para a direita e depois uma posição para a esquerda a partir da posição atual:

    1
     \
      3
     /
   2

RR:
 1
  \
   2
    \
     3

LL:

    2
  /   \
 1      3

}