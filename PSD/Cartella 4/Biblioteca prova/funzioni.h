typedef struct libro *Libro;


Libro inseriscilibro(char titolo[],int pagine,Libro head);
Libro inserscilibropos(char titolo[],int pagine,int pos,Libro head);
Libro cancellatesta(Libro head); 
Libro cancellalibropos(int pos,Libro head); 
