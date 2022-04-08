#ifndef __USER__
#define __USER__
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<unistd.h>
#include"articulo.hpp"
#include"tarjeta.hpp"
#include"fecha.hpp"
#include"cadena.hpp"
class Tarjeta;
class Clave;
class Usuario{
	public:
		Usuario(Cadena&,Cadena&,Cadena&,Cadena&,char*);
		Cadena&id()const;
		Cadena&nombre()const;
		Cadena&apellidos()const;
		Cadena&direccion()const;
	private:
		static std::unordered_set<Cadena>UserLooser;
		std::unordered_map<Articulo*, unsigned int> Articulos;
		std::map<Numero, Tarjeta*> Tarjetas;
		Cadena& iden_;
		Cadena& nombre_;
		Cadena& apellido_;
		Cadena& direccion_;
		const Clave& clave_;
};



//Subclase Clave
class Clave{
	public:
		enum Razon{CORTA,ERROR_CRYPT};
		Clave(const char*);
		char* clave()const;
		bool verifica(const char*);
		
		
		class Incorrecta{
			public:
				Razon razon()const;
			private:
				Razon causa;
		};
	private:
		static const char* CrB;
		char*claveC_;
};
