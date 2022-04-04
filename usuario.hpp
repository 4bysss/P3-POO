class Usuario{
	public:
		Usuario(Cadena&,Cadena&,Cadena&,Cadena&);
	private:
		typedef std::unordered_map<Articulo*, unsigned int> Articulos;
		typedef std::map<Numero, Tarjeta*> Tarjetas;
		Cadena& iden;
		Cadena& nombre;
		Cadena& apellido;
		Cadena& direccion;
		const Clave& clave;
		Articulos arti;
		Tarjetas tarj;
};
class Clave{
	public:
		const static enum Razon{CORTA,ERROR_CRYPT};
		Clave(const char*);
		const char* clave();
		bool verifica(const char*);
		
		
		class Incorrecta{
			public:
				Clave::Razon razon()const;
			private:
				Clave::Razon causa;
		};
	private:
		char*clave;
};

