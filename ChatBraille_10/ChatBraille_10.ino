/*
   Project: ChatBraille CB
   Autor: Edgar Muñoz - German Mora
   Archivo: ChatBraille.ino CB_CORE
   Fecha Creación: 20 de Mayo de 2016
   Fecha última modificación: 4 de Noviembre de 2018
   ChatBraille - Core
   Versión: 0.10
*/
//Librerias
#include <Keypad.h>
#include <SoftwareSerial.h>
#include "lib/ChatBraille_key_process.h"
#include "lib/ChatBraille_Text.h"
#include "lib/ChatBraille_lang.h"

//Configuraciones basicas ChatBraile
#define CBteclado 0 //Idioma CBteclado // 0-> Es, 1-> En
//CONFIGURACION BOARD, ARDUINO
const byte filas = 4;
const byte columnas = 3;
// Se define los simbolos sobre los botones del keypad
char teclas[filas][columnas] = {
  {'1', '4', 'E'},
  {'2', '5', 'D'},
  {'3', '6', 'S'},
  {'*', '0', '#'}
};//E Enter D delete S send
byte pinesfilas[filas] = {6, 5, 4, 3}; //conectar las filas pines de salida del keypad
byte pinescols[columnas] = {9, 8, 7}; //conectar las columnas pines de salida del keypad
Keypad teclado = Keypad( makeKeymap(teclas), pinesfilas, pinescols, filas, columnas);

//Variables ChatBraille
SoftwareSerial CB_Send(1, 2); // TX | RX
String Btecla = ""; //Letra Braille
String enviar_texto = " "; //Enviar texto
//Alfabeto Chat Braille
CB_Process alfabeto;
CB_Text textos;
//CB_Comunication comun;
void setup()
{
  Serial.begin(115200);
  CB_Send.begin(115200);
  //Creamos alfabeto
  alfabeto.crear_alfabeto(CBteclado);
  //alfabeto.imprimir_alfabeto();
  //Serial.print("Nodos: ");Serial.print(alfabeto.size());
  vaciar_Btecla();

}

void loop()
{

  char tecla = teclado.getKey(); //se guarda en la variable customKey el caracter de la tecla presionada
  if (tecla != NO_KEY)         //se evalúa si se presionó una tecla
  {
    //Serial.print(tecla);
    switch (tecla)
    {
      case 'E'://Enter
        char car;
        //Codigo para generar caracter
        char bt[6];
        Btecla.toCharArray(bt, 6);
        car = alfabeto.buscar_caracter(bt);
        textos.adicionar_caracter(car);
        //Serial.print(car);
        //Limpiar Btecla
        vaciar_Btecla();
        break;
      case 'D'://Delete
        //borrar
        //Serial.println("");
        //alfabeto.imprimir_alfabeto();
        textos.quitar_caracter();
        break;
      case 'S'://Send
        //enviar texto
        enviar_texto = textos.texto();
        //CB_NodeMCU.print(enviar_texto);
        //CB_NodeMCU.print("\n 1");
        Serial.print(enviar_texto);
        Serial.print("\n"); //es importante colocar un \n al final de lo que se quiere mandar ya que en el nodem se indica el final
        textos.vaciar();
        break;
      case '*'://Nothing
        textos.vaciar();
        break;
      case '0'://Nothing
        break;
      case '#'://Nothing
        break;
      default:
        //Almacenamos la tecla digitada por el usuario
        //Solo se almacenan las teclas del 1 - 6
        //Permitir concatenar caracteres sin que se repitan
        if (Btecla.indexOf(tecla) == -1) //Tecla no existe y la almacena
          Btecla = Btecla + tecla;
        break;
    }
  }
}

//Funcion vaciado Btecla
void vaciar_Btecla()
{
  Btecla = "";
}
