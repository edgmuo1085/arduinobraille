/*
   Project: ChatBraille CB
   Autor: Edgar Muñoz - German Mora
   Archivo: ChatBraille_Text.h CB_TEXT
   Fecha Creación: 8 de Julio de 2016
   Fecha última modificación: 8 de Julio de 2016
   Libreria ChatBraille - Editor de texto
*/

//ChatBraille_Text
//crear estructura para almacenar los caracteres digitados
//Tipo de estructura Pila LiFo Last In Firts Out
//Doblemente enlazada con cabeza y fin
//Metodo Crear nuevo nodo, Enviar(), Eliminar caracteres

class CB_Text
{
  public:
    // Destructor
    ~CB_Text();
    // Constructor
    CB_Text();
    // insertar nuevo elemento
    void adicionar_caracter(char);
    // quitar elemento de la pila
    void quitar_caracter();
    // Texto a generar
    String texto();
    // Tamano de nodos
    inline int size();
    //Eliminamos lista
    void vaciar();
  private:
    struct BText
    {
      char caracter;
      BText *sig, *ant;
    };
    BText *head; //Pointer Head
    BText *tail; // Pointer tail
    int sz; // List size
};
//Metodo Constructor
CB_Text::CB_Text()
{
  head = NULL;
  tail = NULL;
  sz = 0;
}
//Metodo destructor
CB_Text::~CB_Text()
{
  vaciar();// Clears the list before destroying
}
inline int CB_Text::size()
{
  return sz;
}
//Metodo limpiar nodos
void CB_Text::vaciar()
{
  BText *p;
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
void CB_Text::adicionar_caracter(char caracter)
{
  BText *nuevo;
  // Reserve memory for a new node
  nuevo = (BText*)malloc(sizeof(BText));
  if (nuevo == NULL)
  {
    //No hay memoria
    Serial.println("CBTEXT::Memoria insuficiente");
    return ;
  }
  nuevo->sig = NULL;
  nuevo->ant = NULL;
  nuevo->caracter = caracter;
  if (head == NULL)
  {
    head = nuevo;
    tail = nuevo;
  }
  else
  {
    tail->sig = nuevo;
    nuevo->ant = tail;
    tail = nuevo;
  }
  sz++;
}
//Metodo para generar el texto creado
String CB_Text::texto()
{
  String texto = "";
  if (head == NULL)
    Serial.println("CBTEXT::No existe texto.");
  else
  {
    BText *p;
    //Nos ubicamos en el primer nodo de la lista
    p = head;
    while (p != NULL) //Recorremos la lista
    {
      texto = texto + p->caracter;
      p = p->sig;
    }
  }
  return texto;
}
//Metodo para quitar un elemento
void CB_Text::quitar_caracter()
{
  if (head == NULL)
    Serial.println("CBTEXT::No existe texto.");
  else
  {
    BText *p;
    //Nos ubicamos al final de la lista
    p = tail;
    tail = p->ant;
    tail->sig = NULL;
    free(p);
  }
}
