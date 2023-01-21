typedef struct c_set *set;

set newSet();
int emptySet( set s );
int cardinality(set s);
int contains( set s, item e );

int insertSet( set s, item e );
int removeSet( set s, item e );

int unionSet( set s, set s1);

int intersectSet( set s, set s1 );
