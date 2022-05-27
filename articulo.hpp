#ifndef __ARTI__
#define __ARTI__
#include"cadena.hpp"
#include"fecha.hpp"
#include<iostream>
class Articulo{
	public:
		Articulo(const Cadena&ref,const Cadena&titu,const Fecha&fech,float pr,int c=0 ):CodRef(ref),Titu(titu),FPubli(fech),price(pr),stock_(c){};
		const Cadena& referencia()const;
		const Cadena& titulo()const;
		const Fecha& f_publi()const;
		float precio()const;
		int stock()const;
		double& precio();
		int& stock();
	private:
		const Cadena CodRef;
		const Cadena Titu;
		const Fecha FPubli;
		double price;
		int stock_;
};
std::ostream& operator<<(std::ostream&is,Articulo&art);
#endif
