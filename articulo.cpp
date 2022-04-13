#include"articulo.hpp"
#include"cadena.hpp"
#include"fecha.hpp"
const Cadena& Articulo::referencia()const{return CodRef;}
const Cadena& Articulo::titulo()const{return Titu;}
const Fecha& Articulo::f_publi()const{return FPubli;}
int Articulo::precio()const{return price;}
int Articulo::stock()const{return stock_;}
