/*
   Project: ChatBraille CB
   Autor: Edgar Muñoz - German Mora
   Archivo: ChatBraille_key_process.h CB_PROCESS
   Fecha Creación: 2 de Junio de 2016
   Fecha última modificación: 7 de Julio de 2016
   Libreria ChatBraille - Conversor Braille a alfabeto natural
*/
class CB_Process
{
  public:
    // Destructor
    ~CB_Process();
    // Constructor
    CB_Process();
    // insertar nuevo elemento
    void nuevo_nodo(char*, char);
    // Tamano de nodos
    inline int size();
    //Eliminamos lista
    void vaciar();
    //ordenacion de caracteres
    char* ordenar_caracteres(char*);
    //Buscar caracter
    char buscar_caracter(char*);
    //Imprimir alfabeto
    void imprimir_alfabeto(void);
    //Crear Alfabeto
    void crear_alfabeto(int);
  private:
    //Alfabeto Espanol
    void alfabeto_es(void);
    //alfabeto Ingles
    void alfabeto_en(void);
    struct Balfabeto
    {
      //String braille;
      char* braille;
      char caracter;
      Balfabeto *sig;
    };
    Balfabeto *head;//Pointer Head
    Balfabeto *tail;// Pointer tail
    int sz;           // List size
};
//Metodo Constructor
CB_Process::CB_Process()
{
  head = NULL;
  tail = NULL;
  sz = 0;
}
//Metodo destructor
CB_Process::~CB_Process()
{
  vaciar();// Clears the list before destroying
}
inline int CB_Process::size()
{
  return sz;
}
//Metodo limpiar nodos
void CB_Process::vaciar()
{
  Balfabeto *p;
  p = head;
  while (p != NULL) //Borramos nodos
  {
    head = head->sig;
    free(p);
    p = head;
  }
  // Restore variable stats
  tail = NULL;
  head = NULL;
  sz = 0;
}
//Metodo para crear un nuevo nodo
void CB_Process::nuevo_nodo(char* braille, char caracter)
{
  Balfabeto *nuevo;
  // Reserve memory for a new node
  nuevo = (Balfabeto*)malloc(sizeof(Balfabeto));
  if (nuevo == NULL)
  {
    //No hay memoria
    Serial.print("CBPROCESS::Memoria insuficiente");
    return ;
  }
  nuevo->sig = NULL;
  nuevo->braille = braille;
  nuevo->caracter = caracter;
  if (head == NULL)
  {
    head = nuevo;
    tail = nuevo;
  }
  else
  {
    tail->sig = nuevo;
    tail = nuevo;
  }
  sz++;
}
//Metodo para crear un nuevo nodo
char CB_Process::buscar_caracter(char* braille)
{
  //Realizar ordenacion de caracteres
  braille = ordenar_caracteres(braille);
  Balfabeto *p;
  //Nos ubicamos en el primer nodo de la lista
  p = head;
  while (p != NULL) //recorremos la lista
  {
    if (strcmp(p->braille , braille) == 0)
      break;
    p = p->sig;
  };
  if (p == NULL) //No existe
    return '_';
  else
    return p->caracter;
}
//Metodo para ordenar caracteres a consultar
char* CB_Process::ordenar_caracteres(char* cadena)
{
  char* braille_gen;
  char car;
  braille_gen = cadena;
  int fin = strlen(cadena);
  for (int i = 0; i < fin - 1; i++)
  {
    for (int j = i + 1; j < fin; j++)
    {
      if (braille_gen[i] > braille_gen[j])
      {
        car = braille_gen[i];
        braille_gen[i] = braille_gen[j];
        braille_gen[j] = car;
      }
    }
  }
  return braille_gen;
}
//Metodo para imprimir el alfabeto
void CB_Process::imprimir_alfabeto(void)
{
  if (head == NULL)
    Serial.print("No existe alfabeto.");
  else
  {
    Serial.println("Alfabeto");
    Balfabeto *p;
    //Nos ubicamos en el primer nodo de la lista
    p = head;
    while (p != NULL) //Recorremos la lista
    {
      Serial.print(p->caracter); Serial.print(": ["); Serial.print(p->braille); Serial.println("] ");
      p = p->sig;
    }
  }
}

//Metodo para crear el alfabeto
void CB_Process::crear_alfabeto(int tipo)
{
  //Tipo alfabeto
  //0 español
  vaciar();
  switch (tipo)
  {
    case 0: alfabeto_es(); break; //Español
    case 1: alfabeto_en(); break; //ingles
    default: alfabeto_es(); break;
  }
}
