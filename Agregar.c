#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Este es el struct que agrupa los tipos de datos de la lista,.
typedef struct nodo_s
{
	char username [20];
	char ip [20];
	char puerto [20];
	struct nodo_s *siguiente;
} nodo_t;
 
typedef nodo_t *ptrNodo; // Se define ptrNodo como un puntero al struct anterior
typedef nodo_t *ptrLista;// Se define ptrLista como un puntero al struct anterior
 

 // Crea un nodo y devuelve un puntero hacia el nodo recien creado
ptrNodo crea_nodo(char user[20], char Ip [20], char puer [20])
{
 ptrNodo nuevo_nodo = (ptrNodo)malloc(sizeof(nodo_t)); //Se le asigna memoria al nuevo nodo del tamaño suficiente para almacenar los datos de nodo_ que es de tipo struct
 if (nuevo_nodo != NULL)
    {
		// Se usa strcpy porque los datos son cadenas de caracteres
     strcpy(nuevo_nodo->username, user); // Copia el parametro user en el campo username del nodo
     strcpy(nuevo_nodo->ip, Ip);
     strcpy(nuevo_nodo->puerto, puer);
     nuevo_nodo->siguiente = NULL;//El punto siguiente apunta a nulo
    }
 
 return nuevo_nodo;
}
 
/*
Agrega a la lista que recibe como parámetro, un nodo enseguida del nodo que recibe como parámetro
Si el nodo que recibe como parámetro es NULL, significa que se desea insertar el nodo al inicio de la lista
*/
void inserta_despues(ptrLista *lista, ptrNodo nodo, char user [20],char Ip [20],char puer [20])
{
 ptrNodo nuevo_nodo = crea_nodo(user, Ip, puer);
 
 if (nodo != NULL)
    {
     /* El apuntador nuevo_nodo->siguiente va a apuntar a la misma dirección a donde apunta
        el apuntador "siguiente" del nodo que recibe como parámetro
     */
     nuevo_nodo->siguiente = nodo->siguiente;
     /* El apuntador "siguiente" del nodo que recibe como parámetro va a apuntar al nodo recien creado
        con esto, el nodo recien creado se ha insertado adelante del nodo que se recibe como parámetro
     */
     nodo->siguiente = nuevo_nodo;
    }
 else
    {
     // Si la lista no está vacía, hace que el apuntador "siguiente" del nuevo nodo apunte al primer elemento de la lista
     if (*lista != NULL)
         nuevo_nodo->siguiente = *lista;
     // Hace que la lista apunte hacia el nuevo nodo para que sea el primer nodo de la lista
     *lista = nuevo_nodo;
    }
}
 

/*
  Regresa 1 si no hay nodos en la lista ligada y cero en caso contrario
  *lista es el apuntador que apunta a la lista ligada
*/
char lista_vacia(ptrLista *lista)
{
 return (*lista == NULL ? 1:0);
}
 
/*
  Muestra los datos de los nodos
*/
void nodos_lista(ptrNodo nodo)
{
 if (nodo == NULL)
     printf("La lista está vacia\n");
 else
     {
      while (nodo != NULL)
            {
             printf("%s %s %s",nodo->username,nodo->ip,nodo->puerto);
             nodo = nodo->siguiente;
             if (nodo != NULL)
                 printf(" -> ");
            }
      printf("\n");
     }
}



int AgregarAmigos (){
	FILE * fp;
	char opcion [2];
	fp = fopen ("Amigos.txt", "a");
	printf ("\n¿Desea agregar un amigo?\n");
	printf ("\nDigite S o N tal y como se muestra \n");
	scanf ("%s", opcion);
	if ((opcion[0]=='S')|| (opcion[0]=='s')){
	    char username [15];
		char ip [15];
		char puerto [15];
		printf("Ingrese el username: ");
		scanf("%s",username);
		printf("\nIngrese la IP: ");
		scanf("%s", ip);
		printf("\nIngrese el puerto: ");
		scanf("%s",puerto);
		fprintf(fp,"%s%s%s%s%s\n",username,";",ip,";",puerto);	
		printf("%s",username);	
		printf("\nAmigo agregado =D\n");
		AgregarAmigos ();
		fclose(fp);  
	}
	else{
		if (opcion[0]=='N' || opcion[0]=='n')
			printf("\nGracias");
		else{
			printf ("\nPor favor digite unicamente S o N ");
			AgregarAmigos ();
		}
	}
	return(0);
}


void leerarchivo(){
struct DatosPersona {
	char nombre[15];
	char apellido[15];
	char telefono [10];
	};
	
struct DatosPersona registro;
FILE* Archivo;
char cadena[150];
char* cpToken;

nodo_t *nuevo=NULL;
Archivo = fopen ("Amigos.txt", "r");
 
while (fscanf (Archivo, "%s", cadena) != EOF) {
cpToken = strtok (cadena,";");
// obtiene el primer campo del registro y lo guarda en cpToken
strcpy (registro.nombre, cpToken);
// supuse que el primero será el nombre
printf("%s ",registro.nombre);
cpToken = strtok (NULL, ";");
strcpy (registro.apellido, cpToken);
//obtiene el segundo campo... apellido
printf("%s ",registro.apellido);
cpToken = strtok (NULL, ";");
strcpy (registro.telefono, cpToken);
printf ("%s \n",registro.telefono);
inserta_despues(&nuevo,nuevo,registro.nombre,registro.apellido,registro.telefono);
}// sigue leyendo el archivo hasta que llegue al fin

fclose (Archivo); // cierra el archivo
printf("Esta es la lista de amigos:\n\n");
nodos_lista(nuevo);
}

int main ()
{
	//AgregarAmigos();
	leerarchivo();
	//nodo_t *nuevo=crea_nodo("a","b","c");
	//inserta_despues(&nuevo,nuevo,"eliz","56379.09","563646hj");
	//nodos_lista(nuevo);
	return 0;
}
