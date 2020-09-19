#include <iostream>
using namespace std;
typedef struct Song
{
	char artist[30];
	char title[30];
} song;
typedef struct Playlist
{
	int no_of_songs;
	song song_list[30];
} playlist;

int main()
{
	playlist my_playlist;
	my_playlist.no_of_songs = 0;
	strcpy_s(my_playlist.song_list[0].artist, 30, "Twice");
	strcpy_s(my_playlist.song_list[0].title, 30, "Cheer Up!");
	my_playlist.no_of_songs++; //곡이 추가될 때마다 1씩 증가.
	strcpy_s(my_playlist.song_list[1].artist, 30, "BTS");
	strcpy_s(my_playlist.song_list[1].title, 30, "Dynamite");
	my_playlist.no_of_songs++;
	strcpy_s(my_playlist.song_list[2].artist, 30, "IU");
	strcpy_s(my_playlist.song_list[2].title, 30, "25");
	my_playlist.no_of_songs++;
	strcpy_s(my_playlist.song_list[3].artist, 30, "도자캣");
	strcpy_s(my_playlist.song_list[3].title, 30, "Say so");
	my_playlist.no_of_songs++;
	strcpy_s(my_playlist.song_list[4].artist, 30, "IU");
	strcpy_s(my_playlist.song_list[4].title, 30, "에잇");
	my_playlist.no_of_songs++;
	strcpy_s(my_playlist.song_list[5].artist, 30, "전소미");
	strcpy_s(my_playlist.song_list[5].title, 30, "What You Waiting For");
	my_playlist.no_of_songs++;

	printf("No\tArtist\tTitle\n");
	printf("==\t======\t=====\n");
	for (int i = 0; i < my_playlist.no_of_songs; i++)
		cout << i + 1 << "\t" << my_playlist.song_list[i].artist << "\t" << my_playlist.song_list[i].title << endl;
	cout << "A total number of songs in the list: " << my_playlist.no_of_songs << endl;
	return 0;
}