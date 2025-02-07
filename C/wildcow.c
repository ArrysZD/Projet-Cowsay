// https://github.com/ArrysZD

    #include <stdio.h>
    #include <unistd.h>

    void update() {
        printf("\033[H\033[J");
    }

    void gotoxy(int x, int y) {
        printf("\033[%d;%dH", x, y);
    }

    void drawCow(int x,char *text) {
        gotoxy(1, x);
        printf("%s\n",text);
        gotoxy(3, x);
        printf("  ^__^  \n");
        gotoxy(4, x);
        printf("  (oo)\\_______\n");
        gotoxy(5, x);
        printf("  (__)/       )\\/\\\n");
        gotoxy(6, x);
        printf("      ||----w |\n");
        gotoxy(7, x);
        printf("      ||     ||\n");

    }

    void drawtaureau(int x,char *text){
        gotoxy(1,x-30);
        printf("%s",text);
        gotoxy(3, x);
        printf("                (__)\n");
        gotoxy(4, x);
        printf("     _ _______//(oo)\n");
        gotoxy(5, x);
        printf("/\\//(         //(__)\n");
        gotoxy(6, x);
        printf("       | -----||\n");
        gotoxy(7, x);
        printf("       ||     ||\n");
    }

    void amour(int x){
        printf("                           \n");
        gotoxy(3, x);
        printf("               (__)        ^__^\n");
        gotoxy(4, x);
        printf("     ________//(♥♥)        (♥♥)\\_______\n");
        gotoxy(5, x);
        printf("/\\//(        //(__)        (__)\\       )\\/\\\n");
        gotoxy(6, x);
        printf("       | -----||              ||----w |\n");
        gotoxy(7, x);
        printf("       ||     ||              ||     ||\n");
        gotoxy(8, x);
        //printf("         taureau        ♥♥      vache\n");

    }
    void discution(int x,int y){
        drawtaureau(y,"Eh, belle vache, tu es absolument ravissante \naujourd'hui avec tes taches noires et blanches.");
        drawCow(x,"");
        sleep(5);
        drawCow(x,"Oh, merci, cher taureau! Tes cornes imposantes \n");
        gotoxy(2,x);
        printf("te donnent un air si viril et séduisant.");
        drawtaureau(y,"");
        sleep(5);
        update();
        drawtaureau(y,"Je ne peux m'empêcher d'être attiré par ta douceur.\nVeux-tu aller brouter l'herbe fraîche avec moi?");
        drawCow(x,"");
        sleep(5);
        drawCow(x,"Hmm, ça semble être une proposition irrésistible! J'adorerais! \n");
        gotoxy(2,x);
        printf("surtout dans ce pré verdoyant.");
        drawtaureau(y,"");
        sleep(5);

        update();
        gotoxy(1,y+20);
        printf("allons-y");
        amour(y);
        sleep(3);

    }

void partir(int x){
    printf("                           \n");
    gotoxy(3, x);
    printf("(__)                   ^__^  \n");
    gotoxy(4, x);
    printf("(♥♥)\\_______          (♥♥)\\______\n");
    gotoxy(5, x);
    printf("(__)\\       )\\/\\      (__)\\       )\\/\\\n");
    gotoxy(6, x);
    printf("     ||------|               ||----w |\n");
    gotoxy(7, x);
    printf("     ||     ||               ||     ||\n");
}

    void anime_vache() {
        int x,y=0;
        for (x = 80; x >= 55; x--) {
            update();
            drawCow(x,"");
            drawtaureau(y,"");
            y++;
            fflush(stdout);
            usleep(100000); // Petit délai pour créer l'effet d'animation
        }

        // Une fois que la vache arrive au milieu, afficher le taureau à sa place
        update();
        discution(x,y);
        update();
        for(x=55;x>=0;x--){
            update();
            partir(x);
            fflush(stdout);
            usleep(100000); // Petit délai pour créer l'effet d'animation
        }


        fflush(stdout);
        usleep(1000000); // Attendre un peu avant de quitter
    }

    int main() {
        anime_vache();
        return 0;
    }
