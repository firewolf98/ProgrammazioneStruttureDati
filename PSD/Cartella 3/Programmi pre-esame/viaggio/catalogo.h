typedef struct catalogo *catalogo;
catalogo NewCatalogo(char nome_cat[]);
int AggiungiViaggio(catalogo c,viaggio v);
viaggio SearchViaggio(catalogo c,char cod[]);
