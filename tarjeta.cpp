#include "tarjeta.hpp"
#include "luhn.cpp"
#include <ctime>
time_t t=time(nullptr);
struct tm* conv2=localtime(&t);
char output[20];
//Constructores 
Tarjeta::Tarjeta(const Numero& nume,Usuario& ussr,const Fecha&fecha__):num(nume),cadu(fecha__),acti(true){
	Fecha hoy;
	titu = &ussr;
	if(fecha__<hoy){
		throw Tarjeta::Caducada(fecha__);
	}
	else{
		ussr.es_titular_de(*this);
	}
}



//Metodo tipo
Tarjeta::Tipo Tarjeta::tipo()const{
	if (num[0]==3){
		if(num[1]==4||num[1]==7){
			return AmericanExpress;
		}
		else{
			return JCB;
		}
	}
	else if(num[0]==4){return VISA;}
	else if(num[0]==5){return Mastercard;}
	else if(num[0]==6){return Maestro;}
	else {return Otro;}
}




//Sobrecarga del operador menor que
bool operator<(const Tarjeta&T1, const Tarjeta&T2){
	return T1.num<T2.num;
}



//Operador de extraccion
std::ostream& operator<<(std::ostream&on,const Tarjeta&T){
	setlocale(LC_ALL, "es_ES.UTF-8");
	Fecha fech = T.caducidad();
	conv2->tm_year= fech.anno()- 1900;
	conv2->tm_mon=fech.mes()-1;
	conv2->tm_mday=fech.dia();
	mktime(conv2);
	std::strftime (output,80,"%m/%y" ,conv2);
	on<<enum_name[T.tipo()]<<'\n'<<T.numero()<<'\n'<<T.titular()<<'\n'<<"Caduca: "<<output<<'\n';
	return on;
}




//Metodo de activacion
bool Tarjeta::activa(bool t){
	acti = t;
	return t;
}



//Metodo de anular titular
void Tarjeta::anular_titular(){
	titu=nullptr;
	acti=false;
}


Tarjeta::~Tarjeta(){
	titu->no_es_titular_de(*this);
}
//=========================



//Constructor de numero
Numero::Numero(const Cadena& c){
	char* troquelador=nullptr;
	int j=0;

	for(Cadena::iterator i=c.begin();i<c.end();i++){
		if(*i!=' '){
			if(isdigit(*i)){
				troquelador[j]=*i;
				j++;
			}
			else{
				throw Numero::Incorrecto(DIGITOS);
				
			}
		}
	}
	if(strlen(troquelador)<13||strlen(troquelador)>19){
		throw Numero::Incorrecto(LONGITUD);
	}
	if(!luhn(troquelador)){
		throw Numero::Incorrecto(NO_VALIDO);
	}

	troq= troquelador;
}



//Conversor a cadena a bajo nivel
Numero::operator const char*()const{
	return troq.c_str();
}



//Sobrecarga del operador <
bool operator<(const Numero&a,const Numero&b){
	return a.troq<b.troq;
}
