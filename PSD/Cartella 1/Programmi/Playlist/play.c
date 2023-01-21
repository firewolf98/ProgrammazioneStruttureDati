#include <stdio.h>
#include "song.h"
#include "playlist.h"

int main(){

	Playlist new = newPlaylist();
	int ris, pos;
	printf("\n\n");
	scanf("%d", &ris);
	while ( ris == 1 ){
		newSong(new);
		scanf("%d", &ris);
	}		
	outputPlaylist(new);
	printf("Pos: ");
	scanf("%d", &pos);
	forwardSong(new, pos);
	outputPlaylist(new);
	scanf("%d", &pos);
	backSong(new,pos);
	outputPlaylist(new);
	char a[20];
	printf("Autore: ");
	scanf("%s", a);
	Playlist p = subPlaylist(new, a);
	printf("\n\n\n");
	outputPlaylist(p);
}
