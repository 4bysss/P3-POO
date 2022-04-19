#include "usuario.hpp"
#include <cstdlib>
const char* CrB = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890";

//Constructor
Usuario::Usuario(const Cadena& id,const Cadena&name,const Cadena&SName,const Cadena&dir,const Clave&key):iden_(id),nombre_(name),apellido_(SName),direccion_(dir),clave_(key){
	if(UserLooser.insert(id).second == false){
		throw Id_duplicado("Id no valida");
	}
	else{
		UserLooser.insert(id);
	}
}

//Metodos observadores
const Cadena& Usuario::id()const{return iden_;}
const Cadena& Usuario::nombre()const{return nombre_;}
const Cadena& Usuario::apellidos()const{return apellido_;}
const Cadena& Usuario::direccion()const{return direccion_;}
Articulos Usuario::compra()const{return Artis;}
Tarjetas Usuario::tarjetas()const{return Tarjs;}


void Usuario::es_titular_de(Tarjeta&Tr)const{
	Tarjeta*T=&Tr;
	Numero N = T->numero();
	Tarjs.insert(std::pair<Numero,Tarjeta*>(N,T));
}

void Usuario::no_es_titular_de(Tarjeta&Tr)const{
	Tarjeta*T=&Tr;
	Numero N = T->numero();
	Tarjs.erase(N);
}
void Usuario::compra(Articulo& Ar,int cant)const{
	Articulo*A=&Ar;
	if (cant==0){
		Artis.erase(A);
	}
	else{
		Artis.insert(std::pair<Articulo*,unsigned int>(A,cant));
	}
}
std::ostream& operator<<(std::ostream&on,const Usuario&sus){
	on<<sus.iden_<<" ["<<sus.clave_.clave()<<']'<<sus.nombre_<<sus.apellido_<<'\n'<<"Tarjetas:\n";
	for(auto it = sus.Tarjs.begin();it!=sus.Tarjs.end();++it){
		on<<it->second;
	}
	return on;
}
int Usuario::n_articulos()const{
	int i = 0;
	for(auto it = Artis.begin();it!=Artis.end();++it){++i;}
	return i;
}
std::ostream& mostrar_carro(std::ostream&on,Usuario&sus){
	on<<"Carrito de la compra de "<<sus.iden_<<"[Articulos "<<sus.n_articulos()<<"]\n";
	for(auto it = sus.Artis.begin();it!=sus.Artis.end();++it){
		on<<it->second<<" "<<it->first;
	}
	return on;
}
Usuario::~Usuario(){
	for(auto it=Tarjs.begin();it!=Tarjs.end();++it){
		Tarjs.erase(it);
		it->second->anular_titular();
		it->second->activa(false);
	}
}
//Construcor de clave cifrada
Clave::Clave(const char* password):claveC_(password){}
//Metodo verifica
bool Clave::verifica(const char* aux){ return strcmp(aux,claveC_)==0;}
//Metodo obervador
char* Clave::clave()const{
	char CBaux[2];
	for(int i=0;i<2;i++){
		CBaux[i] = CrB[rand()%strlen(CrB)];
	}
	return crypt(claveC_,CBaux);
}


