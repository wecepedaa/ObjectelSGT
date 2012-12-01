//============================================================================
// Name        : RutinasArbolesBinarios.cpp
// Author      : William Cepeda
// Version     :
// Copyright   : Docencia UNACH
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <stdio.h>
#include <stdlib.h>
using namespace std;
typedef struct tnode
  {
    int valor;
    struct tnode *left;
    struct tnode *right;
  } nodo, * pnodo;

pnodo getnodo(int dato)
{
  pnodo pi=NULL;
  if ( (pi= (pnodo) malloc(sizeof(nodo))) ==NULL) exit(1);
  else
   {
      pi->valor=dato;pi->left=NULL;pi->right=NULL;
   }
   return(pi);
}

void prtinorder(pnodo p)
{
   if (p!= NULL)
   {
     prtinorder(p->left);
     printf ("%d \n", p->valor);
     prtinorder(p->right);
   }
}
void inorder(pnodo T, int nivel)
{
  if (T != NULL) {
    inorder(T->left,nivel+1);
    printf ("%d %d \n", T->valor,nivel);
    inorder(T->right,nivel+1);
   }
}

void prtpreorder(pnodo p)
{
   if (p!= NULL)
   {
     printf ("%d \n", p->valor);
     prtpreorder(p->left);
     prtpreorder(p->right);
   }
}

void prtpostorder(pnodo p)
{
   if (p!= NULL)
   {
     prtpostorder(p->left);
     prtpostorder(p->right);
     printf ("%d \n", p->valor);
   }
}

pnodo buscar(int x, pnodo t )
{
   if ( t == NULL) return (NULL); /* no está */
   else {
          if ( t->valor == x ) return(t); /* lo encontró */
          else {
                if ( t->valor > x ) t = buscar( x, t->left);
                else t = buscar( x, t->right);
               }
        }
   return ( t ); /* ! */
}

pnodo buscar_nr(int x, pnodo t) /* algoritmo iterativo */
{
   while ( t != NULL)
   {
      if ( t->valor == x ) return (t);
      else {
             if (t->valor < x) t = t->right;
             else t = t->left;
           }
   }
   return (t); /* NULL No lo encontró*/
}

pnodo insert(int x, pnodo T)  /* recursivo */
{
  if (T == NULL) {
    T = (pnodo) malloc(sizeof(nodo));
    if (T == NULL) printf("Rebalse del heap!\n");
    else {
      T->valor = x;
      T->left = T->right = NULL;
    }
  }
  else
    if (x < T->valor)
      T->left = insert(x,T->left);
    else
      if (x > T->valor)
       T->right = insert(x,T->right);
       /* else x ya estaba en el árbol. No hace nada. */
  return(T);
}


pnodo insert_nr(int x, pnodo t)  /*iterativo */
{
  while ( t != NULL)
   {
      if ( t->valor == x ) {/*lo encontró, no inserta.*/ return (t);}
      else {
             if (t->valor < x) t = t->right;
             else t = t->left;
           }
   }
   /*Al salir del while  t apunta al sitio a insertar */
   t = (pnodo) malloc(sizeof(nodo));
   if (t == NULL) printf("Rebalse del heap!\n");
   else {
      t->valor = x;
      t->left = t->right = NULL;
    }
   return (t); /* Apunta al recién insertado. Null si no se pudo insertar*/
}

pnodo busca_min(pnodo T) {  /* Algoritmo recursivo. Siempre por la izquierda */
  if (T == NULL)
    return(NULL);
  else
    if (T->left == NULL)
       return(T);
    else
      return(busca_min(T->left));
}

pnodo buscar_min_nr(pnodo t) /* algoritmo iterativo */
{
   while ( t != NULL)
   {
      if ( t->left == NULL ) return (t);
      else  t=t->left;
   }
   return (t); /* NULL Si árbol vacío*/
}

pnodo busca_max(pnodo T) {  /* Iterativo. Siempre por la derecha */
  if (T != NULL)
    while (T->right != NULL)
      T = T->right;
  return(T);
}

pnodo delet(int x, pnodo T)
{
  pnodo temp;
  if (T == NULL) printf("Elemento no encontrado\n");
  else
    if (x < T->valor) /* por la izquierda */
      T->left = delet(x,T->left);
    else
       if (x > T->valor) /* por la derecha */
          T->right = delet(x,T->right);
    else /* se encontro el elemento a descartar */
      if (T->left && T->right) /* dos hijos */
      {
         /* reemplázelo con el menor del subárbol derecho */
         temp = busca_min(T->right);
         T->valor = temp->valor;
         T->right = delet(temp->valor,T->right);  /*borrar la hoja  */
      }
      else
         { /* un hijo o ninguno */
           temp = T;
           if (T->left == NULL)  /* sólo hijo derecho o sin hijos */
              T = T->right;
           else
             if (T->right == NULL) /* solamente un hijo izquierdo */
               T = T->left;
           free(temp);  /*libera espacio  */
         }
  return(T);
}

pnodo saca_min_hijo_der_nr(pnodo t)    /* Algoritmo iterativo */
/*menor descendiente de hijo derecho */
{  pnodo p;
   p = t->right;
   if (p->left == NULL)     /* No hay hijo izq. */
     {  t->right = p->right; return (p);}  /*Pega subarbol derecho del menor. Retorna el menor */
   while ( p->left != NULL) {              /* Mientras no tenga hijo izq descender por la izq */
     t = p;
     p = p->left;
    }
    /*Al terminar el while p apunta al menor descendiente */
   t->left = p->right;  /*Pega subárbol derecho del menor*/
   return (p);          /* Retorna el menor */
}

int Profundidad(pnodo t)
{
    int left=0,right = 0;
    //Si arbol vacio, profundidad 0
    if(t==NULL) return 0;
    //calcula profundidad subarbol izq
    if(t->left != NULL) left = Profundidad(t->left);
    //calcula profundidad subarbol der
    if(t->right != NULL)  right = Profundidad(t->right);

    if( left > right)  //si el izq tiene mayor profundidad
        return left+1; //retorna profundidad del subarbol izq + 1
    else
        return right+1; //retorna profundidad del subarbol der + 1
}
int Height(pnodo T)
{
int h, max;
  if (T == NULL)
    return -1;
  else {
    h = Height(T->left);
    max = Height(T->right);
    if (h > max) max = h;
    return(max+1);
  }
}

int NumerodeHojas(pnodo t)
{
    int total = 0;
    //Si arbol vacio, no hay hojas
    if(t==NULL) return 0;
    // Si es hoja, la cuenta
    if(t->left == NULL && t->right == NULL) return 1;
    //cuenta las hojas del subarbol izquierdo
    if(t->left!= NULL) total += NumerodeHojas(t->left);
    //cuenta las hojas del subarbol derecho
    if(t->right!=0) total += NumerodeHojas(t->right); //
    return total; //total de hojas en subarbol
}
//Contar en subárbol apuntado por t los nodos,
//que tengan valores menores o iguales que k.

int countLE(pnodo t, int k)
 {
	if (t == NULL) return 0;
	else
	  if (t->valor < k)
	    { // Si valor menor que k, contarlo y además en ambos subárboles
	     return (1 + countLE(t->left,k) + countLE(t->right,k) );
	     }
	  else
	    if (t->valor == k)
	    {  // Si valor igual a k, contarlo y además sólo en subarbol izq
	       return (1 + countLE(t->left, k));
	    }
	    else
	      { // Si valor mayor que k, contar solo los del subarbol izq. Sin incluirlo
	       return countLE(t->left, k);
	      }
}

pnodo root=NULL;

int main(void)
{
  printf(" hojas = %d \n", NumerodeHojas(root));
  printf(" Profundidad = %d \n", Profundidad(root));
  printf(" Profundidad2 = %d \n", Height(root));
  root=insert(5,root);
  root=insert(6,root);
  root=insert(4,root);
  root=insert(10,root);
  root=insert(1,root);
  prtinorder(root);
  inorder(root, 0);
  prtpreorder(root);
  prtpostorder(root);
  delet(4, root);
  prtinorder(root);
  printf(" hojas = %d \n", NumerodeHojas(root));
  printf(" Profundidad = %d \n", Profundidad(root));
  printf(" Profundidad2 = %d \n", Height(root));
  return 0;
}
