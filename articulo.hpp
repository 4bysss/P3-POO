class Articulo{
	public:
		Articulo(Cadena&ref,Cadena&titu,Fecha&fech,int pr,int c=0 );
		Cadena& referencia()const;
		Cadena& titu()const;
		Fecha& f_publi()const;
		int& precio()const;
		int& stock()const;
	private:
		const Cadena& CodRef;
		const Cadena& Titu;
		const Fecha& FPubli;
		int price;
		int stock_;
}
std::istream& operator<<(std::istream&is,Articulo&art);

