typedef int item;

#define NULLITEM 0

void inputItem ( item a );
void outputItem ( item a );
int eq ( item a, item b );
int cmpItem ( item, item );
item cloneItem( item a );
void destroyItem( item *a );
