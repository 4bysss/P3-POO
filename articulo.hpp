#ifndef __ARTI__
#define __ARTI__
#include"articulo.hpp"
#include"cadena.hpp"
#include"fecha.hpp"
#include<iostream>
class Articulo{
	public:
		Articulo(Cadena&ref,Cadena&titu,Fecha&fech,int pr,int c=0 ):CodRef(ref),Titu(titu),FPubli(fech),price(pr),stock_(pr){};
		const Cadena& referencia()const;
		const Cadena& titulo()const;
		const Fecha& f_publi()const;
		int precio()const;
		int stock()const;
	private:
		const Cadena& CodRef;
		const Cadena& Titu;
		const Fecha& FPubli;
		int price;
		int stock_;
};
std::istream& operator<<(std::istream&is,Articulo&art);
#endif
