#include "usuario.hpp"
#include <cstdlib>
const char* CrB = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890";

//Constructor
Usuario::Usuario(Cadena& id,Cadena&name,Cadena&SName,Cadena&dir,char* key):iden_(id),nombre_(name),apellido_(SName),direccion_(dir),clave_(key){}

//Metodos observadores
Cadena& Usuario::id()const{return iden_;}
Cadena& Usuario::nombre()const{return nombre_;}
Cadena& Usuario::apellidos()const{return apellido_;}
Cadena& Usuario::direccion()const{return direccion_;}





//Construcor de clave cifrada
Clave::Clave(const char* password){
	char CBaux[2];
	for(int i=0;i<2;i++){
		CBaux[i] = CrB[rand()%strlen(CrB)];
	}
	claveC_=crypt(password,CBaux);
}

//Metodo obervador
char* Clave::clave()const{return claveC_;}


