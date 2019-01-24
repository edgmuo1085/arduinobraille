/*
  Project: ChatBraille CB
  Autor: Edgar Muñoz - German Mora
  Archivo: ChatBraille_lang.h CB_LANG
  Fecha Creación: 2 de Junio de 2016
  Fecha última modificación: 28 de Octubre de 2018
  Libreria ChatBraille - Gestión del alfabeto
*/
//Metodo Teclado Espanol
void CB_Process::alfabeto_es(void)
{
  nuevo_nodo("1", 'a');
  nuevo_nodo("12", 'b');
  nuevo_nodo("14", 'c');
  nuevo_nodo("145", 'd');
  nuevo_nodo("15", 'e');
  nuevo_nodo("124", 'f');
  nuevo_nodo("1245", 'g');
  nuevo_nodo("125", 'h');
  nuevo_nodo("24", 'i');
  nuevo_nodo("245", 'j');
  nuevo_nodo("13", 'k');
  nuevo_nodo("123", 'l');
  nuevo_nodo("134", 'm');
  nuevo_nodo("1345", 'n');
  nuevo_nodo("135", 'o');
  nuevo_nodo("1234", 'p');
  nuevo_nodo("12345", 'q');
  nuevo_nodo("1235", 'r');
  nuevo_nodo("234", 's');
  nuevo_nodo("2345", 't');
  nuevo_nodo("136", 'u');
  nuevo_nodo("1236", 'v');
  nuevo_nodo("2456", 'w');
  nuevo_nodo("1346", 'x');
  nuevo_nodo("13456", 'y');
  nuevo_nodo("1356", 'z');
  //nuevo_nodo("12346", 'ç');
  //nuevo_nodo("123456", '\');
  nuevo_nodo("12356", 'á');
  nuevo_nodo("2346", 'é');
  nuevo_nodo("23456", 'ú');
  nuevo_nodo("126", '(');
  nuevo_nodo("12456", 'ñ');
  nuevo_nodo("2", ',');
  nuevo_nodo("23", ';');
  nuevo_nodo("25", ':');
  nuevo_nodo("256", '/');
  nuevo_nodo("26", '?');
  nuevo_nodo("235", '!');
  nuevo_nodo("2356", '=');
  nuevo_nodo("236", '"');
  nuevo_nodo("35", '*');
  nuevo_nodo("34", 'í');
  nuevo_nodo("345", ')');
  nuevo_nodo("3456", '#'); //Generador de Números
  nuevo_nodo("346", 'ó');
  nuevo_nodo("36", '-');
  nuevo_nodo("3", '.');
}
//Metodo Teclado Ingles
void CB_Process::alfabeto_en(void)
{
  nuevo_nodo("1", 'a');
}
