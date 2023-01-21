typedef struct esame *Esame;

Esame inserisciEsame(char nome[], int val, Esame head);
Esame inserisciCentro( char nome[], int val, int pos, Esame head);
Esame cancellaTesta(Esame head);
Esame cancellaCentro(Esame head, int pos);

