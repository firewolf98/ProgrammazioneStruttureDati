typedef struct pto *punto;

punto creapuntonoset(void);
punto creapunto(void);
int distanzapunti(punto a, punto b);
void inspto(punto pto);
int checkpto(punto indovina, punto tentativo);
void waterfire(punto indovina, punto tentativo);
