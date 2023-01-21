typedef struct viaggio *viaggio;
viaggio NewViaggio(char cod[],char localita[],int dur,int price,int posti);
viaggio InputViaggio();
void OutputViaggio(viaggio v);
char *getKey(viaggio v);
