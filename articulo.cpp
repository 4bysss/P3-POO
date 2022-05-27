#include"articulo.hpp"
#include"cadena.hpp"
#include"fecha.hpp"
const Cadena& Articulo::referencia()const{return CodRef;}
const Cadena& Articulo::titulo()const{return Titu;}
const Fecha& Articulo::f_publi()const{return FPubli;}
float Articulo::precio()const{return price;}
int Articulo::stock()const{return stock_;}
double& Articulo::precio(){return price;}
int& Articulo::stock(){return stock_;}
std::ostream& operator<<(std::ostream&on,Articulo&ar){
	on<<'['<<ar.referencia()<<"] "<<'"'<<ar.titulo()<<'"'<<','<<ar.f_publi().anno()<<'.'<<ar.precio()<<" €";
	return on;
}
