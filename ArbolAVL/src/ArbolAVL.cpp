//============================================================================
// Name        : ArbolAVL.cpp
// Author      : William Cepeda
// Version     :
// Copyright   : Docencia UNACH
// Description : Hello World in C++, Ansi-style
//============================================================================


/* avl.c */
#include <stdlib.h>
#include <stdio.h>
#include "avl.h"
using namespace std;
# define max(A,B) ((A)>(B)?(A):(B))	/* Definición de macro  */
# define min(A,B) ((A)>(B)?(B):(A))


//Métodos
tree search(typekey, tree);
tree insert(typekey, tree);
tree delet(typekey, tree);
int height(tree); // Retorna altura h .
int count(tree);  //Cuenta recursivamente los nodos del árbol
tree deltree(tree);


//Rutinas internas
tree insertR(tree);
tree deleteR(tree);
tree deltreeR(tree);
tree lrot(tree);
tree rrot(tree);
node* newNode(void);
void freeNode(node*);
void Error(int);

//Variables globales
int flag; /* Marca para registrar cambios de altura. En rebalance ascendente */
//flag = 1 indica que debe seguir el ascenso rebalanceando.
int key;  /* Variable global, para disminuir argumentos */
int avl_height = 0; /* Altura árbol avl. Número de nodos desde la raíz a las hojas.*/

tree pool = NULL;  /* Lista para reutilizar nodos */
int pool_num = 0;  /* Número de nodos en la lista */
#define POOL_SIZE 1       /* Tamaño del pool de nodos    */

/*
 * Buscar clave en subárbol apuntado por t
 * Retorna puntero al nodo o NULL si no lo encontró.
 */
tree search(typekey key, tree t)
{
	while(t != NULL)
	  if (t->k > key) t = t->left;
	  else
	    if (t->k < key) t = t->right;
	    else return t;
	return NULL;
}
/*
 * Inserta nodo en sub-árbol apuntado por t
 * Mantiene variable global con el alto del árbol.
 */
tree insert(typekey k, tree t)
{
	key = k;
	t = insertR(t);
	if (flag == 1) avl_height++;
	//si la propagacion llega hasta la raiz, aumenta la altura.
	return t;
}

tree insertR(tree t)
{
	if (t == NULL){ /* Llego a un punto de inserción */
	  	t = newNode(); /* Crea nuevo nodo */
		t->k = key;
		t->left = NULL;
		t->right = NULL;
	  	t->bal = 0; /* Los dos hijos son nulos */
	  	flag = 1; /* Marca necesidad de revisar balances  */
		return t; /* retorna puntero al insertado */
	}
  	else if (t->k < key){
  			//desciende por la derecha
	  		t->right = insertR(t->right);
	  		//se pasa por aca en la revision ascendente
	  		t->bal += flag; /* Incrementa factor de balance */
	}
	else if (t->k > key){
			//desciende por la izquierda
	  		t->left = insertR(t->left);
	  		//se corrige en el ascenso
	  		t->bal -= flag; /* Decrementa balance */
	}
	else { /* (t->k == key) Ya estaba en el árbol */
	  	Error(1);
		flag = 0;
	}

	if (flag == 0) /* No hay que rebalancear. Sigue el ascenso */
		return t;

	/* Mantiene árbol balanceado avl. Sólo una o dos rotaciones por inserción */
	if(t->bal < -1) {
		/* Quedó desbalanceado por la izquierda */
		if(t->left->bal > 0)
			/* Si hijo izquierdo está cargado a la derecha */
			t->left = lrot(t->left);
		t = rrot(t);
		flag = 0; /* El subárbol no aumenta su altura */
	}
	else if(t->bal > 1) {
		/* Si quedo desbalanceado por la derecha*/
		if(t->right->bal < 0)
			/* Si hijo derecho está cargado a la izquierda */
			t->right = rrot(t->right);
		t = lrot(t);
		flag = 0; /* El subárbol no aumenta su altura */
	}
	else if(t->bal == 0)/* La inserción lo balanceo  */
		flag = 0; /* El subárbol no aumenta su altura */
	else /* Quedó desbalanceado con -1 ó +1  */
		flag = 1; /* Propaga ascendentemente la necesidad de rebalancear */
	return t;
}
/*
 * 1965  C. C. Foster
 */
tree delet(typekey k, tree t)
{
	key = k;
	t = deleteR(t);
	if (flag == 1) avl_height--;
	return t;
}

tree deleteR(tree t)
{
	tree p;
	char * temp;

	if(t == NULL) { /* No encontró nodo a descartar */
		Error(0);
		flag = 0;
	}
	else if(t->k < key) {
		//Comienza el descenso por la derecha
		t->right = deleteR(t->right);
		//aqui se llega en el retorno ascendente.
		t->bal -= flag; /* Se descartó por la derecha. Disminuye factor */
		//Se retorna despues de la revision de los factores
	}
	else if (t->k > key) {
		//Desciende por la izquierda
		t->left = deleteR(t->left);
		//o se llega por esta via si se descarto por la izquierda.
		t->bal += flag; /* se descartó por la izq. Aumenta factor de balance */
	}
	else { /* (t->k == key) */
 		/* Encontró el nodo a descartar */
		if (t->left == NULL) {  /*Si hay hijo derecho debe ser hoja, por ser AVL */
			p = t;
			t = t->right;
			freeNode(p);
			flag = 1; /* Debe seguir revisando factores de balance */
			return t; /* ascendentemente */
		}
		else if (t->right == NULL) {  /*Si hay hijo izquierdo debe ser hoja */
			p = t;
			t = t->left;
			freeNode(p);
			flag = 1; /* Asciende revisando factores de balance */
			return t; /* Corrigiendo */
		} else {	/* Tiene dos hijos */
			if(t->bal<0) {
				/* Si cargado a la izquierda, elimina mayor descendiente hijo izq */
				p = t->left;
				while (p->right != NULL) p = p->right;
				t->k = p->k;
				temp = t->v; //si hay string, lo salva
				t->v = p->v;
				p->v = temp;  //le pega string al que debe eliminarse
				key = p->k;   //busca hoja a eliminar
				t->left = deleteR(t->left);
				t->bal += flag; /* incrementa factor de balance  */
			} else {
				/* Si cargado a la derecha, elimina menor descendiente hijo der */
				p = t->right;
				while (p->left != NULL) p = p->left;
				t->k = p->k;
				temp = t->v;
				t->v = p->v;
				p->v = temp;
				key = p->k;
				t->right = deleteR(t->right);
				t->bal -= flag; /* decrementa balance */
			}
		}
	}

 	if (flag == 0 ) /* No hay que rebalancear. Sigue el ascenso, sin rebalancear */
		return t;
	/* Hay que revisar factores de balance en el ascenso*/
	if(t->bal < -1) {
		/* Si quedo desbalanceado por la izquierda y dejó de ser AVL */
		if(t->left->bal > 0) {
			/* Si el hijo izquierdo está cargado a la derecha */
			t->left = lrot(t->left);
			flag = 1;
		}
		else if (t->left->bal == 0)
			flag = 0;   /*No debe seguir el rebalance  */
   		else
			flag = 1;/* Debe seguir revisando factores de balance */
		t = rrot(t);
  	}
	else if(t->bal > 1) {
		/* Si quedo desbalaceado por la derecha */
		if(t->right->bal < 0) {
			/* Si hijo derecho está cargado a la izquierda */
			t->right = rrot(t->right);
			flag = 1; //debe seguir revisando. Caso d.
		}
		else if (t->right->bal == 0)
			flag = 0;   /* No debe seguir el rebalance. Caso c.  */
   		else  //positivo
			flag = 1;/* Debe seguir revisando factores de balance. Caso e. */
		t = lrot(t);
	}
	else if (t->bal == 0) /* Si estaba en +1 ó -1 y queda en cero */
		flag = 1; /* Debe seguir corrigiendo. Caso b.*/
	else /* Si estaba en cero y queda en -1 ó +1  */
		flag = 0; /* No debe seguir rebalanceando. Caso a.*/
	return t;
}

/* Rotación Izquierda
 *
 *            A              B
 *           / \            / \
 *          a   B    ==>   A   c
 *             / \        / \
 *            b   c      a   b
 * Sólo cambian los factores de balance de los nodos A y B
 * Los factores de balance de los sub-árboles no cambian.
 */
static tree lrot(tree t)
{
	tree temp;
	int x,y;

	temp = t;
	t = t->right;
	temp->right = t->left;
	t->left = temp;
	//Recalcula factores de balance de los dos nodos
	x = temp->bal;  // oldbal(A)
	y = t->bal;     // oldbal(B)

	/*  A  tiene factor de balance x, B tiene factor de balance y. Antes de lrot
	 *  Sean a, b y c los altos de los subárboles, que no cambian.
	 *  Entonces: y = c-b  y si (b>c) se tiene x= b+1-a o x= c+1-a(si c>b. Este es el caso que se corrige)
	 *  Nuevo factor de A: nA= b-a. Nuevo factor de B: nB= c-1-a (con a>b) o nB=c-1-b = y-1 si b>a.
	 *  nA=x-1-0 para (b>c) ó nA=x-1-y (para c>b) Esto implica nA=x-1-max(y,0)
	 *  Para a>b: nB=x-2+y si b>c o nB=x-2+0 con c>b, que es el caso que se corrige.
	 *  Estos dos casos se resumen en: nB=x-2-min(y,0)
	 *  Finalmente:
	 *  nA = x-1-max(y,0);
	 *  nB = c-(max(a,b)+1) => min(c-a-1,c-b-1)  => min(x-2+min(y,0),y-1)
	 */
	temp->bal = x-1-max(y, 0);          // newbal(A) = oldbal(A) -1 -max(oldbal(B),0)
	t->bal = min(x-2+min(y, 0), y-1);   // newbal(B) = min( oldbal(A)-2+min(oldbal(B),0 )), oldbal(B)-1)
	return t;
}
/* Rotación derecha
 *
 *            A              B
 *           / \            / \
 *          B   c    ==>   a   A
 *         / \                / \
 *        a   b              b   c
 *
 */
static tree rrot(tree t)
{
	tree temp;
	int x,y;
	temp = t;
	t = t->left;
	temp->left = t->right;
	t->right = temp;
	x = temp->bal;
	y = t->bal;
	/* x=c-1-a ó x=c-1-b.   y = b-a
	 * nA = c-b.  nB =c+1-a ó nB=b+1-a
         * nA= x+1-y o nA=x+1-0
	 * nA = x+1-min(y,0)
	 * nB = max(b,c)+1-a => max(b-a+1,c-a+1)
	 *     => max(y+1,x+2+max(y,0))
	 */
	temp->bal = x+1-min(y, 0);
	t->bal = max(x+2+max(y, 0), y+1);
	return t;
}

static void Error(int tipo)
{
	if (tipo) printf("\nError en inserción\n");
	else printf("\nError en descarte\n");
}
static node* newNode(void)
{
	node* p;
	if (pool != NULL) {
		p = pool;
		pool = pool->right;
		pool_num--;
	}
	else
		p=(node*)malloc(sizeof(node));
	p->v=NULL;
	return p;
}
static void freeNode(node * p)
{

	if (p->v != NULL) free(p->v);  //borra string
	if (pool_num < POOL_SIZE) {
		p->right = pool;
		pool = p;
		pool_num++;
	}
	else
		free(p);
}

int height(tree t)
{
	return avl_height;
}


//Cuenta los nodos del árbol.
int count(tree t)
{
	if (t == NULL) return 0;
	return 1+count(t->left)+count(t->right);
}

tree deltree(tree t) 	//borra el árbol completo
{
	avl_height = 0;
	return deltreeR(t);
}

tree deltreeR(tree t)
{
	if (t != NULL) {
		t->left = deltreeR(t->left);
		t->right = deltreeR(t->right);
		freeNode(t);  //borra la raíz
	}
	return NULL;
}
/* end of avl.c */

//Test rutinas avl
static tree avlraiz = NULL;  /* Raíz  */

#define nnodos 5
int Arr[nnodos]={1, 3, 5, 6, 7};
void poblararbol(void)
{
  int j;
  for(j=0;j<nnodos;j++) avlraiz=insert(Arr[j], avlraiz);
}

void inorder(tree T, int depth)
{
  if (T != NULL) {
    inorder(T->left,depth+1);
    printf ("v= %d h=%d bal=%d \n", T->k,depth,T->bal);
    inorder(T->right,depth+1);
  }
}

void main(void)
{
poblararbol();
inorder(avlraiz,0);
printf(" altura = %d \n", height(avlraiz));
printf(" nodos  = %d \n", count(avlraiz));



}
