#ifndef __50CENTS__
#define __50CENTS__
#include"usuario.hpp"
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<ctype.h>
#include"articulo.hpp"
#include"fecha.hpp"
#include"cadena.hpp"

class Usuario;
class Numero;
static const char* enum_name[]={ "Otro", "VISA", "Mastercard", "Maestro", "JCB", "AmericanExpress"};
class Tarjeta{
	public:
		enum Tipo{Otro,VISA,Mastercard,Maestro,JCB,AmericanExpress};
		Tarjeta(Numero& num,Usuario*,Fecha&);
		Tarjeta(Tarjeta&) = delete;
		Tarjeta& operator=(Tarjeta&) = delete;
		Tipo tipo()const;
		const Numero& numero()const { return num;};
		const Usuario* titular()const{ return titu;};
		const Fecha& caducidad()const{ return cadu;};
		const bool activa()const {return acti;};
		bool activa(bool t=true);
		void anular_titular();
		friend bool operator<(const Tarjeta&,const Tarjeta&);

		//Clase excepcion para tarjetas caducadas
		class Caducada{
			public:
				
				Caducada(Fecha&fech):cuand(fech){};
				Fecha& cuando(){return cuand;};
			private:
				Fecha& cuand;
		};
		//Clase excepcion para tarjetas duplicadas
		class Num_duplicado{
			public:
				Num_duplicado(Numero& n):dup(n){};
				Numero&que();
			private:
				Numero&dup;
		};
		class Desactivada{};

	private:
		const Numero& num;
		const Usuario* titu;
		const Fecha& cadu;
		bool acti;
};

//Subclase Numero 

class Numero{
	public:
		explicit Numero(Cadena&);
		enum Razon{LONGITUD,DIGITOS,NO_VALIDO};
		operator const char*() const;
		friend bool operator<(const Numero&,const Numero&);
		class Incorrecto{
			public:
				Incorrecto(Numero::Razon r);
				Numero::Razon& razon();
			private:
				Numero::Razon raz;
		};
	private:
		Cadena& troq;
};


//Metodos externos de Numero 
bool operator<(const Numero&,const Numero&);


//Metodos externos de Tarjeta 
bool operator<(const Tarjeta&,const Tarjeta&);
std::ostream& operator<<(std::ostream&,Tarjeta&);
#endif
