#include "pedido.hpp"
Pedido::Pedido(Usuario_Pedido&PU,Pedido_Articulo&PeA,Usuario&U,const Tarjeta&T,const Fecha&F):num_ped(todoP+1),imporT(0),cantP(0),tarj(&T),dia(F){
  if(&U!=T.titular()){
    throw Impostor(&U);
  }
  if(U.compra().empty()){
    throw Vacio(&U);
  }
  if(T.caducidad()<F){
    throw Tarjeta::Caducada(T.caducidad());
  }
  if(!T.activa()){
    throw Tarjeta::Desactivada();
  }
  double imporLP=0;
  for(auto&iter:U.compra()){
    if(iter.first->stock()<iter.second){
      for (auto& iter2:U.compra()){
        iter2.second = 0;
      }
      throw SinStock(iter.first);
    }
  }

  PU.asocia(*this,U);
  for(auto&iter:U.compra()){
    ++cantP;
    imporT+=(iter.first->precio()* iter.second);
    iter.first->stock()-=iter.second;
    PeA.pedir(*iter.first,*this,iter.first->precio(),iter.second);
    //PA.pedir(*this,iter.first,iter.first->precio(),iter.second);
  }
  num_ped=++todoP;
  U.compra().clear();

}
std::ostream& operator<<(std::ostream&on,const Pedido&p){
  on<<"Núm pedido: "<<p.numero()<<std::endl;
  on<<"             "<<"Fecha: "<<p.fecha()<<std::endl;
  on<<"             "<<"Pagado con: "<<p.tarjeta()->tipo()<<"n.º:"<<p.tarjeta()->numero()<<std::endl;
  on<<"             "<<"Importe: "<<std::fixed<<std::setprecision(2)<<p.total()<<" €"<<std::endl;
  return on;

    }
