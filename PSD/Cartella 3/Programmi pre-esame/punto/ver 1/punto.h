/*
	-Specifica sintattica:
		Tipi:
			-Tipo di riferimento: punto
			-Tipi usati: reale
		Operatori:
			-CreaPunto(reale,reale)->punto
			-Ascissa(punto)->reale
			-Ordinata(punto)->reale
			-Distanza(punto,punto)->reale
	-Specifica semantica:
		Tipi:
			-Il tipo punto è l'insieme delle coppie (ascissa,ordinata),dove:
				Ascissa e Ordinata sono numeri reali
		Operatori:
			-CreaPunto(x,y)=p
				post: p=(x,y)
			-Ascissa(p)=x
				post: p=(x,y)
			-Ordinata(p)=y
				post: p=(x,y)
			-Distanza(p1,p2)=d
				post: d=sqrt((ascissa(p1)-ascissa(p2))^+(ordinata(p1)-ordinata(p2))^
*/

typedef struct punto {
	float x;
	float y;
}; punto

punto CreaPunto(float x,float y);
float Ascissa(punto p);
float Ordinata(punto p);
floar Distanza(punto p1,punto p2);
		
