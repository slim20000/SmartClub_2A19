#include "son.h"
/*
son::son()
{

}
*/
void mettreMusique()
{
QMediaPlayer * music = new QMediaPlayer();
music->setMedia(QUrl("C:/Users/DELL/Downloads/ellie-goulding-juice-wrld-hate-me-lyrics.mp3"));
music->play();
}

void mettreMusique2()
{
    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("C:/Users/DELL/Downloads/ellie-goulding-juice-wrld-hate-me-lyrics.mp3"));
    music->play();
}
