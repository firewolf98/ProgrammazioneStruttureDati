typedef int item;

#define NULLITEM 0

void inputItem ( item a );
void outputItem ( item a );
int eq ( item a, item b );
int cmpItem ( item val, item val1 );
item cloneItem( item a );
void destroyItem( item *a );
