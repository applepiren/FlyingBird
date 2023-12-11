//Nama Anggota:
//Suntan Jundi Khalid 2217051021
//Intan Purnama Sari 2217051050
//Rimba Jati Dwi Djatmiko 2217051069

#include <iostream> //untuk menggunakan cin dan cout
#include <windows.h> //untuk peletakan posisi
#include <conio.h> //untuk menggunakan getch
#include <time.h> //untuk mendefinisikan waktu

using namespace std;

HANDLE console = GetStdHandle (STD_OUTPUT_HANDLE); //mendeklarasikan console 
COORD PosisiCursor; //mendeklarasikan posisicursor 

void gotoxy (int x, int y){
	PosisiCursor.X = x;
	PosisiCursor.Y = y;
	SetConsoleCursorPosition (console, PosisiCursor);
}

void loading(){ //menampilkan scene loading
	for (int i = 1; i <= 3; i++){
		system ("cls");
		gotoxy(50,10); cout << "L O A D I N G";
		Sleep(200);
		gotoxy(50,10); cout << "L O A D I N G .";
		Sleep(200);
		gotoxy(50,10); cout << "L O A D I N G ..";
		Sleep(200);
		gotoxy(50,10); cout << "L O A D I N G ...";
		Sleep(200);
		gotoxy(50,10); cout << "L O A D I N G ....";
		Sleep(200);
		gotoxy(50,10); cout << "L O A D I N G .....";
		Sleep(200);
	}
	system("cls");
}

void logo(){
	gotoxy(6, 10); cout << "   _vv__" << endl;
	gotoxy(6, 11); cout << "  (    0)>" << endl;
	gotoxy(6, 12); cout << "<(_/_/_/)" << endl;
	gotoxy(25, 7); cout << "   _vv__" << endl;
	gotoxy(25, 8); cout << "  (    0)>" << endl;
	gotoxy(25, 9); cout << "<(_/_/_/)" << endl;
	gotoxy(70, 10); cout << "   _vv__" << endl;
	gotoxy(70, 11); cout << "  (    0)>" << endl;
	gotoxy(70, 12); cout << "<(_/_/_/)" << endl;
	gotoxy(60, 2); cout << "   _vv__" << endl;
	gotoxy(60, 3); cout << "  (    0)>" << endl;
	gotoxy(60, 4); cout << "<(_/_/_/)" << endl;
	gotoxy(60, 20); cout << "   _vv__" << endl;
	gotoxy(60, 21); cout << "  (    0)>" << endl;
	gotoxy(60, 22); cout << "<(_/_/_/)" << endl;
	gotoxy(85, 5); cout << "   _vv__" << endl;
	gotoxy(85, 6); cout << "  (    0)>" << endl;
	gotoxy(85, 7); cout << "<(_/_/_/)" << endl;
	gotoxy(85, 16); cout << "   _vv__" << endl;
	gotoxy(85, 17); cout << "  (    0)>" << endl;
	gotoxy(85, 18); cout << "<(_/_/_/)" << endl;
	gotoxy(100, 11); cout << "   _vv__" << endl;
	gotoxy(100, 12); cout << "  (    0)>" << endl;
	gotoxy(100, 13); cout << "<(_/_/_/)" << endl;
	gotoxy(2, 2); cout << "HOW TO PLAY : " << endl;
	gotoxy(2, 3); cout << "HINDARI RINTANGAN DENGAN MENEKAN APAPUN" << endl;
	gotoxy(2, 5); cout << "HAVE A NICE GAME!";
}

int play(){
	srand(time(0)); //untuk membuat program merandom
	char mv; //untuk mengerakan burung
	char ulang = 'y'; //untuk melakukan repeat apabila kita menekan y
	int highscore = 0; //untuk skor tertinggi
	
    while (ulang == 'y'){ //perulangan agar bermain kembali ketika repeat sama dengan y
    int score = 0; //perhitungan skor
    bool wasit = true;
    int x = 9; //posisi awal burung
    int pipay[5]; // rintangan sumbu y
    int pipax[5]; // rintangan sumbu x
    pipax[0] = 10; //rintangan 1 akan muncul pada kolom 10
    pipax[1] = 18; //rintangan 2 akan muncul pada kolom 18
	pipax[2] = 27; //rintangan 3 akan muncul pada kolom 27
    for (int i = 0; i < 3; i++){
    	pipay[i] = (rand()-1) % 12 + 2; //random pipa sumbu y
	}
	
	string map[20][30]; //membuat map
    for (int i = 0; i < 20; i++){
        for (int j = 0; j < 30; j++){
            if (i == 0 || i == 19 || j == 0 || j == 29){ //mengoutput batasan dari window 
                map[i][j] = "# ";
            }
            else{
                map[i][j] = "  ";
            }
        }
    }
    
	while (wasit == true){
        for (int i = 0; i < 3; i++){
            for (int j = 1; j < 19; j++){
                map[j][pipax[i]] = "  ";
            }
        }
        for (int i = 0; i < 3; i++){ //membuat rintangan bergerak ke kiri
            pipax[i]--;
        }
        for (int i = 0; i < 3; i++){ //membuat rintangan muncul kembali dari kanan setelah rintangan melewati kolom ketiga
            for (int j = 1; j < 19; j++){
                map[j][pipax[i]] = "* ";
            }
        }
        for (int i = 0; i < 3; i++){ //membuat jarak antara pipa atas dan pipa bawah
            map[pipay[i]][pipax[i]] = "  ";
            map[pipay[i]+1][pipax[i]] = "  ";
            map[pipay[i]+2][pipax[i]] = "  ";
            map[pipay[i]+3][pipax[i]] = "  ";
            map[pipay[i]+4][pipax[i]] = "  ";
        }
        for (int i = 0; i < 3; i++){
            if (pipax[i] == 1){
				pipax[i] = 28;
                pipay[i] = (rand()-1) % 12 + 2;
                }
        }
        map[x][3] = "  ";
        if (kbhit()){ //kbhit memeriksa konsol untuk penekanan tombol terbaru
            mv = getch();
            x = x-3;
        }
        x++;
        if(x < 1){
            x = 1;
        }
        for (int i = 0; i < 3; i++){ //perhitungan score
            if (pipax[i] == 3){
                if (map[x][3] == "  ") {//perhitungan score untuk setiap melewati rintangan
                    score = score + 1;
                }
                if (map[x][3] == "* "){ //ketika burung menabrak "*" maka game over
                    wasit = false;
                }
            }
        }
        map[x][3] = "> "; //burung, dimana diposisikan pada x = 9, yaitu baris ke 9 dan kolom ketiga
        for (int i = 1; i < 19; i++){
            map[i][1] = "  ";
        }
        for (int i = 0; i < 20; i++){
            for (int j = 0; j < 30; j++){
                cout << map[i][j];
            }
        cout << endl;
        }
		cout << "Score : " << score; //menampilkan skor
        Sleep (150);
    	system ("cls");
	}
	gotoxy(45, 12); cout << "GAME OVER!" << endl;
	gotoxy(45, 13); cout << "Score : " << score << endl;
    if (highscore < score){
        highscore = score;
    }
    gotoxy(45, 14); cout << "Highscore : " << highscore << endl;
    gotoxy(45, 15); cout << "Mulai Lagi? (Y / N) : "; cin >> ulang;
	if(ulang =='N') exit(0);
}
}

void menu(){
	do{
		system("cls");
		loading();
		logo();
		gotoxy(47,12); cout << "PLEASE CHOOSE ONE :";
		gotoxy(47,13); cout << "1. START";	 
		gotoxy(47,14); cout << "2. QUIT";
		gotoxy(47,15); cout << "CHOOOSE : ";
		char opt = getche();
		//getche fungsinya sama dengan getch bedanya dapat menampilkan karakter yang diinput
		//option
		if(opt == '1') play(); //jika menjawab 1 maka bermain
		else if (opt == '2') exit(0); //jika 2 maka exit atau memberhentikan program secara paksa/manual
	}
	while (true); //while true
}

int main(){
	menu();
	getch();
}
