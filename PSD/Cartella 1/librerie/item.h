typedef int item;

#define NULLITEM 0

void inputItem ( item a );
void outputItem ( item a );
int eq ( item a, item b );
item cloneItem( item a );
void destroyItem( item *a );
